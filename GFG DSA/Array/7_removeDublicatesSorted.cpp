#include <bits/stdc++.h>
using namespace std;

int removeDublicates(int *arr, int n)
{
    int res = n;
    int i = 1;
    while (i < res)
    {
        if (arr[i] == arr[i - 1])
        {
            for (int j = i; j < n; j++)
            {
                arr[j - 1] = arr[j];
            }
            res--;
        }
        else if (arr[i] != arr[i - 1])
        {
            ++i;
        }
    }
    return res;
} // O(n^2)

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int newN = removeDublicates(arr, n);

    for (int i = 0; i < newN; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

/*

7
1 2 2 3 3 3 4

7
10 20 20 30 30 30 30

*/