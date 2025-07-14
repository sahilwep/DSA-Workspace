/*

//  1290. Convert Binary Number in a Linked List to Integer


//  Problem Statement: 
    -> Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.
    -> Return the decimal value of the number in the linked list.
    -> The most significant bit is at the head of the linked list.

 
// Example: 
    Example 1:
        Input: head = [1,0,1]
        Output: 5
        Explanation: (101) in base 2 = (5) in base 10

    Example 2:
        Input: head = [0]
        Output: 0


// Approach:
    -> Store the values form linked list to string.
    -> after that convert that binary string into decimal:

    // Binary To Decimal conversion: 

        -> Bin to decimal code:

                        int binToDec(string s) {
                            int n = s.size();

                            int power = 1, val = 0;
                            for(int i = n - 1; i >= 0; i--) {
                                if(s[i] == '1') val += power;   // add that power into value
                                power <<= 1;    // move power bits left to right: 2^0 -> 2^1 -> 2^2 ...
                            }
                            
                            return val;
                        }


        -> We will use shift operations to convert the binary to decimal.
        -> x << n shifts the bits of x to the left by n places.
        -> for every set bits we need (2^k), where k is nth position
        -> We can use:  
            power <<= 1 means power = power * 2 by shifting bits left.


                Step        Binary representation   Decimal value	    Meaning
            power = 1	                0001	            1             2^0
            power <<= 1	                0010	            2             2^1
            power <<= 1 again           0100	            4             2^2
            power <<= 1 again           1000	            8             2^3

        So every time you do power <<= 1, you’re doubling the value — or equivalently moving to the next power of 2.

        

// Complexity: 
    -> TC: O(N)
    -> SC: O(N)
        -> N = list.size()
        


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
    int binToDec(string s) {
        int n = s.size();

        int power = 1;
        int val = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '1') {
                val += power;   // add that power into value
            }
            power <<= 1;    // move power bits left to right: 2^0 -> 2^1 -> 2^2 ...
        }
        
        return val;
    }
public:
    int getDecimalValue(ListNode* head) {
        
        string bin = "";
        ListNode* temp = head;
        while(temp != NULL) {
            bin += (char)(temp->val + '0');
            temp = temp->next;
        }

        cout << bin << endl;
        
        return binToDec(bin);
    }
};