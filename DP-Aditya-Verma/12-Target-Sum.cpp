/*

//  Target sum


//  Problem Statement:
    * You are given an integer array nums and an integer target.
    * You want to build an expression out of nums by adding one of the symbol '+' and '-' before each integer in nums and then concatenate all the integers.
    * For Example: 
        nums = [2, 1]
        You can add a '+' before 2 & '-' before 1 and concatenate them to build the expression "+2-1"

    * Return the number of different expression that you can build, which evaluates to target.


// Example:

    Input: nums = [1,1,1,1,1], target = 3
    Output: 5
    Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
    -1 + 1 + 1 + 1 + 1 = 3
    +1 - 1 + 1 + 1 + 1 = 3
    +1 + 1 - 1 + 1 + 1 = 3
    +1 + 1 + 1 - 1 + 1 = 3
    +1 + 1 + 1 + 1 - 1 = 3


    Input: nums = [1], target = 1
    Output: 1

// Observations: 

        Input: nums = [1, 1, 2, 3], target = 1

            +1 -1 -2 +3 = 1
            -1 +1 -2 +3 = 1
            +1 +1 +2 -3 = 1
        
        * We will have to apply '+' or '-' in front of every element of an array. & when we sum up it should equal to target


    * So, we are doing nothing but assigning '+' & '-' to our array value so that we can have target value after that.
                 + - + + - + -
                [ | | | | | | ]
                 
                         + - - +
                        [1|1|2|3]
                        /       \
                    {+1,+3}    {-1, -2}
                      4         -3 = 1(target)
                
                * We have written '+' value together, & '-' values together, & when we take difference we can have our target value..
                * And we have to find the number of such subsets that have this target value after adding '+' & '-'
                * This question is same as we have done previous "Count the number of subset with a given difference"
                * There we have given difference, but here we are given target value..
    
    * They have add '+' & '-' just to increase the complexity of understanding, otherwise the question is same as "count the number of subset with a given difference"
    * Now, To solve this question, we know that:
        * first we need to calculate the sum of array => Total sum
        * Then we can add Array_Sum with target(difference) value  & divide it by 2, the we can get the number of subset for S1 sum..
        * Example:
                 
                  target = 1 -> Denote this by S

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

        * When we got this Number of subset Sum for S1, we can return that, because that is our count..
        
        * NOTE: 
            * We need to take care of some edge cases like if(abs(target) > totalSum) => return 0, because if target is grater than total sum no subset can form.
            * if((target + totalSum) % 2 != 0) => return 0, because it's odd we can't split into two equal integers.

    * TC: O(n*targetSum)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int subsetSum(vector<int> &nums, int target){
    int n = nums.size();

    int totalSum = accumulate(nums.begin(), nums.end(), 0); // finding total sum of array

    // Edge Case:
    if(abs(target) > totalSum) return 0;     // If the target is greater than the total sum, no subsets can form
    if((target + totalSum) % 2 != 0) return 0;  // If (target + totalSum) is odd, it can't be split into two equal integers

    // Find the target sum for one of the subsets (S1)
    int targetSum = (totalSum + target) / 2;

    // Initialization:
    vector<vector<int> > t(n+1, vector<int> (targetSum+1, 0));

    // There is only 1 subset when n = 0 & sum = 0 -> (t[0][0] = 1)
    t[0][0] = 1;

    for(int i=1;i<n+1;i++){
        // start iteration from 0, because we have to take care of (sum = 0) for array having only 0's in it..
        for(int j=0;j<targetSum+1;j++){
            if(nums[i-1] <= j){
                t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][targetSum]; // last return the count of subset 1 Sum.
}

void solve(){
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for(int i=0;i<n;i++)  cin >> nums[i];

    // Subset Sum: 
    cout << subsetSum(nums, target) << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}