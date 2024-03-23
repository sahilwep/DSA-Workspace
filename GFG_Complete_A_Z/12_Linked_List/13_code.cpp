/*
// Doubly Linked List: 
    * Doubly linked list contains of address of previous & next Nodes.

    NULL<----[add | value | add]<-->[add | value | add]<-->[add | value | add]--->NULL
    
    // Example: 
            NULL<----[NULL | 10 | 2001]<-->[1002 | 20 | 3001]<-->[2001 | 30 | NULL]--->NULL
    address:                 1002                   2001                    3001

*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int x){
        data = x;
        prev = next = NULL;
    }
};

void display_front(Node* head){
    if (head == NULL) return;
    cout << (head->data) << " ";
    display_front(head->next);

}

void display_back(Node* tail){
    if (tail == NULL) return;
    cout << (tail->data) << " ";
    display_back(tail->prev);

}



int main(void){
    // allocation of nodes:
    Node* head = new Node(10);
    Node* first_node = new Node(20);
    Node* sec_node = new Node(30);
    Node* third_node = new Node(40);
    Node* tail = new Node(50);

    // linking of nodes:
    head->next = first_node;
    first_node->prev = head;

    first_node->next = sec_node;
    sec_node->prev = first_node;

    sec_node->next = third_node;
    third_node->prev = sec_node;

    third_node->next = tail;
    tail->prev = third_node;

    // traversal:
    display_front(head);
    cout << "\n";
    display_back(tail);

    return 0;
}
