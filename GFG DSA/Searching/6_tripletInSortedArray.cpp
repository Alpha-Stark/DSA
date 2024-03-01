#include <bits/stdc++.h>
using namespace std;

bool tripletSum(int arr[], int n, int x)
{
    if (n < 3)
        return false;

    int j, k;
    for (int i = 0; i < n - 2; i++)
    {
        if (arr[i] > x)
            continue;

        /* Now, Pair sum/ 2Pointers approach. Could have also used already made pairSum function(with few parameter modifications) to make the current code more shorter. */
        int remSum = x - arr[i];
        j = i + 1;
        k = n - 1;

        while (j < k)
        {
            int smallSum = arr[j] + arr[k];
            if (smallSum == remSum)
                return true;
            else if (smallSum > x)
                k--;
            else
                j++;
        }
    }
    return false;
} // O(n^2) , if we are not given a sorted array, them me can use sort function to sort the array with O(nlogn) as it won't have any change on our overall time complexity of O(n^2)

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cin >> x;

    if (tripletSum(arr, n, x))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}

/*

5
2 3 5 6 15
14

7
2 3 4 8 9 20 40
32

*/