#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string &s, int start, int end) // we do this referencing for optimization as it avoids the string's unnecessary copy.
{
    if (start >= end)
    {
        return true;
    }

    return (s[start] == s[end]) && checkPalindrome(s, start + 1, end - 1);
}
/*
T(n) = T(n-2) + ø(1), and this comes to be O(n). And ø(n/2) function calls, means the Aux Space ø(n/2)~= ø(n) => O(n).
 */

int main()
{
    string s;
    cout << "Enter the String: ";
    cin >> s;
    if (checkPalindrome(s, 0, s.length() - 1))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}