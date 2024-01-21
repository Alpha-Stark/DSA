#include <bits/stdc++.h>
using namespace std;

int powerOpt(int n, int p)
{
    int res = 1;
    while (p > 0)
    {
        // if (p % 2 != 0) //Can be also written as below, and its faster because of bitwise nature.
        if (p & 1)
        {
            // cout << "1 ";
            res = res * n;
        }
        else
        {
            // cout << "0 ";
        }
        n = n * n;
        // p = p / 2; //Also written as below, and its faster because of bitwise nature.
        p = p >> 1;
    }
    return res;
} // O(logn), better than recursive, because it's complexity is same as Recursive, but auxilary Space is O(1) only.

int main()
{
    int n, p;
    cout << "Enter a number and its power:";
    cin >> n >> p;
    cout << powerOpt(n, p) << endl;
    return 0;
}

/*

If a number is large.
Or told use return the value under some modulo m,

long long int powerOpt(int n, int p, int m)
{
    long long int res = 1;
    while (p > 0)
    {
        if (p & 1)
        {
            // cout << "1 ";
            res = (res * n)%m;
        }
        else
        {
            // cout << "0 ";
        }
        n = (n * n)%m;
        p = p >> 1;
    }
    return res;
} // O(logn), better than recursive, because it's complexity is same as Recursive, but auxilary Space is O(1) only.

 */