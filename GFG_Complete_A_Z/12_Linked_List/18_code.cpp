/*
// Delete head of Doubly linked list: 

    I/p : [10]<--->[20]<-->[30]
    O/p : [30]<-->[40]


    I/p : NULL
    O/p : NULL

    I/p : [10]
    O/p : NULL

    // TC : O(1)
    

*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *prev;
    Node *next;
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
    if (head == NULL)  return;
    cout << head->data << " ";
    display(head->next);
}

Node *deleteBeg(Node *head){
    if(head == NULL){
        return NULL;
    }
    if (head->next == NULL){
        delete head;
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

int main(void){

    Node *head = insertBeg(NULL, 40);
    head = insertBeg(head, 30);
    head = insertBeg(head, 20);
    head = insertBeg(head, 10);
    head = insertBeg(head, 5);

    display(head);
    cout << endl;

    head = deleteBeg(head);

    display(head);
    cout << endl;

    head = deleteBeg(head);

    display(head);
    cout << endl;

    return 0;
}