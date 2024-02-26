/*
// Traversing in singly linked list  :

// Approach : 
    * We need to to start from head node, and go till head != NULL


// Iterative solution : TC : O(n)  AS : O(1)
// Recursive Solution : TC : O(n), AS : O(n) 

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

// Iterative traversal : 
void display(Node *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

// Iterative traversal : 
void display_1(Node *head){
    for(Node *i = head;i!= NULL;i=i->next){
        cout << i->data << " ";
    }
}

// Recursive traversal : 
void display_2(Node *head){
    if(head == NULL) return;
    cout << head->data << " ";
    display_2(head->next);
}

int main(void){

    // Creation & linking of nodes.
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    // Traversal function calls : 
    display(head);
    cout << endl;
    display_1(head);
    cout << endl;
    display_2(head);

    return 0;
}