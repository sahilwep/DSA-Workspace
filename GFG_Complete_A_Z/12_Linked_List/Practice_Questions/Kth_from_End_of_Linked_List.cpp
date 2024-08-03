/*

// Kth from End of Linked List

// Observations: 
    * We have to remove node kth node from end of linked list..
    * Example:
                LL: 1->2->3->4->5->6->7->8->9       k = 2
                Output: 8 
                Explanation: 
                    * From last, if we count 2'nd node, we have 8

// Approach 1: 
    * We can use stack to solve this particular question...
    * Idea is to insert all the element into stack..
    * Once all the element is inserted we will pop(), every element & count for the position...
    * TC: O(N), AS: O(N)

// Approach 2: 
    * first we calculate the size of linked list..
    * Then we can subtract k from it, & add 1, because of addition start from 0...
    * then we return the value if it's falls in the range : else -1...
    * TC: O(N), AS: O(1)

*/


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

// Function to find the data of kth node from the end of a linked list.
class Solution {
  public:
    // Approach 1: Using stack
    int getKthFromLast_A1(Node *head, int k) {
        // first we use stack to store all the elements of linked list.
        stack<int> s;   
        Node *curr = head;
        while(curr != NULL){
            s.push(curr->data);
            curr = curr->next;
        }

        // once it's done, we pop() it out from stack & decrement the kth pointer, until it's become 1
        int n = s.size();
        int res;
        for(int i=0;i<n;i++){
            if(k == 1){
                res = s.top();
                break;
            }
            k--;
            s.pop();
        }

        // last we have to check whether the given position is appropiate or not, if the position is not appropiate, we return -1, : else we return the value...
        if(s.empty()){
            return -1;
        }
        return res;
    }
    // Approach 2: Using normal maths logic...
    int getKthFromLast_A2(Node *head, int k){
        // first we calculate the size of linked list
        Node *c = head;
        int size = 0;
        while(c != nullptr){
            size++;
            c = c->next;
        }
        // when pointer is more than the size of linked list
        if(k > size){
            return -1;
        }

        // we use maths logic to get the position of an element..
        int pos = size - k + 1;
        Node *curr = head;
        int res;
        while(curr != NULL){
            // when pos become 1, we return the value
            if(pos == 1){
                res = curr->data;
            }
            pos--;
            curr = curr->next;
        }
        return res; // at end we return the
    }

};


int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        int x;
        cin >> x;
        cin.ignore();

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }

        Solution ob;
        // cout << ob.getKthFromLast_A1(head, x) << endl;  // approach 1
        cout << ob.getKthFromLast_A2(head, x) << endl; // approach 2
    }
    return 0;
}