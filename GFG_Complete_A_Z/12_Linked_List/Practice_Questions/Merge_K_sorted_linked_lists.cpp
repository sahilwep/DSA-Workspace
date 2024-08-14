/*
//  Merge K sorted linked lists

// Observations: 
    * we are given an array that contains multiple linked list, which are sorted in ordre..
    * We have to get all the data from it & make it one.
    * At last we have to return the linked list..


// Intrusion:


*/

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


class Solution {
  public:
    // Function to merge K sorted linked list.
    Node* mergeKLists(vector<Node*>& arr) {
        Node *curr = arr[0];
        for(int i=0;i<arr.size();i++){
            if(arr[i]->next == NULL){
                
            }
        }
    }
};


int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<Node*> arr;
        vector<int> nums;
        string input;

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            nums.push_back(number);
        }
        int ind = 0;
        int N = nums.size();

        while (ind < N) {
            int n = nums[ind++];
            int x = nums[ind++];
            Node* head = new Node(x);
            Node* curr = head;
            n--;

            for (int i = 0; i < n; i++) {
                x = nums[ind++];
                Node* temp = new Node(x);
                curr->next = temp;
                curr = temp;
            }
            arr.push_back(head);
        }

        Solution obj;
        Node* res = obj.mergeKLists(arr);
        printList(res);
    }
    return 0;
}