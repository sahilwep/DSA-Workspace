/*

//  898. Bitwise ORs of Subarrays


//  Problem Statement: 
    -> Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.
    -> The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. The bitwise OR of a subarray of one integer is that integer.
    -> A subarray is a contiguous non-empty sequence of elements within an array.


// Example: 
    Example 1:
        Input: arr = [0]
        Output: 1
        Explanation: There is only one possible result: 0.

    Example 2:
        Input: arr = [1,1,2]
        Output: 3
        Explanation: The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
        These yield the results 1, 1, 2, 1, 3, 3.
        There are 3 unique values, so the answer is 3.

    Example 3:
        Input: arr = [1,2,4]
        Output: 6
        Explanation: The possible results are 1, 2, 3, 4, 6, and 7.
        

// Observations: 
    -> Given nums of positive integer
    -> We need to all the possible subarray & compute OR of them
    -> We need to return all the unique OR of subarray.

    // BruteForce:       
        -> Use nested loop to generate all possible subarray.
        -> Generate all the possible subarray & store their OR result, & find the total number of unique OR results on all possible OR's

        // Complexity:
            -> TC: O(n)
            -> SC: O(1)



    // Efficient Solution: 
        // OR Property: 
            -> **In OR operations A set bit can never be unset**

                    0000...0001
                    0000...0100
                    0000...1000     OR
                    -----------------
                    0000...1101 -> Here, Set bit can't be unset

            -> When we Take OR any number with current number, will always get a value >= current value.

        // Example Observations: 
                arr = {1, 5, 2, 3}

                 1  |   5      |         2        |          3              | 
                    | [1] OR 5 |     [5] OR 2     |     [5 OR 2] OR 3       |
                    |          |  [1 OR 5] OR 2   |  [1 OR 5 OR 2] OR 3     |
                    |          |                  |                         |

            -> For every number we are taking OR from previous OR Results
            -> We can maintain Two unique Set:
                -> Prev: Contains the result of previous OR's
                -> Curr: Contains the result of Current OR's

            -> Try to build this Solutions from this Approach: 
            -> Code: 

                        set<int> prev, curr, res;

                        for(int num: arr) {
                            for(int x: prev) {
                                curr.insert(x | num);   // take OR for current number, from previous OR's
                                res.insert(x | num);   // Save the result in result
                            }

                            // Last Element itself is also considered as self OR:
                            curr.insert(num);
                            res.insert(num);


                            // Now Overwrite the prev as curr & clear the curr
                            prev = curr;
                            curr.clear();
                        }

                        return res.size();  // this will be our answer.


            -> Observe the complexity: 
                -> You might be thinking taking OR for current number from all the previous Stored OR's will take O(n), right
                -> and we are doing this for all the number of given array, which will take O(n * n) => O(n^2), Well NO :)

                // Explanations: 
                    -> We are Using set to store OR's result, right means only unique value will be stored
                    -> OR Property: Set bits can't be unset, means: 

                        0000....0000    -> 32 bits in total

                    -> means, when we take any number & perfrom OR with previous, set bit's can't be flipped.
                    -> Only unset bits will be updated
                    -> We Have 32 positions, where we can set 1's in worse case
                    -> means 32 unique value we can store in set, by setting bit's one-by-one
                    -> In simple, in worse case we are iterating only 32 unique value from previous set only.

                            for(int x: prev) {  // 32 VALUE ITERATE ONLY, BECAUSE OF OR PROPERTY.
                                curr.insert(x | num);   // take OR for current number, from previous OR's
                                res.insert(x | num);   // Save the result in result
                            }                    

                            
            // Complexity: 
                -> TC: O(n * 32) = O(n)
                -> O(N)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient Solution: 
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();

        unordered_set<int> prev;    // SC: O(32)
        unordered_set<int> curr;    // SC: O(32)
        unordered_set<int> res;     // SC: O(n)

        for(auto& num: arr) {   // TC: O(n * 32), {From OR property, by taking or, bit only can be set, it can't be unset.}
            // Iterate in previous stored OR set, & take OR's with current num & store the result into curr & res
            for(auto& x: prev) {    // max size = 32
                curr.insert(num | x);
                res.insert(num | x);
            }
            // insert the current element into current & res
            curr.insert(num);
            res.insert(num);

            // Last overwrite the previous as current, so that we can compute for future operations:
            prev = curr;
            curr.clear();   // clear the current
        }
        
        return res.size();  // return the total number of unique OR's
    }
};

// Bruteforce Solution: 
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st;
        for(int i = 0; i < n; i++) {
            int temp = 0;
            for(int j = i; j < n; j++) {
                temp |= nums[j];
                
                st.insert(temp);
            }
        }

        return st.size();
    }
};
