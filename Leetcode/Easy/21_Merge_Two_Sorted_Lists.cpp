/*

//  21. Merge Two Sorted Lists


//  Problem Statement:
    - You are given the heads of two sorted linked lists list1 and list2.
    - Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
    - Return the head of the merged linked list.

 
// Example:
    Example 1:
        Input: list1 = [1,2,4], list2 = [1,3,4]
        Output: [1,1,2,3,4,4]

    Example 2:
        Input: list1 = [], list2 = []
        Output: []

    Example 3:
        Input: list1 = [], list2 = [0]
        Output: [0]


// Observations:
    - We are given two reference point with sorted values, we need to build a linked list with sorted values..
    
    // Approach:
        -> create a empty linked list chain
            -> make sure to store the starting reference point, as we need to store the starting point..
        -> make tow reference point pointing both the linked list..
        -> start itereating & getting the values & compare the smallest & store in sorted order..
        -> Make sure to store the leftover..

    // Complexity:
        -> TC: O(max(list1.size(), list2.size()))
        -> SC: O(list1.size() + list2.size())


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // Edge case:
        if(list1 == NULL && list2 != NULL) return list2;
        else if(list1 != NULL && list2 == NULL) return list1;
        else if(list1 == NULL && list2 == NULL) return NULL;
        
        // Create a dummy node to start:
        ListNode* ans = new ListNode(-1);       // Start a reference point
        ListNode* temp = ans;                   // this will use to bind nodes values..

        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        
        // Build Nodes:
        while(ptr1 != NULL && ptr2 != NULL) {
            if(ptr1->val < ptr2->val) {
                temp->next = new ListNode(ptr1->val);
                temp = temp->next;
                ptr1 = ptr1->next;
            } else {
                temp->next = new ListNode(ptr2->val);
                temp = temp->next;
                ptr2 = ptr2->next;
            }
        }

        // Store LeftOver
        while(ptr1 != NULL) {
            temp->next = new ListNode(ptr1->val);
            temp = temp->next;
            ptr1 = ptr1->next;
        }

        while(ptr2 != NULL) {
            temp->next = new ListNode(ptr2->val);
            temp = temp->next;
            ptr2 = ptr2->next;
        }

        return ans->next;   // return ans->next, as first value is '-1'
    }
};