/*

//  Equal Sum Partition Problem

//  Problem Statement: 
    * Given an array nums, return "true" if you can partitions an array in two equal subset such that the sum of the element in both subset is equal or "false" otherwise.


// Example:

    Input: nums = [1,5,11,5]
    Output: true
    Explanation: The array can be partitioned as [1, 5, 5] and [11].

    Input: nums = [1,2,3,5]
    Output: false
    Explanation: The array cannot be partitioned into equal sum subsets.



// Observations:
    * For a given array, we need to determine whether it can be divided into two parts with equal sums.
    * Example: 
        arr = [1, 5, 11, 5]     T/F

                {1, 5, 5}   {11}
            sum:  11         11

        * This problem is very similar to the **Subset Sum Problem**.
        * In the Subset Sum Problem:
            * We are finding a subset whose sum is equal to a given target.
            * The result is returned as a boolean (whether such a subset exists).
            * We can apply the same logic for the Equal Sum Partition problem.

    * For this problem:
                [array]
                 /   \
              [P1]   [P2]

            * We need to check whether (P1_sum == P2_sum) -> T/F.
        
            * In other words, we are looking for a partition of the array such that the sum of both parts is equal:

                    P1_sum + P2_sum = Array_sum
            
            * Therefore, we can infer:
            
                          2 * P1_sum = Array_sum (since P1_sum = P2_sum)
                

                * Here, 2 times any number results in an "even number".

            * From this, we conclude that the sum of all the elements in the array must be "even" for partitioning into two equal sums to be possible.

            * Example:

                        arr = [1 + 5 + 11 + 5] = 22 (even)
                                /        \
                           {1, 5, 5}     {11}
                    Sum:      11          11
                                
                    * It's straightforward: when the total sum is even, it’s possible to divide it into two equal parts. Otherwise, it's impossible.
                    * For an odd number, division into two equal parts (without fractions) is not possible.
                    * Example:
                            arr = [2 + 5 + 11 + 5] = 23 (odd)
                            -> We cannot divide this into two equal parts, since fractions are not allowed.


            * First conclusion: If the total sum of the array is odd, partitioning into two equal parts is not possible.
                * We can calculate the sum of the array, and if it is odd, return false immediately.
                    * if (sum % 2 != 0) -> No need to check further, return false.
                    
                * However, even if the sum is even, we still need to verify if an equal sum partition is possible. It may be that the sum is even, but the array cannot be partitioned into two equal sums.
                    * Example:
                        arr = [1 + 5 + 7 + 5] = Sum:18
                        -> Even though the sum is even, the array cannot be divided into two equal-sum subsets.

            * So, if the sum is odd, return false. If the sum is even, further checks are required.
                           [1, 5, 11, 5] = 22
                            /       \
                    [subset:1]     [subset:2]
                        11              11
                    
                
                * Earlier, we solved the "Subset Sum Problem", where we were given an array and a target sum, and we had to determine whether any subset with that sum exists.
                * Here, we can leverage that logic:
                    * First, we compute the sum of the entire array. If the sum is even, divide the sum by 2 (sum / 2).
                    * Next, using the Subset Sum Problem approach, we check if there exists a subset with the sum equal to (sum / 2).
                    * If such a subset is found, we can partition the array into two equal subsets.
                    * Based on this result, we return true or false.

            
            * Time Complexity: O(n * Sum)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    // Function to determine if there is a subset with the given sum
    bool subsetSum(vector<int>& nums, int sum) {
        int n = nums.size();
        // Create a DP table with dimensions (n+1) x (sum+1)
        vector<vector<int> > dp(n+1, vector<int>(sum+1));

        // Initialize the DP table:
        // dp[i][0] = true for all i (sum 0 can always be achieved with an empty subset)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // dp[0][j] = false for all j > 0 (we can't get non-zero sum with 0 elements)
        for (int j = 1; j <= sum; j++) {
            dp[0][j] = false;
        }

        // Fill the DP table using a bottom-up approach
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                // If the current element is less than or equal to the sum
                if (nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                } else {
                    // If the current element is greater than the sum, ignore it
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        // The answer is whether we can achieve the target sum
        return dp[n][sum];
    }

    // Function to determine if the array can be partitioned into two subsets with equal sum
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return false;  // If the array has 0 or 1 elements, partitioning is not possible
        
        int sum = accumulate(nums.begin(), nums.end(), 0);  // Calculate the total sum of the array

        // If the sum is odd, it's impossible to partition into two equal subsets
        if (sum % 2 != 0) {
            return false;
        }

        // Check if there exists a subset with sum = total_sum / 2
        return subsetSum(nums, sum / 2);
    }
};


void solve(){
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];

    Solution obj;

    (obj.canPartition(nums)) ? cout << "Yes" : cout << "No";
    cout << endl;    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}