/*

//  19. Remove Nth Node From End of List | Linked list

//  Problem Statement: 
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 
// Example:
    Example 1:
        Input: head = [1,2,3,4,5], n = 2
        Output: [1,2,3,5]

    Example 2:
        Input: head = [1], n = 1
        Output: []

    Example 3:
        Input: head = [1,2], n = 1
        Output: [1]

// Observations: 
    -> We have to remove the kth positioned element from the list
    -> First find the size of lined list
    -> Get the position from begin for which we have to remove.
    -> Iterate just before that position, & change the connection orientations as "next" to "next->next"
 
    // Complexity: 
        -> TC: O(N)
        -> SC: O(1)

        
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
private: 
    int getSize(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            temp = temp->next;
            cnt++;
        }

        return cnt;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int size = getSize(head);   // get the size of linked list
        int k = size - n;           // find the position for which we have remove.

        if(k == 0) return head->next;   // If it's first element, move to next & return
        

        // Remove kth node from link-list:
        ListNode* temp = head;
        for(int i = 0; i < k - 1; i++) {    // iterate jus before the kth node:
            temp = temp->next;
        }

        temp->next = temp->next->next;      // move the current to current->next->next

        return head;
    }
};