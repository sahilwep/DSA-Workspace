/*

// Count the number of subset with a given difference

// Problem Statement:
    * Given an array partition into two subsets(possibly empty) such that each element must belong to only one subset.
    * Let the sum of element of these two subsets be S1 and S2.
    * Given a difference d, count the number of partition in which S1 is grater than or equal to S2
    * and the difference b/w S1 & S2 is equal to d. Since the answer may be large return it modulo 10e9+7


// Example:

    Input:
    n = 4
    d = 3
    arr[] =  { 5, 2, 6, 4}
    Output: 1
    Explanation:
    There is only one possible partition of this array. Partition : {6, 4}, {5, 2}. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.

    Input:
    n = 4
    d = 0 
    arr[] = {1, 1, 1, 1} 
    Output: 6 
    Explanation:
    we can choose two 1's from indices {0,1}, {0,2}, {0,3}, {1,2}, {1,3}, {2,3} and put them in S1 and remaning two 1's in S2.
    Thus there are total 6 ways for partition the array arr. 



// Observations:

                        [array items]
                        /           \
                   {subset1}       {subset2}
            sum:       S1              S2


              
            abs(s1 - s2) = diff(given)


        * We have to return the output in int, i.e count..
        * We will have to return the count, How many subsets are there whose difference is "diff", i.e given
        * Example:
                diff = 1

                        [1, 1, 2, 3]
                         /        \
                 [Subset1]       [Subset1]

                 * Possible subset:
                        {1, 2}  {1, 3}
                          (3  - 4) = 1

                        {1, 3}  {1, 2}
                          (4  - 3) = 1

                                * Note, both 1 are Different, so we have take each one of them..
                        
                        {1, 1, 2}   {3}
                            (4     -  3) = 1
                        
                
                * So, count is 3 


        * Now, let's reduce it into simpler problem:

                Diff = 1 -> Denote this by S

                        [1, 1, 2, 3]
                         /        \
                 [Subset1]       [Subset1]
                    S1              S2      -> Sum of these subsets

                    S1 - S2 = S(given)              ------(I)

                    S1 + S2 = Sum or array -> because we are breaking our subset into two.          -----(II)


                (I) + (II)

                    S1 - S2 = S
                 +  S1 + S2 = Sum_Array
                 -----------------------
                  2*S1  = S + Sum_Array

                  S1 = (S + Sum_Array) / 2
                
                * So, from this equation, we have S(Diff) & Sum_Array(We can get it from our array)
                * We can easily calculate S1
                    
                    (S + Sum_Array)/2
                    (1 +  7)/2  =  4

                    So, Subset 1 Sum = 4 
                
                * From mathematically we calculate Subset 1 Sum = 4


            * But, we need to find the count:
                Count ?? -> How many subsets are there, whose sum difference is 1

                If S1 = 4, then (S1 - S2) = diff
                    S1 - diff = S2
                    4 - 1 = 3   -> S2 we can get the sum value of subset 2
            
            * So, this value is reduce to, we need to find the count of subset of an array which sum we recently found..

                        [array]
                        /     \
                [subset1]     [subset1]
                    S1     -    S2      = Diff

                * If we got S1, then we can easily found S2..
                * If S1 = 4, then S2 = 3
                * So, we need to find the count of S1, 
                * means, we need to find the count of an array with given sum
                * This problem is reduced to:
                    * We are given an array, whose subset sum is 4, and we need to count how many subset's are there..

                               [array]
                                 |
                              {Subset}
                               Sum = 4

                    * This problem become "Count of Subset Sum"
                    * Sum can be found by: (Array_Sum + Diff) / 2
            
            * So Concluding, We need to find the number of subset whose subset sum are given.






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

    

    * We also need to take care of the edge case where it's not possible to partition the array.
    * In the derived formula, {target = (dff + totalSum) / 2}
    * Notice, that (diff + totalSum) must be even for target to be a whole number, else it's not possible to find a decimal target in subset sum.

        Fix: Check if it's odd, there is no way --> if((diff + totalSum) % 2 != 0)  return 0


*/


#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define mod 1000000007


// Function to count the number of subsets with a given difference
int countTheNumberOfSubsetWithGivenDifference(vector<int> &nums, int diff) {
    int n = nums.size();
    int totalSum = accumulate(nums.begin(), nums.end(), 0); // Calculate the total sum of the array

    // Edge cases:
    if (diff > totalSum) return 0; // If the difference is greater than the total sum, no subsets can form
    if ((diff + totalSum) % 2 != 0) return 0; // If (diff + totalSum) is odd, it can't be split into two equal integers

    // Find the target sum for one of the subsets (S1)
    int targetSum = (diff + totalSum) / 2;


    // Create a DP table to count Subset sums
    vector<vector<long long int> > t(n + 1, vector<long long int>(targetSum + 1, 0)); // Initialize DP table of size (n+1) x (targetSum+1)


    // There is only 1 subset when n = 0 & sum = 0 -> (t[0][0] = 1)
    t[0][0] = 1;


    // DP Transition:
    for (int i = 1; i < n + 1; i++) {
        // start iteration from 0, because we have to take care of (sum = 0) for array having only 0's in it..
        for (int j = 0; j < targetSum + 1; j++) {
            // If the current element is smaller or equal to the current sum, include/exclude it
            if (nums[i - 1] <= j) {
                t[i][j] = t[i - 1][j - nums[i - 1]] + t[i - 1][j] % mod;
            } 
            // If the current element is greater than the current sum, exclude it
            else {
                t[i][j] = t[i - 1][j];
            }
        }
    }


    return t[n][targetSum] % mod; // Return the result modulo 10^9+7
}




void solve(){
    int n, diff;
    cin >> n >> diff;
    vector<int> nums(n);
    for(int i=0;i<n;i++)  cin >> nums[i];

    // Subset Sum: 
    cout << countTheNumberOfSubsetWithGivenDifference(nums, diff) << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}