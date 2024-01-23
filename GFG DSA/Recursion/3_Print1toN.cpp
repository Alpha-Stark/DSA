#include <bits/stdc++.h>
using namespace std;

void printNTo1(int n)
{
    if (n == 0)
        return;
    printNTo1(n - 1);
    cout << n << " ";
} // ø(n) and auxilary space = ø(n+1)

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    printNTo1(n);
    return 0;
}