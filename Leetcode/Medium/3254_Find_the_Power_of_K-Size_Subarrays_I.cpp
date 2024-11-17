/*

// 3254. Find the Power of K-Size Subarrays I


// Problem Statement:
    * You are given an array of integers nums of length n and a positive integer k.
    * The power of an array is defined as:
        * Its maximum element if all of its elements are consecutive and sorted in ascending order.
        * -1 otherwise.

    * You need to find the power of all subarrays of nums of size k.
    * Return an integer array results of size (n - k + 1), where results[i] is the power of nums[i..(i + k - 1)]


// Example:

    Example 1:

        Input: nums = [1,2,3,4,3,2,5], k = 3
        Output: [3,4,-1,-1,-1]

        Explanation:
        There are 5 subarrays of nums of size 3:

            [1, 2, 3] with the maximum element 3.
            [2, 3, 4] with the maximum element 4.
            [3, 4, 3] whose elements are not consecutive.
            [4, 3, 2] whose elements are not sorted.
            [3, 2, 5] whose elements are not consecutive.

    Example 2:

        Input: nums = [2,2,2,2,2], k = 4
        Output: [-1,-1]

    Example 3:

        Input: nums = [3,2,3,2,3,2], k = 2
        Output: [-1,3,-1,3,-1]


// Visualization: 
    -> we are given an array & and a integer 'k'
    -> We need to form k size window, we have to check the subarray should be in sorted, & consecutive
    -> If they are consecutive then, return the maximum element from the window, else return "-1"

    -> NOTE: we are asked to check consecutive: consecutive means one after another: 
        Example: 
            1 2 3 4 6 -> sorted, but not consecutive
            1 2 3 4 5 6 -> Sorted & consecutive

        For finding the answer these two condition satisfy.
            (consecutive & sorted)


    -> Let's come back to the question: 

        Input: nums = [1,2,3,4,3,2,5], k = 3
        Output: [3,4,-1,-1,-1]


                -> First window:
                    [1 2 3] => Consecutive & sorted, return max element "3"
                            => ans = {3}
                
                -> Second window: 
                    [2 3 4] => Consecutive & sorted, return max element "4"
                            => ans = {3, 4}
                            
                -> Third window: 
                    [3 4 3] => Consecutive, but not sorted, return "-1"
                            => ans = {3, 4, -1}
                            
                -> Fourth window: 
                    [4 3 2] => Consecutive, but not sorted, return "-1"
                            => ans = {3, 4, -1, -1}
                
                -> Fifth window: 
                    [3 2 5] => Not-Consecutive & not sorted, return "-1"
                            => ans = {3, 4, -1, -1, -1}
                

    -> From this above observations we are checking the consecutive & sorted: 
        -> If we will check consecutive for increasing only we don't need to check for sorted, because increasing consecutive is always in sorted form
        -> Example: 
               nums = [1 2 3 4 5]
                         i

               if(nums[i] == nums[i-1]+1) -> This condition will take care of consecutive & sorted.
        
        -> Now what if all the element are in increasing consecutive, then how should be return the maximum element form 'k' size window.

                nums = [1 2 3 4 5]
                
                [1 2 3] => 3
                [2 3 4] => 4
                [3 4 5] => 5

            every time last element is maximum if we have consecutive element, that we means we will return last element of window, if we have consecutive elements
            if(elements are consecutive in k window) return last element
        
        -> Now, how do we know, how much long array is in increasing consecutive order?
            
            we will use consecutive count -> which will maintain maintain the consecutive length
            if(consecutive_length >= k) => we are sure that elements are in consecutive & sorted, we will return last element of window

        -> Now, how do we increase or decrease consecutive count

            if(nums[i] == nums[i-1]+1){
                consecutiveCnt++;
            }
            else{
                consecutiveCnt = 1;
            }
    
    -> We will use fixed size sliding window approach:

            Input: nums = [1,2,3,4,3,2,5], k = 3

            -> first, find answer for k size window, and Store answer
            -> Second find answer for remaining array, with taking k size window, and Store answer

                [1,2,3,4,3,2,5]

                
                Finding k size window answer:
                    [1,2,3]
                        for(i = 1; i < k; i++):
                            if(arr[j] == arr[j-1]+1) consecutiveCnt++;   // satisfy for all the given answer
                        
                        consecutiveCnt = 3;
                        ans = {3}

                Finding answer for remaining array, by taking k size window
                
                    i = 1;  // because first window is already processed
                    j = k;  // second pointer

                    [1, 2, 3, 4, 3, 2, 5]
                     0  1  2  3  4  5  6
                        i     j

                            Checks: 
                                if(arr[j] == arr[j-1]+1): consecutiveCnt++;     // ConsecutiveCnt = 4
                                if(consecutive >= k) ans[i] = nums[j];  // storing last element, i.e maximum
                                i++;
                                j++;

                            ans = {3, 4}


                    [1, 2, 3, 4, 3, 2, 5]
                     0  1  2  3  4  5  6
                           i     j

                            Checks: 
                                if(arr[j] != arr[j-1]+1): consecutiveCnt = 1;     // reseting consecutive count
                                if(consecutive < k) ans[i] = -1;  // consecutive count is not equal or grater to k
                                i++;
                                j++;

                            ans = {3, 4, -1}


                    [1, 2, 3, 4, 3, 2, 5]
                     0  1  2  3  4  5  6
                              i     j

                            Checks: 
                                if(arr[j] != arr[j-1]+1): consecutiveCnt = 1;     // reseting consecutive count
                                if(consecutive < k) ans[i] = -1;  // consecutive count is not equal or grater to k
                                i++;
                                j++;

                            ans = {3, 4, -1, -1}
                

                    [1, 2, 3, 4, 3, 2, 5]
                     0  1  2  3  4  5  6
                                 i     j

                            Checks: 
                                if(arr[j] != arr[j-1]+1): consecutiveCnt = 1;     // reseting consecutive count
                                if(consecutive < k) ans[i] = -1;  // consecutive count is not equal or grater to k
                                i++;
                                j++;

                            ans = {3, 4, -1, -1, -1}


                    Loop break, because 'j' is out of bound:

                        ans = {3, 4, -1, -1, -1}
                

// Approach: 
    -> We will use sliding window concept.
    -> consecutive means one after another -> This makes logic super easy
    -> we just need to check whether element are consecutive in k size window or not?
    -> depending upon that we will fill our answer.


// Complexity: 
    -> TC: O(n), because we have visit every element twice


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> res(n-k+1, -1); // result array

        // Find the first k size sliding window:
        int consecutiveCnt = 1; // variable that check consecutive count
        for(int i=1;i<k;i++){
            if(nums[i-1]+1 == nums[i]){ // if previous element incremented by 1, & gives current element:
                consecutiveCnt++;// increment consecutive count
            }
            else{
                consecutiveCnt = 1; // reset consecutive count
            }
        }

        // last check consecutive count & fill answer for first k size window:
        if(consecutiveCnt == k) res[0] = nums[k-1];

        // Now, shifting our window by 1,
        int i = 1;  // first pointer start from 1, because we have shifted our window by 1
        int j = k;  // second pointer start from k, as index is 0 based, & we have only iterated till (< k) less than k.

        // Process rest of the element:
        while(j < n){
            // if current element is 1 grater than the previous once:
            if(nums[j] == nums[j-1]+1){
                consecutiveCnt++;   // increment consecutive count
            }
            else{
                consecutiveCnt = 1; // reset consecutive count
            }

            // Check Consecutive count if it's grater or equal to k, fill our i.e maximum:
            if(consecutiveCnt >= k) res[i] = nums[j];

            // increment the pointers:
            i++;
            j++;
        }

        return res;
    }
};