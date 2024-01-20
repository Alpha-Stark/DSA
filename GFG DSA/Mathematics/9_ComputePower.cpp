#include <bits/stdc++.h>
using namespace std;

int power(int n, int p)
{
    int res = 1;
    for (int i = 0; i < p; i++)
    {
        res *= n;
    }
    return res;
}

int main()
{
    int n, p;
    cout << "Enter a number and its power:";
    cin >> n >> p;
    cout << power(n, p) << endl;
    return 0;
}
