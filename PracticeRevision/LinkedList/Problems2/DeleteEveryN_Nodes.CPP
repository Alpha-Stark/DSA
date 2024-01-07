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

void deleteEveryN(Node* head, int m, int n){
    if (m == 0)
    {
        return;
    }
    Node* init = head;
    
    while (head != NULL)
    {
        for (int i = 0; i < m; i++) // we can also add the if head == NULL condition here
        {
            if (head == NULL)
            {
                break;
            }
            if (head==init)
            {
                init = NULL; //to skip 1st unwanted ittration
                continue;
            }// we can also do other thing and that is to take a step one time less and add this statement at end of loop // Start from next node and delete N nodes t = curr -> next; 
            head = head->next;
        }
        for (int i = 0; i < n; i++)
        {
            if (head == NULL || head->next == NULL)
            {
                break;
            }
            Node* temp=head->next;
            // head->next = head->next->next;
            head->next = temp->next;
            delete(temp);
        }   
    }
}


int main(){

    Node* head = takeInput();
    int m,n;
    cin>>m>>n;

    deleteEveryN(head,m,n);
    printList(head);
    return 0;
}


/*

1 2 3 4 5 6 7 8 9 10 11 12 13 -1
2
2


1 2 3 4 5 6 7 8 -1
2
3

*/