/*

//  1390. Four Divisors


//  Problem Statement: 
    - Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. 
    - If there is no such integer in the array, return 0.

//  Example:

    Example 1:
        Input: nums = [21,4,7]
        Output: 32
        Explanation: 
        21 has 4 divisors: 1, 3, 7, 21
        4 has 3 divisors: 1, 2, 4
        7 has 2 divisors: 1, 7
        The answer is the sum of divisors of 21 only.

    Example 2:
        Input: nums = [21,21]
        Output: 64

    Example 3:
        Input: nums = [1,2,3,4,5]
        Output: 0

// Observations:
    - We are given nums of size 'n'
    - we have to find the nums[i] that has 4 divisor.
        - We have to compute the sum of that, & return into answer.

    // Bruteforce Approach:
        - For every nums[i]:
            - compute the divisors:
                - iterating from 1 <= j <= nums[i]
                - If any 'j' divisible by nums[i] add that into our answer..
        
        // Complexity:
            - TC: O(n * max(nums[i]))
            - SC: (1)

    // Optimization:
        - As we have to compute the divisors:
            - we can use sqrt() logic to compute:
            - If we iterate from 1 <= j <= sqrt(nums[i])
                - the 'j' that are divisible by nums[i]:
                    - add j
                    - add (num/j) if (j != num/j)
            - This will improve our internal loop complexity from max(nums[i]) to sqrt(max(nums[i]))

        // Complexity:
            - TC: O(n * sqrt(max(nums[i])))
            - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Optimized: TC: (n * sqrt(max(num)))
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        
        int ans = 0;
        for(auto &num: nums) {  // TC: O(n)
            int tempSum = 0;
            int cnt = 0;
            for(int i = 1; i <= sqrt(num); i++) {   // TC: O(sqrt(max(num)))
                if(num % i == 0) {  // for divisible:
                    tempSum += i;   // add (i)
                    cnt++;
                    

                    // if i & num/i is not same:
                    if(i != num/i) {    
                        tempSum += num/i;   // add(num/i)
                        cnt++;
                    }
                }
            }
            
            if(cnt == 4) {
                ans += tempSum;
            }
        }

        return ans;
    }
};

// Bruteforce: TC: O(n * (max(num)))
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        
        int ans = 0;
        for(auto &num: nums) {
            int tempSum = 0;
            int cnt = 0;
            // Compute Divisors:
            for(int i = 1; i <= num; i++) {
                if(num % i == 0) {
                    tempSum += i;
                    cnt++;
                }
            }

            if(cnt == 4) {
                ans += tempSum;
            }
        }

        return ans;
    }
};