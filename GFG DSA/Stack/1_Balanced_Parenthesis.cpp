#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string s)
{
    stack<char> st;
    int i = 0;
    for (auto &&i : s)
    {
        if (i == '(' || i == '{' || i == '[')
        {
            st.push(i);
        }
        else if (i == ')' || i == '}' || i == ']')
        {

            if (st.empty())
            {
                return false;
            }

            if (i == ')' && st.top() == '(')
            {
                st.pop();
            }
            else if (i == '}' && st.top() == '{')
            {
                st.pop();
            }
            else if (i == ']' && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }

    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    string s;
    cout << "Enter the String:";
    cin >> s;
    bool res = isBalanced(s);
    if (res)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}