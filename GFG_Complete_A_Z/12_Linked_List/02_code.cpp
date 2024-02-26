/*
// Linked list Implementation : 

*/

#include <bits/stdc++.h>
using namespace std;

// Node Structure
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
    cout << (head->data) << " ";
    display(head->next);
}

int main(void){
    // Creating of nodes : 
    
    Node *head = new Node(10);
    Node *head1 = new Node(20);
    Node *head2 = new Node(30);
    Node *head3 = new Node(40);

    // Linking of node : 

    head->next = head1;
    head1->next = head2;
    head2->next = head3;

    display(head);

    return 0;
}