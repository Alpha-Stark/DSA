#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int l, int h) // lamuto
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
int kthSmallest(vector<int> &arr, int low, int high, int k)
{
    while (low <= high)
    {
        int pi = partition(arr, low, high);
        if (pi == k - 1)
            return arr[pi];

        if (pi < k - 1)
        {
            low = pi + 1;
        }
        else if (pi > k - 1)
        {
            high = pi - 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    // int arr[n];
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;
    cout << kthSmallest(arr, 0, n - 1, k) << endl;

    return 0;
}

/*
6
15 20 5 10 8 30
2
=8

*/

int kthSmallestRec(vector<int> &arr, int low, int high, int k)
{
    int pi = partition(arr, low, high);

    if (pi == k - 1)
        return arr[pi];

    int result;
    if (pi < k - 1)
    {
        result = kthSmallest(arr, pi + 1, high, k);
    }
    else if (pi > k - 1)
    {
        result = kthSmallest(arr, low, pi - 1, k);
    }
    return result;
}
