#include <bits/stdc++.h>
using namespace std;

int lamutoPartition(int arr[], int l, int h)
{
    int i = l;
    int pivotInd = h;
    for (int j = l; j <= h - 1; j++)
    {
        if (arr[j] <= arr[pivotInd])
        {
            swap(arr[j], arr[i]);
            i++;
        }
    }
    swap(arr[i], arr[pivotInd]);
    return i;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = lamutoPartition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

/*
6
30 20 5 10 8 15

*/