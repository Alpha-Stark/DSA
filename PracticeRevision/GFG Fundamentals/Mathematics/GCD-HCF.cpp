#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num1, num2;
    cout << "Enter both numbers:";
    cin >> num1 >> num2;

    int result = min(num1, num2);

    while (result > 0)
    {
        if (num1 % result == 0 && num2 % result == 0)
        {
            break;
        }
        result--;
    }
    cout << result << endl;

    return 0;
}

/* My naive, but more time consuming

    int big, small;
    if (num1 > num2)
    {
        big = num1;
        small = num2;
    }
    else
    {
        big = num2;
        small = num1;
    }

    if (big % small == 0)
    {
        cout << small << endl;
        return 0;
    }

    int result = 1;
    int i = 1;
    while (i <= small / 2)
    {
        if (big % i == 0 && small % i == 0)
        {
            result = i;
        }
        i++;
    }
    cout << result << endl;

 */