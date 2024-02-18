#include <bits/stdc++.h>
using namespace std;

int maxOnes(int *arr, int n)
{
    int allMax = 0;
    int currentMax = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            allMax = max(currentMax, allMax);
            currentMax = 0;
        }
        else
        {
            currentMax++;
        }
    }
    return allMax;
    // This is not fully right solution because this will not count the max 1s if they appear at the last. Eg: 1 0 1 1 0 1 1 1 1
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
    cout << maxOnes(arr, n) << endl;

    return 0;
}

/*

6
0 1 1 0 1 0

4
1 1 1 1

3
0 0 0

9
1 0 1 1 1 1 0 1 1

9
1 0 1 1 0 1 1 1 1

*/