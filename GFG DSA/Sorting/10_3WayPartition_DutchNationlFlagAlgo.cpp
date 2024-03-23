#include <bits/stdc++.h>
using namespace std;

void threeWayPartition(vector<int> &arr, int n) // lamuto
{
    int pivot = 1;
    int low = 0, high = n - 1;
    int mid = 0;
    while (mid <= high)
    {
        if (arr[mid] < pivot)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] > pivot)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
        else
        {
            mid++;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    // int arr[n];
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    threeWayPartition(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

/*
6
0 1 2 1 1 2
*/