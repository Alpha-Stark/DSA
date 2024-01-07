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

void removeDublicates(Node* head){

    while (head->next != NULL)
    {
        if (head->data == head->next->data)
        {
            Node* temp = head->next;
            head->next = head->next->next;
            delete(temp);
        }
        if (head->next != NULL && head->data != head->next->data) //written head.next!=NULL first, because it that's false then have to move down without checking other condition because that will make segmentation fault
        {
            head = head->next;   
        }
        
    }

}
 // 1 2 3 3 3 4 4 5 5 5 7 7 -1

int main(){

    Node*head = takeInput();
    removeDublicates(head);

    printList(head);

    return 0;
}
