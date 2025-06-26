/*

//  697. Degree of an Array


//  Problem Statement: 
    -> Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
    -> Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

 
// Example: 
    Example 1:
        Input: nums = [1,2,2,3,1]
        Output: 2
        Explanation: 
        The input array has a degree of 2 because both elements 1 and 2 appear twice.
        Of the subarrays that have the same degree:
        [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
        The shortest length is 2. So return 2.

    Example 2:
        Input: nums = [1,2,2,3,1,4,2]
        Output: 6
        Explanation: 
        The degree is 3 because the element 2 is repeated 3 times.
        So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.

// Observations: 
    -> Approach is quite simple: 
        -> first hash the the frequency.
        -> Get the valid degrees.
        -> Compute the shortest length.

    // Complexity: 
        -> TC: O(n)
        -> SC: O(n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    int firstOccur(vector<int>& nums, int n, int degree) {
        int start = 0;
        for(; start < n; start++) {
            if(nums[start] == degree) break;
        }
        
        return start;
    }
    int lastOccur(vector<int>& nums, int n, int degree) {

        int end = n-1;
        for(; end >= 0; end--) {
            if(nums[end] == degree) break;
        }

        return end;
    }
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();

        // Hash Frequency:
        unordered_map<int, int> mp;
        for(auto &num: nums) {
            mp[num]++;
        }

        // Find the valid degrees:
        int freq = 0;
        vector<int> degree;
        for(auto &[key, val]: mp) {
            if(val > freq) {
                freq = val;
                degree.clear();
                degree.push_back(key);
            }
            else if(val == freq) {
                degree.push_back(key);
            }
        }

        // Compute the shortest ones:
        int minSize = INT_MAX;
        for(auto &it: degree) {
            int first = firstOccur(nums, n, it);
            int last = lastOccur(nums, n, it);

            minSize = min(minSize, last - first + 1);
        }

        return minSize;
    }
};