/*

//  3318. Find X-Sum of All K-Long Subarrays I


//  Problem Statement: 
    -> You are given an array nums of n integers and two integers k and x.
    -> The x-sum of an array is calculated by the following procedure:
        -> Count the occurrences of all elements in the array.
        -> Keep only the occurrences of the top x most frequent elements. If two elements have the same number of occurrences, the element with the bigger value is considered more frequent.
        -> Calculate the sum of the resulting array.
    -> Note that if an array has less than x distinct elements, its x-sum is the sum of the array.
    -> Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the
    -> nums[i..i + k - 1].

 
// Example: 
    Example 1:
        Input: nums = [1,1,2,2,3,4,2,3], k = 6, x = 2
        Output: [6,10,12]
        Explanation:
            For subarray [1, 1, 2, 2, 3, 4], only elements 1 and 2 will be kept in the resulting array. Hence, answer[0] = 1 + 1 + 2 + 2.
            For subarray [1, 2, 2, 3, 4, 2], only elements 2 and 4 will be kept in the resulting array. Hence, answer[1] = 2 + 2 + 2 + 4. Note that 4 is kept in the array since it is bigger than 3 and 1 which occur the same number of times.
            For subarray [2, 2, 3, 4, 2, 3], only elements 2 and 3 are kept in the resulting array. Hence, answer[2] = 2 + 2 + 2 + 3 + 3.

    Example 2:
        Input: nums = [3,8,7,8,7,5], k = 2, x = 2
        Output: [11,15,15,15,12]
        Explanation: Since k == x, answer[i] is equal to the sum of the subarray nums[i..i + k - 1].
    


// Observations: 
    - we need to select k size subarray
    - we will choose top x most frequent element
        - If two element have same number of frequency, choose bigger value..

    // Bruteforce Approach:
        - Select 'k' size subarray
        - Maintain frequency
        - choose top x most frequent element..

    // Complexity:  
        - TC: O(n * k + n * k * logk)
        - SC: O(n * k)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();

        vector<int> ans;

        for(int i = k - 1; i < n; i++) {

            // hash the values:
            unordered_map<int, int> mp;
            for(int j = i - k + 1; j <= i; j++) {
                mp[nums[j]]++;
            }

            // build a list by <freq: element> order..
            vector<pair<int, int>> freq;
            for(auto &[num, fre]: mp) {
                freq.push_back({fre, num});
            }
        
            sort(rbegin(freq), rend(freq)); // sort in descending order:

            // Last get the sum of top 'x' element:
            int sum = 0;
            for(int j = 0; j < min(x, (int)freq.size()); j++) {
                sum += freq[j].first * freq[j].second;
            }
            
            ans.push_back(sum); // store sum
        }

        return ans;
    }
};