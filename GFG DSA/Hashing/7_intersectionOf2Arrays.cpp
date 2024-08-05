#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int a[m], b[n];

    for (int i = 0; i < m; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        cin >> b[i];

    /*
    // Better/Right solution, Space-wise more and time wise too. TC=O(m+n) , SC=O(m)

    unordered_set<int> s;

    for (auto&& x : a)
        s.insert(x);

    int ans=0;
    for (auto&& i : b)
    {
        if (s.find(i) != s.end()){
            ans++;
            s.erase(i);
        }
    }

    */

    unordered_set<int> sa, sb;

    for (auto&& x : a)
        sa.insert(x);

    for (auto&& x : b)
        sb.insert(x);

    int ans = 0;
    for (auto&& i : sa)
    {
        if (sb.find(i) != sb.end())
            ans++;
    }
    cout << ans << endl;

    return 0;
}

/*

7 4
10 15 20 15 30 30 5
30 5 30 80
=2

2 2
10 20
20 30
=1

3 3
10 10 10
10 10 10
=1

*/