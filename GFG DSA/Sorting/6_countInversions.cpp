#include <bits/stdc++.h>
using namespace std;

// Not fully right
int countInversions(int arr[], int n)
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

    cout << countInversions(arr, n) << endl;
    return 0;
}