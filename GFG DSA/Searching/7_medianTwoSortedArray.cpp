#include <bits/stdc++.h>
using namespace std;

float median(int arr1[], int arr2[], int n1, int n2)
{
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    int arr1[n1];
    int arr2[n2];
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    cout << median(arr1, arr2, n1, n2) << endl;

    return 0;
}

/*

3 4
1 2 3
10 11 12 13
=10

5 5
10 20 30 40 50
5 15 25 35 45
=27.5

6 5
1 2 3 4 5 6
10 20 30 40 50
=6

6 5
10 20 30 40 50 60
1 2 3 4 5
=10

*/

float median(int arr1[], int arr2[], int n1, int n2)
{
    // Similar to merge 2 sorted LinkedList
    int tillIndex;
    int total = n1 + n2;
    bool is2Med = false;
    if (total % 2 != 0)
        tillIndex = ((total - 1) / 2);
    else
    {
        tillIndex = ((total - 1) / 2) + 1;
        is2Med = true;
    }
    cout << "TillIndes: " << tillIndex << endl;

    int i = 0, j = 0;
    vector<int> arr(n1 + n2, 0);
    int k = 0;
    while ((i < n1) && (j < n2) && (k <= tillIndex))
    {
        if (arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    if (i == n1 && k <= tillIndex)
    {
        for (int l = j; l < n2; l++) // mistake in
        {
            arr[k] = arr2[l];
            k++;
            if (k > tillIndex)
                break;
        }
    }
    else if (j == n2 && k <= tillIndex)
    {
        for (int l = i; l < n1; l++)
        {
            arr[k] = arr1[l];
            k++;
            if (k > tillIndex)
                break;
        }
    }

    if (is2Med)
    {
        float med = ((float)arr[tillIndex] + (float)arr[tillIndex - 1]) / 2;
        return med;
    }
    else
        return arr[tillIndex];
} // O(n1+n2) = O(n), but if we can bring the complexity to logarithmic time, it will be better.
