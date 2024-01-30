#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(int n, int increment)
    {
        if (increment <= n)
        {
            if (n % increment == 0)
                return (false);

            n = n - (n / increment);
            increment++;

            return solve(n, increment);
        }
        else
        {
            return true;
        }
    }

    bool isLucky(int n)
    {
        return (solve(n, 2));
    }
}; // O(√n)

signed main()
{
    int n;
    cin >> n;
    Solution obj;
    // calling isLucky() function
    if (obj.isLucky(n))
        cout << "1\n"; // printing "1" if isLucky() returns true
    else
        cout << "0\n"; // printing "0" if isLucky() returns false
}
// } Driver Code Ends