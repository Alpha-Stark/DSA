//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find two repeated elements.
    vector<int> twoRepeated(int arr[], int n)
    {
        vector<int> ans;
        for (int i = 0; i < n + 2; i++)
        {
            int toCheck = arr[abs(arr[i])];
            if (toCheck >= 0)
            {
                arr[abs(arr[i])] = -arr[abs(arr[i])];
            }
            else
            {
                // print(abs(arr[i]));
                ans.push_back(abs(arr[i]));
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    int a[n + 2];

    for (int i = 0; i < n + 2; i++)
        cin >> a[i];

    Solution obj;
    vector<int> res;
    res = obj.twoRepeated(a, n);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}
