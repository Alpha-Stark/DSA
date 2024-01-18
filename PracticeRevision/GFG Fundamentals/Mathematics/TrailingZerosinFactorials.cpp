#include <bits/stdc++.h>
using namespace std;

long long int factorial(int i)
{
    if (i == 1 || i == 0)
    {
        return i;
    }

    return i * factorial(i - 1);
}

int main()
{
    int i;
    cout << "Enter the number:";
    cin >> i;
    long long int fact = factorial(i);
    int count = 0;
    while (fact % 10 == 0)
    {
        count++;
        fact /= 10;
    }
    cout << count << endl;
    return 0;
}