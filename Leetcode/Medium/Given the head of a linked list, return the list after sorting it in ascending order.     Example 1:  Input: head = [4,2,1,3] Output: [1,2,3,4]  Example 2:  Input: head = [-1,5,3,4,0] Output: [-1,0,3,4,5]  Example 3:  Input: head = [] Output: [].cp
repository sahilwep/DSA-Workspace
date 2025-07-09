/*

//  148. Sort List | linked list | sorting |


//  Problem Statement: 
    -> Given the head of a linked list, return the list after sorting it in ascending order.


// Example: 
    Example 1:
        Input: head = [4,2,1,3]
        Output: [1,2,3,4]

    Example 2:
        Input: head = [-1,5,3,4,0]
        Output: [-1,0,3,4,5]

    Example 3:
        Input: head = []
        Output: []


//  Observations: 
    -> Store all the element from list to priority_queue
    -> overwrite the list value from priority_queue.


    // Complexity: 
        -> TC: O(n * logn)
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
    ListNode* sortList(ListNode* head) {

        if(head == nullptr) return nullptr; // edge case

        // Store all the element into priority queue:
        priority_queue<int, vector<int>, greater<>> pq;
        ListNode* temp = head;
        
        while(temp->next != NULL) {
            pq.push(temp->val);
            temp = temp->next;
        }
        pq.push(temp->val);

        // Overwrite all the values from priority queue to list:
        ListNode* list = head;
        while(list->next != nullptr && !pq.empty()) {
            list->val = (pq.top());
            list = list->next;
            pq.pop();
        }
        list->val = pq.top();


        return head;
    }
};

