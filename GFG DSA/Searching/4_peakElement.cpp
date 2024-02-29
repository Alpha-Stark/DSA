#include <bits/stdc++.h>
using namespace std;

int peakELement(int arr[], int n)
{
    if (n == 1)
        return arr[0];

    if (arr[0] >= arr[1])
        return arr[0];

    if (arr[n - 1] >= arr[n - 2])
        return arr[n - 1];

    int low = 1, high = n - 2;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1])
            return arr[mid];

        if (arr[mid - 1] >= arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << peakELement(arr, n) << endl;

    return 0;
}

/*

5
6 7 8 20 12

*/

/* Sir's Solution, more flexible solution for variations

    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if ( mid==0 || (arr[mid-1] <= arr[mid])) && (mid==n-1 || (arr[mid+1]) <= arr[mid]))
        {
            return arr[mid];
        }

        if (mid>0 && arr[mid-1] >= arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;

*/