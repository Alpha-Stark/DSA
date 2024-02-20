#include <bits/stdc++.h>
using namespace std;

int maxEvenOdd(int *arr, int n)
{
    // To solve it in linear time, thinking approach should to from the Kadane's algorithm. Understand the pattern why.
    int result = 1;
    int currentMax = 1;
    for (int i = 1; i < n; i++)
    {
        // Odd + Even = Odd  |  Even + Odd = Odd
        if ((arr[i] + arr[i - 1]) % 2 != 0)
        {
            currentMax++;
            result = max(result, currentMax);
        }
        else
        {
            currentMax = 1;
        }
    }
    return result;
} // ø(n) //Because we can work just by knowing if previous was under valid or not that's it. And from it, it was clear we can apply kadane's
/*
Like Kadane's Algo, here too, we start from i=1, and for every element - 2 cases, either we countinue/extend the previous subarray or we begin a new one. Because here too we are looking at the end of the subarray and making next decision.
*/

int maxEvenOdd2(int *arr, int n)
{
    int result = 1;
    for (int i = 0; i < n - 1; i++)
    {
        int currentMax = 1;
        // Odd + Even = Odd  |  Even + Odd = Odd
        for (int j = i + 1; j < n; j++)
        {
            if ((arr[j] + arr[j - 1]) % 2 != 0) // if (( arr[j]%2!= 0 && arr[j - 1]%2==0) || arr[j]%2== 0 && arr[j - 1]%2!=0)){}
            {
                currentMax++;
            }
            else
            {
                break;
            }
        }
        result = max(result, currentMax);
    }
    return result;
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
    cout << maxEvenOdd(arr, n) << endl;

    return 0;
}

/*

5
10 12 14 7 8
=3

4
7 10 13 14
=4

4
10 12 8 4
=1

6
5 10 20 6 3 8
=3

*/