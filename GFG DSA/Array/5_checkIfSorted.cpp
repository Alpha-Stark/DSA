#include <bits/stdc++.h>
using namespace std;

string checkSorted(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return "False";
        }
    }
    return "True";
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

    cout << checkSorted(arr, n) << endl;

    return 0;
}

/*

4
5 20 80 100

*/