/*

//  1004. Max Consecutive Ones III

//  Observations: 
    * We are given a binary array and an integer k, Return the maximum number of consecutive 1's in an array, if we can flip at most 'k'  0's.



// Example:

    Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
    Output: 6
    Explanation: [1,1,1,0,0,1,1,1,1,1,1]
    Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.


    Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
    Output: 10
    Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
    Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

// Intrusion: 
    // Sliding Window Approach:
        * We will use sliding window with two pointer approach,
        * first pointer(left) use to maintain the valid window.
        * Second pointer(right) used to iterate throughout the array.
        * At any movement we will be encounter with 0's we will increment the zeroCount,
        * When ever zeroCount exceed the k limit, we will move left pointer forward until zeroCnt not become in k range..
            * while moving left counter whenever we encounter with 0's we will decrement zeroCounter by 1...
        * At the end of every iteration we will get the maximum size of window by getting: (right - left + 1), & compare with all the previous iterations..
        * TC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();


        int zeroCnt = 0;    // variable used to count the number of 0's that are occurring.
        int left = 0;       // left pointer that will move only when the zeroCnt exceed the limit of k
        // k is given to us..
        int res = 0;    // variable to store the maximum size of window at every iterations.

        // Right pointer that is used to iterate from 0 to n-1
        for(int right = 0; right < n; right++){
            
            // Whenever we encounter with 0's
            if(nums[right] == 0){
                zeroCnt++;  // increment zero count.
            }

            // When zeroCnt reaches the give k limit or become more than k, we need to move the left pointer to make our window valid.
            while(zeroCnt > k){
                // when left encounter with 0's we will decrement zeroCnt by 1
                if(nums[left] == 0){
                    zeroCnt--;  // decrement zeroCnt to make window valid with at max k size of 0's flips.
                }
                left++; // increment left pointer.
            }


            // Storing the maximum possible size of subarray of 1's with k flips in every iterations:
            res = max(res, right - left + 1);   // +1 because we are iterating from 0th index
            // cout << left << " " << right << endl;
        }

        // returning the result with k flips, we don't need to subtract it from count, as it's the flip part, so we can include them in count:
        return res;
    }
};

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    Solution obj;
    cout << obj.longestOnes(v, k) << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}