#include <bits/stdc++.h>
using namespace std;

int repeatingElement(int arr[], int n) // as out problem say we will get arr[i] == 0, hence we have modified the standard algorithm listed below.
{
    // everywhere added 1, and return slow-1. Because we are treating every element as it's incremented value. 0=>1, 1=>2, 2=>3,.... By this we'll still be able to implement the same standard algorithm and at the end just return this value by decreasing it with 1. Because due to 0 value, we can get into infinite loop
    int slow = arr[0] + 1, fast = arr[0] + 1;
    do
    {
        slow = arr[slow] + 1;
        fast = arr[arr[fast] + 1] + 1;
    } while (slow != fast);

    slow = arr[0] + 1;
    while (slow != fast)
    {
        slow = arr[slow] + 1;
        fast = arr[fast] + 1;
    }
    return slow - 1;
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

    cout << repeatingElement(arr, n) << endl;

    return 0;
}

/*

6
0 2 1 3 2 2

7
1 2 3 0 3 4 5

2
0 0

*/

int repeatingElementStandard(int arr[], int n) // This works if any element arr[i] != 0, but our question allows arr[i] == 0, so we medify this problem a bit
{
    // This is the standard algorithm, which can be also seen in the other LinkedList problem called, detect loop in LinkedList
    int slow = arr[0], fast = arr[0];
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    slow = arr[0];
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}