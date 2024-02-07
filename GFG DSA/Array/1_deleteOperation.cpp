#include <bits/stdc++.h>
using namespace std;

int deleteElement(int arr[], int n, int del)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == del)
        {
            break;
        }
    }
    if (i == n)
        return n;

    for (int j = i; j < n - 1; j++)
    {
        arr[j] = arr[j + 1];
    }
    return n - 1;
}

int main()
{
    int n, del;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> del;

    n = deleteElement(arr, n, del);

    cout << "Final Array:";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

/*
5
3 8 12 5 6
6
 */