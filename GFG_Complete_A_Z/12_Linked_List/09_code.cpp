/*
// Insert at the given position in singly linked list : 



// case : 

    I/p : 10-->20-->30-->40 
          1    2    3    4
    
        pos = 2
        data = 15

    O/p : 10-->15-->20-->30 
    


    I/p : 10-->20-->30-->40 
          1    2    3    4
   
        pos = 5 is outside the last node.
        data = 15

    O/p : 10-->15-->20-->30-->15
    


    I/p : 10-->20 
          1    2 

        pos = 4, as the location is 4 & we only have 2 element, so we can't insert, we just return the list.
        data = 5

    O/p : 10-->20


// Observations : 

    pos = 4, data = 45

            head
             |
            [10]-->[20]-->[30]-->[40]-->[50]
              1     2      3      4      5
        * as head at 10 and we need to iterate only till 3 so that we can have the reference of 3, because after 3 we will insert our desired node.
        * so, we will iterate only (pos-2) time.


                         current
                            |
            [10]-->[20]-->[30]-->[40]-->[50]
              1     2      3      4      5
                             [45]
                             temp
                        
        * after getting the reference we will first link temp->next wih curr->next,
        * because if we link curr->next = temp, then we will loose the reference of nodes that are after the curr nodes.
        
                temp->next = curr->next
                curr->next = temp;



// Time complexity : 
    * as we are iterating to the last in worst case, the time complexity will be O(n),

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

void display(Node *head){
    if(head == NULL) return;
    cout << head->data << " ";
    display(head->next);
}

Node *insertAtGiven(Node *head, int x, int pos){
    Node *temp = new Node(x);
    if(pos == 1){
        temp->next = head;
        return temp;
    }
    // iteration case : 
    Node *curr = head;
    for(int i=1;i<=(pos-2) && (curr != NULL);i++){
        curr = curr->next;
    }
    // edge case : when insertion is outside of the last node.
    if(curr == NULL) return head;

    // insertion that node : 
    temp->next = curr->next;
    curr->next = temp;

    return head;
}

int main(void){

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);

    display(head);

    int pos = 4;
    head = insertAtGiven(head, 999, pos);

    cout << endl;
    display(head);
    
    return 0;
}