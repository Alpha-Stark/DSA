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

Node* mergeSortedLL(Node* h1, Node* h2){

    Node* newHead = NULL;
    Node* newTail = NULL;
    Node* otherHead = NULL;
    while (1)
    {
        if (newHead == NULL)
        {
            if (h1->data < h2->data)
            {
                newHead = h1;
                newTail = newHead;
                // h1 = h1->next;
                otherHead = h2;
            }else
            {
                newHead = h2;
                newTail = newHead;
                // h2 = h2->next;
                otherHead = h1;
            }            
        }else
        {
            if (newTail->next == NULL || otherHead == NULL)
            {
                break;
            }
            
            if (otherHead->data <= newTail->next->data)
            {
                // newTail = newTail->next;
                Node* temp = newTail->next;
                newTail->next = otherHead;
                otherHead = otherHead->next;
                newTail->next->next = temp;
                newTail = newTail->next;
            }else
            {
                newTail = newTail->next;
            }   
        }
        
        
    }
    if (newTail->next == NULL && otherHead != NULL)
    {
        newTail->next = otherHead;
        return newHead;
    }
    else if (newTail->next != NULL && otherHead == NULL)
    {
        return newHead;
    }
    else if(newHead->next == NULL && otherHead->next == NULL)
    {
        newTail->next = otherHead;
        return newHead;
    }
    // else
    // {
    //     return newHead;
    // }
    
}

int main(){


    Node* head1 = takeInput();
    Node* head2 = takeInput();

    Node* head3 = mergeSortedLL(head1, head2);
    printList(head3);

    return 0;
}

/*

2 5 8 12 -1
3 6 9 -1

2 5 -1
3 6 9 -1

2 5 8 12 -1
2 3 5 6 9 -1

1 2 3 -1
4 5 6 -1

2 5 8 12 -1
2 3 5 6 9 -1

1 -1
0 -1

*/