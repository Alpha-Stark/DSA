#include <bits/stdc++.h>
using namespace std;

int main() {
    string str = "mann";
    cout << str.length() << endl;
    str = str + "gfg";
    cout << str << " Legth: " << str.length() << endl;
    cout << str.substr(1, 3) << endl; // Print the substring between given indexes inclusive
    cout << str.find("ann") << endl; // Returns the first occurance index of the given substring

    string s1 = "abc";
    string s2 = "baa";
    if (s1 == s2)
        cout << "Same" << endl;
    else if (s1 > s2)
        cout << "Larger" << endl;
    else
        cout << "Smaller" << endl;


    string name;
    cout << "Enter your name:";
    /*
    cin >> name;
    By using this if the input is "mann" it works perfectly find and will print perfectly.
    But if the input is "mann savani". It just stores "mann", doesn't get the things after space, coz the compiler considers it as some other input value.
    To solve this we have, getline(cin, name); Cox this will stop reading only when we hit enter and not when it find space.
    */
    getline(cin, name);
    // getline(cin, name, 'a'); //Means read it till you find 'a'
    cout << name << endl;

    //String traversing. Can be done with for loop and i index. And with the way below
    for (char c : name)
        cout << c; cout << endl;

    /* So it is always recommened to only use C++ Style Strings and its functions. */

    return 0;
}