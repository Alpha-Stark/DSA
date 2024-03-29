#include <bits/stdc++.h>
using namespace std;

int countAndMerge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    int res = 0;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
        {
            arr[k++] = right[j++];
            res += (n1 - i); // combined inversions addition, number of left[] elements, greater than right[]'s current element
        }
    }
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];

    return res;
}

int countInversions(int arr[], int l, int r)
{
    int res = 0;
    if (l < r)
    {
        int m = l + ((r - l) / 2);
        res += countInversions(arr, l, m);
        res += countInversions(arr, m + 1, r);
        res += countAndMerge(arr, l, m, r);
    }
    return res;
}

/*

5
2 4 1 3 5

*/

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << countInversions(arr, 0, n - 1) << endl;
    return 0;
}

// Not fully right

/*
int countInv(int arr[], int n)
{
    if (n == 1)
        return 0;

    int count = 0;
    int min = arr[0], max = arr[1];
    if (arr[0] > arr[1])
    {
        count++;
        min = arr[1];
        max = arr[0];
    }

    for (int i = 2; i < n; i++)
    {
        if (min < arr[i] && arr[i] < max)
        {
            count++;
        }
        else if (arr[i] < min)
        {
            count += 2;
            min = arr[i];
        }
        else
            max = arr[i];
    }
    return count;
}
*/