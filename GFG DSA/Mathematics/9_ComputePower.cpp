#include <bits/stdc++.h>
using namespace std;

int power(int n, int p)
{
    int res = 1;
    for (int i = 0; i < p; i++)
    {
        res *= n;
    }
    return res;
} // O(n)

long long int powerOpt(int n, int p)
{
    if (p == 1)
    {
        return n;
    }

    if (p % 2 == 0)
    {
        return powerOpt(n, p / 2) * powerOpt(n, p / 2);
    }
    else
    {
        return powerOpt(n, p - 1) * n;
    }
} // O(logn)

int main()
{
    int n, p;
    cout << "Enter a number and its power:";
    cin >> n >> p;
    // cout << power(n, p) << endl;
    cout << powerOpt(n, p) << endl;
    return 0;
}
