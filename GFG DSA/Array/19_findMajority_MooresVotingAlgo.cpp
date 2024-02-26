#include <bits/stdc++.h>
using namespace std;

// Also known as Moore’s Voting Algorithm.
int majority(int *arr, int n)
{
    // Phase 1, finding the most frequently appearing element
    int res = 0;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[res] == arr[i])
            count++;
        else
            count--;

        if (count == 0)
        {
            res = i;
            count = 1;
        }
    }

    // Phase 2, checking if the maximum occuring element is a Majority
    int finalCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[res] == arr[i])
        {
            finalCount++;
        }
    }

    if (finalCount <= n / 2)
        return -1;

    return res;

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

    cout << majority(arr, n) << endl;
    return 0;
}