#include <bits/stdc++.h>
using namespace std;

int maxCut(int n, int a, int b, int c)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return -1;
    }

    int ma = maxCut(n - a, a, b, c);
    int mb = maxCut(n - b, a, b, c);
    int mc = maxCut(n - c, a, b, c);

    int res = max(ma, max(mb, mc));

    if (res == -1)
    {
        return res;
    }
    else
    {
        return 1 + res;
    }
} // Time complexity = O(3^n)
// Did it by my own, after the initial approach, Great Self-Positivity Achievement. And Always remember the CodingNinjas' sir's approach to solve any problem using recursion.
/* Coding Ninjas Sir's Method of PMI
1)Base Case
2)Write/figure out the 1 common step, and beleive that everything else will be fine.
*/

int main()
{
    int n, a, b, c;
    cout << "Enter all numbers: ";
    cin >> n >> a >> b >> c;

    cout << maxCut(n, a, b, c) << endl;

    return 0;
}