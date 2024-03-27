/*
// Reverse Doubly Linked list: 

          head
    I/p : [10]<--->[20]<-->[30]
    O/p : [20]<--->[20]<-->[10]

    I/p : NULL
    O/p : NULL

    I/p : [10]
    O/p : [10]

    // TC: O(n)

*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next, *prev;
    Node(int x){
        data = x;
        prev = next = NULL;
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

Node *reverseList(Node *head){
    Node *prev = NULL;
    Node *curr = head;
    while(curr != NULL){
        // swapping curr->prev with curr->next
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        curr = curr->prev;
    }
    return prev->prev;
}

int main(void){

    Node *head = insertBeg(NULL, 40);
    head = insertBeg(head, 30);
    head = insertBeg(head, 20);
    head = insertBeg(head, 10);

    display(head);
    cout << endl;

    head = reverseList(head);

    display(head);

    return 0;
}