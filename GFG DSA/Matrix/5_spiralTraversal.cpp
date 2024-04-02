#include <bits/stdc++.h>
using namespace std;
// To be allowed to declare a multidementional vector, have to change formatting setting, as it wont be done just by disabelling prettier extension. In settings, under format section, changed the "c_cpp: Formatting" from "default" to "vsFormat". 

// Sir's code
void spiralTraversal(vector<vector<int> >& A) {
    int r = A.size(), c = A[0].size();
    if (r == 1)
    {
        for (int j = 0;j < c;j++)
            cout << A[0][j] << " ";
    }
    else if (c == 1) {
        for (int i = 0;i < r;i++)
            cout << A[i][0] << " ";
    }
    else {
        int top = 0, right = c - 1, bottom = r - 1, left = 0;
        while (top <= bottom && left <= right) {
            //  Print the first row from the remaining rows
            for (int i = left; i <= right; i++)
                cout << A[top][i] << " ";
            top++;

            //  Print the last column from the remaining columns
            for (int i = top; i <= bottom; i++)
                cout << A[i][right] << " ";
            right--;

            // Print the last row from the remaining rows
            if (top <= bottom) {
                for (int i = right; i >= left; i--)
                    cout << A[bottom][i] << " ";
                bottom--;
            }

            // Print the first column from the remaining columns
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    cout << A[i][left] << " ";
                left++;
            }
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
    spiralTraversal(A);
    // printMatrix(A);
    return 0;
}

/*
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

5 5
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25

1 3
1 2 3

3 1
1
2
3

*/


// My code, this prints dublicates at the end
/*
void spiralTraversal(vector<vector<int> >& A) {
    int r = A.size(), c = A[0].size();
    if (r == 1)
    {
        for (int j = 0;j < c;j++)
            cout << A[0][j] << " ";
    }
    else if (c == 1) {
        for (int i = 0;i < r;i++)
            cout << A[i][0] << " ";
    }
    else {
        int top = 0, right = c - 1, bottom = r - 1, left = 0;

        // top row
        // right column
        // bottom row (reverse traversal)
        // left column (reverse traversal)

        while (top <= bottom && left <= right) //if we put || between the conditions too, it works fine.
        {
            for (int j = left; j <= right; j++)
                cout << A[top][j] << " ";
            top++;

            for (int i = top; i <= bottom; i++)
                cout << A[i][right] << " ";
            right--;

            for (int j = right;j >= left;j--)
                cout << A[bottom][j] << " ";
            bottom--;

            for (int i = bottom; i >= top; i--)
                cout << A[i][left] << " ";
            left++;
        }
    }
}

*/