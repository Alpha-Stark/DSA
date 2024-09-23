#include <bits/stdc++.h>
using namespace std;


/*
So there are two steps of solving this problem.
That is,
1. 1st we reverse the full string. And then,
2. We reverse the individual words.
So at the end we get the desired full string.

We have seen this kind of question before, so pattern should be recognized in yourm mind and that's how it is solved.
Sir, in the video follow similar but slightly different approach.
 */

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
    cout << endl;
    cout << s << endl;
    cout << endl;

    return 0;
}