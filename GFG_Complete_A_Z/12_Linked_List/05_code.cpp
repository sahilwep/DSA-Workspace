/*
// insertion at the beginning of singly linked list : 

// Approach : 
    * We will create a Node (say temp)& assign value in it...
    * if (head == NULL) return newly created node as new Head.
    * else :
        * temp->next = head // linking temp to head
        * head = temp   // now new head will be temp
        * return head   // returning new head.

// time Complexity : O(1)
    * as we insert in head of linked list.

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

Node *insertBeg(Node *head, int x){
    Node *temp = new Node(x);
    if(head == NULL){
        return temp;
    }
    temp->next = head; 
    head = temp;
    return head;
}

void display(Node *head){
    if(head == NULL) return;
    cout << head->data << " ";
    display(head->next);
}

int main(void){
    Node *head = NULL;
    head = insertBeg(head, 50);
    head = insertBeg(head, 40);
    head = insertBeg(head, 30);
    head = insertBeg(head, 20);
    head = insertBeg(head, 10);
    
    display(head);

    return 0;
}