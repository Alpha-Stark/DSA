#include <bits/stdc++.h>
using namespace std;

void printUnion(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    int prevE = -1;
    while (i < m && j < n)
    {
        if (arr1[i] <= arr2[j])
        {
            if (arr1[i] != prevE)
            {
                prevE = arr1[i];
                cout << arr1[i++] << " ";
            }
            else
                i++;
        }
        else if (arr2[j] < arr1[i])
        {
            if (arr2[j] != prevE)
            {
                prevE = arr2[j];
                cout << arr2[j++] << " ";
            }
            else
                j++;
        }
    }

    while (i < m)
    {
        if (arr1[i] != prevE)
        {
            prevE = arr1[i];
            cout << arr1[i++] << " ";
        }
        else
            i++;
    }

    while (j < n)
    {
        if (arr2[j] != prevE)
        {
            prevE = arr2[j];
            cout << arr2[j++] << " ";
        }
        else
            j++;
    }
}

/*
8 5
3 5 10 10 10 15 15 20
5 10 10 15 30

5 7
1 1 3 3 3
1 1 1 1 3 5 7

6 2
2 3 3 3 4 4
4 4
*/

int main()
{
    int m, n;
    cin >> m >> n;
    int arr1[m], arr2[n];
    for (int i = 0; i < m; i++)
        cin >> arr1[i];

    for (int i = 0; i < n; i++)
        cin >> arr2[i];

    printUnion(arr1, arr2, m, n);

    return 0;
}