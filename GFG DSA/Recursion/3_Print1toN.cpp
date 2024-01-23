#include <bits/stdc++.h>
using namespace std;

void printNTo1(int n)
{
    if (n == 0)
        return;
    printNTo1(n - 1);
    cout << n << " ";
} // ø(n) and auxilary space = ø(n+1)

// Lets change it to tail recursive
void printNTo1Opt(int n, int k)
{
    if (k == n + 1)
        return;
    cout << k << " ";
    printNTo1Opt(n, k + 1);
} // Now auxilary space is O(1) only.

/* GFG Code:

    void fun(int n, int k){
        if(n == 0) return;
        cout<<n<<" ";
        fun(n-1,k+1);
    }

 */

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    // printNTo1(n);
    printNTo1Opt(n, 1);
    return 0;
}