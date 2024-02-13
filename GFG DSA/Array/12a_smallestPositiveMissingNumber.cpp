//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n)
    {
        // The below one must be kept in mind, because it is the more efficient approach to solve problems of such type
        // Putting the numbers on it's right index (i.e., i-1) and then at the end looking for misplaced element's index, because that will be out result.
        for (int i = 0; i < n; i++)
        {
            int correctIndex = arr[i] - 1;
            while (correctIndex >= 0 && correctIndex <= n - 1 && arr[correctIndex] != arr[i])
            {
                swap(arr[i], arr[correctIndex]);
                correctIndex = arr[i] - 1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] != i + 1)
            {
                return i + 1;
            }
        }
        return n + 1;
        // O(n)

        /*sort(arr, arr+n);
        int k = 1;
        for(int i = 0; i<n;i++){
            if(arr[i]>0){
                if(arr[i] == k){
                    k++;
                }else if(arr[i]>k){
                    return k;
                }
            }
        }
        return k;
        //O(N*logN)
        */
    }
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main()
{
    // input number n
    int n;
    cin >> n;
    int arr[n];

    // adding elements to the array
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Solution ob;
    // calling missingNumber()
    cout << ob.missingNumber(arr, n) << endl;

    return 0;
}

/*

5
0 -10 1 3 -20

5
1 2 3 4 5

*/