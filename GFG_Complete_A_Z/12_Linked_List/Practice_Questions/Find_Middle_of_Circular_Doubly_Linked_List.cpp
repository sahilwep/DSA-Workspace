/*

// Find Middle of Circular Doubly Linked List
    * We are given odd size circular linked list, we need to find middle element of it.

// Observations: 
    * We are given circular doubly inked list..
    * We need to find the middle of circular linked list..
    * The linked list size is odd...



// Intrusion: 
    * first we will iterate throughout the linked list & find the size of it..
    * then we will iterate n/2 size of it, & return the middle value..


*/
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node * next;
    Node * prev;
    Node (int x){
        data=x;
        next=NULL;
        prev=NULL;
    }
};

Node *newNode(int data){
    Node * temp=new Node(data);
    return temp;
}

class Solution{
    public:
    // Function to find the middle of circular linked list:
    int findMiddle(Node * head){
        Node *ref = head;   // making ref to compare at iteration time..
        Node *curr = head->next;    // making curr to iterate 
        int cnt = 1;    // as curr is decare head->next, so we declare count as 1
        // iterate until our curr will not become head or ref we can say...
        while(curr != ref){
            cnt++;  // increment counter
            curr = curr->next;  // updating current node..
        }

        // at last we will iterate till count/2, & return the value...
        for(int i=0;i<cnt/2;i++){
            ref = ref->next;
        }

        return ref->data;
    }
};

void makeCircular(Node * head){

    Node * temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = head;
    head->prev = temp;
}


int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head=NULL, *tail=NULL;
        int x;
        cin>>x;
        head = newNode(x);
        tail = head;

        for(int i=0;i<n - 1;i++){
            cin>>x;
            Node* temp=newNode(x);
            tail->next=temp;
            temp->prev= tail;
            tail = temp;
        }
        Solution ob;
        makeCircular(head);
        cout<<ob.findMiddle(head);

        cout<<endl;
    }
    return 0;
}