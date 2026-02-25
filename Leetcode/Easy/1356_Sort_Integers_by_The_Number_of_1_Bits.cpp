/*

//  1356. Sort Integers by The Number of 1 Bits


//  Problem Statement: 
    - You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.
    - Return the array after sorting it.

 
// Example:
    Example 1:
        Input: arr = [0,1,2,3,4,5,6,7,8]
        Output: [0,1,2,4,8,3,5,6,7]
        Explantion: [0] is the only integer with 0 bits.
            [1,2,4,8] all have 1 bit.
            [3,5,6] have 2 bits.
            [7] has 3 bits.
            The sorted array by bits is [0,1,2,4,8,3,5,6,7]

    Example 2:
        Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
        Output: [1,2,4,8,16,32,64,128,256,512,1024]
        Explantion: All integers have 1 bit in the binary representation, you should just sort them in ascending order.

 
// Observations:
    - we are given array with several number
    - we nee dto sort all the number based on their set bits.

    // Approach:
        - For Every number get their bits count.
        - sort them according to their bits count.
        - return the answer.

    // Complexity:
        - TC: O(n * logn)
        - SC: O(n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private:
    int countBits(int n) {

        int cnt = 0;

        for(int i = 1; i <= 32; i++) {
            cnt += n & 1;
            n >>= 1;
        }

        return cnt;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        // Count bits of every nums
        vector<pair<int, int>> nums;
        for(auto &num: arr) {
            int totalBit = countBits(num);
            nums.push_back({totalBit, num});
        }

        // Sort & return the valid answer.
        sort(begin(nums), end(nums));

        vector<int> res;
        for(auto &it: nums) {
            res.push_back(it.second);
        }

        return res;
    }
};