#include <bits/stdc++.h>
using namespace std;

int longestSubarraySum(vector<int> arr, int sum) {
    int ans = 0;
    unordered_map<int, int> m;
    int prefixSum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        prefixSum += arr[i];
        if (prefixSum == sum) {
            ans = max(ans, i + 1);
        }

        int remSum = prefixSum - sum;
        if (m.find(remSum) != m.end()) {
            ans = max(ans, i - m[remSum]);
        }

        // m.insert({ prefixSum, i }); // By just writing this line, we can miss some of the longest occuring subsets, because we override the previous value's with newer/bigger indexex while will further on decrease the max lenght possible.

        // its adviced to not override, we should update the value. 
        if (m.find(prefixSum) == m.end()) {
            m[prefixSum] = i;
            //or m.insert({ prefixSum, i });
        }
    }
    return ans;
}

int main() {
    int n, sum;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    cin >> sum;

    cout << longestSubarraySum(arr, sum) << endl;

    return 0;
}

/*
7
5 8 -4 -4 9 -2 2
0
=3

8
3 1 0 1 8 2 3 6
5
=4

3
8 3 7
15
=0
*/