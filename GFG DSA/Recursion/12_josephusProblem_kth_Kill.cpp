#include <bits/stdc++.h>
using namespace std;

int jos(int n, int k)
{
    if (n == 1)
    {
        return 0;
    }

    return (jos(n - 1, k) + k) % n;
} // T(n) = T(n-1) + C. Hence, ø(n) is the time complexity of this solution.

int main()
{
    int n, k;
    cout << "Enter 2 number: ";
    cin >> n >> k;

    cout << jos(n, k) << endl;

    return 0;
}