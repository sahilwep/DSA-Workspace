/*

//  2149. Rearrange Array Elements by Sign


//  Problem Statement: 
    -> You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
    -> You should return the array of nums such that the the array follows the given conditions:
        -> Every consecutive pair of integers have opposite signs.
        -> For all integers with the same sign, the order in which they were present in nums is preserved.
        -> The rearranged array begins with a positive integer.
    -> Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

 
// Example:
    Example 1:
        Input: nums = [3,1,-2,-5,2,-4]
        Output: [3,-2,1,-5,2,-4]
        Explanation:
        The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
        The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
        Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions.  

    Example 2:
        Input: nums = [-1,1]
        Output: [1,-1]
        Explanation:
        1 is the only positive integer and -1 the only negative integer in nums.
        So nums is rearranged to [1,-1].

//  Observations: 
    -> We are given array with exactly same number of positive & negative numbers.
    -> we need to build an answer vector, where positive & negative numbers are adjacent to each other.


    // Bruteforce Approach: 
        -> Extract, positive & negative numbers & then build answer.


        // Complexity: 
            -> TC: O(n)
            -> SC: O(n)

    // Efficient Approach: 
        -> Use two pointer, one for positive & one for negative
            -> Every positive numbers lies on: 0, 2, 4,.. even positions
            -> Every negative numbers lies on: 1, 3, 5,.. odd positions
        -> We can set two pointers one for negative & one for positive & move accordingly.
        -> Build answer by iterating in given list.

        // Complexity: 
            -> TC: O(n)
            -> SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient Solution: 
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);
        int pos = 0;
        int neg = 1;
        for(int i = 0; i < n; i++)  {
            if(nums[i] < 0) {
                ans[neg] = nums[i];
                neg += 2;
            } else {
                ans[pos] = nums[i];
                pos += 2;
            }
        }
 
        return ans;
    }
};

// BruteForce Solution:
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        // Extract -ve & +ve elements:
        vector<int> pos, neg;
        for(auto& it: nums) {
            if(it >= 0) pos.push_back(it);
            else neg.push_back(it);
        }

        // Build answer: 
        vector<int> ans;
        int k = 0;
        for(int i = 0; i < (n / 2); i++) {
            ans.push_back(pos[k]);
            ans.push_back(neg[k++]);
        }

        return ans;
    }
};