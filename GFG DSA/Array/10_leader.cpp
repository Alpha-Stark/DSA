#include <bits/stdc++.h>
using namespace std;
void printLeaders(int *arr, int n)
{
    int curr_large = arr[n - 1];
    cout << curr_large << " ";

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > curr_large)
        {
            curr_large = arr[i];
            cout << curr_large << " ";
        }
    }
} // ø(n)

int main()
{
    int n, d;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    printLeaders(arr, n);

    return 0;
}

/*

7
7 10 4 10 6 5 2

*/