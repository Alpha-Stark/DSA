#include <bits/stdc++.h>
using namespace std;

int slidingWindow(int *arr, int n, int k)
{
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    int maxResult = sum;
    int j = 0;
    for (int i = k; i < n; i++)
    {
        sum += arr[i] - arr[j]; // in place of using j, we could have directly done j <-> i-k
        maxResult = max(maxResult, sum);
        j++;
    }
    return maxResult;
}

int main()
{
    int n, k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    cout << slidingWindow(arr, n, k) << endl;
    return 0;
}

/*

6
1 8 30 -5 20 7
3
=45

5
5 -10 6 90 3
2
=96

*/