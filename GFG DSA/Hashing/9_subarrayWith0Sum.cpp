#include <bits/stdc++.h>
using namespace std;

// Sir's Solution:- Look at the idea/logic behind to write this solution from video
void subarraySum0(int arr[], int n) {
    unordered_set<int> hash;
    int prefixSum = 0;
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        if ((hash.find(prefixSum) != hash.end()) || prefixSum == 0)
        {
            cout << "Yes" << endl;
            return;
        }
        hash.insert(prefixSum);
    }
    cout << "No" << endl;
    return;
}

int main() {
    int n;
    cin >> n;
    int arr[n], totalSum = 0;

    for (int i = 0;i < n;i++) {
        cin >> arr[i];
        totalSum += arr[i];
    }

    subarraySum0(arr, n);

    // As it is subarray, so we only have to consider contegious elements. i.e., {1,2,3} => {1,3} is not considered a subset
    int i = 0, j = n - 1;
    if (totalSum == 0)
    {
        cout << "Yes" << endl;
        return 0;
    }

    int currentSum = totalSum;
    while (i < j)
    {
        if (currentSum == 0)
        {
            cout << "Yes" << endl;
            return 0;
        }

        if (arr[j] >= arr[i])
        {
            currentSum -= arr[j]; //arr[j--]
            j--;
        }
        else {
            currentSum -= arr[i]; //arr[i--]
            i++;
        }
    }

    if (currentSum == 0)
    {
        cout << "Yes" << endl;
        return 0;
    }
    else {
        cout << "No" << endl;
        return 0;
    }
}

/*
6
1 4 13 -3 -10 5
=Yes

5
-1 4 -3 5 1
=Yes

5
3 1 -2 5 6
=No

4
5 6 0 8
=Yes

5
1 2 -3 3 1
=Yes

*/