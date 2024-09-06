#include <bits/stdc++.h>
using namespace std;

bool helper(string s1, string s2) {
    int i = 0;
    int j = 0;

    while (i < s1.size() && j < s2.size())
    {
        if (s1[i] == s2[j]) {
            i++;j++;
        }
        else
            i++;

        if (j == s2.size())
        {
            return true;
        }
    }
    return false;
}

bool recursiveHelper(string s1, string s2, int m, int n) {

    if (n == 0)
        return true;

    if (m == 0)
        return false;

    if (s1[m - 1] == s2[n - 1])
        return recursiveHelper(s1, s2, m - 1, n - 1);
    else
        return recursiveHelper(s1, s2, m - 1, n);
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    // considering s2 is the smaller subsequence

    // if (helper(s1, s2))
    if (recursiveHelper(s1, s2, s1.size(), s2.size()))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}

/*
abcdefgh
cgh

geeksforgeeks
grgs

geeksforgeeks
grgo
*/