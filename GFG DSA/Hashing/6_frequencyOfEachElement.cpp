#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    unordered_map<int, int> hash;
    for (int x : arr)
        hash[x]++;

    for (auto e : hash)
        cout << e.first << " " << e.second << endl;

    return 0;
}

/*
In the video of "Frequencies of array elements", sir talked about a variation of this, and its a bit cautious one, so must revisit.

*/