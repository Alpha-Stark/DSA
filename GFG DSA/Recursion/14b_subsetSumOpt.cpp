#include <bits/stdc++.h>
using namespace std;

int subsetSum(int arr[], int n, int sum)
{
    if (n == 0)
        return (sum == 0) ? 1 : 0;

    return subsetSum(arr, n - 1, sum) + subsetSum(arr, n - 1, sum - arr[n - 1]);
}

int main()
{
    int n;
    cin >> n;

    // create an array of size n and take input from user
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int current;
        cin >> current;
        arr[i] = current;
    }

    int sum;
    cin >> sum;

    cout << subsetSum(arr, n, sum) << endl;

    return 0;
}

/*

5
10 5 2 3 6
8

=2

*/