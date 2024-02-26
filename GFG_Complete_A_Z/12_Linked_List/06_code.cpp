/*
// Insert at the end of singly linked list : 


// Approach : 
    * create a node & assign value to it.
    * make a iterator & iterate it till last element reference.
    * assign temp to last of the node.
    * Edge case : when there is no node present, we will return new node only.


// TC : O(n)
    * as we have to iterate till last element.


*/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

void display(Node *head){
    if(head == NULL) return;
    cout << head->data << " ";
    display(head->next);
}

Node *insertEnd(Node *head, int x){
    Node *temp = new Node(x);
    if(head == NULL){
        return temp;
    }
    Node *curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

int main(void){

    Node *head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);
    head = insertEnd(head, 50);

    display(head);

    return 0;
}
