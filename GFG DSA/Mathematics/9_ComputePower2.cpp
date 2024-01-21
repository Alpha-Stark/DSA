#include <bits/stdc++.h>
using namespace std;

int powerOpt(int n, int p)
{
    int res = 1;
    while (p > 0)
    {
        if (p % 2 != 0)
        {
            // cout << "1 ";
            res = res * n;
        }
        else
        {
            // cout << "0 ";
        }
        n = n * n;
        p = p / 2;
    }
    return res;
} // O(logn)

int main()
{
    int n, p;
    cout << "Enter a number and its power:";
    cin >> n >> p;
    cout << powerOpt(n, p) << endl;
    return 0;
}
