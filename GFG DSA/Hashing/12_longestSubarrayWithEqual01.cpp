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


int optimalSolutionFunction(vector<int> arr) {
    // Replace all the zeros with -1 in the array ad then just call the normal/standard function used to find the longest length of subarray with sum 0.
    for (int i = 0;i < arr.size();i++)
        if (arr[i] == 0)
            arr[i] = -1;


    return longestSubarraySum(arr, 0);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // cout << naiveSolutionFunction(arr) << endl;
    cout << optimalSolutionFunction(arr) << endl;

    return 0;
}

int naiveSolutionFunction(vector<int> arr) {
    int ans = 0;
    int num0 = 0, num1 = 0;
    for (int i = 0;i < arr.size();i++) {
        for (int j = i; j < arr.size(); j++)
        {
            if (arr[j] == 0)
                num0++;
            else
                num1++;


            if (num0 == num1)
                ans = max(ans, num0 + num1);
        }
        num0 = 0, num1 = 0;
    }

    return ans;
}

/*

7
1 0 1 1 1 0 0
=6

4
1 1 1 1
=0

8
0 0 1 1 1 1 1 0
=4

6
0 0 1 0 1 1
=6

*/