/*

// Delete without head pointer: 

// Observations: 
    * We are given not given the head of linked list...
    * We are given the node of linked list that we have to delete...

// Example


    Input:
        Linked List = 1 -> 2
        del_node = 1
    Output: 2
    Explanation: 
        After deleting 1 from the linked list, 
        we have remaining nodes as 2.


    Input:
        Linked List = 10 -> 20 -> 4 -> 30
        del_node = 20
    Output: 
        10 4 30
    Explanation: 
        After deleting 20 from the linked list, 
        we have remaining nodes as 10, 4, 30.


// How to delete the node when you dont have the head pointer?
    * The trick here is we can copy the data of the next node to the data field of the current node to be deleted.
    * Then we can move one step forward.
    * Now our next has become the current node and the current has become the previous node. 
    * Now we can easily delete the current node by conventional deletion methods. 

// In simple word we can say:
    * We are not deleting the current given node, but we are deleting the current next node..
    * we are copying the current->next->data to the current node data i.e curent->data
    * now we are one step previous the node that we have to delete...
    * we can simply delete current next the node by creating a temporary node reference..
    * but before we have to connect curr->next with curr->next->next
    * then we can simply delete the curr->next, i.e the temporary node reference that we have created recently...

// TC: O(1)

*/


#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;

class Solution{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del_node){
        del_node->data = del_node->next->data;  // copying the next node data into current node..
        Node *temp = del_node->next;    // we can create a reference of current->next node..
        del_node->next = del_node->next->next;  // merging del_node->next with next to next node to it..
        delete temp;    // Now we can delete the curr->next i.e temp node in our case...
    }
};

Node *findNode(Node* head, int search_for){
    Node* current = head;
    while (current != NULL){
        if (current->data == search_for)
            break;
        current = current->next;
    }
    return current;
}


void insert(){
    int n,i,value;
    Node *temp;
    scanf("%d",&n);

    for(i=0; i<n; i++){
        scanf("%d",&value);
        if(i==0){
            head=new Node(value);
            temp=head;
            continue;
        }
        else{
            temp->next= new Node(value);
            temp=temp->next;
            temp->next=NULL;
        }
    }
}

/* Function to print linked list */
void printList(Node *node){
    while (node != NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

int main(void){
    int t,k,n,value;
    
    scanf("%d",&t);
    while(t--){
        insert();
        scanf("%d",&k);
        Node *del = findNode(head, k);
        Solution ob;
        if (del != NULL && del->next != NULL){
            ob.deleteNode(del);

        }
        printList(head);
    }
    return(0);
}