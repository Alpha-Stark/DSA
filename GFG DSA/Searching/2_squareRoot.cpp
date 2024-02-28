#include <bits/stdc++.h>
using namespace std;

// **From this we can understand that using binary search technique, we can solve mathematical problem which are monotonic function in nature.
int squareRoot(int x)
{
    int low = 1, high = x;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (mid * mid == x || (mid * mid < x && (mid + 1) * (mid + 1) > x))
        {
            return mid;
        }
        else if (mid * mid < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
} // O(log(n))

int main()
{
    int x;
    // cin >> x;
    // cout << squareRoot(x) << endl;

    for (int x = 1; x <= 100; x++)
    {
        cout << x << ": " << squareRoot(x) << endl;
    }

    return 0;
}

// Sir's solution
/*

int squareRoot(int x)
{
    int low = 1, high = x, ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int mSq = mid * mid;
        if (mSq == x)
        {
            return mid;
        }
        else if (mSq > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
            ans = mid;
        }
    }
    return ans;
}


*/