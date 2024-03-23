/*
// Insertion at the end of Doubly linked list:

    I/p : [10]<--->[20]<-->[30]
    data = 40;
    O/p : [10]<--->[20]<-->[30]<-->[40]


    I/p : NULL
    data = 40;
    O/p : [40]


// TC : O(n)

*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
    Node(int x){
        data = x;
        prev = next = NULL;
    }
};

void display(Node *head){
    if (head == NULL) return;
    cout << (head->data) << " ";
    display(head->next);
}

Node *insertEnd(Node *head, int x){
    Node *temp = new Node(x);   // creating dynamic node at random x position.
    // if there is no node, we return the allocated node as head.
    if(head == NULL) {
        return temp;
    }
    Node *curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
    temp->prev = curr;
    return head;
}

int main(void){
    Node *head = insertEnd(NULL, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);
    head = insertEnd(head, 50);

    display(head);

    return 0;
}