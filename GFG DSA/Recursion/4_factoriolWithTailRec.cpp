#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    return n * fact(n - 1);
}

int factOpt(int n, int k)
{
    if (n == 1 || n == 0)
    {
        return k;
    }
    return factOpt(n - 1, k * n);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    // cout << fact(n) << endl;
    cout << factOpt(n, 1) << endl;
    return 0;
}