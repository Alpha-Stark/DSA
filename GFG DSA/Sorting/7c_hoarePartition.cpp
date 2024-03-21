#include <bits/stdc++.h>
using namespace std;

int hoarePartition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l - 1, j = h + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        // Move till we find an element bigger than pivot from left side
        do
        {
            j--;
        } while (arr[j] > pivot);
        // Move back till we find an element smaller than pivot from right side

        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
        // swap both position as the element smaller than pivot is placed left of it and element bigger than it to it's right
    }
}
// Generally more efficient than Lomuto's algorithm due to its simultaneous scanning from both ends, leading to fewer steps and swaps, and often better pivot selection.

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = hoarePartition(arr, low, high);

        quickSort(arr, low, pi);
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
15 20 5 10 8 30

*/