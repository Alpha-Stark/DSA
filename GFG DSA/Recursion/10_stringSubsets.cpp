#include <bits/stdc++.h>
using namespace std;

void printSubStrings(string curr, string &s)
{
    if (s.length() == 0)
    {
        return;
    }
    // cout << curr << " ";
    cout << curr + s[0] << " ";

    string sub = s.substr(1); // this means create a substring from index 1 to the end. Or we can write it as s.substr(1, s.length() - 1);
    printSubStrings(curr, sub);
    printSubStrings(curr + s[0], sub);
}

int main()
{
    string s;
    cout << "Enter a String: ";
    cin >> s;

    printSubStrings("", s);

    return 0;
}