/*
// Is Doubly linked List Circular



// Observations:
    * We are given doubly linked list, where we have to find is that doubly linked list is circular or not?


// Intrusion: 
    * We can check this condition by checking if last node is connected with the first node...
        * If last node is connected with first node, we return 1
        * Else return 0



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
    Node *temp=new Node(data);
    return temp;
}


class Solution{
    public:
    // Function to check whether doubly liked list is circular or not?
    bool isCircular(Node * head){
        // edge case when we have only one element...
        if(head->next == NULL) return 0;
        else if(head->next == head) return 1;

        // checking the iteration cases:
        Node *curr = head->next;    // making current iteration reference 
        Node *ref = head;
        bool flag = 0;  // flag will help us to find the linked list is circular or not?
        while(curr != ref){
            // condition hit only when we don't have circular linked list..
            if(curr->next == NULL){
                flag = 1;
                break;
            }
            curr = curr->next;
        }
        if(flag){
            return 0;
        }
        return 1;
    }
};


void makeCircular(Node * head){
    Node * temp=head;
    
    while(temp->next){
        temp=temp->next;
    }
    
    temp->next=head;
    head->prev=temp;
}

int main() {
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


        int y;
        cin>>y;

        if(y==1){
            makeCircular(head);
        }
        Solution ob;
        cout<<ob.isCircular(head);

        cout<<endl;
    }
    return 0;
}