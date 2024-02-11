#include <bits/stdc++.h>
using namespace std;

int maxDiff(int *arr, int n)
{
    int result = arr[1] - arr[0];
    int smallest = arr[0];
    for (int i = 1; i < n; i++)
    {
        result = max(result, arr[i] - smallest);
        smallest = min(smallest, arr[i]);

        /* if ((arr[i] - smallest) > result)
        {
            result = arr[i] - smallest;
        }

        if (arr[i] < smallest)
        {
            smallest = arr[i];
        } */
    }
    return result;
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

    int result = maxDiff(arr, n);
    cout << result << endl;

    return 0;
}

/*

7
2 3 10 6 4 8 1

6
7 9 5 6 3 2

3
10 20 30

4
30 10 8 2

*/