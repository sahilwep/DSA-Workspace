/*

//  2058. Find the Minimum and Maximum Number of Nodes Between Critical Points


//  Problem Statement: 
    - A critical point in a linked list is defined as either a local maxima or a local minima.
    - A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.
    - A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.
    - Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.
    - Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

 
// Example:
    Example 1:
        Input: head = [3,1]
        Output: [-1,-1]
        Explanation: There are no critical points in [3,1].

    Example 2:
        Input: head = [5,3,1,2,5,1,2]
        Output: [1,3]
        Explanation: There are three critical points:
            - [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
            - [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.
            - [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
            The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.
            The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.

    Example 3:
        Input: head = [1,3,2,2,3,2,2,2,7]
        Output: [3,3]
        Explanation: There are two critical points:
            - [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 is greater than 1 and 2.
            - [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is greater than 2 and 2.
            Both the minimum and maximum distances are between the second and the fifth node.
            Thus, minDistance and maxDistance is 5 - 2 = 3.
            Note that the last node is not considered a local maxima because it does not have a next node.

 


// Observations:
    - Given linked list
    - critical point in linked list is defined as either a local maxima or local minima
    - local maxima: if current node has a value strictly grater than the previous and the next node.
    - local minima: if current node has value strictly smaller than the previous and the next node.
    - Note: node can only be a local maxima/minima if there exist both a previous and a next node.
    - given linked list head, return array of length 2 containing [minDistance, maxDistance] where minDist is min dist b/w any two distinct critical point and maxDist is the maximum dist b/w any two distinct critial points.
    - if there are fewer than two critical points, return [-1, -1]


    // Approach:
        - From the linked list, we will have to grep out the local maxima, or local minima:
            Critical point: 
                if([i - 1] < [i] > [i + 1] || [i - 1] > [i] < [i + 1]) {
                    store index of i
                }

        - Iterating pointer: 
            [i - 1]--->[i]---->[i + 1]
                int i = head->next;
                iterate till i->next != NULL

        - maintain idx = 1, which is starting point for i = head->next

        // Complexity:
            - TC: O(n)
            - SC: O(1)


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

//  Approach 2: Space Optimized  TC: O(n), SC: O(1)
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        // Edge case:
        if(head == NULL || head->next == NULL || head->next->next == NULL) return {-1, -1};

        ListNode* currPtr = head->next;
        ListNode* prevPtr = head;
        int idx = 1;

        int firstCri = -1, prevDist = -1, currDist = -1;
        int minDist = INT_MAX;
        
        while(currPtr->next != NULL) {
            int prev = prevPtr->val;
            int curr = currPtr->val;
            int next = currPtr->next->val;

            // Critical point for maxima || minima
            if(prev < curr && curr > next || prev > curr && curr < next) {
                if(firstCri == -1) {
                    firstCri = idx;
                }
                
                prevDist = currDist;
                currDist = idx;

                if(prevDist != -1) {
                    minDist = min(minDist, currDist - prevDist);
                }
            }
            

            currPtr = currPtr->next;
            prevPtr = prevPtr->next;
            idx++;
        }

        // Check if we have atleast 2 critical point:
        if(firstCri == -1 || prevDist == -1) return {-1, -1};

        int maxDist = currDist - firstCri;

        return {minDist, maxDist};
    }



//  Approach 1: No space optimized  TC: O(n), SC: O(n)
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        // Edge case:
        if(head == NULL || head->next == NULL || head->next->next == NULL) return {-1, -1};

        ListNode* currPtr = head->next;
        ListNode* prevPtr = head;
        int idx = 1;

        vector<int> critical;
        
        while(currPtr->next != NULL) {
            int prev = prevPtr->val;
            int curr = currPtr->val;
            int next = currPtr->next->val;

            // Critical point for maxima || minima
            if(prev < curr && curr > next || prev > curr && curr < next) {
                critical.push_back(idx);
            }
            

            currPtr = currPtr->next;
            prevPtr = prevPtr->next;
            idx++;
        }

        // Now fetch the minima and maxima:
        if(critical.empty() ||critical.size() == 1) return {-1, -1};
        int maxDist = critical[critical.size() - 1] - critical[0];
        int minDist = maxDist;
        for(int i = 1; i < critical.size(); i++) {
            minDist = min(minDist, critical[i] - critical[i -1 ]);
        }


        return {minDist, maxDist};
    }
};