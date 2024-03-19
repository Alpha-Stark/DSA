#include <bits/stdc++.h>
using namespace std;

void naivePartition(int arr[], int l, int h, int p)
{
    int nTemp = h - l + 1;
    int temp[nTemp];
    int index = 0;
    for (int i = l; i <= h; i++)
    {
        if (arr[i] <= arr[p])
            temp[index++] = arr[i];
    }
    for (int i = l; i <= h; i++)
    {
        if (arr[i] > arr[p])
            temp[index++] = arr[i];
    }
    for (int i = l; i <= h; i++)
        arr[i] = temp[i - l]; // or make index=0 again and use temp[index++];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    naivePartition(arr, 0, n - 1, n - 1);

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