#include <bits/stdc++.h>
using namespace std;

void LargestFraction(int n, int d)
{
    vector<int> result;
    float frac = (float)n / (float)d;
    for (int i = 9999; i >= 1; i--)
    {
        int a = i * (float)frac;
        float b = frac * (float)i;
        if (b - a <= frac)
        {
            result.push_back(a);
            result.push_back(i);
            break;
        }
    }
    // return result;
    cout << result[0] << " " << result[1] << endl;
}

int main()
{
    int n, d;
    cin >> n >> d;
    LargestFraction(n, d);
    return 0;
}

/*

1 8

2 53

15 23
= 6508 9979

*/