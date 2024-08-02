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
Node* removeDuplicates(Node *root){
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

        Node *result  = removeDuplicates(head);
        print(result);
        cout<<endl;
    }

    return 0;
}