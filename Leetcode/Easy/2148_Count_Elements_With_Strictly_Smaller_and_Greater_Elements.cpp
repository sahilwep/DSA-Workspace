/*

//  2148. Count Elements With Strictly Smaller and Greater Elements


//  Problem Statement: 
    - Given an integer array nums, return the number of elements that have both a strictly smaller and a strictly greater element appear in nums.

    
    Example 1:
        Input: nums = [11,7,2,15]
        Output: 2
        Explanation: The element 7 has the element 2 strictly smaller than it and the element 11 strictly greater than it.
        Element 11 has element 7 strictly smaller than it and element 15 strictly greater than it.
        In total there are 2 elements having both a strictly smaller and a strictly greater element appear in nums.

    Example 2:
        Input: nums = [-3,3,3,90]
        Output: 2
        Explanation: The element 3 has the element -3 strictly smaller than it and the element 90 strictly greater than it.
        Since there are two elements with the value 3, in total there are 2 elements having both a strictly smaller and a strictly greater element appear in nums.

// Observations:
    - given list of nums
    - we need to count the number of elements who have both strictly smaller & strictly grater..

    // Bruteforce: 
        - use nested loop & find smaller & grater if they exist count them in.

        // Complexity:
            - TC: O(n^2)
            - SC: O(1)


    // Optimization:
        - if we get maximum & smallest, first then we can easily count the reaming nums..
        - all element should be counted except smaller & bigger:
            eg: 
                [-3, 3, 3, 4, 5, 11]
                min = -3
                max = 11

                remaining all the element in b/w is are the ones, who follows the rule..

    // Complexity:
        - TC: O(n)
        - SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Optimized Version: TC: O(n)
class Solution {
public:
    int countElements(vector<int>& nums) {  // TC: O(n)
        int n = nums.size();

        // find min & max:
        int minEl = *min_element(begin(nums), end(nums));
        int maxEl = *max_element(begin(nums), end(nums));

        // Edge case: if min & max are same: no such element
        if(minEl == maxEl) return 0;

        // Now iterate & find the element that have this conditions:
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(minEl < nums[i] && nums[i] < maxEl) cnt++;
        }

        return cnt;
    }
};


// Bruteforce Solution:
class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return 0;
        
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            int num = nums[i];
            bool smaller = false, greater = false;
            for(auto &it: nums) {
                if(it < nums[i]) smaller = true;
                if(it > nums[i]) greater = true;
            }
            if(smaller == true && greater == true) cnt++;
        }
      
        return cnt;
    }
};
