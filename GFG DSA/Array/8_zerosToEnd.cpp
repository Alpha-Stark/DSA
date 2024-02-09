#include <bits/stdc++.h>
using namespace std;

void zeroToEnd(int *arr, int n)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
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

    zeroToEnd(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

/*

6
8 5 0 10 0 2

6
0 0 0 0 10 0

2
10 20

*/