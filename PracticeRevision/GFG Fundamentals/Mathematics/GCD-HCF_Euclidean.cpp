#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == b)
    {
        return a;
    }

    if (a > b)
    {
        a = a - b;
    }
    else
    {
        b = b - a;
    }
    int res = gcd(a, b);
    return res;

    /* while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
        // cout << a << " " << b << endl;
    }
    return a; */
}

int gcdOpt(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcdOpt(b, a % b);
}
// This is super optimized and the a>b or b>a problem will also be handled in this. The a%b will give the remainder, which we indirectly want.

int main()
{
    int num1, num2;
    cout << "Enter both numbers:";
    cin >> num1 >> num2;
    // int result = gcd(num1, num2);
    int result = gcdOpt(num1, num2);
    cout << result << endl;

    return 0;
}