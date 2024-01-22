//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // compute pow(n, R) with mod 1000000007

    long long modfun(long long n, long long R)
    {
        // Base cases

        if (n == 0)
            return 0;
        // power zero mean answer is 1
        if (R == 0)
            return 1;

        long long y;
        // If R is even
        if (R % 2 == 0)
        {
            // finding r/2 power as power is even then storing answer in y and if power is even like 2^4 we can simply do (2^2)*(2^2)
            y = modfun(n, R / 2);
            y = (y * y) % 1000000007;
        }

        // If R is odd
        else
        {
            y = n % 1000000007;
            // reduce the power by 1 to make it even. The reducing power by one can be done if we take one n out. Like 2^3 can be written as 2*(2^2)
            y = (y * modfun(n, R - 1) % 1000000007) % 1000000007;
        }
        // finally return the answer (y+mod)%mod = (y%mod+mod%mod)%mod = (y%mod)%mod
        return ((y + 1000000007) % 1000000007);
    }

    long long power(int N, int R)
    {
        return modfun(N, R) % 1000000007;
    }
};

//{ Driver Code Starts.

// compute reverse of a number
long long rev(long long n)
{
    long long rev_num = 0;
    while (n > 0)
    {
        rev_num = rev_num * 10 + n % 10;
        n = n / 10;
    }
    return rev_num;
}

int main()
{
    int T;
    cin >> T; // testcases

    while (T--)
    {
        long long N;
        cin >> N; // input N

        long long R = 0;

        // reverse the given number n
        R = rev(N);
        Solution ob;
        // power of the number to it's reverse
        long long ans = ob.power(N, R);
        cout << ans << endl;
    }
}
// } Driver Code Ends

/* GPT Explaination

This code defines two functions, `modfun` and `power`, which are used to calculate modular exponentiation.

1. **`modfun` function:**
   - Input Parameters: `n` (base), `R` (exponent)
   - Output: Modular exponentiation of `n^R` with respect to the modulo `1000000007`.
   - This function is a recursive implementation of modular exponentiation using the divide-and-conquer approach.
   - Base cases:
     - If `n` is 0, it returns 0.
     - If `R` is 0, it returns 1 (any number raised to the power of 0 is 1).
   - If `R` is even, it calculates `y = (n^(R/2)) % 1000000007` and then squares it: `y = (y * y) % 1000000007`.
   - If `R` is odd, it calculates `y = (n * modfun(n, R - 1)) % 1000000007`, essentially reducing the problem to an even power.
   - The final result is returned as `((y + 1000000007) % 1000000007)`.

2. **`power` function:**
   - Input Parameters: `N` (base), `R` (exponent)
   - Output: Modular exponentiation of `N^R` with respect to the modulo `1000000007`.
   - This function simply calls `modfun(N, R)` and takes the result modulo `1000000007`. It provides an interface to calculate modular exponentiation with a given base and exponent.

The code uses modular arithmetic throughout the calculations, which is often used to prevent integer overflow by taking the result modulo a large prime number (in this case, `1000000007`). The modulo operation is applied at each step to keep the intermediate results within manageable bounds. The code appears to be well-commented, explaining each step of the modular exponentiation process.

 */

/* Base Logic:

int powerOpt(int n, int p)
{
    int res = 1;
    while (p > 0)
    {
        // if (p % 2 != 0) //Can be also written as below, and its faster because of bitwise nature.
        if (p & 1)
        {
            // cout << "1 ";
            res = res * n;
        }
        else
        {
            // cout << "0 ";
        }
        n = n * n;
        // p = p / 2; //Also written as below, and its faster because of bitwise nature.
        p = p >> 1;
    }
    return res;
} // O(logn), better than recursive, because it's complexity is same as Recursive, but auxilary Space is O(1) only.


 */
