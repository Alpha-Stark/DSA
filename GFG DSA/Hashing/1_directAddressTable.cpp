#include <bits/stdc++.h>
using namespace std;


bool arr[1000] = { false };

void insertNum(int n) {
    arr[n] = 1;
}
void deleteNum(int n) {
    arr[n] = 0;
}
bool search(int n) {
    return arr[n];
}


int main() {


    insertNum(10); cout << "Inserted" << endl;
    insertNum(20);cout << "Inserted" << endl;
    insertNum(119);cout << "Inserted" << endl;
    cout << search(10) << endl;
    cout << search(20) << endl;
    deleteNum(119);cout << "Deleted" << endl;
    cout << search(119) << endl;

    return 0;
}