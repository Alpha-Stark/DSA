#include <bits/stdc++.h>
using namespace std;

int trappedWater2(int *arr, int n)
{
    int res = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int leftMax = arr[i];
        for (int j = 0; j < i; j++)
        {
            leftMax = max(arr[j], leftMax);
        }
        int rightMax = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            rightMax = max(arr[j], rightMax);
        }
        res += min(leftMax, rightMax) - arr[i];
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
    cout << trappedWater2(arr, n) << endl;

    return 0;
}

/*

3
2 0 2

5
3 0 1 2 5

8
3 0 1 2 5 1 2 4

3
1 2 3

3
3 2 1

*/