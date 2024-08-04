/*

// Find Middle of Circular Doubly Linked List
    * We are given odd size circular linked list, we need to find middle element of it.


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
    // 
    int findMiddle(Node * head){


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