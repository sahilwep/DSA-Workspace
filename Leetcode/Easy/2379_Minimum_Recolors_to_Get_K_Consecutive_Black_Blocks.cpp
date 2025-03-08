/*

//  2379. Minimum Recolors to Get K Consecutive Black Blocks


//  Problem Statement:
    -> You are given a 0-indexed string blocks of length n, where blocks[i] is either 'W' or 'B', representing the color of the ith block. The characters 'W' and 'B' denote the colors white and black, respectively.
    -> You are also given an integer k, which is the desired number of consecutive black blocks.
    -> In one operation, you can recolor a white block such that it becomes a black block.
    -> Return the minimum number of operations needed such that there is at least one occurrence of k consecutive black blocks.

 
// Example: 

    Example 1:

        Input: blocks = "WBBWWBBWBW", k = 7
        Output: 3
        Explanation:
        One way to achieve 7 consecutive black blocks is to recolor the 0th, 3rd, and 4th blocks
        so that blocks = "BBBBBBBWBW". 
        It can be shown that there is no way to achieve 7 consecutive black blocks in less than 3 operations.
        Therefore, we return 3.

    Example 2:

        Input: blocks = "WBWBBBW", k = 2
        Output: 0
        Explanation:
        No changes need to be made, since 2 consecutive black blocks already exist.
        Therefore, we return 0.

// Observations:
    -> The string consists of 'W' (white) and 'B' (black) blocks.
    -> To achieve `k` consecutive black blocks, we need to minimize the number of 'W' blocks in any `k`-sized window.
    -> Each 'W' block in the chosen window requires one recolor operation.
    -> Our goal is to find the window with the minimum number of 'W' blocks.

    // Thought Process (Optimal Approach - Sliding Window):
        -> Use a sliding window of size `k`.
        -> First, count the number of 'W' blocks in the initial `k`-sized window.
        -> As the window slides forward:
        - Add the character at the front of the window.
        - Remove the character at the back of the window.
        -> Track the minimum number of 'W' blocks encountered during this process.
        -> This minimum value represents the required number of recolor operations.


// Complexity: 
    -> TC: O(N)
    -> SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int minimumRecolors(string s, int k) {
        int n = s.size();
        if(k > n) return 0; // if k is greater than n -> not-possible

        // Count Black & white in first 'k' sized window:
        int black = 0, white = 0;
        int i = 0, j = 0; 

        while(j < k) {
            if(s[j] == 'B') black++;
            else white++;
            j++;
        }

        int minRemoval = white;

        // Now Process the rest of the window:
        while(j < n) {
            // Additions of front block:
            if(s[j] == 'B') black++;
            else white++;

            // Removal of last block:
            if(s[i] == 'B') black--;
            else white--;

            minRemoval = min(minRemoval, white);    // Store answer:

            // Move both pointer forward:
            j++;
            i++;
        }

        return minRemoval;
    }
};