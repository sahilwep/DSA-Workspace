/*

// Display linked list: 

// Observations: 
    * we have to store each elements of linked list into vector & return it the the parent function call...


// Time complexity: O(n)

*/

#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

// function to display data of linked list.
vector<int> displayList(Node *head){
    vector<int> res;
    Node *curr = head;
    while(curr != NULL){
        res.push_back(curr->data);
        curr = curr->next;
    }

    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int data;
        cin>>data;
        Node *head = new Node(data);
        Node *tail = head;
        for (int i = 0; i < n-1; ++i){
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        vector<int> list = displayList(head);
        for(int x : list){
            cout<<x<<" ";
        }
        cout << endl;
    }
    return 0;
}