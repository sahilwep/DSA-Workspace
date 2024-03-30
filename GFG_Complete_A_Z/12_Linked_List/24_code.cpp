/*
// Insert End of Circular linked list: 

        head                            head
    I/p : [10]-->[30]-->[20]---circ------>[10]
    x = 15
          head                 End                head
    O/p : [10]-->[30]-->[20]-->[15]----circ----->[10]

    
    I/p : NULL
    x = 10
          head          head
    O/p : [10]----circ----->[10]


    I/p : [10]
    x = [20]
          head   end         head
    O/p : [10]-->[20]------->[10]

// Naive Solution: 
    * iterate to the element before the head location
    * Insert the node & connect it to the head
    * TC:  O(n)

// Efficient Solution: 
    * Allocate temp node
    * connect that node to head->next
    * swap the values of temp->data & head->data
    * return temp as new head..
    * O(1)
*/

#include<bits/stdc++.h>
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
    cout << head->data << " ";
    Node *curr = head->next;
    while(curr != head){
        cout << curr->data << " ";
        curr = curr->next;
    }
}

// Efficient Solution: TC : O(1)
Node *insertEnd(Node *head, int x){
    Node *temp = new Node(x);
    if(head == NULL){
        temp->next = temp;
        return temp;
    }
    // inserting the nodes:
    temp->next = head->next;
    head->next = temp;
    // swapping the values:
    int temp_data = temp->data;
    temp->data = head->data;
    head->data = temp_data;
    return temp;    // returning temp will make it's as new head, which will make our previous head as end node.
}

// Naive Solution: TC : O(n)
Node *insertEnd_(Node *head, int x){
    Node *temp = new Node(x);   // allocating temp node.
    // checking the condition where if the head is empty.
    if(head == NULL){
        temp->next = temp;  // making temp node as circular link list.
        return temp;    // returning the temp as head
    } 
    Node *curr = head->next;    // making iterator
    while(curr->next != head){
        curr = curr->next; 
    }
    temp->next = head;  // adding the temp->next as the head, which help temp node to make itself as end node.
    curr->next = temp;  // now connecting the (iterator)curr->next to the temp node
    return head;    // returning the head as our original head.
}

int main(void){

    Node *head = insertEnd(NULL, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);

    display(head);

    return 0;
}

