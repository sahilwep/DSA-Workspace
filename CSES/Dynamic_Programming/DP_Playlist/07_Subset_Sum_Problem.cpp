/*

//  7 Subset Sum Problem


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


// Similarities:
    * First, we are given limit on size of knapsack that is sum, means sum will have some capacity.
    * Second, we are given a choice to choose any element that makes up sum..
    * So these two things which makes it similar to knapsack..


// Code variations: 
    // Initialization:
        * First we will initialize the first row, & first cols:
        * Example: 
            n = 5, 
            arr[n] = {2, 3, 7, 8, 10},  
            sum = 11
        
                            <-----sum+1-------->
                              0   1   2   3   4   5   6   7   8   9  10  11  12
                        0   | T | F | F | F | F | F | F | F | F | F | F | F | F |
                 ^      1   | T |   |   |   |   |   |   |   |   |   |   |   |   |
                 |      2   | T |   |   |   |   |   |   |   |   |   |   |   |   |
                n+1     3   | T |   |   |   |   |   |   |   |   |   |   |   |   |
                 |      4   | T |   |   |   |   |   |   |   |   |   |   |   |   |
                 |      5   | T |   |   |   |   |   |   |   |   |   |   |   |   |   matrix = t


                        * We have to fill this array, & output should be in true or false.
                        * t[0][0] = t
                            because for sum = 0, we can have 0 element set, i.e {}
                        * Also, for all sum = 0, whatever the value of n we have, we can always have {} an empty set, so, we can fill all true..
                            * i.e a[i][0] = T -> i = 0 to n+1
                        * But, for all n = 0(no element in set), we can't have sum above 0, i.e 1, 2, 3...
                            * So, a[0][i] = F -> i = 1 to sum+1

                        * Now, all the base condition are build up, now we have to build the choice diagram logic:


    // Code:
        * Now, we will see how this code vary with knapsack.
        * 
        * Now we will have to generate all the values using previous smaller values:
        * In knapsack we are given two array, weight & value, but these belongs to a single entity that is 'item'. So, that item becomes the subset itself.
        * Also we are given capacity i.e W, so here in subset Sum we are given sum, so sum becomes our W.
        * knapsack code:

            if(wt[i-1] <= j){
                t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        
        * In Subset sum problem Now, compare to knapsack:

            * Weight array now become array : wt -> arr[]
            * In knapsack values are stored in numbers, but here values are stored in T/F.
            * Whenever we are given some number, first we need to check whether that number is less than or equal to sum or not?
                * If it's fullfil that condition, we have two options:
                    * Include that number into knapsack
                    * Exclude that number into knapsack
            * If The number itself is grater than the given sum, we can't put that into knapsack.
            
            * Now, let's see how to deal with max()
                    Let's see: max(2, 3) -> 3
                    same max(T, F) => T => instead of max we can do OR -> || 
                    Because, if we take OR -> This will work in case of max()
                            T T -> T
                            T F -> T
                            F T -> T
                            F F -> F    
                            
                            -> We are finding max() in knapsack, so OR will give maximum time false.
                        
                        when we have (wt[i-1] <= j) ->  max(include(item), exclude(item))
                            t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j] )
                        
                        * So, include value & exclude value will be here in OR ||
                        * Also, here we don't have any value[] array, so we don't need to add anything in our result, we just have to return T/F

                        if(arr[n-1] <= Sum) -> include(item) || exclude(item)

                            if(arr[i-1] <= j):  
                                t[i][j] = t[i-1][j - arr[i-1]] || t[i-1][j]
                                //          include                 exclude
                            else:
                                t[i][j] = t[i-1][j];    // exclude

                        * Example: 

                                arr[] = {3, 2, 8}, sum = 11

                                                {3, 8} => true
                                    t[i][j]
                                                {3} => false

                                            * When we include something -> we need to subtract it from sum,
                                            * So t[i-1][j - arr[i-1]]
                                                        -------------
                                                        sum - current value that we select.
                                        
                                        * So, if we include 3, in above array we need to check from remaining once, whether we can get the value or not, after subtract that value from sum.
                                            If we include 3 from array, sum = (11 - 3) = 8
                                            * Now remaining values are: {2, 8}, & we need sum = 8
                                            * again we will choose such value which makes sum or less than that..
                                        * At last, we will get our value in T/F whether we will get that sum in subset or not?


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Function to find the Subset: 
bool subsetSum(vector<int>& nums, int sum){
    int n = nums.size();
    // Initialization:
    vector<vector<int> > t(n+1, vector<int> (sum+1));   // declaring t[n+1][sum+1] size matrix

    // filling first column as true:
    for(int i=0;i<n+1;i++){
        t[i][0] = 1;    // marking true for empty set {}
    }
    
    // filling the first row from 1 to n-1 as false
    for(int i=1;i<sum+1;i++){
        t[0][i] = 0;    // marking them false, for empty array, with having non-zero sum.
    }

    // Building Decision Tree: 
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            // if current element is less or equal to sum:
            if(nums[i-1] <= j){
                t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];     // getting the current value after the checking: include/exclude.
            }
            // when current element is grater than the sum:
            else{
                t[i][j] = t[i-1][j];    // exclude the value from the knapsack
            }
        }
    }

    return t[n][sum];   // return the given array & sum result.
}


int knapsack(int val[], int wt[], int W, int n){
    // Initializations:
    int t[n+1][W+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i == 0 || j == 0){
                t[i][j] = 0;
            }
        }
    }

    // Now building the Decision tree:
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if(wt[i-1] <= j){
                t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][W];
}


void solve(){
    int n, sum;
    cin >> n >> sum;
    vector<int> nums(n);
    for(int i=0;i<n;i++)  cin >> nums[i];

    (subsetSum(nums, sum)) ? cout << "Yes" : cout << "No";
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