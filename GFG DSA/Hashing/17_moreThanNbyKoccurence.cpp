#include <bits/stdc++.h>
using namespace std;

void moreThanNbyKoccurances(vector<int> arr, int k) {
    int n = arr.size();
    int NbyK = n / k;
    unordered_map<int, int> h;
    for (int x : arr)
        h[x]++;

    for (auto i : h) {
        if (i.second > NbyK)
            cout << i.first << " ";
    }
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

    moreThanNbyKoccurances(arr, k);

    return 0;
}