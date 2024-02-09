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

int removeDublicates2(int *arr, int n)
{
    int i = 1;
    int j = 0;
    for (i = 1; i < n; i++)
    {
        if (arr[j] != arr[i])
        {
            arr[j + 1] = arr[i];
            j++;
            /* int temp = arr[j + 1]; arr[j + 1] = arr[i]; arr[i] = temp; // instead of swapping we, can just assign the arr[i] to the jth index, because that swapped or unswapped element wont be touched after that.*/
        }
    }
    return j + 1; // because simple j is index, but we have to send the number of elements, so total number of element will be j+1 in the array;
} // O(n)

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int newN = removeDublicates2(arr, n);

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