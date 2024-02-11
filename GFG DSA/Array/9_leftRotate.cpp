#include <bits/stdc++.h>
using namespace std;

void reverse(int *arr, int low, int high)
{
    while (low < high)
    {
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}

void leftRotate(int *arr, int n, int d)
{
    reverse(arr, 0, d - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, n - 1);
} // ø(n) along with aux space ø(1) only. OPTIMIZED

int main()
{
    int n, d;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> d;
    d = d % n; // for d's value greater than n

    if (d == 0 or d == n)
    {
        cout << "Array will remain the same." << endl;
        return -1;
    }

    leftRotate(arr, n, d);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// Solution 2 - better than naive
int *leftRotate2(int arr[], int n, int d)
{
    int *arr2 = new int[n]; // or we can take the approach where we take a temporary array with the size of length of d, and store that many elements in it and then shift element in original array and then assign temp array's elements to original array at right place. That's i think more better, because in it less auxilary space will be used.
    int i = 0;
    int j = n - d;
    while (i < d)
    {
        arr2[j] = arr[i];
        i++;
        j++;
    }
    j = 0;
    while (i < n)
    {
        arr2[j] = arr[i];
        i++;
        j++;
    }
    return arr2;
} // ø(n) but aux space also ø(n)

/* int *newArray = leftRotate2(arr, n, d);
for (int i = 0; i < n; i++)
{
    cout << newArray[i] << " ";
}
cout << endl;

delete[] newArray; */

/*

5
1 2 3 4 5
2

*/