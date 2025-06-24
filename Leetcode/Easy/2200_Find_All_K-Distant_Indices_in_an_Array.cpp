/*

//  2200. Find All K-Distant Indices in an Array


//  Problem Statement: 




// BruteForce Solution: 
    -> Implement the given statements: 

    // Complexity: 
        -> TC: O(n * logN + n^2) = O(n^2)
        -> SC: O(n), for using set


// Optimizations: 
    -> We need the range of index {i & j} for which "key" is present
    -> Analyzing on paper will give us direct hits of sliding window || tow-pointers
    -> Iterate in nums & whenever we hit with key: 
        -> get the starting range in left side
        -> get the ending range in right side
            -> mark that range as true, so that we can aware about those index whose participating in our answer.


            // More Optimization: 
                -> Insted of making that window, we can use something like checkmark for starting & ending range index
                -> later on we can use something like prefix sum & with that we can get the details of the index which satisfied the conditions..


    // Complexity: 
        -> TC: O(n)
        -> SC: O(n)
s
*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient Solution: 
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();

        // Find the window for which the conditions satisfies: 
        vector<int> prefix(n); // at max we can have n-index
        for(int j = 0; j < n; j++) {
            if(nums[j] == key) {
                int start = max(0, j - k);      // (start, j with k diff) This will be our starting point of window 
                int end = min(n - 1, j + k);    // (last, j with k diff)  This will be our ending point of window

                // Now mark that window:
                prefix[start] += 1;
                if(end + 1 < n ) prefix[end + 1] -= 1;
                
            }
        }


        // Build answer: 
        vector<int> ans;
        int sum = 0;    // use to get the sum details for prefix sum
        for(int i = 0; i < n; i++) {
            sum += prefix[i];   // accumulate the values from the prefix sum.

            if(sum > 0) ans.push_back(i);  // store index.
        }

        return ans;
    }
};


// Improved Solution: 
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();

        // Find the window for which the conditions satisfies: 
        vector<int> valid(n); // at max we can have n-index
        for(int j = 0; j < n; j++) {
            if(nums[j] == key) {
                int start = max(0, j - k);      // (start, j with k diff) This will be our starting point of window 
                int end = min(n - 1, j + k);    // (last, j with k diff)  This will be our ending point of window

                // Now mark that window:
                for(int i = start; i <= end; i++) {
                    valid[i] = 1;
                }
            }
        }


        // Build answer: 
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(valid[i] == 1) ans.push_back(i);
        }

        return ans;
    }
};


// Bruteforce Solution: 
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();

        set<int> st;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (abs(i - j) <= k && nums[j] == key) {
                    st.insert(i);
                }
            }
        }

        // Build answer: 
        vector<int> ans(begin(st), end(st));

        return ans;
    }
};