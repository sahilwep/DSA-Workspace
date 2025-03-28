/*

//  Count of Subsets Sum with a Given Sum   


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


// Code Variations: 
    // Initialization: 
        * Same initialization as subset sum, 
            t[n+1][sum+1]
        
        * Example:
                n = 6, arr = [2 3 5 6 8 10], sum = 10
              
                            <-----sum+1-------->
                              0   1   2   3   4   5   6   7   8   9  10  
                        0   | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
                 ^      1   | 1 |   |   |   |   |   |   |   |   |   |   |
                 |      2   | 1 |   |   |   |   |   |   |   |   |   |   |
                n+1     3   | 1 |   |   |   |   |   |   |   |   |   |   |
                 |      4   | 1 |   |   |   |   |   |   |   |   |   |   |
                 |      5   | 1 |   |   |   |   |   |   |   |   |   |   |   matrix = t
                 |      6   | 1 |   |   |   |   |   |   |   |   |   |   |   matrix = t

                * In the place of True, we are filling as 1, & in the place of false we are filling as 0.
                * Because, for (sum = 0 & n = whatever) we will have at least 1 subset, i.e {} empty set.
                * if we have (n = 0, & sum > 0) we will don't have any subset, because there is no element in our subset & still we have some sum value.
                
                * But here, we need to find the count of it: 
                    * So, instead of 1, 0, we need to fill some legit integer values, because these are count..



    * Decision Tree: filling the rest of the item:

            if(nums[i] <= sum){
                // we can include or reject 
                // we have perform (Include || reject) -> depending on this we will get T/F
            }
            else{
                // reject
            }
            

        * Similarly:

            if(nums[i-1] <= j){
                // here we need count, so we will we doing "+" addition operation b/w include & reject
                //               include             reject
                t[i][j] =  t[i-1][j-nums[i-1]]  +   t[i-1][j]
            }
            else{
                t[i][j] = t[i-1][j]
            }


            * We have taken "+" -> this will give all the included part where we have get the solution.
            * & also it will sum up those values, & return the count.
            * In iteration it will add up for all the values where we get our result for sum.
 
                    {result}
                       +
                    {result}
                       +
                    {result}

            * This '+' will more explainable with recursive solution & memoization of this code, for that i will be uploading memo code also..

        * So, Concluding, we will use int type in return instead of bool.
        * Then we will use '+' instead of OR operations..

    * TC: O(n*sum)
    * AS: O(n*sum)




// NOTE:
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



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Function to return the count of subset sums:
int countSubsetSum(vector<int>& nums, int sum){
    int n = nums.size();
    // Initialization: Create a 2D DP table
    vector<vector<int> > t(n+1, vector<int> (sum+1));


    // There is only 1 subset when n = 0 & sum = 0 -> (t[0][0] = 1)
    t[0][0] = 1;


    // Filling the DP table using the decision tree logic
    for(int i=1;i<n+1;i++){
        // start iteration from 0, because we have to take care of (sum = 0) for array having only 0's in it..
        for(int j=0;j<sum+1;j++){
            if(nums[i-1] <= j){
                // Include or exclude the current element
                t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];
            }
            else{
                // Exclude the current element
                t[i][j] = t[i-1][j];
            }
        }
    } 

    return t[n][sum];   // Return the final count of subsets that sum to 'sum'
}


void solve(){
    int n, sum;
    cin >> n >> sum;
    vector<int> nums(n);
    for(int i=0;i<n;i++)  cin >> nums[i];

    cout << countSubsetSum(nums, sum) << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}