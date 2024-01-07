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

void insertNode(Node* head, int index, int data){
    if (index<1){cout<<"Enter valid Index!"<<endl; return;} 
    
    Node* temp = head;
    while (index != 1)
    {
        temp = temp->next;
        index--;
        if(temp == NULL)
        {
            cout<<"Invalid Index"<<endl;
            return;
        }
    }
    if (temp->next != NULL)
    {
        Node* future = temp->next;
        Node* newNode = new Node(data);
        if (temp == head)
        {
            int intTemp = temp->data;
            temp->data = data;
            newNode->data = intTemp;
            newNode->next = future;
            temp->next = newNode;
            return;
        }
        temp->next = newNode;
        newNode->next = future;
    }else if (temp->next == NULL)
    {
        Node* newNode = new Node(data);
        temp->next = newNode;
    }    
}

void insertRec(Node* head, int index, int data){

    if (head == NULL)
    {
        cout<<"Invalid Index"<<endl;
        return;
    }
    

    if (index == 1)
    {
        Node* newNode = new Node(data);
        if (head->next == NULL)
        {
            head->next = newNode;
            return;
        }
        else
        {    
            Node* temp = head->next;
            head->next = newNode;
            newNode->next = temp;
            return;
        }
        
    }else if (index == 0)
    {
        Node* newNode = new Node(head->data);
        Node*temp = head->next;
        newNode->next = temp;
        head->data = data;
        head->next = newNode;
        return;
    }
    
    head = head->next;
    index--;
    insertRec(head, index, data);
}

void deleteNodeRec(Node* head, int index){
    if (head == NULL)
    {
        cout<<"Invalid Index"<<endl;
        return;
    }
    
    if(index == 0){
        head->data = head->next->data;
        Node* temp = head->next;
        head->next = head->next->next;
        delete(temp);
        return;
    }
    
    if (index == 1)
    {
        if (head->next == NULL)
        {
            cout<<"Invalid Index"<<endl;
            return;
        }
        
        Node* temp = head->next;
        head->next = head->next->next;
        delete(temp);
        return;
    }
    head = head->next;
    index--;
    deleteNodeRec(head,index);
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

int lengthLLRec(Node* head){
    
    int count = 0;
    
    if (head->next == NULL)
    {
        return 1;
    }
    count = lengthLLRec(head->next) + 1;
    return count;
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

int printIthNode(Node* head, int index){
    while (head != NULL && index > 0)
    {
        head = head->next;
        index--;
    }
    
    if (head == NULL)
    {
        return -1;
    }

    return head->data;
}
 
int main(){
 
    Node* head = takeInput();
 
    // insertNode(head, 6, 100);
    // insertRec(head, 6, 100);
    // deleteNodeRec(head, 6);
    // printList(head);
    // cout<<endl;
    // cout<<"Length of LinkedList: "<<lengthLLRec(head)<<endl;
    cout<<"Value at ith Node: "<<printIthNode(head, 9)<<endl;
    
    return 0;
}