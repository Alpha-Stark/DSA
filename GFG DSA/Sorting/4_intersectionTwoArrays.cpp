#include <bits/stdc++.h>
using namespace std;

void printIntersections(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    int lastPrinted = -1;
    while (i < m && j < n)
    {
        if (arr1[i] == arr2[j] && arr1[i] != lastPrinted) /* or we could do: if(i>0 && arr1[i]==arr1[i-1]){i++;continue;}  */
        {
            cout << arr1[i] << " ";
            lastPrinted = arr1[i];
            i++;
            // j++; //because of this j++, the 1 entry got skipped in a very big input
        }

        if (arr1[i] < arr2[j])
            i++;
        else
            j++;
    }
    cout << endl;
}

/*
8 5
3 5 10 10 10 15 15 20
5 10 10 15 30

5 7
1 1 3 3 3
1 1 1 1 3 5 7
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

    printIntersections(arr1, arr2, m, n);

    return 0;
}