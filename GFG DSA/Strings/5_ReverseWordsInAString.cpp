#include <bits/stdc++.h>
using namespace std;

void reverse(string& s, int startI, int endI) {
    int j = endI;
    for (int i = startI; i <= (startI + endI) / 2; i++) {
        swap(s[i], s[j--]);
    }
}

void helper(string& s) {
    int n = s.size();
    reverse(s, 0, n - 1);

    int prevStop = 0;
    for (int i = 0; i <= n; i++) {
        if (i == n || s[i] == ' ') {
            reverse(s, prevStop, i - 1);
            prevStop = i + 1;
        }
    }
}

int main()
{
    string s = "mann arvindbhai savani";
    helper(s);
    cout << s << endl;

    return 0;
}