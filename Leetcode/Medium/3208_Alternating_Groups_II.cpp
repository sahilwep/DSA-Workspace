/*

//  3208. Alternating Groups II


//  Problem Statement: 
    -> There is a circle of red and blue tiles. You are given an array of integers colors and an integer k. The color of tile i is represented by colors[i]:
        -> colors[i] == 0 means that tile i is red.
        -> colors[i] == 1 means that tile i is blue.
    -> An alternating group is every k contiguous tiles in the circle with alternating colors (each tile in the group except the first and last one has a different color from its left and right tiles).
    -> Return the number of alternating groups.
    -> Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.


// Example:

    Example 1:
        Input: colors = [0,1,0,1,0], k = 3
        Output: 3

    Example 2:
        Input: colors = [0,1,0,0,1,0,1], k = 6
        Output: 2

    Example 3:

        Input: colors = [1,1,0,1], k = 4
        Output: 0

        

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient Approach:
// Another Sliding window Approach -> Only counting the valid pairs and matching with window size:
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();

        // Edge case: If k is greater than n, no valid group can exist
        if (k > n) return 0;

        int ans = 0;
        int validPairs = 0;  // Count of valid alternating pairs in the current window

        // Initial window setup (first k elements)
        for (int i = 0; i < k - 1; i++) {
            if (colors[i] != colors[i + 1]) validPairs++;
        }

        // If the first window is valid
        if (validPairs == k - 1) ans++;

        // Sliding window logic
        for (int i = 1; i < n; i++) {
            // Remove the outgoing element valid pairs:
            if (colors[i - 1] != colors[(i) % n]) validPairs--;
            
            // Add the incoming element valid pairs:
            if (colors[(i + k - 2) % n] != colors[(i + k - 1) % n]) validPairs++;

            // Check if current window is valid:
            if (validPairs == k - 1) ans++;
        }

        return ans;
    }
};
    

// Sliding Window Approach for Counting Alternating Groups
class Solution {
public:
    // Function to count the number of alternating groups of size 'k'
    int numberOfAlternatingGroups(vector<int>& s, int k) {
        int n = s.size();    // Size of the array
        int cnt = 0;         // Counter for valid alternating groups
        bool isAlt = true;   // Flag to track if current window is alternating

        // Step 1: Check the first 'k' elements to see if they form a valid alternating group
        for (int i = 1; i < k; ++i) {
            if (s[i] == s[i - 1]) {  // Consecutive elements should differ
                isAlt = false;      // Found a pair that breaks the alternating condition
                break;              // Exit the loop as this window is invalid
            }
        }

        // Step 2: If the first window is valid, increment the count
        if (isAlt) {
            cnt++;  // First window is a valid alternating group
        }

        // Step 3: Sliding Window logic to check subsequent windows
        for (int i = k; i < n + k - 1; i++) {
            // Step 3.1: Check the new element entering the window
            if (s[i % n] == s[(i - 1) % n]) {
                isAlt = false;  // Consecutive elements are the same — window becomes invalid
            } 
            // Step 3.2: Check the element that is leaving the window
            else if (s[(i - k) % n] == s[(i - k + 1) % n]) {
                isAlt = true;  // Recheck the new window for alternating condition
                
                // Step 3.3: Ensure the entire window maintains the alternating condition
                for (int j = 1; j < k; j++) {
                    if (s[(i - k + j + 1) % n] == s[(i - k + j) % n]) {
                        isAlt = false;  // Found a non-alternating pair
                        break;          // No need to check further
                    }
                }
            }   

            // NOTE: if our entering & exiting elements are already true, our flow will not fall into any condition, it directly incremented the count.

            // Step 4: If the current window is valid, increment the count
            if (isAlt) {
                cnt++;
            } 
        }

        // Step 5: Return the total number of valid alternating groups
        return cnt;
    }
};


// BruteForce Solution:
class Solution {
private:
    bool check(vector<int> &clr, int start, int end) {  // function to check alternating group in given range.
        for(int i = start + 1; i <= end; i++) {
            if(clr[i] == clr[i-1]) return false;
        }

        return true;
    }
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int size = colors.size();
        
        // Create an array of twice size of given colors & duplicates the values in it.
        vector<int> clr = colors;
        for(auto &it: colors) clr.push_back(it);

        int n = clr.size();
        int i = 0;      // first pointer start from 0
        int j = k-1;    // second pointer is at difference of k from first pointer.


        int ans = 0;
        while(i < size) {       // process while first pointer not reaches to colors size
            if(check(clr, i, j)) {  // check alternative group in given range (i, j)
                ans++;
            }
            i++;
            j++;
        }

        return ans;
    }
};