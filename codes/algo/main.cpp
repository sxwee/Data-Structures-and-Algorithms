#include <iostream>
#include <cstdlib>
#include <ctime>
#include "msort.h"
using namespace std;

void visit(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n = 10;
    srand(time(0));
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10000;
    }
    visit(arr, n);
    // bubble_sort(arr, n);
    // select_sort(arr, n);
    // insert_sort(arr, n);
    // shell_sort(arr, n);
    // int *temp = new int[n];
    // merge_sort_rec(arr, temp, 0, n - 1);
    // delete [] temp;
    // merge_sort(arr, n);
    // quick_sort(arr, 0, n - 1);
    heap_sort(arr, n);
    visit(arr, n);
    return 0;
}