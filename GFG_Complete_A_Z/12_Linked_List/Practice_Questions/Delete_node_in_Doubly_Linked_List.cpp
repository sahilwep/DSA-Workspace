/*

//  Delete node in Doubly Linked List
    * We are given the position oof doubly linked list, and we have to delete that node...

    x = 4;
    []<->[]<->[]<->[*]<->[]<->[]
                    |
                    we have to remove this...

// Observations: 
    * While deleting nodes at specific location we have to take care of certain things..
        * If there is linked list with no nodes in it..
        * If we are given the position which is grater than the linked list size
        * If we are deleting the head node..
        * If we are deleting the last node..
    * These are some cases that we have to explicitly define..


*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
  public:
    // function to remove node from doubly linked list:
    Node* deleteNode(Node* head, int x) {
        if(head == NULL) return NULL;   // if there no nodes in linked list...
        // If we have to delete first node, x = 1
        if(x == 1){
            Node *temp = head;  // storing the reference of head, so that we can delete it..
            head = head->next;  // changing the head reference to head->next
            head->prev = NULL;  // making head previous reference as NULL
            delete temp;    // last we delete the original head...
            return head;
        }
        // Else for other nodes: We have to iterate over the linked list & found the position where we have to delete...
        Node *curr = head;
        while(curr->next != NULL){
            if(x == 1) break;   // if position become 1 we will break out from the iteration..
            x--;    // at every iteration we are subtracting the pos..
            curr = curr->next;
        }

        // edge case: when x is grater than the linked list size...
        if(curr->next == NULL && x > 1){
            return head;    // when th given position are grater than the linked list size.
        }
        // when we have to delete the last node of linked list...
        if(curr->next == NULL){
            Node *temp = curr;
            curr->prev->next = NULL;
            delete temp;
            return head;
        }
        // when we have to delete any node b/w the head & tail..
        Node * temp = curr->prev;   // allocate that node into temp..
        temp->next = curr->next;    // changing the reference of next..
        curr->next->prev = temp;    // changing the next->prev to newly allocated node..
        delete curr;    // delete the current reference...

        return head;    // return the head.
    }
};

void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    int t, x, n, i;
    scanf("%d", &t);

    while (t--) {
        struct Node *temp, *head = NULL;
        scanf("%d", &n);

        temp = NULL;

        for (i = 0; i < n; i++) {
            scanf("%d", &x);

            if (head == NULL) {
                head = new Node(x);
                temp = head;
            } else {
                Node *temp1 = new Node(x);
                temp->next = temp1;
                temp1->prev = temp;
                temp = temp->next;
            }
        }

        scanf("%d", &x);

        Solution ob;
        head = ob.deleteNode(head, x);

        printList(head);
        while (head->next != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }

        free(head);
    }
    return 0;
}