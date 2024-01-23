#include <bits/stdc++.h>
using namespace std;

int NaturalNumberSum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + NaturalNumberSum(n - 1);
} // ø(n) for both time and Auxilary Space.

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << NaturalNumberSum(n) << endl;

    return 0;
}