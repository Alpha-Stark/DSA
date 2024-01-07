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

int findNodeRec(Node* head, int val){
    if (head == NULL)
    {
        return INT_MIN;
    }
    
    if (head->data == val)
    {
        return 0;
    }

    int smallAns = findNodeRec(head->next,val);
    return smallAns+1;
}

int main(){


    Node* head = takeInput();
    cout<<"Index of Given element:"<<findNodeRec(head,10)<<endl;
    // printList(head);
    return 0;
}