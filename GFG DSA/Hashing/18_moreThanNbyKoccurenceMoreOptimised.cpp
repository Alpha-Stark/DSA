#include <bits/stdc++.h>
using namespace std;

/*
We do something like moore's voting alogirthm for this optimized solution.

This bases of creating this solution also is because there cannot be k or more than k number of elements as output,
because of the logic explained in the video. Therefore below's Phase1's 2)'s b) block is written.

This special algorithm works in 2 phases:
Phase 1:
    1) Create a new unorderedmap m [Empty]
    2) for(int i = 0;i<n;i++)
        a) if(m contains arr[i])
            m[arr[i]]++;

        b) else if(m.size() is less than k-1)
            m.put(arr[i], 1); //m.insert({arr[i], 1})

        c) else{decrease all values in m by 1. if value becomes 0, remove it.}

Phase 2:
    3) For all elements in m, print the elements that actually appears more than n/k times.
*/

void moreThanNbyKoccurancesOptimized(vector<int> arr, int k) {
    int n = arr.size();
    int NbyK = n / k;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        if (m.find(arr[i]) != m.end())
            m[arr[i]]++;
        else if (m.size() <= k - 1)
            m.insert({ arr[i], 1 });
        else {
            for (auto i : m) {
                i.second--;

                if (i.second == 0)
                    m.erase(i.first);
            }
        }
    }
    for (auto i : m)
        if (i.second > NbyK)
            cout << i.first << " ";

}

/*

8
30 10 20 20 10 20 30 30
4
=20 30

9
30 10 20 30 30 40 30 40 30
2
=30

*/

int main() {
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0;i < n;i++)
        cin >> arr[i];
    cin >> k;

    moreThanNbyKoccurancesOptimized(arr, k);

    return 0;
}