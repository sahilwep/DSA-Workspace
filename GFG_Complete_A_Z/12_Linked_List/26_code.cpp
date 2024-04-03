/*
// Delete Kth node of circular linked list : must visit


          head                            head
    I/p : [10]-->[30]-->[20]---circ------>[10]
          head                 End                head
          k = 2;
    O/p : [10]-->[20]---circ------>[10]


          head                            head
    I/p : [10]-->[30]-->[20]---circ------>[10]
          head                 End                head
          k = 1;
    O/p : [30-->[20]---circ------>[30]


    I/p : [10]
    k = 1
    O/p : NULL


// TC : O(n)

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

void display(Node *head){
    cout << head->data << " ";
    Node *curr = head->next;
    while(curr != head){
        cout << curr->data << " ";
        curr = curr->next;
    }
}

Node *deleteKth(Node *head, int k){
      if(head == NULL) return NULL;
      if(k == 1){
            return deleteBeg(head);
      }
      Node *curr = head;
      for(int i=0;i<(k-2);i++){
            curr = curr->next;
      }
      Node *temp = curr->next;
      curr->next = curr->next->next;
      delete temp;
      return head;
}

int main(void){

    int k;
    cin >> k;

    Node *head = insertBeg(NULL, 40);
    head = insertBeg(head, 30);
    head = insertBeg(head, 20);
    head = insertBeg(head, 10);

    display(head);

    head = deleteKth(head, k);
    cout << endl;
    display(head);
    return 0;
}