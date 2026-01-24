/*

//  3507. Minimum Pair Removal to Sort Array I


//  Problem Statement: 
    - Given an array nums, you can perform the following operation any number of times:
        - Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
        - Replace the pair with their sum.
    - Return the minimum number of operations needed to make the array non-decreasing.
    - An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).


// Example:
    Example 1:
        Input: nums = [5,2,3,1]
        Output: 2
        Explanation:
                The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
                The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
            The array nums became non-decreasing in two operations.


    Example 2:
        Input: nums = [1,2,2]
        Output: 0
        Explanation: The array nums is already sorted.



// Observations:
    - Given nums, we have to choose the adjacent pair with minimum sum, if multiple pair exist choose leftmost.
        - remove both the elements and insert the sum at the index.
    - we can perform these operations any number of time.
    - we have to return minimum number of operations to make our array non-decreasing order.


    // Approach:
        - until our array is not sorted or we left with single element.
        - Every time choose the pair for which we have minimum sum.
            - Remove those element & insert the sum of the element.
            - We will keep counting the operations.
        - Last we will have to return the count.
        - This whole approach takes O(N^2)


    // Complexity:
        - TC: O(n^2)
        - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private:
    void removeAtIdx(vector<int>& nums, int idx) {

        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            if(i == idx) continue;
            res.push_back(nums[i]);
        }

        nums = res;
    }
public:
    int minimumPairRemoval(vector<int>& nums) {

        int opr = 0;
        while(nums.size() > 1) {
            
            bool isAscending = true;
            int miniSum = INT_MAX;
            int targetIdx = -1;
            for(int i = 0; i < nums.size() - 1; i++) {
                int sum = nums[i] + nums[i + 1];

                if(nums[i] > nums[i + 1]) {
                    isAscending = false;
                }

                if(sum < miniSum) {
                    miniSum = sum;
                    targetIdx = i;
                }
            }

            if(isAscending) break;  // break out as sorted
            
            nums[targetIdx] = miniSum;
            removeAtIdx(nums, targetIdx + 1);
            opr++;
        }

        return opr;
    }
};