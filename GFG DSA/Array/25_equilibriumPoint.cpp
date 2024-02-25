#include <bits/stdc++.h>
using namespace std;

bool optimized(int *arr, int arrSum, int n)
{
    if (arrSum - arr[0] == 0)
        return true;
    arrSum -= arr[0];
    // Instead of the above thing, we can maintain a leftSum = 0 in starting and we can run loop normally;

    for (int i = 1; i < n; i++)
    {
        arrSum -= arr[i];
        if (arrSum == arr[i - 1])
        {
            return true;
        }
        arr[i] += arr[i - 1];
    }
    return false;
} // Time: ø(n) & Space: O(1)

void fillPrefix(int arr[], int preArray[], int n)
{
    preArray[0] = arr[0];
    for (int i = 1; i < n; i++)
        preArray[i] = preArray[i - 1] + arr[i];
}

void fillPostfix(int arr[], int postArray[], int n)
{
    postArray[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        postArray[i] = arr[i] + postArray[i + 1];
}

bool isEquilibrium(int arr[], int preArray[], int postArray[], int n)
{
    if (postArray[1] == 0 || preArray[n - 2] == 0)
        return true;

    for (int i = 1; i <= n - 2; i++)
    {
        if (preArray[i - 1] == postArray[i + 1])
            return true;
    }
    return false;
} // Time: ø(n) & Space: ø(2n)

int arraySum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
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

    int arrSum = arraySum(arr, n);
    if (optimized(arr, arrSum, n))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    /* int preArray[n];
    int postArray[n];
    fillPrefix(arr, preArray, n);
    fillPostfix(arr, postArray, n);
    if (isEquilibrium(arr, preArray, postArray, n))
        cout << "Yes" << endl;
    else
        cout << "No" << endl; */

    return 0;
}

/*

5
2 -3 3 -2 2

6
-1 1 1 1 -2 3

6
3 4 8 -9 9 7

*/