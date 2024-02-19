#include <bits/stdc++.h>
using namespace std;

int maxSum(int *arr, int n)
{
    int res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        int currentMax = INT_MIN;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            currentMax = max(currentMax, sum);
        }
        res = max(res, currentMax);
    }
    return res;
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
    cout << maxSum(arr, n) << endl;

    return 0;
}

/*

7
2 3 -8 7 -1 2 3
=11

3
5 8 3
=16

3
-6 -1 -8
=-1

*/