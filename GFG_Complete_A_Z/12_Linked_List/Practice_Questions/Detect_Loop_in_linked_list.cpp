/*

// Detect Loop in linked list

// Observations: 
    * We are given singly linked list, we need to find whether the linked list contains loop or not?

// Example: 
    Input: LinkedList: 1->3->4, pos = 2
    Output: true
    Explanation: See the above list there exists a loop connecting the last node back to the second node.

    Input: LinkedList: 1->8->3->4, pos = 0
    Output: false
    Explanation: There is no loop exists.

    Input: LinkedList: 1->2->3->4, pos = 1
    Output: true
    Explanation: A loop is present connecting the last node back to the first node.

// Intrusion: 
    * for finding loop, if we revisit the same node again, we can say loop exist..
    * We can use hashing approach...
    * We can use map data structure...
    * we can hash every node, & while hashing if we revisit that node, again, we return 1, else return 0


*/

#include <bits/stdc++.h>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void loopHere(Node* head, Node* tail, int position) {
    if (position == 0)
        return;

    Node* walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}


class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        if(head == NULL) return 0;
        else if(head->next == NULL) return 0;
        else if(head->next == head) return 1;

        unordered_map<Node *, int> mp;
        bool isLoop = 0;
        for(Node *i=head;i!=NULL;i=i->next){
            // if the node is going to hashed again, that's means we have loop...
            if(mp[i] == 1){
                isLoop = 1;
                break;
            }
            mp[i]++;    // hashing each node at every iterations...
        }
        if(!isLoop){
            return 0;
        }else{
            return 1;
        }

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

        while (ss >> number) {
            arr.push_back(number);
        }

        int pos;
        cin >> pos;
        cin.ignore();

        Node* head = nullptr;
        Node* tail = nullptr;

        if (!arr.empty()) {
            head = new Node(arr[0]);
            tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
            loopHere(head, tail, pos);
        }

        Solution ob;
        if (ob.detectLoop(head))
            cout << "true\n";
        else
            cout << "false\n";

        // Free the allocated memory
        unordered_set<Node *> visited;

        Node* current = head;
        while (current && visited.find(current) == visited.end()) {
            visited.insert(current);
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    return 0;
}