/*

//  1653. Minimum Deletions to Make String Balanced


//  Problem Statement: 
    - You are given a string s consisting only of characters 'a' and 'b'​​​​.
    - You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.
    - Return the minimum number of deletions needed to make s balanced.

 
// Example:
    Example 1:
        Input: s = "aababbab"
        Output: 2
        Explanation: You can either:
        Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
        Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").

    Example 2:
        Input: s = "bbaaaaabb"
        Output: 2
        Explanation: The only solution is to delete the first two characters.



// Observations:
    - we are given string s, containing characters 'a' & 'b'
    - we need to make sure that our string has only 'ab' arrangement, so that our string s is balanced
    - we need to remove all the 'ba' from the string so that we can make string balanced.
    - we need to minimum number of characters so that we can make our string s balanced.

    // Approach:
        - we need to make sure that mostly 'a' is in left side, & 'b' is in right side.
        - If we have sequence 'ba' we have to remove any character 'a' or 'b' so that we can have our sequence correct.
        - We try to remove: 
            - Right side 'a'
                - we can use something like counting, or suffix sum of every 'a'
                - starting from right

            - Left side 'b'
                - we will create another prefix sum of every 'b'
                - starting from left
        - Once we have list of couting of rightRemoveA & leftRemoveB:
            - To balance the array, we will have to delete every rightSide 'a' and every leftSide 'b'
            - From every index i, from (1, n - 1):
                - we will get totalDelete = rightRemoveA[i + 1] + leftRemoveB[i - 1]
                - we will get totalDelete as minimum as possible, so that we can have a balanced array
        
        // Complexity:
            - TC: O(n)
            - SC: O(n)

    // Space Optimizations:
        - We can optimize the space form O(n) to O(1) by removeing prefix & suffix sums, Initially we can use a variable which stores the total count of 'a'
        - While iterating from left to right we will start counting the bCnt 
        - and calculate the totalDelete by simply from these two variables.
        - while itering forward, we simply adjust the 'a' and 'b' counters..

        // Complexity:
            - TC: O(n)
            - SC: O(1)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Counting based Solution:
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();

        // edge case:
        if(n == 1) return 0;    // for single nothing need to remove
        
        // we need 'a' from the right to delete, mostly
        vector<int> aCnt(n, 0);
        if(s[n - 1] == 'a') aCnt[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--) {
            if(s[i] == 'a') {
                aCnt[i] = aCnt[i + 1] + 1;
            } else {
                aCnt[i] = aCnt[i + 1];
            }
        }

        // we need 'b' from the left to delete, mostly
        vector<int> bCnt(n, 0);
        if(s[0] == 'b') bCnt[0] = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == 'b') {
                bCnt[i] = bCnt[i - 1] + 1;
            } else {
                bCnt[i] = bCnt[i - 1];
            }
        }
        
        // Debugging:
        // for(auto &it: s) cout << it << " ";
        // cout << endl;
        // for(auto &it: aCnt) cout << it << " ";
        // cout << endl;
        // for(auto &it: bCnt) cout << it << " ";
        // cout << endl;

        // Now calculate the minimum removal:
        int removal = n;    // in worse case we will remove all.
        for(int i = 1; i < n - 1; i++) {
            // for every "i"
            // delete all the left side of b
            // delete all the right side of a
            int totalDelete = bCnt[i - 1] + aCnt[i + 1];

            // store minimum deletions as possible.
            removal = min(removal, totalDelete);
        }

        // left Over: handel the leftOver as we iterate only from 1 to n - 2
        removal = min(removal, aCnt[1]);        // at index '0' delete all the right side of 'a'
        removal = min(removal, bCnt[n - 2]);    // at index 'n - 1' delete all the left side 'b'

        return removal;
    }
};


// Space Optimized:
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        
        // we need 'a' from the right to delete, mostly
        int aCnt = 0;
        for(auto &c: s) {
            if(c == 'a') aCnt++;
        }

        // we need b from the left to delete, mostly, we will calculate it on-the-go:
        int bCnt = 0;

        // Now calculate the minimum removal:
        int removal = aCnt;    // in worse case we will have all 'a' to remove
        for(auto &c: s) {
            if(c == 'a') aCnt--;
            else bCnt++;
            
            // for every "i"
            // delete all the left side of b
            // delete all the right side of a
            int totalDelete = bCnt + aCnt;

            // store minimum deletions as possible.
            removal = min(removal, totalDelete);
        }

        return removal;
    }
};