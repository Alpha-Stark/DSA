#include <bits/stdc++.h>
using namespace std;

int sortedRotated(int arr[], int low, int high, int x)
{
    int mid = (low + high) / 2;
    if (arr[mid] == x)
        return mid;

    if (low >= high)
    {
        return -1;
    }

    if (arr[low] < arr[mid])
    {
        if (arr[low] <= x && x <= arr[mid - 1])
            return sortedRotated(arr, low, mid - 1, x);
        else
            return sortedRotated(arr, mid + 1, high, x);
    }
    else
    {
        if (arr[mid + 1] <= x && x <= arr[high])
            return sortedRotated(arr, mid + 1, high, x);
        else
            return sortedRotated(arr, low, mid - 1, x);
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
    int x;
    cin >> x;
    cout << sortedRotated(arr, 0, n - 1, x) << endl;

    return 0;
}

/*

7
10 20 30 40 50 8 9
30

5
100 200 300 10 20
40

7
100 200 300 400 20 30 40
50

7
100 500 10 20 30 40 50
40 or 500 or 100

7
100 200 500 1000 2000 10 20
25

*/

/* Sir's solution:

int sortedRotated(int arr[], int n, int x)
    int mid = (low + high) / 2;
    while(low<=high){
        if (arr[mid] == x)
            return mid;

        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= x && x <= arr[mid - 1])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (arr[mid + 1] <= x && x <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

*/