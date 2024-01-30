#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool helper(vector<int> v, int inc, int n)
    {
        if (inc > sqrt(n) + 2) // base case, because if we do only +1, it will ignore the case in which if we go one more time, our number can be eleminated, and that what we want to check if our number is lucky or not.
        {
            // write a code to check if a vector v contains number n
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i] == n)
                {
                    return 1;
                }
            }
            return 0; // else part
        }

        for (int i = inc - 1; i < v.size(); i = i + inc)
        {
            v[i] = 0;
        }

        vector<int> temp;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] != 0)
            {
                temp.push_back(v[i]);
            }
        }

        // print the vector
        for (int i = 0; i < temp.size(); i++)
        {
            cout << temp[i] << " ";
        }
        cout << endl;

        return helper(temp, ++inc, n);
    }

    bool isLucky(int n)
    {
        vector<int> v;
        for (int i = 1; i <= n; i++)
        {
            v.push_back(i);
        }

        return helper(v, 2, n);
    }
};

signed main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    Solution obj;
    // calling isLucky() function
    if (obj.isLucky(n))
        cout << "1\n"; // printing "1" if isLucky() returns true
    else
        cout << "0\n"; // printing "0" if isLucky() returns false
}
