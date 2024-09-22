#include <bits/stdc++.h>
using namespace std;

const int CHAR = 256;

int optimized(string s) {
    int count[CHAR] = { -1 };
    int result = INT_MAX;
    for (int i = 0; i < s.size(); i++)
    {
        if (count[int(s[i])] == -1) {
            count[int(s[i])] = i;
        }
        else {
            result = min(result, count[int(s[i])]);
        }
    }
    if (result != INT_MAX)
        return result;
    else
        return -1;
}

int helper(string s) {
    unordered_map<char, int> um;
    for (char x : s)
        um[x]++;

    for (int i = 0; i < s.size(); i++)
    {
        if (um[s[i]] > 1) {
            return i;
        }
    }
    return -1;
}

int main() {
    string s;
    cin >> s;

    // cout << helper(s) << endl;
    cout << optimized(s) << endl;
    return 0;
}

/*

geeksforgeeks
=0

abbcc
=1

abcd
=-1
*/




/* int optimized(string s) {
    unordered_map<char, int> um;
    int result = INT_MAX;
    for (int i = 0; i < s.size(); i++)
    {
        if (um[s[i]] >= 0) {
            result = min(result, um[s[i]]);
            break;
        }
        um[s[i]] = i;
    }
    if (result < s.length()) {
        return result;
    }
    return -1;
} */