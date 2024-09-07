#include <bits/stdc++.h>
using namespace std;

const int CHAR = 256;
bool optimized(string s1, string s2) {
    if (s1.length() != s2.length()) return false;

    int count[CHAR] = { 0 };
    for (int i = 0; i < s1.size(); i++)
    {
        count[s1[i]]++;
        count[s2[i]]--;
    }
    for (int i = 0; i < CHAR; i++)
        if (count[i] != 0)
            return false;

    return true;
}

bool helper(string s1, string s2) {
    unordered_map<char, int> hash;
    for (char x : s1)
        hash[x]++;

    for (char x : s2)
        hash[x]--;

    for (auto it : hash) {
        if (it.second != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string s1, s2;
    cin >> s1;
    cin >> s2;

    if (optimized(s1, s2))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}

/*

mann
namn

*/