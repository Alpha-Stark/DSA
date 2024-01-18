#include <bits/stdc++.h>
using namespace std;

int factorial(int i)
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

    cout << factorial(i) << endl;

    return 0;
}