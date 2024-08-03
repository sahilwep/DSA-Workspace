/*
// Is linked list Sorted
    * We have to check if linked list is sorted in ascending or descending order or not?
    * If it's sorted in any fashion we return 1 : else return 0


// Intrusion: 
    * First we check ascending order, then we check descending order, if both fails then return 0 : else return 1
*/
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node (int x){
        data = x;
        next = NULL;
    }
};

void displayList(Node *head){
    if(head != NULL){
        cout << head->data << " ";
        displayList(head->next);
    }
}

bool isSorted(Node * head){
    if(head == NULL) return 1;  // when we have no values
    if(head->next == NULL) return 1;    // when we have single value
    if(head->next->next == NULL) return 1;  // when we have 2 value

    // checking ascending sorting
    bool isSortedAsc = 1;
    Node *curr = head;
    while(curr->next != NULL){
        if(curr->data > curr->next->data){
            isSortedAsc = 0;
        }
        curr = curr->next;
    }

    // checking descending sorting: 
    bool isSortedDes = 1;
    Node *curr1 = head;
    while(curr1->next != NULL){
        if(curr1->data < curr1->next->data){
            isSortedDes = 0;
        }
        curr1 = curr1->next;
    }

    // Now at last we are comparing both the data
    if(isSortedAsc == 0 && isSortedDes == 0) return 0;
    return 1;
}

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < n-1; ++i){
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        cout<<isSorted(head) << endl;
    }
    return 0;
}