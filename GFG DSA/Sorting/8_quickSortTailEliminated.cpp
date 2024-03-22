#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int h) // lamutoPartition
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
start:
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        /* quickSort(arr, pi + 1, high); */
        // Update parameters of recursive call
        // and replace recursive call with goto
        low = pi + 1;
        high = high;
        goto start;
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