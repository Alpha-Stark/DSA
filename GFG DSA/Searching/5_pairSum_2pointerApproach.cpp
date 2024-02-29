#include <bits/stdc++.h>
using namespace std;

bool pairSum(int arr[], int n, int x)
{
    int l = 0, r = n - 1;
    while (l < r)
    {
        int sum = arr[l] + arr[r];
        if (sum == x)
        {
            return true;
        }
        else
        {
            if (sum < x)
                l++;
            else
                r--;
        }
    }
    return false;
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
    int x;
    cin >> x;

    if (pairSum(arr, n, x))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}

/*

5
2 5 8 12 30
17
=yes

4
3 8 13 18
14
=no

*/