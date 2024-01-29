#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << "Move Disc " << n << " from " << a << " to " << c << endl;
        return;
    }

    towerOfHanoi(n - 1, a, c, b);

    cout << "Move Disc " << n << " from " << a << " to " << c << endl;

    towerOfHanoi(n - 1, b, a, c);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}