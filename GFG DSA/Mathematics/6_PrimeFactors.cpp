#include <bits/stdc++.h>
using namespace std;

void PrimeFactors(int n)
{
    if (n <= 1)
        return;

    int i = 2;
    while (n != 1)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            n = n / i;
        }
        else
        {
            i++;
        }
    }
}
// O(n), in first try better than Naive solution.

int main()
{
    cout << "Enter a number:";
    int n;
    cin >> n;

    PrimeFactors(n);

    return 0;
}