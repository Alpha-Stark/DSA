#include <bits/stdc++.h>
using namespace std;

/*
***
Remember there's a pattern, Wherever there's a question where we have to look about sum 0 or some given value,
we mostly/always use prefixSum method. And in most cases, using prefixSum just after calculation each of the prefixSums (in each iteration).
Rather than getting all prefixSum at once and then looking at the scenerio.
***
*/

void subarraySum(int arr[], int n, int sum) {
    unordered_set<int> hash;
    int prefixSum = 0;
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        if (prefixSum == sum)
        {
            cout << "Yes" << endl;
            return;
        }

        int currentRem = prefixSum - sum;
        if (hash.find(currentRem) != hash.end()) {
            cout << "Yes" << endl;
            return;
        }
        hash.insert(prefixSum);
    }

    cout << "No" << endl;
    return;
}


int main() {
    int n, sum;
    cin >> n;
    int arr[n];

    for (int i = 0;i < n;i++)
        cin >> arr[i];

    cin >> sum;

    // As it is subarray, so we only have to consider contegious elements. i.e., {1,2,3} => {1,3} is not considered a subset
    subarraySum(arr, n, sum);
    return 0;
}

/*

6
5 8 6 13 3 -1
22
=Yes

7
15 2 8 10 -5 -8 6
3
=Yes

4
3 2 5 6
10
=Yes

*/