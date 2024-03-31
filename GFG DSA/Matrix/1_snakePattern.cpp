#include <bits/stdc++.h>
using namespace std;
// To be allowed to declare a multidementional vector, have to change formatting setting, as it wont be done just by disabelling prettier extension. In settings, under format section, changed the "c_cpp: Formatting" from "default" to "vsFormat". 

void snakePattern(const vector<vector<int> >& A) {
    int r = A.size(), c = A[0].size();
    for (int i = 0; i < r; i++)
    {
        if (i % 2 == 0) {
            for (int j = 0; j < c; j++)
                cout << A[i][j] << " ";
        }
        else {
            for (int j = c - 1; j >= 0; j--)
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
    snakePattern(A);
    return 0;
}

/*
3 3
45 48 54 21 89 87 70 78 15
*/