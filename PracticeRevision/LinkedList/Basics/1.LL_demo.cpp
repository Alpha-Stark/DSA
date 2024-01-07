#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(){
        data = 0;
        next = NULL;
    }
    Node(int x){
        data = x;
        next = NULL;
    }    
};

Node* createList(int n){
    Node* head = NULL;
    Node* tail = NULL;

    head = new Node(n);
    // tail = head;
    return head;
}

void addNode(Node* head,int index, int x){

    Node*temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node* tail = temp;
    Node* a = new Node(x);
    tail->next = a;
}

int main(){
    // Node* head = new createList();
    Node* head = createList(10);
    addNode(head, 2, 20);
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    

    return 0;
}