#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n == 1)
        return false;

    if (n == 2 || n == 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }

    return true;
} // Overall => O(√n)

void sieve(int n)
{
    vector<bool> v(n + 1, true);

    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime(i))
        {
            // for (int j = 2 * i; j <= n; j = j + i)
            for (int j = i * i; j <= n; j = j + i) // this will not go through the already traversed number which are the part of lower prime's multiple.
            {
                v[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (v[i])
        {
            cout << i << " ";
        }
    }
}

void sieve2(int n) // same complexity as above, just with less lines of code.
{
    vector<bool> v(n + 1, true);

    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
        {
            cout << i << " ";
            for (int j = i * i; j <= n; j = j + i) // this will not go through the already traversed number which are the part of lower prime's multiple.
            {
                v[j] = false;
            }
        }
    }
} // O(n loglog(n)) => This is almost nearly O(n) which is good as compared to naive O(n√n)~O(n^3/2)

int main()
{
    cout << "Enter a number:";
    int n;
    cin >> n;
    sieve(n);

    return 0;
}