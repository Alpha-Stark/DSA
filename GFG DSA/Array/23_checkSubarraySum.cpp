#include <bits/stdc++.h>
using namespace std;

bool checkSubarraySum(int *arr, int n, int k)
{
    int s = 0;
    int e = 0;
    int sum = 0;
    while (s <= e && e < n)
    {
        if (sum < k)
        {
            sum += arr[e];
            e++;
        }
        else if (sum > k)
        {
            s++;
            sum -= arr[s - 1];
        }

        if (sum == k)
            return true;
    }
    return false;
}

// Sir's code:
bool isSubSum(int *arr, int n, int k)
{
    int s = 0, curr = 0;
    for (int e = 0; e < n; e++)
    {
        curr += arr[e];
        while (k < curr)
        {
            s -= arr[s];
            s++;
        }
        if (curr == k)
            return true;
    }
    return false;
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

    if (checkSubarraySum(arr, n, k))
    {

        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}

/*

6
1 4 20 3 10 5
33

6
1 4 20 3 10 5
5

5
3 2 0 4 7
6

1
1
1

*/