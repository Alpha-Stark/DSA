#include <bits/stdc++.h>
using namespace std;

int minKadanes(int *arr, int n)
{
    int resMin = arr[0]; // or INT_MIN
    int prevMin = arr[0];
    for (int i = 1; i < n; i++)
    {
        prevMin = min(prevMin + arr[i], arr[i]);
        resMin = min(prevMin, resMin);
    }
    return resMin;
}
int kadanes(int *arr, int n)
{
    int resMax = arr[0];
    int prevMax = arr[0];
    for (int i = 1; i < n; i++)
    {
        prevMax = max(prevMax + arr[i], arr[i]);
        resMax = max(prevMax, resMax);
    }
    return resMax;
}

/*
    Idea: Take the Maximum of the following two,
        1. Maximum Sum of a Normal Subarray (Easy: Kadane's Algo)
        2. Maximum sum of a circular Subarray (Subtract the minimum sum subarray from the TotalArraySum and to find minumum subarray sum, we can modify Kadane's algorithm slightly)
*/
int circularSubarray(int *arr, int n)
{
    int normalMax = kadanes(arr, n);
    if (normalMax < 0)
        return normalMax;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int circularMax = sum - minKadanes(arr, n);
    return max(normalMax, circularMax);
} // ø(n)

/*
Course solution to get work done using only max kadane's algo:
int overallMaxSum(int arr[], int n)
{
    int max_normal = normalMaxSum(arr, n); //kadanes call
    if(max_normal < 0)
        return max_normal;

    int arr_sum = 0;
    for(int i = 0; i < n; i++)
    {
        arr_sum += arr[i];
        arr[i] = -arr[i];
    }
    int max_circular = arr_sum + normalMaxSum(arr, n);
    return max(max_circular, max_normal);
}
*/

int circularSubarray2(int *arr, int n)
{
    int res = arr[0];
    for (int i = 0; i < n; i++)
    {
        int currentMax = 0;
        for (int j = i; j <= n + i - 1; j++)
        {
            currentMax += arr[j % n];
            res = max(res, currentMax);
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
    cout << circularSubarray(arr, n) << endl;

    return 0;
}

/*

4
5 -2 3 4
=12

3
2 3 -4
=5

5
8 -4 3 -5 4
12

4
-3 4 6 -2
=10

3
-8 7 6
=13

6
3 -4 5 6 -8 7
=17

*/