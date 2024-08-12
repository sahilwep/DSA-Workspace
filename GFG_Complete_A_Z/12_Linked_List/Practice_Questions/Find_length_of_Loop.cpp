/*
// Find Length of loop: 

// Observations: 
    * For finding loop, if we revisit the traversed node, again we can say we found a loop...
    * We can store the frequency of every node that we visit...
    * whenever the frequency will become 2 at any movement, we can say we found loop...
    * Once loop is found we can iterate & find the size of loop...

// Intrusion: 
    * we will use map data structure to perform this task..
    * while storing frequency we, if we revisit the same number, we can say we found the loop.
    * once loop is found, we can calculate the size...
    * If we don't get the loop in our linked list, we need to return 0...



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

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void loopHere(Node *head, Node *tail, int position) {
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}

class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(struct Node *head) {
        // we will use hashing approach: 
        unordered_map<Node *, int> mp;  // TC: O(1) for finding nodes in avg case...
        bool isFound = 0;
        Node *loopPos = NULL;
        for(Node *itr = head;itr != NULL;itr = itr->next){
            if(mp[itr]== 1){
                loopPos = itr;
                isFound = 1;
                break;
            }
            mp[itr]++;    // storing frequency of each node
        }
        // there is no loop found...
        if(isFound == 0){
            return 0;   // returning size as 0
        }
        // else we found the loop
        // now find the length of loop by iterating till that loop:
        Node *curr = loopPos->next;
        int size = 1;
        while(curr != loopPos){
            size++;
            curr = curr->next;
        }

        return size;
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
        int k;
        cin >> k;
        cin.ignore();
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        loopHere(head, tail, k);

        Solution ob;
        cout << ob.countNodesinLoop(head) << endl;
    }
    return 0;
}