/*

//  3066. Minimum Operations to Exceed Threshold Value II

//  Problem Statement: 
    -> You are given a 0-indexed integer array nums, and an integer k.
    -> In one operation, you will:
        -> Take the two smallest integers x and y in nums.
        -> Remove x and y from nums.
        -> Add min(x, y) * 2 + max(x, y) anywhere in the array.
    -> Note that you can only apply the described operation if nums contains at least two elements.
    -> Return the minimum number of operations needed so that all elements of the array are greater than or equal to k.


// Example:

    Example 1:
        Input: nums = [2,11,10,1,3], k = 10
        Output: 2
        Explanation: In the first operation, we remove elements 1 and 2, then add 1 * 2 + 2 to nums. nums becomes equal to [4, 11, 10, 3].
        In the second operation, we remove elements 3 and 4, then add 3 * 2 + 4 to nums. nums becomes equal to [10, 11, 10].
        At this stage, all the elements of nums are greater than or equal to 10 so we can stop.
        It can be shown that 2 is the minimum number of operations needed so that all elements of the array are greater than or equal to 10.

    Example 2:
        Input: nums = [1,1,2,4,9], k = 20
        Output: 4
        Explanation: After one operation, nums becomes equal to [2, 4, 9, 3].
        After two operations, nums becomes equal to [7, 4, 9].
        After three operations, nums becomes equal to [15, 9].
        After four operations, nums becomes equal to [33].
        At this stage, all the elements of nums are greater than 20 so we can stop.
        It can be shown that 4 is the minimum number of operations needed so that all elements of the array are greater than or equal to 20.



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient Approach: O(n * log(n))
class Solution {
    typedef long long ll;
public:
    int minOperations(vector<int>& nums, int k) {

        priority_queue<ll, vector<ll>, greater<>> pq(begin(nums), end(nums));

        int step = 0;
        // Now perfrom given operations:
        while(pq.top() < k) {   // while we have minimum elements left:
            // first get the two minimum elements:
            ll x = pq.top();
            pq.pop();
            ll y = pq.top();
            pq.pop();

            ll num = min(x, y) * 2 + max(x, y);
            pq.push(num);

            step++;
        }

        return step;
    }
};


// Bruteforce Approach:
class Solution_brute {
public:
    int minOperations(vector<int>& nums, int k) {
        
        // Convert nums into another temp vector of long long type to handel longer range values.
        vector<long long> temp(nums.begin(), nums.end());
        
        // Sort the temp vector in descending order
        sort(begin(temp), end(temp), greater<>());  // sort in descending order.
        
        // Initial check:
        bool checkFlag = true;
        for(auto &it: temp) {
            if(it < k) {
                checkFlag = false;
                break;
            }
        }
        if(checkFlag) {
            return 0;
        }

        int times = 0;
        bool flag = false;
        while(!flag) {
            // if temp becomes less than 2, then also break out from the loop:
            if(temp.size() < 2) break;
            
            // First get the two minimum elements from temp & perform the operation
            long long x = temp[temp.size() - 1];
            long long y = temp[temp.size() - 2];
            
            // remove these two elements
            temp.pop_back();
            temp.pop_back();

            // insert new element
            long long res = min(x, y) * 2 + max(x, y);
            temp.push_back(res);

            // increment times:
            times++;

            // after that, sort them in descending order:
            sort(begin(temp), end(temp), greater<>());  // sort in descending order.
            
            // check if all elements are greater or equal to given 'k' or not?
            bool checkFlag = true;
            for(auto &it: temp) {
                if(it < k) {
                    checkFlag = false;
                    break;
                }
            }
            if(checkFlag) {
                break;
            }
        }

        return times;
    }
};
