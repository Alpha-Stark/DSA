#include <bits/stdc++.h>
using namespace std;

/*
// Sir's code: Run more faster
    unordered_set<int> h(arr,arr+n);
    int res = 1;
    for(auto x: h){
        if(s.find(x-1) == s.end()){
            int curr = 1;
            while(h.find(x+curr) != h.end())
                curr++;

            res = max(res, curr);
        }
    }
    return res;
*/

// Perfectly working code
int longestConsecutiveSubsequence(vector<int> arr) {
    // if (arr.size() == 0) return 0; // leetcode line tobe added
    int ans = 1;
    unordered_set<int> s;
    for (int x : arr)
        s.insert(x);

    for (int x : arr) {
        int currentMax = 1;
        if (s.find(x) != s.end())
        {
            int counter = x - 1;
            while (s.find(counter) != s.end())
            {
                currentMax++;
                s.erase(counter);
                counter--;
            }
            counter = x + 1;
            while (s.find(counter) != s.end())
            {
                currentMax++;
                s.erase(counter);
                counter++;
            }
        }
        ans = max(ans, currentMax);
    }
    return ans;
}

/*

6
1 9 3 4 2 20
=4

8
1 3 4 3 3 2 9 10
=4

7
2 6 1 9 4 5 3
=6
*/

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