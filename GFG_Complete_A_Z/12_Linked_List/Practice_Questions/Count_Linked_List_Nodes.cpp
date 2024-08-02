/*
// Count Linked list Nodes:

// Intrusion: 
    * We can make the make a variable count & iterate over the linked list...


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


class Solution{
public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head){
        if(head == NULL) return 0;
        int cnt = 0;
        Node *curr = head;
        while(curr != NULL){
            cnt++;
            curr = curr->next;
        }
        return cnt;
    }
};


int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // insertion of values into vector..
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // formation of linked list
        struct Node *head = new Node(arr[0]);   // allocation of head node, with first value of an array...
        struct Node *tail = head;   // tail will reference head...
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);  // allocation of node into tail->next, by inserting values of array...
            tail = tail->next;  // updating current tail to tail->next...
        }

        // calling for size of linked list
        Solution ob;
        cout << ob.getCount(head) << endl;
    }
    return 0;
}