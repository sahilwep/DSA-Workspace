/*

//  2461. Maximum Sum of Distinct Subarrays With Length K



// Problem Statement:
    * You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:
        * The length of the subarray is k, and
        * All the elements of the subarray are distinct.

    * Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.
    * A subarray is a contiguous non-empty sequence of elements within an array.


    

// Example: 

    Example 1:
        Input: nums = [1,5,4,2,9,9,9], k = 3
        Output: 15
        Explanation: The subarrays of nums with length 3 are:
        - [1,5,4] which meets the requirements and has a sum of 10.
        - [5,4,2] which meets the requirements and has a sum of 11.
        - [4,2,9] which meets the requirements and has a sum of 15.
        - [2,9,9] which does not meet the requirements because the element 9 is repeated.
        - [9,9,9] which does not meet the requirements because the element 9 is repeated.
        We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions

    Example 2:
        Input: nums = [4,4,4], k = 3
        Output: 0
        Explanation: The subarrays of nums with length 3 are:
        - [4,4,4] which does not meet the requirements because the element 4 is repeated.
        We return 0 because no subarrays meet the conditions.

 



// Visualization: 
    -> we are given an array, & a integer 'k'
    -> we need to find the k size subarray, which has maximum sum with the condition: 
        -> Subarray element has to be distinct
        -> if subarray has duplicates element, consider that subarray part sum as '0'
        -> To maintain k size subarray, sliding window will help.

    -> Observations: 
        -> They are asking about k size subarray:
            -> we can use static size Sliding window, which will help us to maintain k size subarray, & we can find maximum sum throughout the array traversal.


        -> Elements should not be duplicate in k range:
            -> We can use set or map, which will help us to maintain distinct elements in 'k' range.
            -> Set will help us to maintain the window where we don't have any duplicate values.
            -> We will use set because by using set, if we encounter with any element that is already in our window, we can shrink that window & maintain a window which have only distinct value.
        


        -> Let's write the solution:    
            -> We will maintain set, which will help us to maintain distinct element in k range.

                nums = [1,5,4,2,9,9,9], k = 3


                    -> Initially i & j start from '0'
                             1 5 4 2 9 9 9
                            ij
                    
                    -> 'j' pointer iterate from 0 to 'n', n = nums.size()

                    -> When we get window size equal to 'k', we will store answer:
                            if(j - i + 1 == k) store answer
                    
                    -> Whenever we encounter with duplicate element, we will move 'i' pointer next to that duplicate element.
                             0 1 2 3 4 5 6 => Index
                             1 5 4 2 9 9 9 => Nums
                            ij             => Pointes
                    
                    -> Let's move both the pointers & visualize:

                        j = 0:
                             0 1 2 3 4 5 6
                             1 5 4 2 9 9 9
                             i j            
                                        set{1}  -> 1 inserted into set
                                        sum = 1
                                        j++
                                        -> every thing is fine here..
                        j = 1:
                             0 1 2 3 4 5 6
                             1 5 4 2 9 9 9
                             i j      
                                        set{1,5}  -> 5 inserted into set
                                        sum = 6 
                                        j++    
                                        -> Fine
                    
                        j = 2: 
                             0 1 2 3 4 5 6
                             1 5 4 2 9 9 9
                             i   j      
                                        set{1,5,4}  -> 4 inserted into set
                                        sum = 10
                                        if(j-i+1 == k) => (2-0+1 == 3)
                                            ans = max(ans, sum) => 10
                                            sum -= nums[i] => 9 // change the sum, because for next window we want only k elements sum
                                            set.erase(nums[i])
                                            i++, because window size should not be grater than 'k'

                                        j++

                    
                        j = 3: 
                             0 1 2 3 4 5 6
                             1 5 4 2 9 9 9
                               i   j
                                        set{5,4,2} -> 2 inserted into set
                                        sum = 11
                                        if(j-i+1 == k)
                                            ans = max(10, 11) => 11
                                            sum -= nums[i] => 6
                                            set.erase(nums[i])
                                            i++;
                                        j++
                    
                        j = 4:
                             0 1 2 3 4 5 6
                             1 5 4 2 9 9 9
                                 i   j
                                    set{4,2,9} -> 9 inserted into set
                                    sum = 15
                                    if(j-i+1 == k)
                                        ans = max(15, 11) => 15
                                        sum -= nums[i] => 11
                                        set.erase(nums[i])
                                        i++;
                                    j++;
                        
                        j = 5:
                             0 1 2 3 4 5 6
                             1 5 4 2 9 9 9
                                   i   j
                                    
                                    set{2, 9}
                                    if(st.find(nums[j])){   // we got duplicate values, because 9 is already in set.
                                        We will have to remove first duplicate value in window[i...j] & make our window in a way so that it can have only distinct values.
                                            Loop: until(nums[i] != nums[j]):
                                                sum -= nums[i];         // minimizing window sum as we are going to remove element from window.
                                                set.erase(nums[i]);     // remove current i pointing value.
                                                i++;                    // moving i pointer forward.
                                        // now we are at position where we only i & j are pointing to same values at two different location.
                                        set.erase(nums[i]);     // because we will going to insert 9, in set, after this check
                                        i++;                    // moving i forward, so that we can have window[i...j] where we only have distinct values.
                                    }
                                    set{9} -> Now insert new nums[j] in set i.e 9
                                    if(j-i+1 == k) => NO:
                                    j++;

                        j = 6:
                             0 1 2 3 4 5 6
                             1 5 4 2 9 9 9
                                       i j
                                    
                                    set{9}
                                    if(st.find(nums[j])){   // yes we got duplicate, same operations we have to perform as we have perform earlier.
                                        Loop: until(nums[i] != nums[j]):
                                            sum -= nums[i];
                                            set.erase(nums[i]);
                                            i++;
                                        set.erase(nums[i]);
                                        i++;     
                                    }
                                    set{9} -> Now insert new nums[j] in set i.e 9
                                    if(j-i+1 == k) => NO:
                                    j++;
                            
                        j = 7: 
                            we are out of bound, means, (j < n) Not satisfied
                                return answer => 15


// Intrusion: 
    * First check value is present in set or not?
        -> If its present, remove element on ith pointer & move i pointer until we are not at a position where i is pointing someone which is not equal to nums[j]
        -> Note: make sure while removing element from set, & moving i pointer forward exclude that element from sum.
    * Second insert values in set:
    * Third check if we got our window size or not?
        -> If(j-i+1 == k):
            store the maximum answer.
            remove nums[i] from Tempsum
            move i pointer forward, to maintain correct window size in next iteration of 'j'


// Complexity:
    * TC: O(n)
        -> Because we are only visiting all element twice.
    * AS: O(1)
        -> No extra space is used during computation.




*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


#define ll long long
#define ll long long

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        ll ans = 0;
        ll currWin = 0;

        unordered_set<int> st;

        int i = 0;
        int j = 0;

        while(j < n){
            // STEP 1: Check for duplicate vlaues: Check if nums[j] is already present in current window nums[i...j]
            // Logic 1:
            if (st.count(nums[j])) { // If we found a duplicate value in the set:
                while (i < j && nums[i] != nums[j]) {
                    cout << nums[i] << " ";
                    currWin -= nums[i];  // Minimize the current window sum
                    st.erase(nums[i]);   // Remove all elements before the duplicate value
                    i++;                 // Move the `i` pointer forward
                }
                // Now `i` is at that duplicate value:
                currWin -= nums[i];      // minimizing the current window sum
                st.erase(nums[j]);       // Remove the duplicate value from the set
                i++;                     // Move `i` one step forward
            }

            // // Logic 2:
            // // Continuously moving i pointer forward & removing i pointer element & minimizing the sum, until that nums[j] is out of set.
            // while (st.count(nums[j])) {  // If element is already found in the set:
            //     currWin -= nums[i];      // Minimize the current window sum
            //     st.erase(nums[i]);       // Remove the value at `i` from the set
            //     i++;                     // Move the `i` pointer forward
            // }


            // STEP 2: insert distinct values in set
            currWin += nums[j];
            st.insert(nums[j]);


            // Step 3: Check window size & update result, & move i pointer forward for next possiblity
            if(j-i+1 == k){
                ans = max(ans, currWin);
                currWin -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            j++;    // as usual moving j pointer at every iteration.
        }


        return ans;
    }
};