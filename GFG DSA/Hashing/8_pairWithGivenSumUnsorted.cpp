#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, sum;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> sum;

    /*
        Major Learning over here is that if the array was sorted, we could have used 2 pointers approach and solved it in less time and space complexity both.
        But the array is unsorted, and only&only that's why we went (should) for Hashing.
    */


    /*
        //My solution below also works. But better Solution which is smart and crisp
        unordered_set<int> s;
        for (int i : arr){
            int remSum = sum - i;
            if (s.find(remSum) != s.end()) {
                return true;
            }
            s.insert(i);
        }
        return false;
     */
    unordered_map<int, int> hash;
    for (int x : arr)
        hash[x]++;

    if (sum % 2 == 0 && (hash.find(sum / 2) != hash.end()) && hash[sum / 2] > 1) {
        cout << "True" << endl; //return true
        return 0;
    }

    for (int i : arr)
    {
        int remSum = sum - i;
        if (hash.find(remSum) != hash.end() && remSum != sum / 2) {
            cout << "True" << endl; //return true
            return 0;
        }
    }
    cout << "False" << endl;

    return 0;
}

/*
5
3 2 8 15 -8
17
=Yes

4
2 4 6 3
11
=No

4
5 8 -3 6
3
=Yes

4
2 2 1 3
4
=Yes

*****
3
11 5 6
10
=No
*****
*/