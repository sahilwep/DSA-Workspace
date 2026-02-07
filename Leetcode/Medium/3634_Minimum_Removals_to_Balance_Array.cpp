/*

//  3634. Minimum Removals to Balance Array


//  Problem Statement: 
    - You are given an integer array nums and an integer k.
    - An array is considered balanced if the value of its maximum element is at most k times the minimum element.
    - You may remove any number of elements from nums​​​​​​​ without making it empty.
    - Return the minimum number of elements to remove so that the remaining array is balanced.
    - Note: An array of size 1 is considered balanced as its maximum and minimum are equal, and the condition always holds true.

 
// Example:
    Example 1:
        Input: nums = [2,1,5], k = 2
        Output: 1
        Explanation:
            Remove nums[2] = 5 to get nums = [2, 1].
            Now max = 2, min = 1 and max <= min * k as 2 <= 1 * 2. Thus, the answer is 1.

    Example 2:
        Input: nums = [1,6,2,9], k = 3
        Output: 2
        Explanation:
            Remove nums[0] = 1 and nums[3] = 9 to get nums = [6, 2].
            Now max = 6, min = 2 and max <= min * k as 6 <= 2 * 3. Thus, the answer is 2.

    Example 3:
        Input: nums = [4,6], k = 2
        Output: 0
        Explanation: Since nums is already balanced as 6 <= 4 * 2, no elements need to be removed.

 



// Observations:
    - We are given array nums & k
    - we need to find the minimum number of removal of element such that we will have balanced array that follows: 
        - maxElement <= minElement * k 


    // Approach:
        - If we observe the constrains, 10e5, which accepts n and n*logn solution.
        - If we carefully observe the problem, we will have to find the largest balanced array that follows
            - maxElement <= minElement * k
        - We need to sort the element for checking minElement & maxElement in efficient way.
            - minElement found on starting & maxElement found at end
        - Now we need to use Two pointer approach and find the valid largest balanced array that follows the rule.
        - the leftOver from the balanced array size will be our minimum removal.
        - i & j pointer start from index '0'
            - if our window i...j follows the given rule: move j & expands the size of balanced array.
            - If our window i...j didn't follows the given rule:
                if(nums[i] * k < nums[j]) move ith pointer further
                because, anyway if we not move ith pointer further our overall value (nums[i] * k) never be be grater equal to nums[j], logically.
        - Now all we need to find is size everytime & we will have to take as-minimum as possible.

        // Finding size of removed elements:
            - let's analyze with range:
    
                0....i............j........n        whole array, somewhere we have i & j
                |.................| j               0 to j range
                |....| i                            0 to i range
                     |............| j - i           i to j range

                    balanced array j - i 
                    left over = n - balanced array => n - j - i
                    + 1 to handel the 0-based indexing

        // Complexity:  
            - TC: O(n*logn + n)   => O(n * logn)
            - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
    typedef long long ll;
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();

        sort(begin(nums), end(nums));   // sort to make every things in order, TC: O(n*logn)

        
        int i = 0, j = 0;
        int removal = n;    // in worse we will remove all.
        while(j < n) {  // TC: O(n)
            ll minEl = nums[i];
            ll maxEl = nums[j];
            ll givenCond = 1LL * minEl * k;
            if(i < j && maxEl > givenCond) {    // if given rule violates: (max <= min * k) move ith pointer.
                i++;
            }

            // else calculate size & move jth pointer.

            // Get the size:
            int bSize = j - i + 1;              // size of balanced array
            int leftOver = n - bSize;           // subtract from n
            removal = min(removal, leftOver);   // store min-removal

            j++;    // everytime move j pointer forward
        }

        return removal;
    }
};