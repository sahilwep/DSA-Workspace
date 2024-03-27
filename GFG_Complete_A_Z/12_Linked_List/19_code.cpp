/*
// Delete last node of doubly linked list.

          head
    I/p : [10]<--->[20]<-->[30]
    O/p : [10]<--->[20]

    I/p : NULL
    O/p : NULL

    I/p : [10]
    O/p : NULL

    // TC: O(n)

*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next, *prev;
    Node(int x){
        data = x;
        next = prev = NULL;
    }
};

Node *insertBeg(Node *head, int x){
    Node *temp = new Node(x);
    if(head == NULL){
        return temp;
    }
    temp->next = head;
    head->prev = temp;
    return temp;
}

void display(Node *head){
    if (head == NULL) return;
    cout << head->data << " ";
    display(head->next);
}

Node *deleteEnd(Node *head){
    if(head == NULL) return NULL;
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node *curr = head;
    while(curr->next != NULL) curr = curr->next;    // this will move pointer at the last node

    curr->prev->next = NULL;
    delete curr;
    return head;
}

int main(void){

    Node *head = insertBeg(NULL, 40);
    head = insertBeg(head, 30);
    head = insertBeg(head, 20);
    head = insertBeg(head, 10);

    display(head);
    cout << endl;
    
    head = deleteEnd(head);

    display(head);

    return 0;
}