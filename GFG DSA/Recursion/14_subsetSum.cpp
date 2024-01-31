#include <bits/stdc++.h>
using namespace std;

int subsetSum(vector<int> current, vector<int> &v, int sum)
{
    if (sum == 0)
    {
        return 1;
    }

    int currentSum = 0;
    if (v.size() == 1)
    {
        int front = v.front();
        current.push_back(front);
        for (int i = 0; i < current.size(); i++)
        {
            currentSum += current[i];
        }
        if (currentSum == sum)
        {
            return 1;
        }
        return 0;
    }

    // new v
    vector<int> newV;
    if (v.size() != 1)
    {
        for (int i = 1; i < v.size(); i++)
        {
            newV.push_back(v[i]);
        }
    }

    /* for (int i = 0; i < current.size(); i++)
    {
        cout << current[i] << " ";
    }
    cout << endl; */

    int a = subsetSum(current, newV, sum);
    // new current
    int front = v.front(); // print(front: v.front())
    // cout << "Front: " << front << endl;
    current.push_back(front);
    int b = subsetSum(current, newV, sum);

    int Returnsum = a + b;

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

    if (v.empty())
    {
        cout << "0" << endl;
        return 0;
    }

    cout << subsetSum(current, v, sum) << endl;

    return 0;
}

/*

5
10 5 2 3 6
8


=2
 */