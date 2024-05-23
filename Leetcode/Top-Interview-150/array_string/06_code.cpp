/*
// 189. Rotate Array            https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
// Explanation:
    rotate 1 steps to the right: [7,1,2,3,4,5,6]
    rotate 2 steps to the right: [6,7,1,2,3,4,5]
    rotate 3 steps to the right: [5,6,7,1,2,3,4]


Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

Constraints:
    1 <= nums.length <= 10^5
    -231 <= nums[i] <= 231 - 1
    0 <= k <= 10^5



// Bruteforce Solution: TLE, as TC : O(n*k)
    * Making oneRightRotate() function that rotate one element towards right.
    * Using loop k time to rotate this...



// Efficient Solution: 
    * If we carefully observe the pattern, 
    * this is more similar to left rotate, where we are rotating towards left side...
    * But here we have to rotate the element towards right side...    

    1 2 3 4 5 6 7, k = 3             ->  5 6 7 1 2 3 4

        1 2 3 4 5 6 7   -> rotate 0 to n-1 index
        7 6 5 4 3 2 1   -> rotate first k element, 0 to k-1
        5 6 7 4 3 2 1   -> rotate rest element element, k to n-1
        5 6 7 1 2 3 4   -> final 


    -1-100 3 99, k = 2              -> 3,99,-1,-100

        -1 -100 3 99    -> rotate 0 to n-1 index
        99 3 -100 -1    -> rotate first k element, 0 to k-1
        3 99 -100 -1    -> rotate rest element element, k to n-1
        3 99 -1 -100    -> final


* NOTE : We have to round the k, as we are rotating,
        int n = nums.size();
        k = k % n;  // ensure k is within range[0, n)

    .begin() return iterator pointing to first element
    .end() return iterator pointing after last element.
    range of reverse : [first,last)
*/ 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Efficient Solution: 
void rotate(vector<int> &nums, int k){
    int n = nums.size();    
    k = k % n;  // ensure k is within range[0, n)
    // reverse entire array:
    reverse(nums.begin(), nums.end());
    // reverse first k element: 
    reverse(nums.begin(),nums.begin() + k);
    // reverse rest k to n-1 element
    reverse(nums.begin()+k, nums.end());
}

// bruteforce solution: Rotate oneRightRotate k times : TC : O(k*n)
void oneRightRotate(vector<int> &nums){
    int n = nums.size();
    int temp = nums[n-1];
    for(int i=n-1;i>0;i--){
        nums[i] = nums[i-1];
    }
    nums[0] = temp;
}
void rotate_(vector<int>& nums, int k) {
    for(int i=0;i<k;i++){
        oneRightRotate(nums);
    }
}

int main(void){
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >>n >> k; 
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin >> nums[i];
        }
        for(auto i : nums) cout << i << " ";
        cout << endl;
    }
    
    
    
    return 0;
}