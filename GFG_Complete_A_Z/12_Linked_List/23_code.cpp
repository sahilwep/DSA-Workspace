/*
// Insert beg of circular linked list: 

          head                            head
    I/p : [10]-->[30]-->[20]---circ------>[10]
    x = 15
          head                                   head
    O/p : [15]-->[10]-->[30]-->[20]----circ----->[15]

    
    I/p : NULL
    x = 10
          head          head
    O/p : [10]----circ----->[10]


    I/p : [10]
    x = [20]
          head               head
    O/p : [20]-->[10]------->[20]

// Naive solution: 
    * TC : O(n)

// Optimal solution:
        head                          head
        [10]-->[15]-->[10]-->[7]----->[10]

        * insert the node temp after head
        * swap the value of temp & head
        * return the head



                [10]-->[15]-->[10]-->[7]----->[10]

        temp node   [99]
                
                [10]-->[99]-->[15]-->[10]-->[7]----->[10]

                swap head, & head->next

                [99]-->[10]-->[15]-->[10]-->[7]----->[99]


    * TC : O(1)
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
    for(Node *curr = head->next;curr != head;curr = curr->next){
        cout << curr->data << " ";
    }
}

// Naive solution: 
Node *insertBeg_(Node *head, int x){
    Node *temp = new Node(x);
    if(head == NULL){
        temp->next = temp;
    } else {
        Node *curr =  head;
        while(curr->next != head){
            curr = curr->next;
        }
        curr->next = temp;
        temp->next = head;
    }
    return temp;
}

// Optimal solution: 
Node *insertBeg(Node *head, int x){
    Node *temp = new Node(x);
    if (head == NULL){
        temp->next = temp;
        return temp;
    }
    // connecting nodes.
    temp->next = head->next;    // connecting node of temp->next = head->next.
    head->next = temp;  // connecting head to temp.

    // storing the value inside the temp variable.
    int head_data = head->data; // storing the head data into the head variable
    
    // assigning values into the nodes:
    head->data = temp->data;
    temp->data = head_data;
    return head;
}

int main(void){

    Node *head = insertBeg(NULL, 10);
    head = insertBeg(head, 20);
    head = insertBeg(head, 30);
    head = insertBeg(head, 40);
    head = insertBeg(head, 50);

    display(head);

    return 0;
}