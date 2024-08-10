#include <bits/stdc++.h>
using namespace std;

int longestConsecutiveSubsequence(vector<int> arr) {
    int ans = 1;
    unordered_set<int> s;
    for (int x : arr)
        s.insert(x);

    for (int x : arr) {
        int currentMax = 1;
        if (s.find(x) != s.end())
        {

        }

    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << longestConsecutiveSubsequence(arr) << endl;
    return 0;
}