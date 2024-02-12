#include <bits/stdc++.h>
using namespace std;

void printFrequencies(int *arr, int n)
{
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            cout << arr[i - 1] << ": " << count << endl;
            count = 1;
            continue;
        }
        count++;
    }
    cout << arr[n - 1] << ": " << count << endl;
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

    printFrequencies(arr, n);

    return 0;
}

/*

6
10 10 10 25 30 30

4
10 10 10 10

3
10 20 30

6
10 10 10 30 30 40

*/

/*

void printFrequencies0(int *arr, int n)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            cout << arr[i] << ": " << count + 1 << endl;
            count = 0;
            continue;
        }
        count++;
    }
    cout << arr[n - 1] << ": " << count + 1 << endl;
}

*/