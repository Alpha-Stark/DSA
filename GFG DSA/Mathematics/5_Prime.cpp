#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n == 1)
    {
        return false;
    }

    int i = 2;
    // while (i < n)        // O(n)
    // while (i <= n / 2)   // O(n/2)
    // while (i <= sqrt(n)) // O(√n)
    // or
    while (i * i <= n) // O(√n)
    {
        if (n % i == 0)
        {
            return false;
        }
        i++;
    }
    return true;
}

int main()
{
    int n;
    cout << "Enter a number:";
    cin >> n;
    if (isPrime(n))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}