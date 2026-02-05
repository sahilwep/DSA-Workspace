/*

//  3637. Trionic Array I


//  Problem Statement: 
    - You are given an integer array nums of length n.
    - An array is trionic if there exist indices 0 < p < q < n − 1 such that:
        - nums[0...p] is strictly increasing,
        - nums[p...q] is strictly decreasing,
        - nums[q...n − 1] is strictly increasing.
    - Return true if nums is trionic, otherwise return false.

 
// Example:
    Example 1:
        Input: nums = [1,3,5,4,2,6]
        Output: true
        Explanation:
        Pick p = 2, q = 4:
            nums[0...2] = [1, 3, 5] is strictly increasing (1 < 3 < 5).
            nums[2...4] = [5, 4, 2] is strictly decreasing (5 > 4 > 2).
            nums[4...5] = [2, 6] is strictly increasing (2 < 6).

    Example 2:
        Input: nums = [2,1,3]
        Output: false
        Explanation: There is no way to pick p and q to form the required three segments.

// Observations:    
    - We are given array nums
    - we need to find the trionic array conditions.
    - With range increasing, decreasing, and increasing apply the given conditions & find the trionic conditions.
 
    
    // Complexity:  
        - TC: O(n)
        - SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();

        // find range 0 to p
        int p = 0;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] < nums[i + 1]) {
                p++;
            } else {
                break;
            }
        }

        // find range p to q:
        int q = p;
        for(int i = p; i < n - 1; i++) {
            if(nums[i] > nums[i + 1]) {
                q++;
            } else {
                break;
            }
        }

        // Now check q to n - 1 if they are increasing:
        int r = q;
        for(int i = q; i < n - 1; i++) {
            if(nums[i] < nums[i + 1]) {
                r++;
            } else {
                break;
            }
        }

        // cout << 0 << " " << p << " " << q << " " << r << " " << n - 1 << endl;
        
        // Checking given range:
        if(0 < p && p < q && q < r && r == n - 1) {
            return true;
        }

        return false;
    }
};