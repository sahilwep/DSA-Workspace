/*

//  2654. Minimum Number of Operations to Make All Array Elements Equal to 1


//  Problem Statement: 
    - You are given a 0-indexed array nums consisiting of positive integers. You can do the following operation on the array any number of times:
    - Select an index i such that 0 <= i < n - 1 and replace either of nums[i] or nums[i+1] with their gcd value.
    - Return the minimum number of operations to make all elements of nums equal to 1. If it is impossible, return -1.
    - The gcd of two integers is the greatest common divisor of the two integers.


 
// Example: 
    Example 1:
        Input: nums = [2,6,3,4]
        Output: 4
        Explanation: We can do the following operations:
        - Choose index i = 2 and replace nums[2] with gcd(3,4) = 1. Now we have nums = [2,6,1,4].
        - Choose index i = 1 and replace nums[1] with gcd(6,1) = 1. Now we have nums = [2,1,1,4].
        - Choose index i = 0 and replace nums[0] with gcd(2,1) = 1. Now we have nums = [1,1,1,4].
        - Choose index i = 2 and replace nums[3] with gcd(1,4) = 1. Now we have nums = [1,1,1,1].

    Example 2:
        Input: nums = [2,10,6,14]
        Output: -1
        Explanation: It can be shown that it is impossible to make all the elements equal to 1.


// Observations:
    - if we have any one nums[i] = 1, then we are able to make all nums to '1'
        ex: [5,3,1,6,7] 
            one = 1
            ans = n - one
            ans = 5 - 1 => 4

        ex: [5,3,1,6,3,1,7] 
            one = 2
            ans = n - one
            ans = 7 - 2 = 5
            
            So, we need to count all the number of 1's, then we can simply subtract it form 'n - one_cnt'
    
    - if we don't have any 1's in our "nums"
        ex: [2,6,3,4]

            we will have to make atleast one 1's by doing gcd bruteforce way
            We will try to implement whatever we have given

            from every ith position, 
                - we will try to find the shortest subarray length 'j - i', which makes atleast 1's
                - We will choose the minimum one: 
                    opr: "j - i"   => which is our subarray size
                - Then we can simply add "n-1" extra operations to make all the remaining nums as 1's


// Complexity:  
    -> TC: O(n^2)
    -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        // First check if we have any 1's in our or not?
        int oneCnt = 0;
        for(auto &num: nums) {
            if(num == 1) oneCnt++;
        }

        if(oneCnt > 0) {
            return n - oneCnt;  // return the remaining operations required to make all nums as 1's
        }

        // Now try to make atleast one 1's -> Try find shortest subarray which make atleast 1's
        int minLen = INT_MAX;   // This minLen is the min-Operations  which we required to make atleast one '1' in our nums.
        for(int i = 0; i < n; i++) {
            int g = 0;  // computing gcd
            for(int j = i; j < n; j++) {
                g = gcd(g, nums[j]);

                // Check if we are able to make 1 or not?
                if(g == 1) {
                    minLen = min(minLen, j - i);
                    break;
                }
            }
        }

        // After getting minimum, we will add the remaining "n - 1" operations.
        int opr = (minLen == INT_MAX) ? -1 : minLen + n - 1;   // opr + "n - 1" required to make all 1's

        return opr;
    }
};