/*
// Circular Doubly Linked list: 
    * In circular doubly linked list, it is similary as doubly linked list, just end node is connected to first node & first node is connected to end node.


         head                               head
    I/p : [10]<-->[30]<-->[20]<---circ------>[10]


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

// Display using next node: 
void display_next(Node *head){
    cout << head->data << " ";
    Node *curr = head->next;
    while (curr != head){
        cout << curr->data << " ";
        curr = curr->next;
    }
}

// Display using prev node: 
void display_prev(Node *head){
    Node *curr = head->prev;
    cout << curr->data << " ";
    curr = curr->prev;
    while(curr != head){
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << head->data << " ";
}

int main(void){

    // creation of Nodes:
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(30);
    Node *end = new Node(40);

    // Linking of Nodes:
        // next:
        head->next = second;
        second->next = third;
        third->next = fourth;
        fourth->next = end;
        end->next = head;
        // prev:
        head->prev = end;
        end->prev = fourth;
        fourth->prev = third;
        third->prev = second;
        second->prev = head;

    // display nodes: 
    display_next(head);
    cout << endl;
    display_prev(head);

    return 0;
}