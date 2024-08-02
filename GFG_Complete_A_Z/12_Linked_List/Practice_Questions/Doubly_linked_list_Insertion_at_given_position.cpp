/*

// Doubly linked list insertion at given position: 

// Observations:
    * We are given pos, & x, which we have to insert in linked list...
    * We have to insert the node after the pos, which we have given...
    * NOTE: index is 0 based...

    x = 0, pos = 2
    0  1  2
    [] [] [] [*] [] []

// Intrusion: 
    * We need to take care of edge case like the last node
        * When we have to insert element at last node, we need to reference accordingly..
    * else when we are inserting before the last node, we have to connect both the nodes reference to allocated node...


*/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x){
        data = x;
        next = prev = NULL;
    }
};

// insert at given position x
void addNode(Node *head, int pos, int data){
    // first we will iterate till the position, & make our reference till there..
    if(head == NULL) return;    // when there is no node..
    int cnt = 0;
    Node *curr = head;
    while(cnt != pos){
        curr = curr->next;
        cnt++;
    }
    // at the end of iteration, we have to reference location where we need to allocate the new node...

    Node *allocateNode = new Node(data);    // allocate node

    // If we are at last node:
    if(curr->next == NULL){
        curr->next = allocateNode;
        allocateNode->prev = curr;
        allocateNode->next = NULL;
        return;
    }
    // else when we are at somewhere before the last last node..
    // fist we will connect recently allocate node with the curr & curr->next;
    allocateNode->next = curr->next;
    allocateNode->prev = curr;
    
    // then we will change the reference of curr & curr->next to allocatedNode
    curr->next->prev = allocateNode;
    curr->next = allocateNode;
}


// Insert at the end of linked list
Node *insert(Node *head, int x){
    if(head == NULL){
        return new Node(x);
    }
    Node *n = new Node(x);

    head->next = n;
    n->prev = head;
    head = n;
    return head;
}

// forward Iterations: 
void printList(Node *head){
    if(head == NULL){
        return;
    }else{
        cout << head->data << " ";
        printList(head->next);
    }
}



int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        Node *head = NULL; 
        Node *root = NULL;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
           int x;
           scanf("%d",&x);
           head = insert(head, x);
           if(root==NULL) root = head;
        }     
        head = root;
        int pos,data;
        cin>>pos>>data;
        addNode(head, pos, data);
        printList(head);
    }
    return 0;
}