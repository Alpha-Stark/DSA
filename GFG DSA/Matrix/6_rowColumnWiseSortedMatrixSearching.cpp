#include <bits/stdc++.h>
using namespace std;
// To be allowed to declare a multidementional vector, have to change formatting setting, as it wont be done just by disabelling prettier extension. In settings, under format section, changed the "c_cpp: Formatting" from "default" to "vsFormat". 

void searchInRowColumnSorted(vector<vector<int> >& A, int x) {
    int r = A.size(), c = A[0].size();
    int i = 0, j = c - 1; //we shouldn't traverse from left top to right, because it will give inaccurate answer. Take the example of x=27 from sir's input example.
    while (j >= 0)
    {
        if (A[i][j] == x) {
            cout << "(" << i << ", " << j << ")" << endl;
            return;
        }
        else if (A[i][j] > x)
            j--;
        else
            break;
    }
    i++;
    while (i <= r - 1 && j != -1)
    {
        if (A[i][j] == x) {
            cout << "(" << i << ", " << j << ")" << endl;
            return;
        }
        else if (A[i][j] < x)
            i++;
        else //or elif(A[i][j] > x)
            break;
    }
    cout << "Element not found." << endl;
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
    int x;
    cin >> x;
    searchInRowColumnSorted(A, x);
    // printMatrix(A);
    return 0;
}

/*
// Sir's example input
4 4
10 20 30 40
15 25 35 45
27 29 37 48
32 33 39 50

4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
15

5 5
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
18

1 3
1 2 3

3 1
1
2
3

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

*/

void searchInRowColumnSortedNaive(vector<vector<int> >& A, int x) {
    int r = A.size(), c = A[0].size();
    for (int i = 0; i < r; i++)
    {
        if (x >= A[i][0] && x <= A[i][c - 1])
        {
            int j = 0;
            while (j <= c - 1 && A[i][j] <= x)
            {
                if (A[i][j] == x) {
                    cout << "(" << i << ", " << j << ")" << endl;
                    return;
                }
                j++;
            }

        }

    }
    cout << "Elemnt Not found in Matrix" << endl;
}


