/*

//  2110. Number of Smooth Descent Periods of a Stock


//  Problem Statement: 
    - You are given an integer array prices representing the daily price history of a stock, where prices[i] is the stock price on the ith day.
    - A smooth descent period of a stock consists of one or more contiguous days such that the price on each day is lower than the price on the preceding day by exactly 1. The first day of the period is exempted from this rule.
    - Return the number of smooth descent periods.


// Example:
    Example 1:
        Input: prices = [3,2,1,4]
        Output: 7
        Explanation: There are 7 smooth descent periods:
        [3], [2], [1], [4], [3,2], [2,1], and [3,2,1]
        Note that a period with one day is a smooth descent period by the definition.

    Example 2:
        Input: prices = [8,6,7,7]
        Output: 4
        Explanation: There are 4 smooth descent periods: [8], [6], [7], and [7]
        Note that [8,6] is not a smooth descent period as 8 - 6 ≠ 1.

    Example 3:
        Input: prices = [1]
        Output: 1
        Explanation: There is 1 smooth descent period: [1]



// Observations: 
    - Try using O(n^2) nested solution => TLE
    - After observing the problem: "adjacent values", we can build our solutions.

    - Example: [3, 2, 1, 4, 3, 9]

            [3], [2], [1], [4], [3], [9]
            [3, 2], [2, 1], [3, 2, 1]
            [4, 3]

    - Important point to notice, is two contigious values:
        for every i: (nums[i - 1] - 1 == nums[i]) it's a valid count
    - for every sequence adjacent values should be decrement by 1, and if it's not the we will have to start looking for other sequence..
    - From this idea we can easily identify all the sequences..
    - all we have to find how we can count number of distinct pairs:
        - Example: [3, 2, 1, 4, 3, 9]

                    For: [3, 2, 1]

                         [3], [2], [1]
                         [3, 2] [2, 1]
                         [3, 2, 1]  
                                    -> Total 6 
                        
                            :       [3, 2, 1]   -> Cnt = 1
                                    |

                                    ans = ans + cnt = 1
                        
                            :       [3, 2, 1]   -> Cnt = 2
                                        |

                                    ans = ans + cnt = 1 + 2 = 3
                                    
                            :      [3, 2, 1]   -> Cnt = 3
                                           |

                                    ans = ans + cnt = 3 + 3 = 6

                            => Total '6'

        - Simply, we can just add count into our answer for every increasing sequence.
        - and that's how we can compute the values..

        
    // Complexity: 
        - TC: O(n)
        - SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient Solution:
class Solution {
private:
    typedef long long ll;
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();

        ll ans = 0;
        int j = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(i == 0 || prices[i-1] - 1 == prices[i]) {
                cnt++;
            } else {    // reset the counter:
                cnt = 1;
            }

            // Store answer: every time count will be added for increasing sequence.
            ans = ans + cnt;
        }

        return ans;
    }
};


// Bruteforce Solution:
class Solution {
private:    
    typedef long long ll;
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();

        ll ans = 0;
        for(int i = 0; i < n; i++) {
            int val = prices[i];
            ans++;  // add for single value
            for(int j = i + 1; j < n; j++) {
                if(val - 1 == prices[j]) {
                    val--;  // decrement val for next check
                    ans++;
                } else {
                    break;
                }
            }
        }

        return ans;
    }
};