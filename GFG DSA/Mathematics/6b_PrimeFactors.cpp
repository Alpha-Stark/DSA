#include <bits/stdc++.h>
using namespace std;

void PrimeFactors(int n)
{
    if (n <= 1)
        return;

    for (int i = 2; i * i <= n; i++) // means if there is a prime factor, then it surely will be in found between 2 to √n.
    {
        while (n % i == 0) // this loop will ensure that if a prime number is factor of number n, it is printed multiple times, and then only move ahead for incrementing i;
        {
            cout << i << " ";
            n = n / i;
        }
    }
    if (n > 1) // this is run if the last prime number is appearing once, because that last single prime number wont be able to go in the for loop.
    {
        cout << n << endl;
    }
} // O(n).

// But we can further optimize this code by handeling 2 and 3's multiples explicitly. Which should reduce iterations drastically.
void PrimeFactorsOpt(int n)
{
    if (n <= 1)
        return;

    while (n % 2 == 0)
    {
        cout << "2 ";
        n = n / 2;
    }
    while (n % 3 == 0)
    {
        cout << "3 ";
        n = n / 3;
    }

    for (int i = 5; i * i <= n; i = i + 6) // means if there is a prime factor, then it surely will be in found between 2 to √n.
    {
        while (n % i == 0) // this loop will ensure that if a prime number is factor of number n, it is printed multiple times, and then only move ahead for incrementing i;
        {
            cout << i << " ";
            n = n / i;
        }
        while (n % (i + 2) == 0) // this loop will ensure that if a prime number is factor of number n, it is printed multiple times, and then only move ahead for incrementing i;
        {
            cout << i + 2 << " ";
            n = n / (i + 2);
        }
    }
    if (n > 3) // this is run if the last prime number is appearing once, because that last single prime number wont be able to go in the for loop. Also this time, it's n>3, because be have already handledprime number till 3, so if there is a leftout one, it must be greater than 3.
    {
        cout << n << endl;
    }
}
// O(√n). Worst case is when its a big prime number, and in that case, it will run the for loop fully till √n time, even thaught it skips 6 number everytime, we dont count it.

int main()
{
    cout << "Enter a number:";
    int n;
    cin >> n;

    // PrimeFactors(n);
    PrimeFactorsOpt(n);

    return 0;
}