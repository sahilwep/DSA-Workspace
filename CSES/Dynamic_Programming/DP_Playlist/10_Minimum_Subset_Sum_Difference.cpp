/*

//  Minimum Subset Sum Difference:


// Problem Statement:
    * We are given an array of size n containing non-negative integers, 
    * the task is to divide it into two sets, s1, s2 such that the absolute difference b/w their sums is minimum, & find the minimum difference.


// Example:

    Input: N = 4, arr[] = {1, 6, 11, 5} 
    Output: 1
    Explanation: 
    Subset1 = {1, 5, 6}, sum of Subset1 = 12 
    Subset2 = {11}, sum of Subset2 = 11   

            abs(subset1:sum - subset2:sum) = 1


    Input: N = 2, arr[] = {1, 4}
    Output: 3
    Explanation: 
    Subset1 = {1}, sum of Subset1 = 1
    Subset2 = {4}, sum of Subset2 = 4


// Observations:
    * According to the question:

                         [array]
                        /      \
                {subset1}      {subset2} 
                    |               |
                    s1              s2

                    s1 = s2     =>      s1 - s2 = 0
                                        s1 - s2 = minimum

                abs(s1:sum - s2:sum) = minimum as possible

    * Example:
                arr[] = {1 6 11 5}

                    {1, 6}      {11, 5}
                      7           16
                        abs(16 - 7) = 9

                    {6, 5}      {11, 1}
                        abs(11 - 12) = 1 Minimum
                
            * So, we have to divide our array into two subset, such a way so that our subset sum difference will be as minimum possible.
        
                        [array]
                        /     \
                     [P1]     [P2]   -> partition
                      |        |
                      S1      S1    -> Sum, we need to find sum..


                      array =   {1, 6, 11, 5}
                                  /      \
                              {...}     {...}   -> From this array some number goes in first subset & rest goes in second subset..
                                S1        S2    -> From this we will get the sum of both the subset...
                            
                    
                    * We, don't know the exact value of S1, & S2, but we can predict the range of it..
                    * We can say:
                                S1 & S2 ∈ (0, n), n can be any number...


                    * Extreme value of subset: 

                            array: [ | | | ] 
                                    -> { }  Empty subset
                                    -> { ... } subset equal to an array itself

                            * If subset is empty, value will be 0.
                            * and if subset is equal to array itself, value will be n.
                            * We need to find the sum of both the subset, right..
                            * We can say the range of sub will lie from 0 to Array:Sum
                        
                            * Range:
                                                    |
                                0 |-----------------|-------------------| n
                                                    |                 
                                        
                            * Similarly, sum range lie, b/w 0(empty set) and array_Sum(Sun of array).

                                                    |
                                0 |-----------------|-------------------| n_Sum
                                        range       |       range
                                   ----------------   ------------------             
                                        s1                     s2
                                
                            * Example: 
                                    
                                    array =   {1, 6, 11, 5}
                                    sum = 23

                                                            |
                                        0 |-----------------|-------------------| 23(Range)
                                                            |                 
                                            ------------          ------------
                                                  s1                    s2

                                * Now, In this range which sum can be represent as subset sum:
                                                            
                                        0 |-|-|-|-|-|-|-|-|-|-|--|--|--|--|--|--|--|--|--|--|--|--|--| 23(Range)
                                          0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23

                                * For, a given range of subset sum, which one can be represent as our subset sum ?

                                        0 |-|-|-|-|-|-|-|-|-|-|--|--|--|--|--|--|--|--|--|--|--|--|--| 23(Range)
                                          0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23

                                                sum = 3 -> this can't be represent..
                                                sum = 4 -> this can't be represent..
                                                sum = 6 -> this can be represent..
                                                sum = 7 -> this can be represent..

                                        * So, not all the sum range can be represent as our subset sum..
                                        * Like s1, s2 value never be 3, 4..
                                        * So, we have to filter those value which are not suitable for our subset sum...
                                

                                * Another Example:

                                            arr[] = {1, 2, 7}   -> Sum = 10

                                            Range:
                                                s1/s2 {0, 1, 2, 3, 7, 8, 9, 10} -> These are the possible candidate that can be subset sum of s1/s2.
                                
                                * Note: S1 & S2 =>  are single array, because when we combined them together:

                                                [array] -> Sum
                                                /    \
                                              [s1]  [s2]

                                    * Observe Carefully:

                                            s1/s2 {0, 1, 2, 3, 7, 8, 9, 10} 
                                                   |                     |
                                                (sum - i)              (sum - i)
                                                 (10-0)                (10-10)
                                                  same                   same   -> If one exist other will also exist..

                                            s1/s2 {0, 1, 2, 3, 7, 8, 9, 10} 
                                                      |              |
                                                  (sum - i)       (sum - i)
                                                   (10-1)          (10-9)
                                                    same            same    -> If one exist other will also exist..
                                                    
                                            ....
                                            ....
                                            .... We can say, for half range we find the other half range..


                                    * Observing again:

                                                               |
                                            s1/s2 {0, 1, 2, 3, | 7, 8, 9, 10} 
                                                               |
                                                   ------------
                                        If this is     s1
                                                                 -------------
                                                                      s2    -> Then this will automatically become s2


                                        * Because, s1 + s2 = sum of whole array..


                                    * Concluding on the point that, we only need to iterate till half, & we can find the s1.
                                    * When we got s1, then we can automatically find s2, because (s2 = range - s1)
                                    * We can Say, we don't need to find s1 & s2, we only need to find:
                                             
                                            s1 & (range - s1)
                                                  ----------
                                                      s2 -> because this is s2
                                    
                                    * So, if we get only one subset, then we can find the other half, & then we can find the minimum subset difference..

                                    * So, We will have to find: abs(s2 - s1) & minimize
                                                
                                                    (S2 - s1)     -> minimum

                                                    ((range - s1) - s1) -> minimum
                                                
                                                    (range - 2 * s1) -> minimize
                                            
                                        * So, we can say, if we find first set S1 sum candidates, & then perform (range - 2* s1) -> we can find the minimum of abs(s2 - s1)...

                                        * Note: abs(range - 2*s1)  -> this will be always be absolute..
                            

                                    * Note: S1 can be found on first half of sum candidate range.
                                        * here only need to check for first half sum candidate range, & We can get s1.
                                                               |
                                            s1/s2 {0, 1, 2, 3, | 7, 8, 9, 10} 
                                                               |
                                                   ------------
                                                        s1


                                    * Conclusion:
                                        * First we can get the sum range, by adding all the elements of an array..
                                        * Then From there we will choose valid candidate subset sum, that can be eligible to becoming s1 & s2..
                                        * Then, we only need to find the first half of subset sum candidate, & from there we can get the absolute minimum subset sum difference..


            * Coming back to the point:

                We are given an array: [ | | | | | | | ]

                * We will find the sum of it..

                * Then from sum, we can see the range: (0 -> sum)

                                         |
                    0 |----|----|--------|--------|--------| range
                           X    Y        |        Z

                * We only need to check whether there is any subset in our array which has sum 'X'.
                * Similarly, whether there are any subset in our array with sum Y, & Z...

                * Now, this Problem is same as Subset Sum Problem: We are whether there is any subset exist in our array with sum X or not?.


                * Example:
                            arr[] = {1, 2, 7}   -> Sum = 10

                            Range:
                                s1/s2 {0, 1, 2, 3, 7, 8, 9, 10} -> These are the possible candidate that can be subset sum of s1/s2.
                                


                                        <-----sum+1-------->
                              0   1   2   3   4   5   6   7   8   9  10  
                        0   | T | F | F | F | F | F | F | F | F | F | F |
                 |      1   | T |   |   |   |   |   |   |   |   |   |   |
                n+1     2   | T |   |   |   |   |   |   |   |   |   |   |
                 |      3   | T | T | T | T | F | F | F | T | T | T | T |


                    * If we observe carefully, on row 3:
                    * we are checking for sum candidate {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10} -> Whether any subset exist or not?
                    * and we are iterating in sum & finding the subset values whether exist or not?
                    * The last row will give us the data about the subset for (sum = 0 -> 10) whether any subset exist or not?
            
            
        * Concluding on the point: 
            * First we need to find the subset Sum of whole array...
            * Then we can get the last row or dp..
            * Then we can iterate till half of that row, & find the credible candidate for s1.
            * Once we got the candidate: we can do abs(s2 - s2) => abs(range - 2*s1) => & find the minimum of it from every candidate...


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Minimum Subset Sum Difference:
int minimumSubsetSumDiff(vector<int>& nums){

    int sum = accumulate(nums.begin(), nums.end(), 0);  // Finding sum of whole array:
    int n = nums.size();

    // Initialization:
    vector<vector<bool> > t(n+1, vector<bool> (sum+1));


    // First column (sum = 0) is always true, as we can make 0 sum by taking no elements.
    for(int i=0;i<n+1;i++){
        t[i][0] = 1;
    }

    // filling the first row from 1 to n+1, because for empty array & sum > 0, we can't have any subsets
    for(int i=1;i<sum+1;i++){
        t[0][i] = 0;
    }


    // Filling the rest of the DP table
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            // If the item is less than or equal to the current sum
            if(nums[i-1] <= j){
                //          accept          /    reject:
                t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }



    // Method 1: to find the valid candidate
    // Now we need the last row, and for s1, we check from 0 to sum/2 only:
    vector<int> res;
    for(int i=0;i<sum/2+1;i++){
        if(t[n][i] == 1){
            res.push_back(i);
        }
    }

    // finding the absolute difference b/w two subset sums: abs(s2 - s1) => abs(range - 2*s1)
    int minVal = INT_MAX;
    for(auto i: res){
        minVal = min(minVal, abs(sum - 2*i));
    }

    return minVal;  // returning the result


    // // Method 2: to find the valid candidate
    // // Now we need the last row, and for s1, we check from sum/2 to 0
    // int s1 = 0;
    // for (int i = sum / 2; i >= 0; i--) {
    //     if (t[n][i] == 1) {
    //         s1 = i;
    //         break;
    //     }
    // }

    // int s2 = sum - s1;

    // return abs(s2 - s1);
}


void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)  cin >> nums[i];


    // Subset Sum: 
    cout << minimumSubsetSumDiff(nums) << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}