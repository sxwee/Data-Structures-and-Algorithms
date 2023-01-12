#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * 分区函数
 * 将大于基准和小于基准的元素划分到基准点的左侧和右侧并返回基准在数组中的位置索引
 */
int partition(vector<int> &arr, int left, int right, int privot_idx)
{
    int privot_val = arr[privot_idx];
    // 将基准元素移动到最右端   
    swap(arr[right], arr[privot_idx]);
    int store_idx = left;
    for (int i = left; i < right; i++)
    {
        if (arr[i] < privot_val)
        {
            swap(arr[i], arr[store_idx]);
            store_idx++;
        }
    }
    swap(arr[store_idx], arr[right]);
    return store_idx;
}

/**
 * 快速选择（递归版）
 */
int quick_select(vector<int> &arr, int left, int right, int k)
{
    if (left == right)
        return arr[left];
    // 在left和right间选择基准索引
    int privot_idx = left + rand() % (right - left + 1);
    privot_idx = partition(arr, left, right, privot_idx);
    if (privot_idx == k - 1)
        return arr[privot_idx];
    else if (privot_idx > k - 1)
        return quick_select(arr, left, privot_idx - 1, k);
    else
        return quick_select(arr, privot_idx + 1, right, k);
}

/**
 * 快速选择（非递归版）
 */
int quick_select(vector<int> &arr, int k)
{
    int left = 0, right = arr.size() - 1;
    while(left < right)
    {
        int privot_idx = left + rand() % (right - left + 1);
        privot_idx = partition(arr, left, right, privot_idx);
        if(privot_idx == k - 1)
            return arr[privot_idx];
        else if(privot_idx > k - 1)
            right = privot_idx - 1;
        else
            left = privot_idx + 1;
    }
    return arr[right];
}

int main()
{
    vector<int> arr = {1, 4, 2, 7, 10, 0, 3};
    int k = 5;
    cout << quick_select(arr, 0, arr.size() - 1, k) << endl; // 4
    cout << quick_select(arr, k) << endl; // 4
    // https://en.cppreference.com/w/cpp/algorithm/nth_element
    nth_element(arr.begin(), arr.begin() + k - 1, arr.end());
    cout << arr[k - 1] << endl; // 4
    return 0;
}