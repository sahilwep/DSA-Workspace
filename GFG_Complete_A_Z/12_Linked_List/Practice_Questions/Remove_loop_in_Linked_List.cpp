/*
// Remove loop in Linked List

// Observations: 
    * We are give singly linked list which contains some loop in it..
    * We have to find the loop & remove it from the linked list...
    * Loop means last node is connected to the any of the node before last...
        * it may be first or any...

// Intrusion: 
    * To solve this particular question we can use hashing approach:
        * we can use hashing to store the node reference..
        * if we try to hash same value again, we can break out, & get the reference..
        * After that we will have the last node reference..
        * we can make that node->next = NULL..
        * So that loop will be removed from teh linked list...


*/

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
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

bool isLoop(Node* head) {
    if (!head)
        return false;

    Node* fast = head->next;
    Node* slow = head;

    while (fast != slow) {
        if (!fast || !fast->next)
            return false;
        fast = fast->next->next;
        slow = slow->next;
    }

    return true;
}

int length(Node* head) {
    int ret = 0;
    while (head) {
        ret++;
        head = head->next;
    }
    return ret;
}

bool notOriginal(Node* head, unordered_map<Node*, int>& myMap) {

    while (head) {
        if (myMap.find(head) == myMap.end())
            return true;
        if (myMap[head] != (head->data))
            return true;

        head = head->next;
    }
}

class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        // common cases: 
        if(head == NULL) return;
        if(head->next == NULL) return;
        if(head->next == head){
            head->next = NULL;
            return;
        }
        int size = 0;    // size will help us to find the last node.
        unordered_map<Node *, int> mp;
        bool isLoop = 0;
        for(Node *i = head;i!=NULL;i=i->next){
            // if we encounter same node again..
            if(mp[i] == 1){
                isLoop = 1;
                break;
            }
            size++;
            mp[i]++;
        }
        // checking the loop is contains or not, if there is no loop, we return:
        if(!isLoop){
            return;
        }
        // Now we got the size, let's iterate till size & make last node NULL
        Node *curr = head;
        while(size > 1){
            curr = curr->next;
            size--;
        }
        curr->next = NULL;  // breaking the link
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

        unordered_map<Node*, int> myMap;

        int n, num;
        n = arr.size();

        Node *head, *tail;
        num = arr[0];
        head = tail = new Node(num);

        myMap[head] = num;

        for (int i = 1; i < n; i++) {
            num = arr[i];
            tail->next = new Node(num);
            tail = tail->next;
            myMap[tail] = num;
        }

        int pos;
        cin >> pos;
        cin.ignore();
        loopHere(head, tail, pos);

        Solution ob;
        ob.removeLoop(head);

        if (isLoop(head) || length(head) != n || notOriginal(head, myMap))
            cout << "false\n";
        else
            cout << "true\n";
    }
    return 0;
}