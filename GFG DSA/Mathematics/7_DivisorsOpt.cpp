#include <bits/stdc++.h>
using namespace std;

void divisors(int n)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            if (n / i != i)
            {
                cout << n / i << " ";
            }
        }
    }
}

void divisorsOpt(int n)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
    for (int i = sqrt(n); i >= 1; i--)
    {
        if (n % i == 0)
        {
            if (n / i == i)
            {
                continue;
            }

            cout << n / i << " ";
        }
    }
} // O(√n + √n) => O(√n) complexity

int main()
{
    cout << "Enter a number:";
    int n;
    cin >> n;
    // divisors(n);
    divisorsOpt(n);

    return 0;
}