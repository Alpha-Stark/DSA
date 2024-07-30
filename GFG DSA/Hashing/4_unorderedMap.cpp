// Unordered Map: Unordered Keys with Fast Search,insert & Delete operation. With (ordered) Maps, it's TC = log(n)

#include <bits/stdc++.h>
using namespace std;

int main() {

    unordered_map<string, int> umap;
    umap["Mann"] = 100000; //umap["key_name"] modifies the existing key's value if already exists, otherwise creats a new pair.
    umap["gfg"] = 10000;
    umap.insert({ "Savani", 100 });

    for (auto&& i : umap)
        cout << i.first << " " << i.second << endl;


    if (umap.find("gfg") != umap.end()) // .find() returns the iterator to the desired pair & in case of not found, returns the .end() address. .end() return/pointd towards the element belond/nextTo the last element.
        cout << "Found!!" << endl;
    else
        cout << "Not Found!!" << endl;

    /*
        auto it = umap.find("gfg"); // .find() returns the iterator to the desired pair.
        if( it != umap.end() ) {
            cout<< it->second <<endl;
        }
    */

    for (auto it = umap.begin(); it != umap.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }


    // Remember this: In unordered_map, the pair's value can we acces by using just .first and .sencond, instead of .first() and .second()

    return 0;
}

/*

Other Function:
    count(""): substitute of .find() where this returns the boolean value when it returns 1 if the given element is present and 0 when not
    size()
    erase(""): erases the key:value pair as per the given attribute. erase("gfg") or erase(umap.begin()) or erase(umap.begin(), umap.end())

Tc: O(1) on average for search,insert and delete operations

*/