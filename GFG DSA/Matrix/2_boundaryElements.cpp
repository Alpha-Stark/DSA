#include <bits/stdc++.h>
using namespace std;
// To be allowed to declare a multidementional vector, have to change formatting setting, as it wont be done just by disabelling prettier extension. In settings, under format section, changed the "c_cpp: Formatting" from "default" to "vsFormat". 

void printBoundary(const vector<vector<int> >& A) {
    int r = A.size(), c = A[0].size();
    if (r == 1)
    {
        for (int j = 0; j <= c - 1; j++)
            cout << A[0][j] << " ";
    }
    else if (c == 1)
    {
        for (int i = 0; i <= r - 1; i++)
            cout << A[i][0] << " ";
    }
    else
    {
        int i = 0, j = 0;
        for (j = 0; j <= c - 1; j++)
        {
            cout << A[i][j] << " ";
        }
        j = c - 1; //to avoid writing these lines, we have to adjust in the loop printing expression & loop's ending conditions.
        for (i = 1; i <= r - 1; i++)
        {
            cout << A[i][j] << " ";
        }
        i = r - 1;
        for (j = c - 2;j >= 0;j--) {
            cout << A[i][j] << " ";
        }
        j = 0;
        for (i = r - 2; i >= 1; i--)
        {
            cout << A[i][j] << " ";
        }

    }
}

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int> > A(r);
    for (int i = 0; i < r; i++)
    {
        A[i].assign(c, 0);
        for (int j = 0; j < c; j++)
        {
            cin >> A[i][j];
        }
    }
    printBoundary(A);
    return 0;
}

/*
4 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16

1 4
1 2 3 4

4 1
1 2 3 4
*/