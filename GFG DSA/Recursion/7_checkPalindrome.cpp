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