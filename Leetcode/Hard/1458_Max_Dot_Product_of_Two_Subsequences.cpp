/*

//  1458. Max Dot Product of Two Subsequences


//  Problem Statement: 
    - Given two arrays nums1 and nums2.
    - Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.
    - A subsequence of a array is a new array which is formed from the original array by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).


// Example:
    Example 1:
        Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
        Output: 18
        Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
        Their dot product is (2*3 + (-2)*(-6)) = 18.

    Example 2:
        Input: nums1 = [3,-2], nums2 = [2,-6,7]
        Output: 21
        Explanation: Take subsequence [3] from nums1 and subsequence [7] from nums2.
        Their dot product is (3*7) = 21.

    Example 3:
        Input: nums1 = [-1,-1], nums2 = [1,1]
        Output: -1
        Explanation: Take subsequence [-1] from nums1 and subsequence [1] from nums2.
        Their dot product is -1.


// Observations:
    - We can pick two subsequence such that both having same length.
    - Then we can perfrom the dot product b/w their element of these subsets & try to find the maximum product.
    - We can start our ith pointer in nums1 & jth pointer in nums2, where we want & build our subsequence..

    // Approach:
        - from both the nums, we have some choices:
            - Pick the current numbers & skip
            - Pick the current number & look further
            - move one index ahead for num1 & look further
            - move one index ahead for num2 & look further.
        - At last we will have to take maximum from all the cases..
        - NOTE: when we are out of bound: like i >= n || j >= m we will return INT_MIN, because we have -ve number in nums & they might generate values less than '0'


    // recursive solution Complexity:  
        - TC: O(3^(n * m))
        - SC: O(n * m)

    // memoization solution Complexity:  
        - TC: O(n * m)
        - SC: O(n * m)

    // Tabulations Solution Complexity:  
        - TC: O(n * m)
        - SC: O(m * m)


    // Tabulations Solution Space optimized Complexity:  
        - TC: O(n * m)
        - SC: O(m)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Space Optimized:
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> prev(m + 1, -1e9);
        // Fill base case: already filled with 1e9
        
        // Decision tree:
        for(int i = 1; i < n + 1; i++) {
            vector<int> curr(m + 1, -1e9);
            for(int j = 1 ; j < m + 1; j++) {
                // Choices:
                int c1 = nums1[i - 1] * nums2[j - 1];
                int c2 = nums1[i - 1] * nums2[j - 1] + prev[j - 1];
                int c3 = prev[j];
                int c4 = curr[j - 1];

                curr[j] = max({c1, c2, c3, c4});
            }
            prev = curr;
        }

        return prev[m];
    }
};


// Tabulations Solution:
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> t(n + 1, vector<int> (m + 1, -1e9));
        // Fill base case: already filled with 1e9
        
        // Decision tree:
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1 ; j < m + 1; j++) {
                // Choices:
                int c1 = nums1[i - 1] * nums2[j - 1];
                int c2 = nums1[i - 1] * nums2[j - 1] + t[i - 1][j - 1];
                int c3 = t[i - 1][j];
                int c4 = t[i][j - 1];

                t[i][j] = max({c1, c2, c3, c4});
            }
        }

        return t[n][m];
    }
};


// Memoization: 
class Solution {
private:
    typedef long long ll;
    int n, m;
    vector<vector<int>> t;
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2) {
        if(i == n || j == m) return -1e9;

        if(t[i][j] != -1e9) return t[i][j];

        // Choices:
        int c1 = nums1[i] * nums2[j];
        int c2 = (nums1[i] * nums2[j]) + solve(i + 1, j + 1, nums1, nums2);
        int c3 = solve(i + 1, j, nums1, nums2);
        int c4 = solve(i, j + 1, nums1, nums2);

        return t[i][j] = max({c1, c2, c3, c4});
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();

        t.resize(n + 1, vector<int> (m + 1, -1e9));

        return solve(0, 0, nums1, nums2);
    }
};

// Recursive Solution:
class Solution {
private:
    int n, m;
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2) {
        if(i == n || j == m) return -1e9;

        // Choices:
        int c1 = nums1[i] * nums2[j];
        int c2 = (nums1[i] * nums2[j]) + solve(i + 1, j + 1, nums1, nums2);
        int c3 = solve(i + 1, j, nums1, nums2);
        int c4 = solve(i, j + 1, nums1, nums2);

        return max({c1, c2, c3, c4});
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();

        return solve(0, 0, nums1, nums2);
    }
};



