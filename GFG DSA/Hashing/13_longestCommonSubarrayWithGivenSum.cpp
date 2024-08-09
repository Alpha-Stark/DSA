/* Longest Common Binary Subarray With Given Sum */
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


int helperFunction(int a[], int b[], int n) {
    int ans = 0;
    vector<int> temp;
    for (int i = 0; i < n; i++)
        temp.push_back(a[i] - b[i]);


    return longestSubarraySum(temp, 0);

    /* unordered_map<int, int> m;
    int prefixSum = 0;
    for (int i = 0;i < n;i++)
    {
        if (m.find(temp[i]) != m.end())
        {
            ans = max(ans, i - m[i]);
        }


    } */




    return ans;
}

int main() {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];


    // cout << naiveHelperFunction(a, b, n) << endl;
    cout << helperFunction(a, b, n) << endl;


    return 0;
}

int naiveHelperFunction(int a[], int b[], int n) {
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int sumA = 0, sumB = 0;
        for (int j = i; j < n; j++)
        {
            sumA += a[j];
            sumB += b[j];

            if (sumA == sumB)
                ans = max(ans, j - i + 1);
        }
    }
    return ans;
}

/*

6
0 1 0 0 0 0
1 0 1 0 0 1
=4

7
0 1 0 1 1 1 1
1 1 1 1 1 0 1
=6

3
0 0 0
1 1 1
=0

4
0 0 1 0
1 1 1 1
=1

*/