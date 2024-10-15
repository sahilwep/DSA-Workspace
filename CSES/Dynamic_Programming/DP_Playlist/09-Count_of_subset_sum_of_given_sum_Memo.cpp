/*

//  Count of Subsets Sum with a Given Sum  -> Memoization


//  Problem Statement:
    * We are given an array and an integer sum, we need to count the number of subset

// Example:
    I/p: nums = [2, 3, 5, 6, 8, 10], sum = 10
    O/p: 3
    Subsets:  {2, 8}, {2, 3, 5}, {10} -> build sum 10


// Similar to Subset Problem:
    * In subset problem, we used to find whether our given array has any subset which is equal to sum or not?
    * We used to return our result in T/F..
    * Similarly here also we need to find how may subsets are there, which is equal to our sum, & return the count of it..


// Return type: 
    * In subset sum problem, return type is true/false, but here we have to return the count of subset sum.


// Solution:
    // Recursive Solution:
        // Base Conditions:
            * When sum == 0 -> return true, because there is always an empty set {} that sums to zero in both empty and non-empty arrays.
            * When (size == 0) -> return false, because we cannot form a positive sum with an empty set.
            * Note: But here we Don't need to return values in T/F, we need to return in count...


            // Decision Tree: Choice Diagram:
            
                                               [Item]
                                                 |
                                [Accept]--------------------[Reject]
                            (item <= sum)                 (item > sum)
                                 |
                    (Accept)-----------(Reject)

                * This question is similar to the subsetSum problem, but here we need to return the result in integer, i.e count.
                * In subsetSum, we deal with only if there is any solution return true, but here we need to check for all the possible subset with given sum.
                * And last we need to return the count of valid subset with given sum.
                * We will use '+' operator b/w include & reject if (item <= sum), & from there if we got any subset with given sum we will return the count of it..
                * '+' Operator will return only those value which makes our (sum = 0), as given in base condition, when (sum = 0) -> we don't need to check further, return true.



                  // Example:
                      * n = 6
                      * nums = [3, 34, 4, 12, 5, 2], sum = 9
                      * O/p: 2
                            {3, 4, 5} {4, 5}
                
                                                  (nums, sum = 9)
                                                       /        \
                                                Include 2      Exclude 2
                                                    |               |
                                            (nums, sum = 7)     (nums, sum = 9)
                                                /       \          /          \
                                        Include 5     Exclude 5  Include 5   Exclude 5
                                     |                 |         |              |
                             (nums, sum = 2) (nums, sum = 7)  (nums, sum = 4) (nums, sum = 9)
                                            /    \         /     \        /     \
                                        ...        ...        ...        ...
    


            * Time Complexity (TC): O(2^n)
                * 2 -> decision points raised to the power of the total number of elements in the array.
            * The same subproblems are computed again and again in the recursive tree.
            * We can optimize this using memoization -> Dynamic Programming Top-Down Solution.



    // Memoization: 
        // Variable values are: (n & W) -> Size & Sum
            * Create a t[n+1][W+1]
            * Initialize it with a default value of -1.
                * memset(t, -1, sizeof(t))
            * Before making recursive calls, check if the value is available in the memo array.
            * If it’s there, return it directly; otherwise, calculate the value, save it in the memo table, and then return it.
            
            * Time Complexity (TC): O(n * sum)



// Note: 
    * The issue arises due to how subsets with sum 0 are handled when the array contains 0s. 
    * In such cases, subsets like {}, {0}, {0, 0} should all contribute to the count when the sum is 0. 
    * The current implementation doesn't handle this scenario correctly.
    * Why is it happening?
        * In the case where the sum is 0, we're always returning 1 (to count the empty subset {}).
        * However, when the array contains 0s, we should also count additional subsets like {0} and {0, 0} that also sum to 0. 
        * The current base case if(sum == 0) return 1 does not account for subsets involving actual elements of the array.

    * Special Handling for Zero Sum (sum == 0):
        If sum == 0, we count all subsets including the empty subset and any subsets made up of zeroes. The expression pow(2, count(nums.begin(), nums.begin() + size, 0)) calculates the number of subsets by counting how many zeroes there are in the array and using the formula 2^k, where k is the number of zeroes.
    * For Non-zero Sums:
        The regular recursive logic for including or excluding elements remains the same. If the current element is less than or equal to sum, we either include or exclude it.

    * Test Case Example:

        For the array {0, 0} and sum = 0:

            Possible subsets that sum to 0: {}, {0}, {0, 0}
            Result should be 3.

        Final Notes: This change ensures the correct handling of cases where 0 is a valid subset sum, and the code works for both normal and zero-sum cases.



    // Explanation of pow(2, count(nums.begin(), nums.begin() + size, 0))

        * Counting the Number of Zeroes:
            The function count(nums.begin(), nums.begin() + size, 0) counts how many times 0 appears in the subarray nums[0] to nums[size - 1].
            Example:
                If nums = {0, 0, 3, 5} and size = 4, then count(nums.begin(), nums.begin() + size, 0) will return 2 (since there are two 0s in the array).

        * Calculating the Number of Subsets from the Zeroes:
            The expression pow(2, k) calculates the number of subsets that can be formed from k zeroes.
            Why 2^k?
                Each 0 in the array has two choices: either be included in a subset or be excluded.
                So, for k zeroes, the number of different subsets we can form just by including or excluding the zeroes is 2^k.
                Example:
                    If there are 2 zeroes (k = 2), the possible subsets are:
                        {}, {0}, {0}, {0, 0}
                    These are 2^2 = 4 subsets.

        * Applying It When sum == 0:
            When sum == 0, the total number of valid subsets includes:
                The empty subset {}.
                All subsets formed by just the zeroes in the array.
            So, if there are k zeroes in the array, the total number of subsets that sum to zero is 2^k.
            That's why pow(2, count(nums.begin(), nums.begin() + size, 0)) correctly counts these subsets.


    * Example Walkthrough

        Let’s go through an example to clarify further:
        Example 1:

        Array: nums = {0, 0}, Sum = 0

            Step 1: Count the number of zeroes:
                count(nums.begin(), nums.begin() + size, 0) = 2 (because there are 2 zeroes).
            Step 2: Calculate the number of subsets from these zeroes:
                pow(2, 2) = 4
            The 4 subsets are:
                {} (empty subset)
                {0} (one of the zeroes)
                {0} (the other zero)
                {0, 0} (both zeroes)

        Thus, for an array of two zeroes, there are 4 subsets that sum to 0.
        Example 2:

        Array: nums = {1, 0, 0}, Sum = 0

            Step 1: Count the number of zeroes:
                count(nums.begin(), nums.begin() + size, 0) = 2 (because there are 2 zeroes).
            Step 2: Calculate the number of subsets from these zeroes:
                pow(2, 2) = 4
            Subsets of zeroes:
                {} (empty subset)
                {0} (one of the zeroes)
                {0} (the other zero)
                {0, 0} (both zeroes)

        Thus, there are 4 subsets that sum to 0.
        Key Takeaways:

            Counting Subsets: The number of subsets that sum to 0 includes the empty subset and all possible subsets made up of zeroes.
            Mathematical Insight: For k zeroes, the formula 2^k gives the total number of ways to form subsets, since each zero can either be included or excluded.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
// Depending upon the constrains of size & sum, assume the value will never exceed 1000 for both
int t[1001][1001];  // create a memo array of 1001x1001


// Recursive Solution:
int countSubsetSum_recur(vector<int>& nums, int sum, int size){
    // Special case: if sum is 0, count all subsets that sum to 0, including the empty subset and subsets made up of zeros.
    if(sum == 0){
        return pow(2, count(nums.begin(), nums.begin() + size, 0)); 
    }

    // If the size is 0 but the sum is not zero, no subsets can sum up to a positive number
    if(size == 0) return 0;

    // Decision tree: either include or exclude the current element
    // If item size is less or equal to sum:
    if(nums[size-1] <= sum){
        //              include                                                  reject
        return countSubsetSum_recur(nums, (sum - nums[size - 1]), size - 1)  +  countSubsetSum_recur(nums, sum, size - 1);
    }
    else{
        // reject that item, because size is grater than sum:
        return countSubsetSum_recur(nums, sum, size - 1);
    }
}


// Dp Solution: Memoization
int countSubsetSum(vector<int>& nums, int sum, int size){
    // Special handling for sum == 0
    // If the sum is zero, we always have one subset (empty set {})
    // We also need to consider subsets with zero elements like {0}, {0, 0}, etc.
    if(sum == 0) {
        // Count all subsets that sum to 0, including empty set and subsets with 0s
        return pow(2, count(nums.begin(), nums.begin() + size, 0));
    }

    if(size == 0) return 0; // No subsets can add up to a positive sum when no elements remain

    
    // Check if the result is already memoized:
    if(t[size][sum] != -1){
        return t[size][sum];    // return it directly
    }

    // Decision tree with memoization:
    // if item size is less or equal to sum:
    if(nums[size-1] <= sum){
        //                              include                                             reject
        return t[size][sum] = countSubsetSum(nums, (sum - nums[size - 1]), size - 1) +  countSubsetSum(nums, sum, size - 1);
    }
    else{
        // reject
        return t[size][sum] = countSubsetSum(nums, sum, size - 1);
    }
}


void solve(){
    int n, sum;
    cin >> n >> sum;
    vector<int> nums(n);
    for(int i=0;i<n;i++)  cin >> nums[i];

    // // Recursion Sol'n Call:
    // cout << countSubsetSum_recur(nums, sum, n) << endl;


    // Memoization Sol'n Call:
    memset(t, -1, sizeof(t));
    cout << countSubsetSum(nums, sum, n) << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}