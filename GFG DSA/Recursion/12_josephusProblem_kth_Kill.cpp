#include <bits/stdc++.h>
using namespace std;

int jos(int n, int k) // Used when the numbers are between 0 to n-1 in the circle
{
    if (n == 1)
    {
        return 0;
    }

    return (jos(n - 1, k) + k) % n;
} // T(n) = T(n-1) + C. Hence, ø(n) is the time complexity of this solution.

int josExtension(int n, int k) // Used when the numbers are between 1 to n
{
    return jos(n, k) + 1;
}

int main()
{
    int n, k;
    cout << "Enter 2 number: ";
    cin >> n >> k;

    cout << jos(n, k) << endl;
    // cout << josExtension(n, k) << endl;

    return 0;
}