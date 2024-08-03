/*

// Join two linked list: 

// Intrusion:
    * We just have to connect the last node of first linked list to the head of second linked list..

*/
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node * next;
    Node (int x){
        data=x;
        next=NULL;
    }
        
};

void displayList(Node *head){
    if(head != NULL){
        cout << head->data << " ";
        displayList(head->next);
    }
}

// Function to join two linked list:
Node* joinTheLists(Node * head1, Node * head2){
    Node *curr = head1;
    while(curr->next != NULL) curr = curr->next;    // getting the last node position
    curr->next = head2;      // making last node next to head2
    
    return head1;
}


int main() {
    int t;
    cin>>t;
    while(t--){
        int n1;
        cin>>n1;
        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 0; i < n1-1; ++i){
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }
        
        int n2;
        cin>>n2;
        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for (int i = 0; i < n2-1; ++i){
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }
        
        Node * newHead=joinTheLists(head1,head2);
        displayList(newHead);
        cout<<endl;
    }

    return 0;
}