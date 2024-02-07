#include <bits/stdc++.h>
using namespace std;

int largestElement(int arr[], int n)
{
    if (n == 0)
        return -1;

    int maxIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[maxIndex])
        {
            maxIndex = i;
        }
    }
    return maxIndex;
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

    cout << largestElement(arr, n) << endl;

    return 0;
}

/*

4
10 5 20 8

4
40 8 50 100
 */