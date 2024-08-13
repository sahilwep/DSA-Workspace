/*

// Pairwise swap of nodes in LinkedList

// Observations: 
    * we are given a singly linked list, we need to perform pair wise swap...
    * For even number of Nodes: 
        * we swap every value pairwise
        * for odd number of nodes, we left last value.

// Intrusion:
    * first we get the size of linked list..
    * Once we have size, we can swap two consecutive elements of linked list..
    * at last we return the head pointer..


*/

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

//Function to swap elements pairwise.
struct Node* pairwise_swap(struct Node* head){
    // common cases: 
    if(head == NULL) return NULL;
    if(head->next == NULL) return head;
    if(head->next->next == NULL){
        swap(head->data, head->next->data);
        return head;
    }
    // finding size: 
    int size = 0;
    Node *curr = head;
    while(curr != NULL){
        size++;
        curr = curr->next;
    }
    // swapping pair wise: 
    Node *c1 = head;
    for(int i=0;i<size-1;i+=2){
        swap(c1->data, c1->next->data);
        c1 = c1->next->next;
    }

    return head;
}

void printList(struct Node* node) { 
    while (node!=NULL) { 
        printf("%d ", (node)->data); 
        node = (node)->next; 
    } 
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n, l,firstdata;
        cin>>n;
        // taking first node of linked list
        cin>>firstdata;
        struct Node* head = new Node(firstdata);
        struct Node* tail = head;
        // taking remaining nodes of linked list
        for(int i = 1; i < n; i++){
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        head =pairwise_swap(head);
        printList(head);
        cout << endl;
    }
}