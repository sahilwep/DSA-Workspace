/*

// Coin change problem: Maximum number of ways


//  Problem Statement:
    * We are given an array of coins, & given an integer sum.
    * So, using this coin, we need to get the sum 5. Supply of given coins are unlimited.
    * We need to find the maximum number of ways that we can get sum = 5
 

    Input: sum = 5 coins = [1,2,5]
    Output: 3
    Explanation:  {1, 1, 1, 1, 1}, {2, 2, 1}, {5}


// Example:

    Input: sum = 4, coins[] = {1,2,3}
    Output: 4
    Explanation: there are four solutions: {1, 1, 1, 1}, {1, 1, 2}, {2, 2} and {1, 3}

    Input: sum = 10, coins[] = {2, 5, 3, 6}
    Output: 5
    Explanation: There are five solutions: 
    {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}

    Input: sum = 10, coins[] = {10}
    Output: 1
    Explanation: The only is to pick 1 coin of value 10.

    Input: sum = 5, coins[] = {4}
    Output: 0
    Explanation:  We cannot make sum 5 with the given coins


// Observations:
    // Why this problem is of knapsack:
        * For every coins we have options that whether we should include this or reject.
        * Means we have choice, whether we should include this item or not?

    // Why this problem is of unbounded knapsack type:
        * We are given unlimited supply of coins, which means same coins include unlimited time, which makes it unbounded knapsack type.
    
    // How to co-relate this question with knapsack:
        * In knapsack we are given:
            W = capacity
            val[]       ->  X
            wt[]

        * If we are not given two array, then ignore the value array, and we can compute our question with wt[] array & W capacity.
            * Matching:
                W   =>  Sum
                Wt[]    =>    coin[]

        * Also, this is unbounded knapsack, because we can take same coin again & again, if we have include that...

    // recalling "Subset-Sum"
        * We were given an array, and a sum value, we need to find whether we were able to form any subset with that sum value or not?
        * We were returning the result in True/False.
        * Code:
                   if(arr[i-1] <= j){
                        t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                   }
                   else{
                        t[i][j] = t[i-1][j]
                   }

                * We were taking || OR to compute whether any subset present or not?
    
    // recalling "Count of Subset-Sum"
        * Similarly we solve another variation of this question using '+' logic instead of '||' to count the number of subset that has equal to sum value...
        * Code:
                   if(arr[i-1] <= j){
                        t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
                   }
                   else{
                        t[i][j] = t[i-1][j]
                   }
                
                * We were using '+' to count the number of subset present in our array with given sum value.
            
            * Note: There Base condition is:

                t[0][0] = 1;
                
                // There is only 1 subset when n = 0 & sum = 0 -> (t[0][0] = 1) -> {}, empty set

                * we were not filling the entire '0th' column with 1, because we can have multiple subset if (sum = 0 & n > 0)
                    * Example: 
                        arr[] = {0}, sum = 0 
                        Subsets: {}, {0}   -> 2
                        arr[] = {0, 0}, sum = 0
                        subsets: {}, {0}, {0}, {0, 0}   -> 4
                    
                * This is why we didn't fill entire 0th column with 1, because for sum = 0, & n > 0, we can have multiple subsets..
        
        * Using the same logic we will build the code for this question..
        * We just have to take care of the unbounded case, when we include any item, item is in unprocessed state, but when we exclude any item, that item is in processed state..

// Complexity:
    * TC: O(n*sum)



// NOTE: For edge case
    * We are initialising first Column to 1, assuming there is only 1 way to make subset sum equal to 0,
    * i.e null Subset, But this fails if we have 0's as element of array.
    * If we have a single 0 present in the array, then the subset will be '{}' and '{0}', whose sum will be 0..
    * Hence, there can be more than 1 way to make (sum == 0)

                arr[] = {0}, sum = 0
                    Possible Subsets: 
                        {}, {0}     -> 2 subsets possible
                

                arr[] = {0, 0}, sum = 0
                    Possible Subsets:
                        {0} {0}
                        {0, 0} {}   -> 4 subsets possible

        Fix: We don't need have to initialise first column to 1, assuming there is only 1 way to make subset sum equal to 0.
            Everything will be initialized to 0 except the first cell in the table, 
                i.e dp[0][0] = 1 
                Because, for sum = 0 & n = 0 => we only have 1 subset i.e {} empty set.

            And j will start from 0, instead of 1.

    // Summary of Initialization Logic:
        * In the standard case (no zeros in the array):
            * You should initialize t[i][0] = 1 for all i, because for any sum 0, there is exactly one way to achieve it (the empty set).

        * When zeros are present in the array:
            * The initialization needs to reflect the fact that there are multiple ways to form the sum 0 if n > 0. 
            * This situation would require a more nuanced initialization based on the number of 0s in the array, not just setting t[i][0] = 1 for all i.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int coinChangeMaxNoOfWays(vector<int> coin, int sum){
    int n = coin.size();

    // Initialization:
    vector<vector<int> > t(n+1, vector<int> (sum+1));

    t[0][0] = 1;    // when we have sum = 0 & n = 0, then we have only 1 set, i.e empty set {}


    for(int i=1;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            // if coin size is less or equal to the sum size: two options -> include / reject
            if(coin[i-1] <= j){
                // include(Un-Processed) / reject(Processed)
                t[i][j] = t[i][j-coin[i-1]] + t[i-1][j];
            }
            else{
                // reject
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][sum];
}

void solve(){
    int n, sum;
    cin >> n >> sum;

    vector<int> coin(n);
    for(int i=0;i<n;i++) cin >> coin[i];

    cout << coinChangeMaxNoOfWays(coin, sum) << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}