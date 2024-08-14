/*

// Palindrome Linked List

// Observations: 
    * Given a singly linked list, we have to perform palindrome check..

// Intrusion: 
    // Approach 1: using stack
        * we can push all the element of linked list into stack..
        * Once we have pushed all the element into the stack, we can iterate from front by using iterator reference & simultaneously we can pop element from stack, & match...
        * at any movement we encounter with distinct value we can return 0, else 1
    
    // Approach 2: using any n size Auxilary space data-structure like array or vector.
        * we can use array or vector or doubly linked list..

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
    bool isPalindrome_Stack(Node *head) {
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

    // Approach 2: using Auxilary space data structure..
    bool isPalindrome(Node *head) {
        if(head == NULL) return 0;  // when there is no element in linked list..
        if(head->next == NULL) return 1;    // when there is single element in linked list..

        // using deque data structure:
        Node *c = head;
        vector<int> v;
        while(c != NULL){
            v.push_back(c->data);
            c = c->next;
        }

        // comparing the elements: using two pointers
        int p1 = 0;
        int p2 = v.size() - 1;
        while(p1 <= p2){
            if(v[p1++] != v[p2--]) return 0;
        }

        return 1;   // else all the element is same..e
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