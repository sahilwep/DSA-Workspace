/*

//  717. 1-bit and 2-bit Characters


//  Problem Statement: 
    - We have two special characters:
        - The first character can be represented by one bit 0.
        - The second character can be represented by two bits (10 or 11).
    - Given a binary array bits that ends with 0, return true if the last character must be a one-bit character.

 
// Example: 

    Example 1:
        Input: bits = [1,0,0]
        Output: true
        Explanation: The only way to decode it is two-bit character and one-bit character.
        So the last character is one-bit character.

    Example 2:
        Input: bits = [1,1,1,0]
        Output: false
        Explanation: The only way to decode it is two-bit character and two-bit character.
        So the last character is not one-bit character.

//  Observations: 
    - We are given two types of characters:
        - one with single digit '0'
        - Second with two digit "11", "10"
    - We need to check wether the last digit of given bits are single or not?
    - In simple word last digit should be '0'

    // Approach: 
        - Example: 
            Input: bits = [1,0,0]
                "10" => makes a pair
                "0" => remaining last digit -> return "true"
            
            Input: bits = [1,1,1,0]
                "11" => makes a pair
                "10" => makes a pair
                nothing left, as we return false, because last digit we don't have any left single digit..
        
        - Approach: 
            - start from 0th index: 
                - if we got '1', we are sure that next bits can be '1' or '0', so we will skip the next index to check..
                    - if we got '1' we will move 2 positions.
                - if we got '0', we will have to check the next index as we need to check the pairs..
                    - if we got '0' we will move only 1, next position
            
            // Complexity: 
                - TC: O(n)
                - SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        
        int i = 0;
        while(i < n) {
            // check conditions satisfies (i == n - 1 && bits[i] == 0)  -> for true conditions:
            if(i == n - 1 && bits[i] == 0) return true;

            // movement according to the bits values:
            if(bits[i] == 1) {
                i += 2; // no need to check, skip
            } else {    // for '0', we will have to check the next index:
                i += 1;
            }
        }

        return false;
    }
};