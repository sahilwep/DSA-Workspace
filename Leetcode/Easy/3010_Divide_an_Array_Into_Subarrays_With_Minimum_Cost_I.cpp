/*

//  3010. Divide an Array Into Subarrays With Minimum Cost I


//  Problem Statement: 
    - You are given an array of integers nums of length n.
    - The cost of an array is the value of its first element. For example, the cost of [1,2,3] is 1 while the cost of [3,4,1] is 3.
    - You need to divide nums into 3 disjoint contiguous .
    - Return the minimum possible sum of the cost of these subarrays.

 
// Example:
    Example 1:
        Input: nums = [1,2,3,12]
        Output: 6
        Explanation: The best possible way to form 3 subarrays is: [1], [2], and [3,12] at a total cost of 1 + 2 + 3 = 6.
        The other possible ways to form 3 subarrays are:
        - [1], [2,3], and [12] at a total cost of 1 + 2 + 12 = 15.
        - [1,2], [3], and [12] at a total cost of 1 + 3 + 12 = 16.

    Example 2:
        Input: nums = [5,4,3]
        Output: 12
        Explanation: The best possible way to form 3 subarrays is: [5], [4], and [3] at a total cost of 5 + 4 + 3 = 12.
        It can be shown that 12 is the minimum cost achievable.

    Example 3:
        Input: nums = [10,3,1,1]
        Output: 12
        Explanation: The best possible way to form 3 subarrays is: [10,3], [1], and [1] at a total cost of 10 + 1 + 1 = 12.
        It can be shown that 12 is the minimum cost achievable.

 
// Observations:
    - We have to separate array into 3 subarray disjoint.
    - We have to include first element of every subarray.
        - arr[0] can't be skipped, because it should be included, either we take single arr[0], or some subarray arr[0]...[i]
    - We have to find two more subarray
        - first element should be minimum so that whole cost of 3 subarray is minimum, in simple we have to find two minimum elements from the remaining array.
        - Now we have to find the two minimum elements among all the subarray.
            - minimum, and second_min
                - minimum & second_min search start from idx = 1
            - and compute all three cost: arr[0] + minimum + second_minimum


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient Approach: TC: O(n), SC: O(1)
class Solution {
private:
    int n;
    int sumOfMinAndSecondMin(vector<int>& nums) {   // function to find min & second min & returning sum
        int min = INT_MAX;
        int secondMin = min;

        for(int i = 1; i < n; i++) {
            if(nums[i] < min) {
                secondMin = min;
                min = nums[i];
            } else if(nums[i] >= min && nums[i] < secondMin) {
                secondMin = nums[i];
            }
        }

        return min + secondMin;
    }
public:
    int minimumCost(vector<int>& nums) {
        n = nums.size();

        return nums[0] + sumOfMinAndSecondMin(nums);
    }
};


// Sorting Approach: TC: O(n*logn), SC: O(1)
class Solution {
private:
public:
    int minimumCost(vector<int>& nums) {

        sort(nums.begin() + 1, nums.end()); // sort from index=1
        return nums[0] + nums[1] + nums[2]; // 3 minimum element we will have
    }
};