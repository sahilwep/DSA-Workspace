/*

//  24. Swap Nodes in Pairs


//  Problem Statement:
    * Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 
// Example:

    Example 1:
        Input: head = [1,2,3,4]
        Output: [2,1,4,3]

    Example 2:
        Input: head = []
        Output: []

    Example 3:
        Input: head = [1]
        Output: [1]

    Example 4:
        Input: head = [1,2,3]
        Output: [2,1,3]




*/

#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        ListNode *temp = head;

        while(temp != NULL){
            if(temp->next == NULL) break;   // check if next value is not there then exit out

            // Swap these two values
            swap(temp->val, temp->next->val);

            // Increment two position forward
            temp = temp->next->next;
        }

        return head;
    }
};