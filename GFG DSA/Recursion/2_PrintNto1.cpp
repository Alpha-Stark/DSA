#include <bits/stdc++.h>
using namespace std;

void nTo1(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    nTo1(n - 1);
}

int main()
{
    int n;
    cin >> n;
    nTo1(n);
    return 0;
}