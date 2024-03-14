#include <bits/stdc++.h>
using namespace std;

void merge2SortedArrays(int arr[], int left[], int right[], int n1, int n2, int k)
{
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < n1)
        arr[k++] = left[i++];

    while (j < n2)
        arr[k++] = right[j++];
}

void mergeFunction(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1, n2 = high - mid;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];

    for (int i = 0; i < n2; i++)
        right[i] = arr[(mid + 1) + i];

    merge2SortedArrays(arr, left, right, n1, n2, low);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int mid = (0 + n - 1) / 2;
    mergeFunction(arr, 0, mid, n - 1);
    return 0;
}