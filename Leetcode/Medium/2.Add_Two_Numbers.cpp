/*

//  2. Add Two Numbers

//  Observations: 
    * We are given two non-empty linked list, represent non-negative integer, the digits are stored in reversed order & each of their nodes contains single digits, add two numbers & return the sum as a linked list.


// Example:



    Input: l1 = [2,4,3], l2 = [5,6,4]
    Output: [7,0,8]
    Explanation: 342 + 465 = 807.

                [2]-->[4]-->[3]     L1
            +   [5]-->[6]-->[4]     L2
            ---------------------
                [7]-->[0]-->[8]     Result


    Input: l1 = [0], l2 = [0]
    Output: [0]


    Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
    Output: [8,9,9,9,0,0,0,1]


// Intrusion: 
    * Iterate in both the linked list & store the sum result in string..
    * At last transfer string values into linked list, & return it.



*/

#include<bits/stdc++.h>
#include<algorithm>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // String to store the result digits and an integer to keep track of carry
        string res = "";    // string used to store the result of sum.
        int carry = 0;
        int sum = 0;

        // Loop through both lists while both are not empty
        while(l1 != nullptr && l2 != nullptr) {
            // Add values of both nodes and carry from previous iteration
            sum = l1->val + l2->val + carry;
            carry = 0; // Reset carry

            // Check if the sum is a two-digit number
            if(sum >= 10) {
                res += to_string(sum % 10);  // Store the last digit of sum
                carry = sum / 10;            // Carry forward the remaining part
            } else {
                res += to_string(sum);       // Store the sum directly if it's a single-digit
            }

            // Move to the next nodes in both lists
            l1 = l1->next;
            l2 = l2->next;
        }

        // If l1 is longer, continue processing remaining nodes of l1
        while(l1 != nullptr) {
            sum = l1->val + carry;
            carry = 0;  // Reset carry

            // Handle if the sum is two-digit
            if(sum >= 10) {
                res += to_string(sum % 10);
                carry = sum / 10;
            } else {
                res += to_string(sum);
            }

            l1 = l1->next;
        }

        // If l2 is longer, continue processing remaining nodes of l2
        while(l2 != nullptr) {
            sum = l2->val + carry;
            carry = 0;

            if(sum >= 10) {
                res += to_string(sum % 10);
                carry = sum / 10;
            } else {
                res += to_string(sum);
            }

            l2 = l2->next;
        }

        // If there's any carry left, append it to the result
        if(carry != 0) {
            res += to_string(carry);
        }

        // Convert the result string into a linked list and return the head
        ListNode *head = new ListNode(res[0] - '0'); // Create head with first digit
        ListNode *current = head;

        // Create the rest of the linked list
        for(int i = 1; i < res.size(); i++) {
            current->next = new ListNode(res[i] - '0');
            current = current->next;
        }

        return head;  // Return the result linked list
    }
};

