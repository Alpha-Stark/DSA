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

bool checkPalindrome(Node* head){

    stack<int> s;
    s.push(head->data);
    head = head->next;
    while (head!=NULL)
    {
        // s.push(head->data);
        if (!s.empty() && s.top() == head->data)
        {
            s.pop();
        }else
        {
            s.push(head->data);
        }    
        head = head->next;
    }
    if (s.empty())
    {
        return true;
    }else
    {
        return false;
    }
}

int main(){

    Node* head = takeInput();
    cout<<"Palindrome: "<<checkPalindrome(head)<<endl;

    return 0;
}