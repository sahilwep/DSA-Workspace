/*

//  2616. Minimize the Maximum Difference of Pairs | Binary Search On Answer |


//  Problem Statement: 
    -> You are given a 0-indexed integer array nums and an integer p. Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized. Also, ensure no index appears more than once amongst the p pairs.
    -> Note that for a pair of elements at the index i and j, the difference of this pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.
    -> Return the minimum maximum difference among all p pairs. We define the maximum of an empty set to be zero.

 
// Example: 

    Example 1:
        Input: nums = [10,1,2,7,1,3], p = 2
        Output: 1
        Explanation: The first pair is formed from the indices 1 and 4, and the second pair is formed from the indices 2 and 5. 
        The maximum difference is max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1. Therefore, we return 1.

    Example 2:
        Input: nums = [4,2,1,2], p = 1
        Output: 0
        Explanation: Let the indices 1 and 3 form a pair. The difference of that pair is |2 - 2| = 0, which is the minimum we can attain.

// Observations: 
    -> We are Given nums & from that nums, we have to select p pairs such that
    -> each pairs element are unique, no two pairs have same elements.
    -> To get minimum difference b/w pairs 
        nums = [10,1,2,7,1,3], p = 2    -> ans = 1

            We have to select the minimum difference values like: 
                (1, 1), (1, 2), (2, 3), (3, 7), (7, 10)
            These pairs will give us minimum differences

        -> If we sort our given nums, our job will be easy..

            nums = [1,1,2,3,7,10]   -> nums will look something like this..
        
            From the above sorted nums, pairs which will gives us minimum values are: 
                
                (1, 1), (1, 2), (2, 3), (3, 7), (7, 10) -> apart from them there is no such pairs which will give lesser values than them

            After sorting the nums, adjacent elements will give us the minimum difference..
    
        -> Now we have to choose (p = 2) pairs
            we have to choose 2 pairs among all the pairs:   

                                p1 (d1)  & p2 (d2)  ->  max(d1, d2) => x1
                                p3 (d3)  & p4 (d4)  ->  max(d3, d4) => x2
                                p5 (d5)  & p6 (d6)  ->  max(d5, d6) => x3
                                p7 (d7)  & p8 (d8)  ->  max(d7, d8) => x4
                                ...
                                ...
                                till nth term
                                            -----------------------------
                                                        min(x1, x2, x3, x4,.. xn)

            
            From all the possibility:
                Let's say we have tow possibility:

                    P1(d1) & p2(d2) => max(d1, d2)  -> 1    
                    P3(d3) & p4(d4) => max(d3, d4)  -> 7    In second one we got our maximum difference is 7

                        In first one we got our maximum difference is 1, 
                        means the difference is definitely be (<= 1), 
                        this is why we got our maximum value from (d1 & d2) is 1

                        In second one we got our maximum difference is 7
                        means the difference is definitely be (<= 7),
                        this is why we got our maximum value from (d3 & d4) is 7

                        Similarly if we have choosen other pairs case, 
                        there must be some maximum difference value for that pairs
                        and that all the pairs difference will lies within it.

                    
                    We know for the given nums, our answer is 1.
                    Let's say if our answer is '0'
                        In that case, we have to find total number of pairs whose difference is <= '0'
                            nums = [1,1,2,3,7,10]   -> (1, 1), we have only 1 pair, so we can't take because our requires 2 pairs
                    
                    Let's say if our answer is '1'
                        In that case we have to find total number of pairs whose difference is  <= '1'
                            nums = [1,1,2,3,7,10]   -> (1, 1), (2, 3) we have only 1 pair, this is our answer

                    In case if we won't find our answer, similarly we can check for other answer until we find our answer.


            In Simple we can try looking how much pairs we can form with difference value: 
                Difference range: [0, till maxDiff]
                    maxDiff in sorted array is: (nums[n-1] - nums[0])

                    Difference_Range = [0, (nums[n-1] - nums[0])]

                    We can try checking how much pairs we can form with different different difference value.
                    & return our minimum answer accordingly..


            // Optimizations: 
                -> We are working with range (0, till maxDiff)
                -> we can optimize this using binary search to find the minimum difference value..

                    
        // Complexity: 
            -> TC: O(log(maxDiff) * N) + (N * logN)
            -> SC: O(1)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient: Binary Search Solution
class Solution {
private: 
    int n;
    bool isValid(vector<int>& nums, int p, int diff) {
        
        int cntPairs = 0;
        int i = 0;
        while(i < n - 1) {
            if(nums[i+1] - nums[i] <= diff) {
                cntPairs++; // increment pairs count
                i += 2;     // increment two value further, because we found 1 pairs
            } else {
                i += 1;
            }
        }

        return (cntPairs >= p);
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        n = nums.size();

        // Edge case: (P == 0)
        if(p == 0) return 0;    // return '0'

        sort(begin(nums), end(nums));   // sort the given nums  // TC: O(N * logN)

        // Binary Search:
        int low = 0;                    // min difference we can get -> starting range
        int high = nums[n-1] - nums[0]; // max difference we can get -> ending range
        int ans = INT_MAX;

        while(low <= high) {    // TC: O(log(maxDiff) * N)
            int mid = (low + high) / 2;

            // found pairs, move left to find much smaller value:
            if(isValid(nums, p, mid)) {
                high = mid - 1; // look for smaller value
                ans = mid;      // save answer
            } 
            else {  // move right side to find pairs:
                low = mid + 1;
            }
        }

        return ans;
    }
};


// BruteForce: Linear Search Solution
class Solution {
private: 
    int n;
    bool validPairs(vector<int>& nums, int p, int diff) {
        
        int cntPairs = 0;
        int i = 0;
        while(i < n - 1) {
            if(nums[i+1] - nums[i] <= diff) {
                cntPairs++; // increment pairs count
                i += 2;     // increment two value further, because we found 1 pairs
            } else {
                i += 1;
            }
        }

        return (cntPairs >= p);
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        n = nums.size();


        // Edge case: (P == 0)
        if(p == 0) return 0;    // return '0'

        sort(begin(nums), end(nums));   // sort the given nums

        // Binary Search:
        int low = 0;                    // min difference we can get -> starting range
        int high = nums[n-1] - nums[0]; // max difference we can get -> ending range

        for(low; low <= high; low++) {
            if(validPairs(nums, p, low)) break; // break for the first value we get our conditions satisfied
        }

        return low;
    }
};