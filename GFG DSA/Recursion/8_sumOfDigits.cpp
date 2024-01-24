#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(int n)
{
    // if (n == 0){return 0;} //the below one will save on recursive call if the number get to below 10.
    if (n <= 9)
        return n;
    return (n % 10) + sumOfDigits(n / 10);
} // Time and Aux Space Complexity is ø(n)

// But for such solution, itrative solution will be prefered because in comparison it will runs much faster, as it doesn't have any overhead of recursive calls.
int getSum(int n)
{
    int res = 0;
    while (n >= 0)
    {
        res = res + n % 10;
        n = n / 10;
    }
    return res;
} // Time Complexity is ø(n) and Aux Space Complexity ø(1), but will run faster because it wont have the overhead due to recursion.

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Sum: " << sumOfDigits(n) << endl;
    return 0;
}