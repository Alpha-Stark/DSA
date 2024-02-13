#include <bits/stdc++.h>
using namespace std;

int stockProfit(int *arr, int n)
{
    int maxProfit = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            maxProfit += arr[i] - arr[i - 1];
        }
    }
    return maxProfit;
}

int stockProfit2(int *arr, int n)
{
    int profit = 0;
    int buyI = 0;
    int sellI = 0;
    bool isBought = false;
    for (int i = 1; i < n; i++)
    {
        if (isBought && arr[i - 1] > arr[i])
        {
            sellI = i - 1;
            profit += arr[sellI] - arr[buyI];
            isBought = false;
        }

        if (!isBought && (arr[i - 1] < arr[i]))
        {
            buyI = i - 1;
            isBought = true;
        }
    }
    if (isBought)
    {
        profit += arr[n - 1] - arr[buyI];
    }

    if (profit > 0)
    {
        return profit;
    }
    else
    {
        return 0;
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

    cout << "Profit: " << stockProfit(arr, n) << endl;

    return 0;
}

/*

5
1 5 3 8 12

3
30 20 10

3
10 20 30

6
1 5 3 1 2 8

*/