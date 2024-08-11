//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
public:

    //Function to return the name of candidate that received maximum votes.

    /* Just have to write this to compare two string lexicographically */
    string lexicographicallySmaller(string a, string b) {
        return a < b ? a : b;
    }

    vector<string> winner(string arr[], int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        unordered_map<string, int> h;
        for (int i = 0; i < n;i++)
            h[arr[i]]++;

        string maxVotesName = arr[0];
        int maxVotes = h[arr[0]];
        for (auto i : h) {
            if (i.second == maxVotes) {
                maxVotesName = lexicographicallySmaller(maxVotesName, i.first);
            }
            else if (i.second > maxVotes) {
                maxVotes = i.second;
                maxVotesName = i.first;
            }
        }
        vector<string> ans;
        ans.push_back(maxVotesName);
        string count = to_string(maxVotes);
        ans.push_back(count);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int n;
    cin >> n;

    string arr[n];

    for (int i = 0;i < n;i++)
        cin >> arr[i];
    Solution obj;
    vector<string> result = obj.winner(arr, n);

    cout << result[0] << " " << result[1] << endl;

    return 0;
}

// } Driver Code Ends