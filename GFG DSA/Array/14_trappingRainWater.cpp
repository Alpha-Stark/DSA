#include <bits/stdc++.h>
using namespace std;

int trappedWater(int *arr, int n)
{
    int localMax = 0;
    int i = 1;
    int res = 0;
    while (i < n)
    {
        if (arr[i] < arr[i - 1] || i == n - 1)
        {
            int threshold = min(arr[i - 1], arr[localMax]);
            for (int j = i - 1; j > localMax; j--)
            {
                res += threshold - arr[j];
            }
            localMax = i - 1;
        }
        i++;
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
    cout << trappedWater(arr, n) << endl;

    return 0;
}

/*

3
2 0 2

5
3 0 1 2 5

8
3 0 1 2 5 1 2

3
1 2 3

3
3 2 1

*/