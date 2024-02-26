/*

// Deletion at the given position of singly linked list : 

// Approach : 
    * same as we used in insertion at given position.
    * Note : after iteration of curr pointer, we have to check for the condition : 
        * if the curr is NULL || curr->next == NULL, we will return head.
        
         
// TC : O(n)

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

Node *deleteAtGiven(Node *head, int pos){
    if(pos == 1){
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    // iteration to the position before the node, that we have to delete.
    Node *curr = head;
    for(int i=1;i<=(pos-2) && (curr != NULL);i++){
        curr = curr->next;
    }
    // if deletion is outside of last node : 
    if(curr == NULL) return head;   // edge case : for position outer than the last node reference
    if(curr->next == NULL) return head; // edge case : for position just after the last node.

    // deletion of the node : 
    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;

    return head;
}

int main(void){

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);

    display(head);

    int pos = 8;
    head = deleteAtGiven(head, pos);

    cout <<endl;
    display(head);

    return 0;
}