#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // int addDigits(int num) {
    //     if (num <= 9) return num;

    //     int res = (num % 10) + addDigits(num / 10);

    //     if(res < 10){
    //         return res;
    //     }else{
    //         return addDigits(res);
    //     }
    // }
    // 5ms, because recursive

    int addDigits(int num)
    {
        if (num < 10)
            return num;
        int digitSum = 0;
        while (num)
        {
            digitSum += num % 10;
            num /= 10;
        }
        return addDigits(digitSum);
    } // 0 ms, because itrative for hard part and recursive for repetation.
};

int main()
{
    Solution solution;

    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Sum: " << solution.addDigits(n) << endl;
    return 0;
}
// Time Complexity: ø(n)
// Aux Space Complexity: ø(1)
// Company Tags: Amazon, Microsoft, Samsung
