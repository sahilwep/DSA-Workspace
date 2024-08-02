/*
// Remove duplicates from a sorted linked list:


// To solve this question we have multiple approach: 
    // Approach 1:
        * We can use auxilary space array of size of unique element, i.e O(n) in worst case, when we have all unique elements...
        * Then we can iterate over the linked list & store the unique element, we can use set data structure in this case...
        * once we are done with storing unique elements, we can reinsert unique values into linked list...
        * at end we can return the head pointer of linked list...
        * Edge case: if the size of linked list & unique element is different, we have to explicitly make our last node element to NULL...
        * TC: O(n), AS: O(n)
    
    // Approach 2: 
        * We compare the adjacent nodes of linked list...
        * whenever we encounter with duplicate node, we delete that node...
        * TC: O(n), AS: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root){
    Node *temp = root;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

// Approach 1: using set data structure
Node* removeDuplicates_A1(Node *root){
    set<int> s; // set DS is used to store unique elements only
    // first we will store all the unique value into set..
    Node *curr1 = root; 
    while(curr1 != NULL){
        s.insert(curr1->data);
        curr1 = curr1->next;
    }

    // then we transfer unique value from set to linked list..
    int x = s.size();   // we use size that will help us to insert all the value...
    Node *curr2 = root;
    for(auto i : s){
        x--;    // every time size is decreased, this will protect our current node to set curr->next
        curr2->data = i;        // storing data from set to linked list node..
        if(x == 0) break;   // this condition break out, & protect current to set current->next..
        curr2 = curr2->next;
    }

    // after insertion remove extra occurring nodes...
    Node *temp = curr2->next;   // allocate next node reference in temp
    curr2->next = NULL; // making current->next = NULL, means we are making it last node..
    delete temp;    // finally deleting the temp reference..

    return root;    // last returning the root node to the parent call..
}

// Approach 2: Normal compare & delete method
Node *removeDuplicates(Node *head){
    Node *curr = head;
    // we are iterating with condition curr->next = NULL, because we can comparing two element curr & curr->next
    while(curr->next != NULL){
        // whenever we encounter with duplicate values..
        if(curr->data == curr->next->data){
            Node *temp = curr->next;    // storing the reference of curr->next, so that we can delete
            curr->next = curr->next->next;  // changing the curr->next reference to one after the curr->next, i.e curr->next->next
            delete temp;    // finally delete curr->next reference which is stored in temp..
            // we don't increment curr pointer to next, because we have to remove duplicate value, means it will execute until we have two unique values....
        }else{
            curr = curr->next;  // when we have unique values...
        }
    }

    return head;    // at last we return head...
}

int main(){
    int T;
    cin>>T; 
    while(T--){
        int K;
        cin>>K;
        Node *head = NULL;
        Node *temp = head;
        for(int i=0;i<K;i++){
        int data;
        cin>>data;
            if(head==NULL)
            head=temp=new Node(data);
            else{
                temp->next = new Node(data);
                temp=temp->next;
            }
        }

        // Node *result  = removeDuplicates_A1(head);  // approach 1 call
        Node *result  = removeDuplicates(head); // approach 2 call
        print(result);
        cout << endl;
    }

    return 0;
}