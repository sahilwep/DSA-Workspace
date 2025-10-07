/*

//  82. Remove Duplicates from Sorted List II


//  Problem Statement: 
    - Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 
// Example:
    Example 1:
        Input: head = [1,2,3,3,4,4,5]
        Output: [1,2,5]

    Example 2:
        Input: head = [1,1,1,2,3]
        Output: [2,3]

// Observations: 
    -> given list, we need to return a list in that there has no duplicate value exist in that list...
    
    // Approach:
        - hash value with their frequency..
        - Get the values that are Unique, in other words, has frequency = 1
        - Build list & return :/

    // Complexity: 
        -> TC: O(n)
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
public:
    ListNode* deleteDuplicates(ListNode* head) {

        // Store unique Values only:
        map<int, int> mp;
        ListNode *temp = head;
        while(temp != NULL) {
            mp[temp->val]++;
            temp = temp->next;
        }

        // Build answer:
        ListNode* ans = new ListNode(-1);
        ListNode* res = ans;
        
        for(auto &[val, freq]: mp) {
            if(freq == 1) {
                res->next = new ListNode(val);
                res = res->next;
            }
        }

        return ans->next;
    }
};