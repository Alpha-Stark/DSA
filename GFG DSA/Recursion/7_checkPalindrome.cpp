#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s)
{
    if (s.length() <= 1)
    {
        return true;
    }

    if (s[0] != s[s.back()])
    {
        return false;
    }

    return checkPalindrome(s.substr(1, s.length()));
}

int main()
{
    string s;
    cout << "Enter the String: ";
    cin >> s;
    if (checkPalindrome(s))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}