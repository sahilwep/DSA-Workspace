/*

//  2337. Move Pieces to Obtain a String

//  Problem Statement: 
    * You are given two strings start and target, both of length n. Each string consists only of the characters 'L', 'R', and '_' where:
    * The characters 'L' and 'R' represent pieces, where a piece 'L' can move to the left only if there is a blank space directly to its left, and a piece 'R' can move to the right only if there is a blank space directly to its right.
    * The character '_' represents a blank space that can be occupied by any of the 'L' or 'R' pieces.
    * Return true if it is possible to obtain the string target by moving the pieces of the string start any number of times. Otherwise, return false.

 
// Example:

    Example 1:
        Input: start = "_L__R__R_", target = "L______RR"
        Output: true
        Explanation: We can obtain the string target from start by doing the following moves:
        - Move the first piece one step to the left, start becomes equal to "L___R__R_".
        - Move the last piece one step to the right, start becomes equal to "L___R___R".
        - Move the second piece three steps to the right, start becomes equal to "L______RR".
        Since it is possible to get the string target from start, we return true.

    Example 2:
        Input: start = "R_L_", target = "__LR"
        Output: false
        Explanation: The 'R' piece in the string start can move one step to the right to obtain "_RL_".
        After that, no pieces can move anymore, so it is impossible to obtain the string target from start.

    Example 3:
        Input: start = "_R", target = "R_"
        Output: false
        Explanation: The piece in the string start can move only to the right, so it is impossible to obtain the string target from start.


// Observation:

    // Bruteforce Solution:
        -> Try all possible approach, & match every approach with target, if anytime it's matched, return '0'
            -> recursively try to replace all the place which has 'L' or 'R'
        -> We will memoize this using DP memoization, because so many same pattern or subproblems is occurring in recursive tree.
        -> This gives us TLE, because of exponential time complexity



    // Efficient Solution
        -> i & j pointer start form 0, & goes up till n, if any of them reach to the limit break the finish the check:
        -> while(i < n && start[i] == '_') i++;     increment i until we don't get any 'L' or 'R'
        -> while(j < n && target[j] == '_') j++;     increment j until we don't get any 'L' or 'R'
        -> if(start[i] != target[j]) return false;      if any character form i and j pointer is not matched return false immediately
        -> if(start[i] == 'L',  && i < j) return false;      if start is 'L' & i pointer is less than 'j', means j pointer 'L' is ahead of i pointer 'L', & no way we can move start pointer 'L' to right
        -> if(start[i] == 'R' && i > j)  return false;     if start is 'R' & i pointer is grater than 'j', means j pointer 'R' is before of i pointer 'R', & no way we can move start pointer 'R' to left
        -> else increment both the pointers i & j
        -> If we break out from the loop, and, any false condition is not hit, return true.

        * TC: O(n)
        * AS: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// BruteForce Solution:
class Solution_BF{
private:
    int n;  // member value define 'n'
    bool solve(string start, string target, unordered_map<string, bool> &mp){
        int n = start.size();
        if(start == target) return true;   // base condition , when string & target are equal return true;

        // checking in memo table, if we have already seen the pattern or string previously, return their result
        if(mp.count(start)){
            return mp[start];
        }

        // Decision Tree:
        for(int i=0;i<start.size();i++){
            // If we have 'L', checking left side has blank space or not?
            if(start[i] == 'L' && i > 0 && start[i-1] == '_'){
                swap(start[i], start[i-1]); // move 'L' to left
                // Now, after swap call solve function:
                if(solve(start, target, mp) == true){   // if recursively we got answer as true, then return true.
                    return true;
                }
                else{   // we don't get true, recursively, again reset the value:
                    swap(start[i], start[i-1]);
                }
            }
            else if(start[i] == 'R' && i < n-1 && start[i+1] == '_'){   // if we got 'R' & i is in bound, & next position character is '_' empty, then swap:
                swap(start[i], start[i+1]); // move 'R' to right
                // Now recursively check for next possibility & return true, if we got true in any branch, else undo the operation.
                if(solve(start, target, mp) == true) return true;   // return true, if any branch return true.
                else swap(start[i], start[i+1]);    // undo
            }
        }

        // last return false if we don't find our answer, & also store in map, i.e mp[start]
        return mp[start] = false;

    }
public:
    bool canChange(string start, string target) {
        n = start.length(); // updating n value, that we have define as member value

        unordered_map<string, bool> mp;
        return solve(start, target, mp);
    }
};


// Efficient Solution:
class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0;
        int j = 0;

        while(i < n || j < n){  // iterate until we got any string reach to their limit.

            // while we got empty space, move pointer until we find any 'L' or 'R'
            while(i < n && start[i] == '_'){
                i++;
            }
            while(j < n && target[j] == '_'){
                j++;
            }

            // if any of the pointer reach to the end:
            if(i == n || j == n){   
                return (i == n && j == n);  // return true, if both pointer reach to end at same time, else return false here itself.
            } 

            // if any string character is not matched, return false directly
            if(start[i] != target[j]) return false;

            // Impossible moves:
            if(start[i] == 'L' && i < j){   // if start is 'L' & i pointer is less than 'j', means j pointer 'L' is ahead of i pointer 'L', & no way we can move start pointer 'L' to right
                return false;
            }
            if(start[i] == 'R' && i > j){   // if start is 'R' & i pointer is grater than 'j', means j pointer 'R' is before of i pointer 'R', & no way we can move start pointer 'R' to left
                return false;
            }

            // else, no rule is violated, increment both the pointers.
            i++;
            j++;
        }

        return true;    // else return true at last, if non of the above false condition has occurred.
    }
};
