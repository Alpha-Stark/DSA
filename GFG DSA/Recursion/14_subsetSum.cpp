#include <bits/stdc++.h>
using namespace std;

int subsetSum(vector<int> current, vector<int> v, int sum)
{

    if (sum == 0)
    {
        return 1;
    }

    if (v.empty())
    {
        return 0;
    }

    // v update
    int back = v.back();
    v.pop_back();

    int a = subsetSum(current, v, sum);

    // new current
    current.push_back(back);
    int b = subsetSum(current, v, sum);

    int Returnsum = a + b;

    int currentSum = 0;
    for (int i = 0; i < current.size(); i++)
    {
        currentSum += current[i];
    }

    if (currentSum == sum)
        Returnsum++;

    return Returnsum;
}

int main()
{
    int n, sum;
    // cout << "Enter the size: ";
    cin >> n;

    // take vector input from user in cpp
    vector<int> current;
    current.push_back(0);

    vector<int> v;

    // cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++)
    {
        int current;
        cin >> current;
        v.push_back(current);
    }

    // cout << "Enter the Sum: ";
    cin >> sum;

    cout << subsetSum(current, v, sum) << endl;

    return 0;
}

/*

5
10 5 2 3 6
8


=2
 */