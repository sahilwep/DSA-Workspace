/*

// Subset Sum Problem


//  Problem Statements: 
    * We are given an array of size n, & integer sum, 
    * we need to find whether this array contains any subset that equal to n or not?
    * We have to return our result in boolean type.
    * NOTE: Subarray, subSequence & subsets are different
        * Example: Consider an array: {1, 2, 3, 4}
            * Subarray: Contigious sequence in an array:
                eg: {1, 2}, {2, 3}, {3, 4}, {1, 2, 3}..
            * Subsequence: Not need to be contigious, but maintains order.
                eg: {1, 3},{1, 3, 4}..
            * Subset: Same as subsequence except it has empty set, i.e {}
                eg: {1, 3}, {}
    

// Example:
    n = 5
    arr[n] = {2, 3, 7, 8, 10},  sum = 11
    output: {3, 8}  -> two  elements.


// Solution: 
    * I have solve this questions earlier using Bottom-up, But here i will solve this questions using recursion & Memoization.


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

                * This question is similar to the knapsack problem, but here we need to return the result as true or false.
                * In knapsack, we deal with maximizing values, but here we only need to check if any valid subset exists.
                * We will use the logical OR (||) to return true if any subset yields the required sum:
                    * if (arr[n-1] <= sum) -> include(item) || exclude(item).



                  // Example:
                      * n = 6
                      * nums = [3, 34, 4, 12, 5, 2], sum = 9
                
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
// Declaring memo-array:
// int t[n+1][size+1];  --> declare t with (n & sum) (constrains + 1)
// let (0 <= n <= 1000) & (0 <= sum <= 10^6 )
int t[1000][100000];

// Memoization Recursive Solution: O(n * Sum)
bool subsetSum(vector<int> nums, int sum, int size){
    if(sum == 0) return 1;  // return true
    else if(size == 0 && sum > 0) return 0;     // return false.
    // if value is already in memo array:
    if(t[size][sum] != -1){
        return t[size][sum];    // returning the value.
    }
    // when item size is less or equal to sum:
    if(nums[size-1] <= sum){
        // accept || reject 
        t[size][sum] = subsetSum(nums, sum - nums[size - 1], size - 1)
                || subsetSum(nums, sum, size -1);

        return t[size][sum]; 
    }
    // when item size is grater than he sum:
    else{
        t[size][sum] = subsetSum(nums, sum, size - 1);  // reject that item.

        return t[size][sum];
    }
}

// Using Recursion: O(2^n)
bool subsetSum_recur(vector<int> nums, int sum, int size){
    // When sum == 0 return 1, because for any case empty & non-empty array there will always be {} empty set.
    if(sum == 0){
        return 1;   // return true
    }
    // when we have empty array with non-empty sum
    else if(size == 0 && sum > 0){
        return 0;   // return false
    }

    // Decision tree:
    // if element is less or equal to sum:
    if(nums[size-1] <= sum){
        // include || reject -> Check the maximum of it..
        return subsetSum_recur(nums, (sum - nums[size - 1]), size - 1) 
        || subsetSum_recur(nums, sum, size - 1);
    }
    // if element is grater than the sum:
    else{
        return subsetSum_recur(nums, sum, size - 1);  // reject
    }
}

// Knapsack Recursive Solution:
int knapsack(int val[], int wt[], int W, int n){
    // Base Condition: when array is empty & weight is empty.
    if(n == 0 || W == 0){
        return 0;
    }
    // Decision Tree:
    // If Current item weight is less or equal to Capacity:
    if(wt[n-1] <= W){
        return max(val[n-1] + knapsack(val, wt, (W-wt[n-1]), n-1), knapsack(val, wt, W, n-1));  // return the max b/w after including item & or rejecting
    }
    // Reject the item:
    else{
        return knapsack(val, wt, W, n-1);   // rejecting item
    }
}

void solve(){
    int n, sum;
    cin >> n >> sum;
    vector<int> nums(n);
    for(int i=0;i<n;i++)  cin >> nums[i];

    // // SubsetSum Recursive function call:
    // (subsetSum_recur(nums, sum, n)) ? cout << "Yes" : cout << "No";
    // cout << endl;

    // SubsetSum Memoize function call:
    // Filling default -1 value into memo array, using memset array
    memset(t, -1, sizeof(t));
    (subsetSum(nums, sum, n)) ? cout << "Yes" : cout << "No";
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


/*

---------------------------------[Extra]---------------------------------



// Allocation of memo-array, vector.

vector<vector<int>> t(n + 1, vector<int>(sum + 1, -1)); // Dynamic allocation



// We can pass the memo-array directly into our function parameter...

bool subsetSum(vector<int>& nums, int sum, int size, vector<vector<int>>& t) {
    if (sum == 0) return true;  // return true
    else if (size == 0 && sum > 0) return false; // return false

    // if value is already in memo array:
    if (t[size][sum] != -1) {
        return t[size][sum]; // returning the value
    }

    // when item size is less or equal to sum:
    if (nums[size - 1] <= sum) {
        // accept || reject
        t[size][sum] = subsetSum(nums, sum - nums[size - 1], size - 1, t) || 
                       subsetSum(nums, sum, size - 1, t);
        return t[size][sum];
    } else {
        // when item size is greater than the sum:
        t[size][sum] = subsetSum(nums, sum, size - 1, t); // reject that item
        return t[size][sum];
    }
}



*/