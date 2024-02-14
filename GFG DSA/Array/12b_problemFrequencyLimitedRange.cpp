//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //** VERY GOOD QUESTION, Because in such question, we have initially find all problem to keep the complexity to O(n) and then smarly solve them one by one in our algorithm.
    void frequencyCount(vector<int> &arr, int N, int P)
    {
        int i = 0;
        while (i < N)
        {
            if (arr[i] > 0 && arr[i] <= N)
            {
                int correctPos = arr[i] - 1;
                if (arr[correctPos] > 0)
                {
                    swap(arr[i], arr[correctPos]);
                    arr[correctPos] = -1;
                }
                else if (arr[correctPos] <= 0)
                {
                    arr[correctPos]--;
                    arr[i] = 0;
                    i++;
                }
            }
            else if (arr[i] > N)
            {
                arr[i] = 0;
                i++;
            }
            else
            {
                i++;
            }
        }
        for (int i = 0; i < N; i++)
        {
            arr[i] = -arr[i];
            /* if (arr[i] < 0)
            {
                arr[i] = abs(arr[i]);
                // arr[i] *= -1;
            } */
        }
    }
};

int main()
{
    int N, P;
    // size of array
    cin >> N;

    vector<int> arr(N);

    // adding elements to the vector
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cin >> P;
    Solution ob;
    // calling frequncycount() function
    ob.frequencyCount(arr, N, P);

    // printing array elements
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

/*

2
8 9
9

4
3 3 3 3
3

5
2 3 2 3 5
5

5
4 5 6 7 8
1000

*/

// code here
/* vector<int> v(N + 1, 0);
for (int i = 0; i < N; i++)
{
    if (arr[i] <= P && arr[i] <= N)
    {
        v[arr[i]] += 1;
    }
}
for (int i = 0; i < N; i++)
{
    arr[i] = v[i + 1];
}
// aux space is O(n+1)
*/