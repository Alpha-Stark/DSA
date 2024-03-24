// Program to find maximum guest at any time in a party
#include <iostream>
#include <algorithm>
using namespace std;

int findMaxGuests(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);

    int curr = 1, res = 1;
    int i = 1, j = 0;

    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            curr += 1;
            i += 1;
        }
        else
        {
            curr -= 1;
            j += 1;
        }
        res = max(res, curr);
    }
    return res;
}
int main()
{
    int arr[] = {1, 2, 10, 5, 5};
    int dep[] = {4, 5, 12, 9, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    findMaxGuests(arr, dep, n);
    return 0;
}
