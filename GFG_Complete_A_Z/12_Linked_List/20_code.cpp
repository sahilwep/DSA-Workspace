/*
// Circular Linked List: 
    * End node is connected to the head node.

         [20]->[30]->[40]------>[20]    
         head        tail       head


*/

#include<bits/stdc++.h>
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
    cout << head->data << " ";
    Node *curr = head->next;
    while(curr != head){
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main(void){

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = head;

    display(head);

    return 0;
}
