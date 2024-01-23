#include <bits/stdc++.h>
using namespace std;

int nthFibonacci(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return nthFibonacci(n - 1) + nthFibonacci(n - 2);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << nthFibonacci(n) << endl;
    return 0;
}