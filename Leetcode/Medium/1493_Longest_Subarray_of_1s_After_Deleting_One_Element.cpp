/*

//  1493. Longest Subarray of 1's After Deleting One Element


//  Problem Statement: 
    -> Given a binary array nums, you should delete one element from it.
    -> Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 
// Example:
    Example 1:
        Input: nums = [1,1,0,1]
        Output: 3
        Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

    Example 2:
        Input: nums = [0,1,1,1,0,1,1,0,1]
        Output: 5
        Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

    Example 3:
        Input: nums = [1,1,1]
        Output: 2
        Explanation: You must delete one element.


// Observations: 
    -> We have to find the longest Subarray of 1's after deleting one element.
    -> We can delete one 0, if there is a continuous sequence of 1's


// Example Visualization:
    -> Count the subarray & their gap

    [0,1,1,1,0,1,1,0,1]
    [1]  3  [1] 2 [1] 1         -> here we have only 1 gap of 0's

    [0,1,1,1,0,1,1,0,1,1,1,1,]
    [1]  3  [1] 2 [1]   4       -> here also we have 1 gap of 0's


    [0,1,1,1,0,1,1,0,0,1,1,1,1,]
    [1]   3   [1]  2  [2]    4  -> here, we have 2 gap of 0's


// BruteForce Approach:
    -> Using nested loop compute the longest subarray group by skipping one 0's
        -> First find first set of longest 1's
        -> skip one 0's
        -> Compute second set of longest 1's
        -> At last compute the longest subarray
    -> EDGE CASE: Handel all 1's saperately


    // Complexity: 
        -> TC: O(n^2)
        -> SC: O(1)

// Efficient Solution: 
    -> Efficient Solution can be build upon the bruteforce Solution.
    -> Observe the pattern of subarray sequences in given array
    -> First count all the 1's & store it somewhere, making sure that there should be only one 0's b/w them, if we have more than 0's b/w them, then stuff with 0's
    -> Example:

            [0,1,1,1,0,1,1,0,0,1,1,1,1,]
                3       2       4

            {3, 2, 0, 4}    -> When we have more than one 0's then try stuffing the 0's in list
    
    -> Last add two adjacent elements & find longest subarray

    // Example:
        [0,1,1,1,0,1,1,0,0,1,1,1,1,]

        list: {3, 2, 0, 4}
        ans = 0

                ans = max(ans, 3 + 2) = 5
                ans = max(ans, 2 + 0) = 2
                ans = max(ans, 0 + 4) = 4
    
    // Complexity: 
        -> TC: O(n)
        -> SC: O(n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient Solution: TC: O(n), SC: O(n)
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        // Store the Longest 1's groups:
        vector<int> temp;   // This auxilary array used to store the continuous 1's sequences.
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {  // if we have 1's count that
                cnt++;
            } else {    // whenever we encounter with 0's   -> if we have multiple 0's in sequence, this will make sure to stuff 0's in list.
                temp.push_back(cnt);    // store that counted result
                cnt = 0;                // reset counter
            }
        }
        temp.push_back(cnt);    // push the leftover.


        if(temp.size() == 1) return n - 1;  // Edge case: If we have only one element in list, means all the elements are 1's


        // Last, Compute sum two adjacent element & find the longest subarray:
        int ans = 0;
        for(int i = 1; i < temp.size(); i++) {
            ans = max(ans, (temp[i-1] + temp[i]));
        }

        return ans;
    }
};



// BruteForce Solution: TC: O(n^2)
class Solution {
private: 
    bool isAllOnes(vector<int>& nums) {  // O(n), SC: O(1)
        for(auto& it: nums) if(it == 0) return false;
        return true;
    }
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        if(isAllOnes(nums)) return n - 1;   // check if all the given elements are 1's

        // Compute two longest subarray Groups:
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            // Get the first Set of 1's count:
            int j = i;
            for(j; j < n; j++) {
                if(nums[j] == 0) {
                    break;
                }
                cnt++;
            }

            j++;    // move one element ahead:
            if(j < n && nums[j] == 0) { // skip if we have multiple 0's
                ans = max(ans, cnt);
                continue; 
            } 

            // Else: Get the second Set of 1's count:
            for(j; j < n; j++) {
                if(nums[j] == 0) break;
                cnt++;
            }

            // Store the largest size subarray:
            ans = max(ans, cnt);
        }

        return ans;
    }
};