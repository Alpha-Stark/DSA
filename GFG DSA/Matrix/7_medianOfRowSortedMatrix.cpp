#include <bits/stdc++.h>
using namespace std;
// To be allowed to declare a multidementional vector, have to change formatting setting, as it wont be done just by disabelling prettier extension. In settings, under format section, changed the "c_cpp: Formatting" from "default" to "vsFormat". 

// Striver's code. Video Link: https://www.youtube.com/watch?v=Q9wXgdxJq48
int myUpperBound(vector<int>& A, int x, int c) {
    int low = 0, high = c - 1;
    int ans = c;
    while (low <= high)
    {
        int mid = (low + high) / 2; //maybe an answer
        if (A[mid] > x) {
            ans = mid;
            high = mid - 1; //look for more small index on left
        }
        else
            low = mid + 1; //look on/for right
    }
    return ans;
}

int countSmallEqual(vector<vector<int> >& A, int r, int c, int mid) {
    int count = 0;
    int x = mid;
    for (int i = 0; i < r; i++)
    {
        count += myUpperBound(A[i], x, c);
    }
    return count;
}

int medianRowSorted(vector<vector<int> >& A) {
    int r = A.size(), c = A[0].size();
    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < r; i++)
    {
        low = min(low, A[i][0]);
        high = max(high, A[i][c - 1]);

        int req = (r * c) / 2;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int smallEqual = countSmallEqual(A, r, c, mid);//its okay if we dont pass row and col count.
            if (smallEqual <= req)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
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
    cout << medianRowSorted(A) << endl;
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

/*
GFG Sir's code:
// C++ program to find median of a matrix
// sorted row wise
#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;

// function to find median in the matrix
int binaryMedian(int m[][MAX], int r ,int c)
{
    int min = INT_MAX, max = INT_MIN;
    for (int i=0; i<r; i++)
    {
        // Finding the minimum element
        if (m[i][0] < min)
            min = m[i][0];

        // Finding the maximum element
        if (m[i][c-1] > max)
            max = m[i][c-1];
    }

    int desired = (r * c + 1) / 2;
    while (min < max)
    {
        int mid = min + (max - min) / 2;
        int place = 0;

        // Find count of elements smaller than mid
        for (int i = 0; i < r; ++i)
            place += upper_bound(m[i], m[i]+c, mid) - m[i];
        if (place < desired)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}

// driver program to check above functions
int main()
{
    int r = 3, c = 3;
    int m[][MAX]= { {1,3,5}, {2,6,9}, {3,6,9} };
    cout << "Median is " << binaryMedian(m, r, c) << endl;
    return 0;
}



*/