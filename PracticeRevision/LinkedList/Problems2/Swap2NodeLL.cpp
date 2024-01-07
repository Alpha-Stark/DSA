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

//wrong solution
Node* swap2Node(Node* head,int m, int n){

    if(m == 0 && n == 0){
        return head;
    }

    // IMPORTANT // IMPORTANT // IMPORTANT // IMPORTANT // IMPORTANT 
    /*REMEMBER in such cases where nodes have to be replaced, Its always better to keep **previous node** */
    // IMPORTANT // IMPORTANT // IMPORTANT // IMPORTANT // IMPORTANT 
    Node* orgHead = head;
    int i = 0;
    Node* newHead = NULL;
    Node* prev1 = NULL;
    Node* prev2 = NULL;
    Node* mAdd = NULL;
    Node* nAdd = NULL;

    while (head != NULL)
    {
        if (i == m-1)
        {
            mAdd = head->next;
            prev1 = head;
        } else if (i == n-1)
        {
            nAdd = head->next;
            prev2 = head;
        }
        head=head->next;
        i++;
    }

    
    // if (m>i || n>i)
    // {
    //     return orgHead;
    // }else 
    if(m == 0 || n == 0){
        
        if (m==0)
        {
            Node* pre = nAdd->next;
            Node* newHead = nAdd;
            newHead->next = orgHead->next;
            prev2->next = orgHead;
            orgHead->next = pre;
            return newHead;
        }else
        {
            Node* pre = mAdd->next;
            Node* newHead = mAdd;
            newHead->next = orgHead->next;
            prev1->next = orgHead;
            orgHead->next = pre;
            return newHead;
        }
        
    }
    
    Node* tail1 = mAdd->next;
    Node* tail2 = nAdd->next;
    prev1->next = nAdd;
    prev2->next = mAdd;
    prev1->next->next = tail1;
    prev2->next->next = tail2;
    //correct
    // Node* temp = mAdd->next;
    // Node* tail1 = mAdd->next->next;
    // Node* tail2 = nAdd->next->next;
    // mAdd->next = nAdd->next;
    // nAdd->next = temp;
    // mAdd->next->next = tail1;
    // nAdd->next->next = tail2;
    

    return orgHead;
}


//original solution
Node* swap_nodes(Node *head,int i,int j)
{

    // IMPORTANT // IMPORTANT // IMPORTANT // IMPORTANT // IMPORTANT 
    /*REMEMBER in such cases where nodes have to be replaced, Its always better to keep **previous node** */
    // IMPORTANT // IMPORTANT // IMPORTANT // IMPORTANT // IMPORTANT 
    Node *temp = head;
    Node *pre = NULL;
    Node *p1 = NULL;
    Node *p2 = NULL;
    Node *c1 = head;
    Node *c2 = head;
    int x=0;
    while(temp != NULL){
        if(x == i){
            p1 = pre;
            c1 = temp;
        }
        else if(x == j){
            p2 = pre;
            c2 = temp;
        }
        pre = temp;
        temp = temp->next;
        x++;
    }
    if(p1 != NULL)
        p1->next = c2;
    else
        head = c2;
    if(p2 != NULL)
        p2->next = c1;
    else
        head = c1;
    Node *TEMP = c2->next;
    c2->next = c1->next;
    c1->next = TEMP;
    return head;

}

int main(){


    Node* head = takeInput();
    // Node* newHead = swap2Node(head,6,0);
    Node* newHead = swap_nodes(head,3,4);
    
    printList(newHead);
    
    return 0;
}

/*

1 2 3 4 5 6 7 8 -1


**
3 4 5 2 6 1 9 -1
3 4
**


3 4 5 2 6 1 9 -1
2 4

*/