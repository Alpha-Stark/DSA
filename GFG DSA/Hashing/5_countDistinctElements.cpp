#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    unordered_set<int> us;
    for (int i = 0; i < n; i++)
        us.insert(arr[i]);

    cout << us.size() << endl;

    /*
    unordered_set<int> us(arr, arr+n); //the constructor of it will take care of inserting operation
    return us.size();

    */

    return 0;
}

/*
7
15 12 13 12 13 13 18

3
10 10 10

3
10 11 12
*/