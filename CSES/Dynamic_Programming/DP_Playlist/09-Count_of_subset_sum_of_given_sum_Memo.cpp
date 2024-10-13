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
            * When (sum > 0 && size == 0) -> return false, because we cannot form a positive sum with an empty set.


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



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
// Depending upon the constrains of size & sum, assume the value will never exceed 1000 for both
int t[1001][1001];  // create a memo array of 1001x1001


// Recursive Solution:
int countSubsetSum_recur(vector<int>& nums, int sum, int size){
    if(sum == 0) return 1;  // for empty set {}
    // for empty list & sum grater than 0, not possible
    else if(size == 0 && sum > 0){
        return false;
    }
    
    // if item size is less or equal to sum:
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
    if(sum == 0) return 1;  // for empty set {}

    // for empty list & sum grater than 0, not possible
    else if(size == 0 && sum > 0) return false;

    // If value is already in memo array:
    if(t[size][sum] != -1){
        return t[size][sum];    // return it directly
    }

    // Else Compute, Store & then return the value:
    // if item size is less or equal to sum:
    if(nums[size-1] <= sum){
        //                              include                                             reject
        return t[size][sum] = countSubsetSum(nums, (sum - nums[size - 1]), size - 1) +  countSubsetSum(nums, sum, size - 1);
    }
    else{
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