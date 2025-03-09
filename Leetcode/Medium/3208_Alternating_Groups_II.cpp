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

// Sliding Window Approach:
class Solution {
public:
    // we can use sliding window approach:
    int numberOfAlternatingGroups(vector<int>& s, int k) {
        int n = s.size();   // size
        int cnt = 0;    // counter
        bool isAlt = true;
        // finding first k size window matching...
        for (int i = 1; i < k; ++i) {
            if (s[i] == s[i - 1]) {
                isAlt = false;
                break;
            }
        }
        // if we have the first window match the pattern..
        if(isAlt){
            cnt++;
        } 

        // Use sliding window to check the rest of the elements
        for (int i=k;i<n+k-1;i++) {
            if (s[i % n] == s[(i - 1) % n]) {
                isAlt = false;
            } else if (s[(i - k) % n] == s[(i - k + 1) % n]) {
                isAlt = true;
                for (int j = 1; j < k; j++) {
                    if (s[(i - k + j + 1) % n] == s[(i - k + j) % n]) {
                        isAlt = false;
                        break;
                    }
                }
            }   
            if(isAlt){
                cnt++;
            } 
        }
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