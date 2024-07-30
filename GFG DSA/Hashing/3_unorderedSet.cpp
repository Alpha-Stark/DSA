#include <bits/stdc++.h>
using namespace std;

int main() {

    unordered_set<int> set; //used here bcz unordered set used hashing in backend and hence it has TC same as Hashing
    set.insert(10);
    set.insert(30);
    set.insert(40);
    set.insert(5);
    set.insert(80);

    for (auto it = set.begin(); it != set.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << set.size() << endl;
    set.clear();
    cout << set.size() << endl;

    /*
        Other discussed function in the video:
            clear(): used when we want to check multiple test cases and hence after every itration, we clear out unordered set.
            find(): returns the iterator/address of the given element I think.
            count(): Same as find(), return boolean response. 1 or 0
            erase(): used to remove an item or a range of items, both by giving/providing the iterator. Eg: erase(set.begin(), set.end()); set.end() is exclusive

        And all of these operations works at O(1) TC on average*

        Application: must look into the video, really good base to understand when to use it. Unordered_set in C++ STL
                     Use it when we want the search(), insert() & delete operation in O(1). Also we use set only when we are dealing with keys.[& each are unique]
                     In case of key-value pair, we use unordered_map.
     */

    return 0;
}