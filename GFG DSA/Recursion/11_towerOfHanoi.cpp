#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        // cout << "Move Disc " << n << " from " << a << " to " << c << endl;
        cout << "Move Disc 1 from " << a << " to " << c << endl;
        return;
    }

    towerOfHanoi(n - 1, a, c, b);

    cout << "Move Disc " << n << " from " << a << " to " << c << endl;

    towerOfHanoi(n - 1, b, a, c);
}

/*
As always we do recursive problem as,
    1) Breaking the problem into single step as in, what we do on a single iteration.
    2) Based on step 1, prepare a base case.

Single Iteration Explaination for n=2, and using this case, all the other n values will be handeled.
    towerOfHanoi(n - 1, a, c, b), move the disc from a to b - using c as the auxilary
    move the disc nth from a to c.
    towerOfHanoi(n - 1, b, a, c), move the disc from b to c - using a as the auxilary

Designed this algorithm just by following the way to solve only n=2 iteration, and by that only the algorithm will solve all the subsequent steps/n>2 cases will be handeled.
*/

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}