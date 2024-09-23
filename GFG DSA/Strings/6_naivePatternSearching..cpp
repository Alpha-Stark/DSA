#include <bits/stdc++.h>
using namespace std;

void helper(string& str, string& pat) {
    int m = str.length();
    int n = pat.length();
    bool flag = false;

    for (int i = 0; i <= m - n; i++)
    {
        if (str[i] == pat[0])
        {
            int stringI = i + 1;
            for (int j = 1; j < n; j++)
            {
                if (str[stringI] == pat[j]) {
                    if (j == n - 1)
                    {
                        cout << i << " ";
                        flag = true;
                        break;
                    }
                    stringI++;
                }
                else {
                    break;
                }
            }
        }
    }

    if (!flag)
        cout << "Not Found" << endl;

}

int main() {
    // string str, pattern;
    // cin >> str;
    // cin >> pattern;
    string str = "mannsavani";
    string pattern = "an";
    helper(str, pattern);

    return 0;
}

/*
AAAAA
AA

AAAAA
AAA

*/