#include <bits/stdc++.h>
using namespace std;

void distinctElementsInWindow(vector<int> arr, int k) {
    // For leetcode, handle the array size less than k case;
    int n = arr.size();
    unordered_map<int, int> h;
    for (int i = 0; i < k;i++)
        h[arr[i]]++;

    cout << h.size() << " ";

    for (int i = 1;i <= n - k;i++) {
        h[arr[i - 1]]--;
        if (h[arr[i - 1]] == 0) h.erase(arr[i - 1]);

        h[arr[i + k - 1]]++;
        cout << h.size() << " ";
    }

    /* cout << endl;
    for (auto i : h)
        cout << i.first << " \t\t\t " << i.second << endl; */
}

/*

6
10 10 5 3 20 5
4
=3 4 3

6
10 20 10 10 30 40
4
=2 3 3
*/

int main() {
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    distinctElementsInWindow(arr, k);


    return 0;
}
