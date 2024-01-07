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

int LengthLL(Node* head){
    int length = 1;
    while (head->next != NULL)
    {
        head = head->next;
        length++;
    }
    return length;
}

Node* appendLast(Node* head, int n){
    if (n <= 0){return head;}
    
    int counter = LengthLL(head) - n - 1;
    Node* temp = head;
    while (counter > 0)
    {
        temp = temp->next;
        counter--;
    }
    Node* store = temp->next;
    temp->next = NULL;
    Node* temp2 = store;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = head;
    return store;

}

/*
node* append_LinkedList(node* head,int n) { 
    node* temp=head,*t=head;
    int i = -n;
    while(temp->next!=NULL) {
        if(i >= 0) 
            t = t -> next;
            temp=temp -> next;
            i++;
    }
    temp -> next = head;
    head = t -> next;
    t -> next = NULL;
    return head;
}
*/ 
//Too good thaught, for eg., last 3 element have to choose, so first- leave 3 element from start(with *fast) and then start a slow point from start and at the end of fast, slow will reach at desired loc.

int main(){

    Node* head = takeInput();
    Node* newHead = appendLast(head, 0);
    printList(newHead);

    return 0;
}