/*

//  141. Linked List Cycle


//  Problem Statement: 
    -> Given head, the head of a linked list, determine if the linked list has a cycle in it.
    -> There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
    -> Return true if there is a cycle in the linked list. Otherwise, return false.

//  Example: 

    Example 1:
        Input: head = [3,2,0,-4], pos = 1
        Output: true
        Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

    Example 2:
        Input: head = [1,2], pos = 0
        Output: true
        Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

    Example 3:
        Input: head = [1], pos = -1
        Output: false
        Explanation: There is no cycle in the linked list.

 
// Observations: 
    -> We are given a linked list, we need to find wether linked list contains cycle or not?


    // BruteForce Solution:
        -> maintain a set or map, & store every node inside it, if we revisit that node again, we can return true : else false

        // Complexity: 
            -> TC: O(N)
            -> SC: O(N)
        

    // Efficient Solution:
        -> We can use two pointers "fast" & "slow"
        -> fast moves 2 steps every time
        -> slow moves 1 steps every time
        -> We will move fast until fast not reaches NULL
            -> If there is cycle fast, means fast will move back & encounter slow, which were in path..
            -> We immediately return true, for cycle.
        -> Else we return false, for no cycle.

        // Complexity: 
            -> TC: O(N)
            -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;



// BruteForce Solution: 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode* temp = head;
        unordered_set<ListNode*> st;

        while(temp != NULL) {
            if(st.count(temp)) {
                return true;    // cycle found
            }
            
            st.insert(temp);
            temp = temp->next;
        }

        return false;   // No cycle found
    }
};




// Efficient Solution: 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) {
                return true;    // cycle found
            }
        }


        return false;   // No cycle found
    }
};