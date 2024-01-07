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

void evenAfterOdd_N2(Node* head){
    int change = 1;
    // Node* temp = head;
    while (change != 0)
    {
        change = 0;
        Node* current = head->next;
        Node* prev = head;
        while (current != NULL)
        {
            if ( (current->data %2 != 0) && (prev->data % 2 == 0))
            {
                int temp = current->data;
                current->data = prev->data;
                prev->data = temp;
                change = 1;
                prev = prev->next;
                current = current->next;
            }else
            {
                prev = prev->next;
                current = current->next;
            }   
        }      
    }
}

int main(){

    Node* head = takeInput();
    evenAfterOdd_N2(head);
    printList(head);
    return 0;
}

/* (Very Good Thinking)Traverse the LL and connect a odd node with other odd number node, as if making LL of only odd numbers. 
And do it for even too. At the end connect odd's tail to even's head */
Node* arrange_LinkedList_fully_optimised(Node* head)
{
        if(head == NULL || head->next == NULL){
        return head;
    }
    Node* current = head;
    Node* oddH = NULL;
    Node* oddT = NULL;
    Node* evenH = NULL;
    Node* evenT = NULL;
    while (current != NULL){
        if(current->data%2 == 0){
            if(evenH == NULL){
                evenH = current;
                evenT = current;
            }
            else{
                evenT->next = current;
                evenT = current;
            }
        }
        else{
            if(oddH == NULL){
                oddH = current;
                oddT = current;
            }
            else{
                oddT->next = current;
                oddT = current;
            }
        }
        current = current->next;
    }
    if(oddH == NULL){
        return evenH;
    }
    else{
        if(evenH != NULL){
            oddT->next = evenH;
            evenT->next = NULL;
            return oddH;
        }
        else{
            return oddH;
        }
    }
}

/*

1 4 5 2 -1

1 11 3 6 8 0 9 -1

*/