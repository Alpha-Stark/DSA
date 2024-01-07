#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

Node* takeInput(){
    int x;
    cout<<"Enter the values of LinkedList: "<<endl;
    cin>>x;

    Node* head = NULL;
    Node* tail = NULL;
    while (x != -1)
    {
        if (head == NULL)
        {
            Node* a = new Node(x); // remember you should not repeat statements, this could be written upside once
            head = a;
            tail = head;
        }else
        {
            Node* newNode = new Node(x); // repeated
            tail->next = newNode;
            tail = tail->next;
        }

        cin>>x;
    }
    cout<<"LinkedList Created"<<endl;
    return head;
}

void printList(Node* head){
    cout<<"LinkedList Data: ";
    Node*temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

class Pair{
    public:
    Node* head;
    Node* tail;
    Pair(Node* head, Node* tail){
        this->head = head;
        this->tail = tail;
    }
};

Pair* reverseLL_2(Node* current){
    // Pair p = new Pair();
    if (current->next == NULL || current == NULL)
    {
        Pair *smallAns = new Pair(current, current);
        return smallAns;
    }
    Pair* fragment = reverseLL_2(current->next);
    fragment->tail->next = current;
    //but here current's next is not right, so lets declare it NULL;
    fragment->tail->next->next = NULL;
    //  or write :- current->next = NULL;
    fragment->tail = fragment->tail->next;
    //  or write :- fragment->tail = current;
    return fragment;
} // pair class object // O(n)

Node* reverseLL(Node* current){
    if (current->next == NULL || current == NULL)
    {
        return current;
    }
    Node* fragment = reverseLL(current->next);
    Node* temp = fragment;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = current;
    //but here current's next is not right, so lets declare it NULL;
    temp->next->next = NULL;
    return fragment;
} // O(n^2)


int main(){

    Node* head = takeInput();
    // Node* newHead = reverseLL(head);
    Pair* p = reverseLL_2(head);
    printList(p->head);
    return 0;
}