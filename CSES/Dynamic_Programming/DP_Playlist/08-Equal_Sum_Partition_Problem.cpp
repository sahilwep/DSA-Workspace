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
    * For a given array we need to find, if we divide this array into two part, can we have equal sum or not?
    * Example: 
        arr = [1, 5, 11, 5]     T/F

                {1, 5, 5}   {11}
                  11         11

        * This problem is very similar to Subset_Sum_Problem..
        * In Subset Sum Problem:
            * we are finding such subset that has equal to sum.
            * we are returning the the sum in boolean type.
            * 


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;



void solve(){
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];



    
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}