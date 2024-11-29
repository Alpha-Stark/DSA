#include <bits/stdc++.h>
using namespace std;

void helperImproved(string& str, string& pat) {
    int m = str.length();
    int n = pat.length();
    bool flag = false;

    int i = 0;
    while (i <= m - n)
    {
        if (str[i] == pat[0])
        {
            int stringI = i;
            for (int j = 0; j < n; j++)
            {
                if (str[stringI] == pat[j]) {
                    if (j == n - 1)
                    {
                        cout << i << " ";
                        flag = true;
                        i++;
                        break;
                    }
                    stringI++;
                }
                else {
                    i = stringI;
                    break;
                }
            }
        }
        else {
            i++;
        }
    }

    if (!flag)
        cout << "Not Found" << endl;
}

void helper(string& str, string& pat) {
    int m = str.length();
    int n = pat.length();
    bool flag = false;

    for (int i = 0; i <= m - n; i++)
    {
        if (str[i] == pat[0])
        {
            int stringI = i; //not using stringI= i+1 & j=1 here because of the edge edge case. str=mann, patt=a;
            for (int j = 0; j < n; j++)
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
    helperImproved(str, pattern);

    return 0;
}

/*
AAAAA
AA

AAAAA
AAA

*/