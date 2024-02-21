#include <bits/stdc++.h>
using namespace std;

void flips(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            if (arr[i] == arr[0])
            {
                cout << "Flip from " << i << " to ";
            }
            else
            {
                cout << i - 1 << endl;
            }
        }
    }
    if (arr[n - 1] != arr[0])
    {
        cout << n - 1 << endl;
    }
} // ø(n)

void flips1(int *arr, int n)
{
    if (arr[0] == 0)
    {
        for (int i = 1; i < n; i++)
        {
            if (arr[i - 1] == 0 && arr[i] == 1)
            {
                cout << "Flip from " << i;
            }
            else if (arr[i - 1] == 1 && arr[i] == 0)
            {
                cout << " to " << i - 1 << endl;
            }
        }
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            if (arr[i - 1] == 1 && arr[i] == 0)
            {
                cout << "Flip from " << i;
            }
            else if (arr[i - 1] == 0 && arr[i] == 1)
            {
                cout << " to " << i - 1 << endl;
            }
        }
    }
} // ø(n), but too much code repeatation

int flips2(int *arr, int n)
{
    int n1 = 0, n0 = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] == 0 && arr[i] == 1)
        {
            n0++;
        }
        else if (arr[i - 1] == 1 && arr[i] == 0)
        {
            n1++;
        }
    }

    if (arr[n - 1] == 0)
    {
        n0++;
    }
    else
    {
        n1++;
    }

    return min(n0, n1);
    // or we again traverse the array and see which group(0 or 1) to print. But this will have ø(2n) for sure.
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

    // cout << flips2(arr, n) << endl;
    flips(arr, n);

    return 0;
}

/*

6
1 1 0 0 0 1

11
1 0 0 0 1 0 0 1 1 1 1

3
1 1 1

2
0 1

*/