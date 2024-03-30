/*
// Delete the head of circular linked list: 


          head                            head
    I/p : [10]-->[30]-->[20]---circ------>[10]
          head                 End                head
    O/p : [30]-->[20]----circ----->[30]

    
    I/p : NULL
    O/p : NULL


    I/p : [10]
    O/p : NULL

// Naive solution takes O(n), Not going to implement, same as we insert....

// Efficient Solution: 
    * Store the head->next->data into some temp_data variable
    * Delete the head->next, & link head->next to head->next->next
    * update the head->date as temp_data
            [10]-->[30]-->[20]---circ------>[10]        data
            [10]-->[20]---circ------>[10]               delete the second node
            [30]-->[20]---circ------>[20]               update the head
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


Node *insertBeg(Node *head, int x){
    Node *temp = new Node(x);
    if(head == NULL){
        temp->next = temp;
        return temp;
    }
    // linking: 
    temp->next = head->next;    
    head->next = temp;  

    // swapping: 
    int head_data = head->data; 
    head->data = temp->data;
    temp->data = head_data;
    return head;
}

void display(Node *head){
    cout << head->data << " ";
    Node *curr = head->next;
    while(curr != head){
        cout << curr->data << " ";
        curr = curr->next;
    }
}

// Efficient Solution: O(1)
Node *deleteBeg(Node *head){
    if(head == NULL) return NULL;
    if(head->next == head){
        delete head;
        return NULL;
    }
    int temp_data = head->next->data;
    Node *temp = head->next;
    head->next = head->next->next;
    delete temp;
    head->data = temp->data;
    return head;
}

int main(void){
    Node *head = insertBeg(NULL, 40);
    head = insertBeg(head, 30);
    head = insertBeg(head, 20);
    head = insertBeg(head, 10);

    display(head);
    cout << endl;

    head = deleteBeg(head);

    display(head);

    return 0;

}