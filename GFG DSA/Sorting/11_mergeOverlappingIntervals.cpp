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

void removeOverlapping(vector<Interval> &arr)
{
    sort(arr.begin(), arr.end(), myComp);
    int resIndex = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[resIndex].end >= arr[i].start)
        {
            arr[resIndex].start = min(arr[resIndex].start, arr[i].start);
            arr[resIndex].end = max(arr[resIndex].end, arr[i].end);
            arr.erase(arr.begin() + i);
        }
        else
        {
            resIndex += 1;
            arr[resIndex] = arr[i];
        }
    }
    for (int i = 0; i <= resIndex; i++)
    {
        cout << "{" << arr[i].start << "," << arr[i].end << "}" << endl;
    }
}

int main()
{
    vector<Interval> arr;
    Interval a = {5, 10};
    Interval b = {3, 15};
    Interval c = {18, 30};
    Interval d = {2, 7};

    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);
    arr.push_back(d);
    removeOverlapping(arr);

    return 0;
}
