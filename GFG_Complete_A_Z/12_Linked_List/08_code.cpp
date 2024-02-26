/*
// Delete at the end of singly linked list : 


// Approach : 
    * iterate to the last element, store that reference & then delete that last element.

// Time Complexity : O(n)


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

Node *deleteEnd(Node *head){
    if(head == NULL) return NULL;
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node *curr = head;
    while(curr->next->next != NULL){
        curr = curr->next;
    }
    Node *temp = curr->next;
    curr->next = NULL;
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

    head = deleteEnd(head);
    head = deleteEnd(head);

    cout << endl;
    display(head);

    return 0;
}