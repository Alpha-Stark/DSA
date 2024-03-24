#include <bits/stdc++.h>
using namespace std;

struct Interval
{
    int start;
    int end;
};

bool myComp(const Interval &a, const Interval &b)
{
    return a.start < b.start;
}

int maxGuests(vector<Interval> &arr)
{
    int ans = 1;
    int count = 1;
    sort(arr.begin(), arr.end(), myComp);
    int resIndex = 0;

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[resIndex].end >= arr[i].start)
        {

            arr[resIndex].start = min(arr[resIndex].start, arr[i].start);
            arr[resIndex].end = max(arr[resIndex].end, arr[i].end);
            count += 1;
        }
        else
        {
            resIndex += 1;
            arr[resIndex] = arr[i];
            ans = max(ans, count);
            count = 1;
        }
    }
    return max(ans, count);
}

int main()
{
    vector<Interval> arr;
    int n;
    cin >> n;
    int a[n];
    int d[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> d[i];

    for (int i = 0; i < n; i++)
    {
        Interval current = {a[i], d[i]};
        arr.push_back(current);
    }
    cout << maxGuests(arr) << endl;

    return 0;
}

/*
2
900 940
1000 1030
=2

4
800 600 700 500
840 820 830 530
=3

6
900 940 950 1100 1500 1800
910 1200 1120 1130 1900 2000
=3

*/