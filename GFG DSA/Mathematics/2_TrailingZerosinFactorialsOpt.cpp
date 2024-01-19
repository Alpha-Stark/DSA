#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number:";
    cin >> n;

    /* Now if we look at the factorial pattern, 1*2*3.4.5.6.7.8.9.10.11.12..15....25...100
    We can understand that to get a zero at the end, we need 2*5 which makes *10, which adds a zero at the end. Now we can count multiple of 2s[2,4,...] and 5s[5,10,15,...],
    but as per the pattern there will be less number of 5's multiple always than number of 2's multiples (because it apperars less than 2's muliple in fixed intervals).
    Now according to that patter, we only need to count the number of 5's multiple coming in that range, and that will do it. n/5 (100/5).
    Right, no because there will be number like 25 which will generate 2 times 5 from itself(5*5), so we need to consider that extra 5s too.
    If we try to account it on paper, we will notice a pattern of 5's exponents, making extra counts. So the pattern will be like zeros = (n/5)+(n/5^2)+(n/5^3)+....
    And it's general equeation comes out ∑(n/5^i) until n>=5^i.
    */

    int i = 5;
    int count = 0;

    while (n >= i)
    {
        count += n / i;
        i *= 5;
    }

    cout << count << endl;
    return 0;
}

/* Now look at this one-liner solution:
return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);

int trailingZeroes(int n){
    return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
}

*/
