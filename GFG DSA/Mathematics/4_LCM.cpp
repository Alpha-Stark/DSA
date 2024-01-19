#include <bits/stdc++.h>
using namespace std;

int lcm(int a, int b)
{
    int x = max(a, b);
    while (x <= a * b)
    {
        if (x % a == 0 && x % b == 0)
        {
            return x;
        }
        x++;
    }
    return -1;
}
// O(a*b - max(a,b)) => O(n^2 - max(a,b)) => ConstantExponential Complexity

int main()
{
    int a, b;
    cout << "Enter 2 Numbers:";
    cin >> a >> b;
    int result = lcm(a, b);
    cout << result << endl;
    return 0;
}