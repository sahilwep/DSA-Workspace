/*

//  86. Partition List


//  Problem Statement: 
    -> Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
    -> You should preserve the original relative order of the nodes in each of the two partitions.

 
// Example:
    Example 1:
        Input: head = [1,4,3,2,5,2], x = 3
        Output: [1,2,2,4,3,5]

    Example 2:
        Input: head = [2,1], x = 2
        Output: [1,2]

 
// Observations:
    - we are given LL, & value 'x'
    - we need to make a LL so that smaller value before 'x' appear first & then the rest arrangement is same as before..
    - In simple we need to get all the value that are smaller than 'x' & then move them in begining & then build the rest of LL as it given originally..

    // Approach:
        - Build chain C1, which will hold all the values which are smaller than 'x'.
        - Build another chain C2 which will hold all the value that are grater or equal to 'x'
        - At last, when everything done, C1->next will be C2->head
        -> return the C1 head..

    // Complexity:
        -> TC: O(n), n = list.size()
        -> SC: O(n)


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
    ListNode* partition(ListNode* head, int x) {

        // Edge case:
        if(head == NULL) return NULL;
        else if(head->next == NULL) return head;


        ListNode* c1 = new ListNode(-1);    // lower than 'x'
        ListNode* c1_ref = c1;

        ListNode* c2 = new ListNode(-1);    // greater, equal than 'x'
        ListNode* c2_ref = c2;

        ListNode* temp = head;

        while(temp != NULL) {
            if(temp->val < x) {
                c1->next = new ListNode(temp->val);
                c1 = c1->next;
            } else {
                c2->next = new ListNode(temp->val);
                c2 = c2->next;
            }

            temp = temp->next;
        }

        // Last merge c1 & c2:
        c1->next = c2_ref->next;

        return c1_ref->next;    // this will be our starting point of linked list.
    }
};