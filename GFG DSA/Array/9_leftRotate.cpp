#include <bits/stdc++.h>
using namespace std;

int *leftRotate2(int arr[], int n, int d)
{
    int *arr2 = new int[n];
    int i = 0;
    int j = n - d;
    while (i < d)
    {
        arr2[j] = arr[i];
        i++;
        j++;
    }
    j = 0;
    while (i < n)
    {
        arr2[j] = arr[i];
        i++;
        j++;
    }
    return arr2;
} // ø(n) but aux space also ø(n)

int main()
{
    int n, d;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> d;
    if (d == 0 or d == n or d % n == 0)
    {
        cout << "Array will remain the same." << endl;
        return -1;
    }

    int *newArray = leftRotate2(arr, n, d);
    for (int i = 0; i < n; i++)
    {
        cout << newArray[i] << " ";
    }
    cout << endl;

    delete[] newArray;

    return 0;
}

/*

5
1 2 3 4 5
2

*/