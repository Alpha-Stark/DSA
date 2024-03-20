#include <bits/stdc++.h>
using namespace std;

void lamutoPartition(int arr[], int l, int h)
{
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    lamutoPartition(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

/*
5
30 20 5 10 8
=5 8 30 20 10
*/