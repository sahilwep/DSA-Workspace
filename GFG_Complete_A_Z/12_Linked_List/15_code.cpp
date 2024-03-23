/*
// Insert at the beginning of doubly linked list: 

    I/p : [10]<--->[20]<-->[30]
    data = 5;
    O/p : [5]<-->[10]<--->[20]<-->[30]


    I/p : NULL
    data = 5;
    O/p : [5]

// TC : O(1)


*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
    Node(int x){
        data = x;
        next = prev = NULL;
    }
};

Node *insertBeg(Node *head, int x){
    Node *temp = new Node(x);   // creation of dynamic node named temp at any x location.
    temp->next = head;  // linking temp node with head node
    // if head node is not the null value.
    if(head != NULL){
        head->prev = temp;
    }
    return temp;    // return temp as our new head.
}

void display(Node *head){
    if(head == NULL) return;
    cout << (head->data) << " ";
    display(head->next);
}

int main(void){

    Node* head = insertBeg(NULL, 50);   // creation of first node(Note the parameter for head should be null because there is no first node available.)
    head = insertBeg(head, 30);
    head = insertBeg(head, 20);
    head = insertBeg(head, 10);

    display(head);

    return 0;
}
