#include <bits/stdc++.h>
using namespace std;

void divisors(int n)
{
    cout << "1 ";
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
    cout << n << endl;
}

int main()
{
    cout << "Enter a number:";
    int n;
    cin >> n;
    divisors(n);

    return 0;
}