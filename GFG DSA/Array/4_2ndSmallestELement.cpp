#include <bits/stdc++.h>
using namespace std;

int secondSmallestElement(int arr[], int n)
{
    int smallest = arr[0];
    int sSmallest = INT_MAX; // secondSmallest
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            sSmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] != smallest && arr[i] < sSmallest)
        {
            sSmallest = arr[i];
        }
    }
    return sSmallest;
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

    cout << secondSmallestElement(arr, n) << endl;

    return 0;
}

/*

4
10 5 8 2

5
20 10 20 8 12

4
10 10 10 10

*/