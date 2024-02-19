#include <bits/stdc++.h>
using namespace std;

int maxSum(int *arr, int n)
{
    int resMax = arr[0]; // or INT_MIN
    int prevMax = arr[0];
    for (int i = 1; i < n; i++)
    {
        prevMax = max(prevMax + arr[i], arr[i]);
        resMax = max(prevMax, resMax);

        /* int newMax = max(prevMax + arr[i], arr[i]);
        resMax = max(newMax, resMax);
        prevMax = newMax;
        */
    }
    return resMax;
} // O(n)

int maxSum2(int *arr, int n)
{
    int res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            res = max(res, sum);
        }
    }
    return res;
} // O(n^2)

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