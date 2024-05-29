#include <bits/stdc++.h>
using namespace std;

struct MyHash
{
    int BUCKET;
    list<int>* table;
    MyHash(int b) {
        BUCKET = b;
        table = new list<int>[b];
    }

    void insert(int key) {
        int i = key % BUCKET;
        table[i].push_back(key);
    }
    void remove(int key) {
        int i = key % BUCKET;
        table[i].remove(key);
    }
    bool search(int key) {
        int i = key % BUCKET;

        list<int>::iterator it;
        for (auto x : table[i]) {
            if (x == key)
                return true;
        }
        return false;
    }
};


int main() {
    int b = 7;
    MyHash a(b);
    a.insert(70);
    a.insert(71);
    a.insert(56);
    a.insert(9);
    a.insert(72);

    if (a.search(56)) cout << "Found" << endl;
    else cout << "Not Found" << endl;

    a.remove(56);

    if (a.search(56)) cout << "Found" << endl;
    else cout << "Not Found" << endl;

    return 0;
}