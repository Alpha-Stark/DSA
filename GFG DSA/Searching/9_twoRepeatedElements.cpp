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
        int count = 0;
        int element1 = -1;
        for (int i = 0; i < n; i++)
        {
            if (count == 0)
            {
                element1 = arr[i];
                count = 1;
            }
            else
            {
                if (arr[i] == element1)
                {
                    count++;
                }
                else
                {
                    count--;
                }
            }
        }

        int element2 = -1;
        count = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == element1)
                continue;

            if (count == 0)
            {
                element2 = arr[i];
                count = 1;
            }
            else
            {
                if (arr[i] == element2)
                {
                    count++;
                }
                else
                {
                    count--;
                }
            }
        }
        cout << "Element1: " << element1 << " Element2: " << element2 << endl;
        int maxIndex1 = 0, maxIndex2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == element1)
            {
                maxIndex1 = max(maxIndex1, i);
            }
            else if (arr[i] == element2)
            {
                maxIndex2 = max(maxIndex2, i);
            }
        }
        ans.push_back(arr[min(maxIndex1, maxIndex2)]);
        ans.push_back(arr[max(maxIndex1, maxIndex2)]);
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
