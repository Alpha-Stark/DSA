#include <bits/stdc++.h>
using namespace std;

int maxEvenOdd(int *arr, int n)
{
    int result = 1;
    for (int i = 0; i < n - 1; i++)
    {
        int currentMax = 1;
        // Odd + Even = Odd  | Even + Odd = Odd
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