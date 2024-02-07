
#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution
{
public:
    // Function to find list of all words possible by pressing given numbers.

    vector<string> helper(int a[], int N, vector<string> &v)
    {
        if (N == sizeof(a) - 1)
        {
            v.push_back("abc");
        }
        for (int j = 0; j < sizeof(a); j++)
        {
            helper(a, N - 1, v);
        }
    }

    vector<string> possibleWords(int a[], int N)
    {
        // Your code here
        vector<string> v;
        helper(a, N, v);
    }
};

int main()
{

    int N;

    cin >> N; // input size of array

    int a[N]; // declare the array

    for (int i = 0; i < N; i++)
    {
        cin >> a[i]; // input the elements of array that are keys to be pressed
    }

    Solution obj;

    vector<string> res = obj.possibleWords(a, N);
    for (string i : res)
        cout << i << " ";
    cout << endl;

    return 0;
}
