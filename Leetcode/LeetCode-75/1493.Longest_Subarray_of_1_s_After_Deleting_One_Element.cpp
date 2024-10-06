/*

//  1493. Longest Subarray of 1's After Deleting One Element


//  Observations: 
    * We are given a binary array nums. we can delete one element from it.
    * Return the size of longest non-empty subarray that contains only 1's in the resulting array. Return '0' if there is no subarray.


// Example:

    Input: nums = [1,1,0,1]
    Output: 3
    Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

    Input: nums = [0,1,1,1,0,1,1,0,1]
    Output: 5
    Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

    Input: nums = [1,1,1]
    Output: 2
    Explanation: You must delete one element.

 
// Intrusion: 
    // Maintaining the array that sore the contigious 1's count.
        * We need to remove one 0's b/w the two contigious 1's so that we can make longest subarray that has only 1.
        * The idea is to maintain an array that store the frequency of contigious 1's, & in b/w we can insert 0's so that we can count what's the longest possible subarray.
        * Example:

                        arr =>  [0,1,1,1,0,1,1,0,1]     -> 5
                                   -----   ---   -
                freq arr[] -> v[] = [0, 3, 0, 2, 0, 1]

                    * Now, we can iterate in 'v', from (1 to n-2) & find the maximum possible subarray by adding both the previous & after element..
                    * sum = arr[i-1] + arr[i+1] -> at every whenever we encounter with 0's we can do this, & find the maximum among all the iterations..
        * TC: O(n)


    // Using Sliding Window Approach:
        * We will use sliding window to find the longest subarray after removing one 0's from it.
        * We will maintain two pointer i(left) & j(right)..
        * We will iterate j & count the number of '0', we will make sure to ignore one 0's, because that is what we have to remove...
        * Once the zero counter become 2, we will find the size of that window, & that's how we will get the maximum size of subarray by ignoring one 0's from it.
        * Example: Step-by-Step Execution:

                    Initialization:
                        zeroCnt = 0: No 0s have been encountered yet.
                        i = 0: Left pointer starts at the beginning of the array.
                        cnt = 0: We haven't found any valid subarrays yet.
                        k = 1: We can ignore at most one 0 (this is the deletion of one element).

                    Iteration Process:

                    We will iterate over nums with j as the right pointer and explain each step:

                        For j = 0:
                            nums[0] = 0
                            Increment zeroCnt = 1 (one 0 encountered in the window).
                            The window is valid since zeroCnt = 1 is not greater than k = 1.
                            Update cnt = max(0, 0 - 0 + 1) = 1 (current window size is 1).

                        For j = 1:
                            nums[1] = 1
                            No change to zeroCnt.
                            The window is valid (still contains one 0).
                            Update cnt = max(1, 1 - 0 + 1) = 2 (current window size is 2).

                        For j = 2:
                            nums[2] = 1
                            No change to zeroCnt.
                            The window is valid.
                            Update cnt = max(2, 2 - 0 + 1) = 3 (current window size is 3).

                        For j = 3:
                            nums[3] = 1
                            No change to zeroCnt.
                            The window is valid.
                            Update cnt = max(3, 3 - 0 + 1) = 4 (current window size is 4).

                        For j = 4:
                            nums[4] = 0
                            Increment zeroCnt = 2 (now the window has two 0s, which exceeds k).
                            The window is no longer valid because it contains more than one 0.
                            Shrink the window by moving the left pointer i until the window contains at most one 0:
                                i = 0: nums[0] = 0, so decrement zeroCnt = 1 and move i = 1.
                            Now, the window is valid again ([1,1,1,0] from index 1 to 4).
                            Update cnt = max(4, 4 - 1 + 1) = 4 (current window size is still 4).

                        For j = 5:
                            nums[5] = 1
                            No change to zeroCnt.
                            The window is valid ([1,1,1,0,1]).
                            Update cnt = max(4, 5 - 1 + 1) = 5 (current window size is 5).

                        For j = 6:
                            nums[6] = 1
                            No change to zeroCnt.
                            The window is valid.
                            Update cnt = max(5, 6 - 1 + 1) = 6 (current window size is 6).

                        For j = 7:
                            nums[7] = 0
                            Increment zeroCnt = 2.
                            The window is invalid (contains two 0s).
                            Shrink the window:
                                i = 1: nums[1] = 1 (no change to zeroCnt).
                                i = 2: nums[2] = 1 (no change to zeroCnt).
                                i = 3: nums[3] = 1 (no change to zeroCnt).
                                i = 4: nums[4] = 0, so decrement zeroCnt = 1 and move i = 5.
                            Now the window is valid again ([1,1,0] from index 5 to 7).
                            Update cnt = max(6, 7 - 5 + 1) = 6 (window size remains 6).

                        For j = 8:
                            nums[8] = 1
                            No change to zeroCnt.
                            The window is valid.
                            Update cnt = max(6, 8 - 5 + 1) = 6 (window size remains 6).

                    * Final Calculation:

                    * After finishing the iteration, we return cnt - 1, because the problem requires us to delete exactly one element. So the final result is 6 - 1 = 5.
                    Final Result:

                    * For the input nums = [0, 1, 1, 1, 0, 1, 1, 0, 1], the size of the longest subarray containing only 1s after deleting one element is 5. 
        
        * TC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    // Function to return longest subarray:
    int longestSubarray_M1(vector<int>& arr) {
        int n = arr.size();
        vector<int> v;  // vector that contains the 1's frequency.
        int cnt = 0;    // temp variable that counter continuous 1's.
        bool flag = 0;  // flag to check whether whole array contains only '0' in it or not?
        // first build 1's frequency array:
        for(int i=0;i<n;i++){
            if(arr[i] == 0){
                v.push_back(cnt);
                v.push_back(0);
                cnt = 0;
            }else{
                flag = true;
                cnt++;
            }
        }
        v.push_back(cnt);   // Insertion of last remaining element 


        // If we have only 1's in our array, means we need to remove 1 element from array, so return cnt -1:
        if(v.size() == 1){
            return cnt-1;   // we need to delete 1 element from it so, return just 1 less than the count.
        }

        // Checking for '0' in array, if we have only 0's, we can't the result is 0, because we can delete single 0 from arary, but this doesn't make any 1's subarray.
        if(!flag){
            return 0;   // we don't have 1's in our array, so return 0
        }

        // Now Finding the size: 
        int size = 0;
        for(int i=1;i<v.size()-1;i++){
            if(v[i] == 0){
                size = max(size, (v[i-1] + v[i+1]));
            }
        }

        return size;
    }
    // Using Sliding Window Technique:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int zeroCnt = 0;   // To count the number of zeros in the current window
        int i = 0;         // Left pointer of the sliding window
        int cnt = 0;       // To store the length of the longest valid window (containing at most one zero)
        int k = 1;         // k is the maximum number of zeros we can ignore, which is 1 (since we're allowed to delete one element)
        
        for(int j = 0; j < nums.size(); j++) {   // j is the right pointer of the sliding window
            if(nums[j] == 0) {   // If the current element is 0
                zeroCnt++;       // Increment zero count
            }
            
            // If the number of zeros in the current window exceeds 1, move the left pointer (i)
            while(zeroCnt > k) {   
                if(nums[i] == 0) {
                    zeroCnt--;   // If the element at position i is a zero, decrement zeroCnt
                }
                i++;   // Move the left pointer to shrink the window
            }
            
            // Update the maximum valid window size
            cnt = max(cnt, j - i + 1);
        }

        // Return the length of the longest subarray with one deletion (i.e., subtract 1)
        return cnt - 1;
    }
};


void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    Solution obj;
    cout << obj.longestSubarray(v) << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}