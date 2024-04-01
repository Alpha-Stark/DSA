#include <bits/stdc++.h>
using namespace std;
// To be allowed to declare a multidementional vector, have to change formatting setting, as it wont be done just by disabelling prettier extension. In settings, under format section, changed the "c_cpp: Formatting" from "default" to "vsFormat". 

void transpose(vector<vector<int> >& A) { //remember to remove the 'const' keyword from the vector initialization
    int r = A.size(), c = A[0].size();
    for (int i = 0; i <= r - 2; i++) //or just 'i<r'
    {
        for (int j = i + 1; j < c; j++)
        {
            swap(A[i][j], A[j][i]);
        }
    }
}

void printMatrix(const vector<vector<int> >& A) {
    cout << endl;
    int r = A.size(), c = A[0].size();
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
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
    transpose(A);
    printMatrix(A);
    return 0;
}

/*
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

3 3
1 0 0
1 2 0
1 1 3

2 2
1 2
1 2

1 1
0

*/