#include <bits/stdc++.h>
using namespace std;

int trappedWater(int *arr, int n)
{
    /* Now how do we get here? from the below solution, there we understood that every element need its left and right max, without it, it was not possible to solve this problem.
       And we didn't wanted the n^2 complexity, so the only way is to keep pre-calculate the left max and right max for all elements using extra spaces, and based on those we solve the problem.
    */
    int leftMax[n]; // left max array
    leftMax[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = max(arr[i], leftMax[i - 1]); // By using last element's value we can get left max and no need maintain currentMax variable.
    }

    int rightMax[n]; // right max array
    rightMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = max(arr[i], rightMax[i + 1]);
    }

    int res = 0;
    for (int i = 1; i <= n - 2; i++)
    {
        res += min(leftMax[i], rightMax[i]) - arr[i];
    }

    return res;
}

int trappedWater2(int *arr, int n)
{
    int res = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int leftMax = arr[i];
        for (int j = 0; j < i; j++)
        {
            leftMax = max(arr[j], leftMax);
        }
        int rightMax = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            rightMax = max(arr[j], rightMax);
        }
        res += min(leftMax, rightMax) - arr[i];
    }

    return res;
} // ø(n^2)

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << trappedWater(arr, n) << endl;

    return 0;
}

/*

3
2 0 2

5
3 0 1 2 5

8
3 0 1 2 5 1 2 4

3
1 2 3

3
3 2 1

*/