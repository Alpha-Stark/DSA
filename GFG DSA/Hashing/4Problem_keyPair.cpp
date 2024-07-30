//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
    // Function to check if array has 2 elements
    // whose sum is equal to the given value
    bool hasArrayTwoCandidates(vector<int>& arr, int x) {
        // code here
        unordered_map<int, int> m;

        int n = arr.size();
        for (int i = 0; i < n;i++)
            m.insert({ arr[i],0 });

        for (int i = 0;i < n;i++) {
            int rem = x - arr[i];
            auto currentAdd = m.find(arr[i]);
            if (m.find(rem) != m.end() && m.find(rem) != currentAdd) {
                cout << "arr[i]" << endl;
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int x;
    cin >> x;
    cin.ignore(); // To discard any leftover newline characters

    vector<int> arr;
    string input;
    getline(cin, input); // Read the entire line for the array elements
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }

    Solution ob;
    auto ans = ob.hasArrayTwoCandidates(arr, x);
    cout << (ans ? "true" : "false") << endl;

    return 0;
}

// } Driver Code Ends