/*
// Intersection Point in Y Shaped Linked Lists

// Observations: 


// Intrusion: 
    // approach 1: Hashing
        * We can use hashing approach, we can use unsorted map
        * First we will hash 1s't list into map..
        * Then while hashing second map, if we encounter with any node that we are hashing again, we simply return that node.
        * else we return -1, if there is no node.



*/

#include <iostream>
#include <algorithm>
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

vector<int> take() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    return arr;
}

Node* inputList(int size, vector<int> v) {
    if (size == 0)
        return NULL;

    int val = v[0];

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 0; i < size - 1; i++) {
        val = v[i + 1];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

class Solution {
  public:
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node* head1, Node* head2) {
        if(head1 == NULL || head2 == NULL) return -1;
        unordered_map<Node *, int> mp;
        // hashed first list into the map:
        Node *curr1 = head1;
        // iterate till last node, & store all the nodes reference into map.
        while(curr1 != NULL){
            mp[curr1]++;
            curr1 = curr1->next;
        }

        // hashing the second node:
        for(Node *i=head2;i!=NULL;i=i->next){
            // if we found the same node, we return the data of it..
            if(mp[i] == 1){
                return i->data;
            }
            mp[i]++;
        }

        return -1;  // else return -1
    }
};


int main() {
    srand(time(0));
    int T, n1, n2, n3;

    cin >> T;
    cin.ignore();
    while (T--) {

        vector<int> v1 = take();
        vector<int> v2 = take();
        vector<int> v3 = take();
        int n1 = v1.size(), n2 = v2.size(), n3 = v3.size();

        Node* head1 = NULL;
        Node* head2 = NULL;
        Node* common = NULL;

        head1 = inputList(n1, v1);
        head2 = inputList(n2, v2);
        common = inputList(n3, v3);

        Node* temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;
        Solution ob;
        cout << ob.intersectPoint(head1, head2) << endl;
    }
    return 0;
}