/*
// Deletion at the beginning of singly linked list : 

// Approach : 
    * store the reference of head into any other node (say temp)
    * make new head = head->next
    * delete temp
    * return head
    
// Time Complexity : O(1)
    * as we are doing constant operations.

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
    cout << (head->data) << " ";
    display(head->next);
}

Node *deleteBeg(Node *head){
    if(head == NULL) return NULL;
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node *temp = head;
    head = head->next;
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

    head = deleteBeg(head);
    head = deleteBeg(head);

    cout << endl;
    display(head);

    return 0;
}