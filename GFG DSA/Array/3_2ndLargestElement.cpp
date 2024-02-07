#include <bits/stdc++.h>
using namespace std;

int secondLargestElement(int arr[], int n)
{
    if (n == 0 || n == 1)
        return -1;

    int maxIndex = 0;
    int secondMaxIndex = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[maxIndex])
        {
            maxIndex = i;
        }

        if (arr[i] < arr[maxIndex] && arr[i] > arr[secondMaxIndex])
        {
            secondMaxIndex = i;
        }
    }
    if (arr[maxIndex] == arr[secondMaxIndex])
    {
        return -1;
    }
    else
    {
        return secondMaxIndex;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << secondLargestElement(arr, n) << endl;

    return 0;
}

/*

4
10 5 8 2

5
20 10 20 8 12

 */