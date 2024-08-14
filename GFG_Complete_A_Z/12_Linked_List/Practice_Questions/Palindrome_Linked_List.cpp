/*

// Palindrome Linked List

// Observations: 
    * Given a singly linked list, we have to perform palindrome check..

// Intrusion: 
    // Approach 1: using stack
        * we can push all the element of linked list into stack..
        * Once we have pushed all the element into the stack, we can iterate from front by using iterator reference & simultaneously we can pop element from stack, & match...
        * at any movement we encounter with distinct value we can return 0, else 1



*/

#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        if(head == NULL) return 0;  // when there is no element in linked list..
        if(head->next == NULL) return 1;    // when there is single element in linked list..

        // Using stack data structure..
        stack<int> stk;
        Node *curr = head;
        while(curr != NULL){
            stk.push(curr->data);
            curr = curr->next;
        }
        
        //  checking the palindrome case:
        Node *crr = head;
        // we will iterate until all the element is not pop out from stack.
        while(stk.size() > 0){
            // checking from top of the stack, & from the linked list node.
            if(stk.top() != crr->data){
                return false;
            }
            stk.pop();  // popping out element from top of the stack
            crr = crr->next;    // moving pointer to next node..
        }

        return 1;   // else all the element is same..
    }
};

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

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

        if (arr.empty()) {
            cout << "empty" << endl;
            continue;
        }

        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        if (ob.isPalindrome(head))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        // Clean up the remaining nodes to avoid memory leaks
        while (head != NULL) {
            struct Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    return 0;
}