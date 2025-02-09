/*

//  2364. Count Number of Bad Pairs


//  Problem Statement: 
    -> You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].
    -> Return the total number of bad pairs in nums.
 

// Example:
    Example 1:
        Input: nums = [4,1,3,3]
        Output: 5
        Explanation: The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
        The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
        The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
        The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
        The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
        There are a total of 5 bad pairs, so we return 5.

    Example 2:
        Input: nums = [1,2,3,4,5]
        Output: 0
        Explanation: There are no bad pairs.


// Efficient Approach:
    -> Instead of checking all pairs (i, j) and counting bad pairs directly (O(n^2)), 
    -> we use a mathematical observation:
        -> A pair (i, j) is good if: nums[i] - i == nums[j] - j
        -> Otherwise, it is a bad pair.

    // Approach:
        1. Transform nums[i] into nums[i] - i.
        2. Use a hashmap to store the count of occurrences of transformed values.
        3. Iterate through the array and calculate bad pairs efficiently.
            -> For each index j, total numbers before j = j.
            -> Count how many times nums[j] has appeared before using the map.
            -> Compute bad pairs using: badPairs = totalNumsBeforej - cntOfNumsj.
            -> Update the answer and the hashmap.
    
            
// Complexity:
    -> TC: O(n)
    -> SC: O(n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient:
class Solution {
private:
    typedef long long ll;
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Transform nums[i] to nums[i] - i
        for(int i = 0; i < n; i++) {
            nums[i] -= i;
        }

        // Step 2: Count bad pairs using a hashmap
        ll ans = 0; // Variable to store total bad pairs
        unordered_map<int, int> mp; // Hashmap to store occurrences of transformed values
        mp[nums[0]] = 1; // Initialize first value in map

        for(int j = 1; j < n; j++) {
            int cntOfNumsj = mp[nums[j]];  // Count occurrences of nums[j] seen before
            int totalNumsBeforej = j;      // Total elements before index j

            int badPairs = totalNumsBeforej - cntOfNumsj; // Compute bad pairs
            ans += badPairs; // Add bad pairs to result

            mp[nums[j]]++; // Update the map with current value
        }

        return ans; // Return total count of bad pairs
    }
};


// Bruteforce:
class Solution {
private:
    typedef long long ll;
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        ll ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i < j && j - i != nums[j] - nums[i]) {
                    ans++;
                }
            }
        }

        return ans;
    }
};