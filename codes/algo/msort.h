#include <iostream>

/**
 * 选择排序
 * 算法复杂度O(n^2)
 */
template <class T>
void select_sort(T *arr, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int k = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[k] > arr[j])
            {
                k = j;
            }
        }
        if (k != i)
        {
            T t = arr[i];
            arr[i] = arr[k];
            arr[k] = t;
        }
    }
}

/**
 * 插入排序
 * 算法复杂度O(n^2)
 */
template <class T>
void insert_sort(T *arr, int n)
{
    for (int i = 1; i < n; ++i)
    {
        T e = arr[i];
        int k = 0;
        int j;
        for (j = i - 1; j >= 0 && arr[j] > e; --j)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = e;
    }
}

/**
 * 冒泡排序
 * 算法复杂度O(n^2)
 */
template <class T>
void bubble_sort(T *arr, int n)
{
    for (int i = 1; i <= n - 1; ++i)
    {
        for (int j = 0; j < n - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                T t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

/**
 * 希尔排序
 * 算法复杂度O(n(\text{log}_2 n)^2)
 */
template <class T>
void shell_sort(T *arr, int n)
{
    int gap = n >> 1;
    while (gap > 0)
    {

        for (int i = gap; i < n; ++i)
        {
            int t = arr[i];
            int j = 0;
            for (j = i - gap; j >= 0 && arr[j] > t; j -= gap)
            {
                arr[j + gap] = arr[j];
            }
            arr[j + gap] = t;
        }
        gap >>= 1;
    }
}

/**
 * 归并排序（递归版）
 * 算法复杂度O(nlogn)
 */
template <class T>
void merge(T *arr, int s, int m, int t, T *temp)
{
    // 归并arr[s..m]和arr[m + 1.. t]
    int i = s, j = m + 1;
    int k = 0;
    while (i <= m && j <= t)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= m)
    {
        temp[k++] = arr[i++];
    }
    while (j <= t)
    {
        temp[k++] = arr[j++];
    }
    // 结果放回原数组
    k = 0;
    while (s <= t)
    {
        arr[s++] = temp[k++];
    }
}

template <class T>
void merge_sort_rec(T *arr, T *temp, int s, int t)
{
    if (s == t)
    {
        temp[s] == arr[s];
        return;
    }
    int m = s + (t - s) / 2;
    // 划分
    merge_sort_rec(arr, temp, s, m);
    merge_sort_rec(arr, temp, m + 1, t);
    // 归并两个有序子序列
    merge(arr, s, m, t, temp);
}

/**
 * 非递归版归并排序
 */
template <class T>
void merge_sort(T *arr, int n)
{
    using std::min;
    T *a = arr;
    T *b = new int[n];                     // 辅助数组
    for (int seg = 1; seg < n; seg += seg) // 自底向上开始归并, 当前子序列长度为2*seg
    {
        for (int s = 0; s < n; s += seg + seg)
        {
            // 归并[s, s + seg + seg]
            int low = s, mid = min(s + seg, n), high = min(s + seg + seg, n);
            int k = low;
            int s1 = low, t1 = mid;
            int s2 = mid, t2 = high;
            while (s1 < t1 && s2 < t2)
            {
                if (a[s1] <= a[s2])
                {
                    b[k++] = a[s1++];
                }
                else
                {
                    b[k++] = a[s2++];
                }
            }
            while (s1 < t1)
                b[k++] = a[s1++];
            while (s2 < t2)
                b[k++] = a[s2++];
        }
        T *temp = a;
        a = b;
        b = temp;
    }
    if (a != arr)
    {
        for (int i = 0; i < n; i++)
            b[i] = a[i];
    }
    delete[] b;
}

/**
 * 快速排序
 * 算法复杂度: O(nlogn)
 */
template <class T>
void quick_sort(T *arr, int left, int right)
{
    if (left >= right)
        return;
    // 以arr[left..right]中最左侧元素为支点,将该子序列中小于等于支点的序列置于其左侧, 否则置于其右侧
    T pivot = arr[left];
    int i = left, j = right;
    while (i < j)
    {
        while (i < j && arr[j] >= pivot)
        {
            --j;
        }
        arr[i] = arr[j];
        while (i < j && arr[i] <= pivot)
        {
            ++i;
        }
        arr[j] = arr[i];
    }
    arr[i] = pivot;
    quick_sort(arr, left, i - 1);
    quick_sort(arr, i + 1, right);
}

/**
 * 堆排序
 * 算法复杂度: O(nlogn)
 */

// 从R[i]开始向下调整
template <class T>
void heap_adjust(T *arr, int i, int n)
{
    int il, ir;
    while (i <= n / 2 - 1) // 遍历到叶子节点结束
    {
        il = 2 * i + 1; // 结点i的左孩子
        ir = 2 * i + 2; // 结点i的右孩子
        int j = il;
        if (ir < n && arr[ir] > arr[j])
            j = ir;
        if (arr[i] > arr[j]) // 根节点最大, 无需交换
            break;
        std::swap(arr[i], arr[j]);
        i = j;
    }
}

template <class T>
void heap_sort(T *arr, int n)
{
    // 根据初始序列构建大根堆
    for (int i = n / 2 - 1; i >= 0;--i)
    {
        heap_adjust(arr, i, n);
    }
    for (int i = 1; i < n;i++)
    {
        std::swap(arr[0], arr[n - i]);
        // 将R[0..n-i]调整为大根堆
        heap_adjust(arr, 0, n - i);
    }
}