#include <bits/stdc++.h>
using namespace std;

int secondLargestElement(int arr[], int n)
{
    int secondMax = -1;
    int largest = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[largest])
        {
            secondMax = largest;
            largest = i;
        }
        else if (arr[i] != arr[largest])
        {
            if (secondMax == -1 || arr[i] > arr[secondMax])
            {
                secondMax = i;
            }
        }
    }
    return secondMax;
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