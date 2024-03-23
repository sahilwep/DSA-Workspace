/*

// Singly Linked list with whole Operations: 

// Operations : 
    * insertBeg : TC -> O(1)
    * insertEnd : TC -> O(n)
    * DeleteBeg : TC -> O(1)
    * DeleteEnd : TC -> O(n)
    * traversal : TC -> O(n)

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
    return temp;
}

Node *insertEnd(Node *head, int x){
    Node *temp = new Node(x);
    if(head == NULL) return temp;
    Node *curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

Node *deleteEnd(Node *head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node *curr = head;
    while(curr->next->next != NULL){
        curr = curr->next;
    }
    delete curr->next;
    curr->next = NULL;
    return head;
}

Node *deleteBeg(Node *head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

void display(Node *head){
    if(head == NULL) return;
    cout << (head->data) << " ";
    display(head->next);
}



int main(void){
    Node *head = new Node(30);
    head = insertBeg(head, 20);
    head = insertBeg(head, 10);
    
    head = insertEnd(head, 40);
    head = insertEnd(head, 50);

    display(head);
    
    head = deleteEnd(head);
    head = deleteBeg(head);

    cout << endl;
    display(head);

    return 0;
}