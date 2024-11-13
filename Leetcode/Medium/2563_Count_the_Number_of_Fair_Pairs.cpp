/*

//  2563. Count the Number of Fair Pairs 



// Problem Statement: 
    -> We are given 0-indexed integer array 'nums' of size 'n' and two integers 'lower' and 'upper', 
    -> return the number of fair pairs.

    -> A pair '(i, j)' is fair if:
        -> 0 <= i < j < n, and
        -> lower <= nums[i] + nums[j] <= upper



// Example: 
    Input: nums = [0, 1, 7, 4, 4, 5], lower = 3, upper = 6
    Output: 6

    Explanation: 
        There are 6 pairs
            (0, 3)
            (0, 4)
            (1, 3)
            (1, 4)
            (1, 5)




// Bruteforce Solution: 
    * TC: O(n^2) -> TLE


// Efficient Solution: 
        nums = [0,1,7,4,4,5],   lower = 3, upper = 6
        
        -> We need the value from nums, which is  (lower <= nums[i] <= upper)
        -> also we can't traverse back, while finding the result, means ->  (i < j < n)
        -> more visualized: 
                    (lower <= nums[i] + nums[j] <= upper)
                
                This is what we have to find, such pair which form this solution..
            
        -> If we sort nums = [0,1,4,4,5,7]
                -> we will have range: lower=3, higher=6

                     [0, 1, 4, 4, 5, 7]

        -> 
                lower <= pairSum <= upper
                    
                    x(pair) -> sum < lower
                    y(pair) -> sum <= upper

                    y - x

        -> let's assume we have 'x' pairs, and sum of these x pairs are lesser than lower

                                            lower = 8
                                            upper = 13
                        7, 6, 5
                        ------- x
                        ------------------------ y




*/


#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    // Efficient Solution: 
    long long countFairPairs(vector<int>& nums, int lower, int upper){
        int n = nums.size();
        sort(nums.begin(), nums.end()); // sorting nums

        long long res = 0;

        for(int i = 0; i < n; i++){
            // auto it = lower_bound(begin(nums) + i + 1, end(nums), lower - nums[i]); // gives the first element NOT LESS than (lower - nums[i])  -> this will return iterator, if we want to get the index, we will subtract it from begin(nums)
            int idx = lower_bound(begin(nums) + i + 1, end(nums), lower - nums[i]) - begin(nums);
            int x = idx - 1 - i;   // we will get total number of elements
            
            int idx = upper_bound(begin(nums) + i + 1, end(nums), upper - nums[i]) - begin(nums);   // // gives the first element GRATER than (upper - nums[i]), we will find the upper bound
            int y = idx - 1 - i;    // we can get the total number of elements

            res += (y - x);
        }

        return res;
    }

    // BruteForce Solution: O(n^2)
    long long countFairPairs_brute(vector<int>& nums, int lower, int upper){
        int n = nums.size();
        ll res = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(i < j < n){
                    int val = nums[i] + nums[j];
                    if(lower <= val && val <= upper){
                        res++;
                    }
                }
            }
        }

        return res;
    }
};

void solve(){
    int n, lower, upper;
    cin >> n >> lower >> upper;
    vector<int> nums(n);
    
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }

    Solution obj;

    cout << obj.countFairPairs(nums, lower, upper) << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}