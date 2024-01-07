#include<bits/stdc++.h>
using namespace std;

int main(){

    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    while (s.size() != 0)
    {
        int val = s.top();
        s.pop();
        cout<<"Deleted Element: "<<val<<endl;
    }
    


    return 0;
}