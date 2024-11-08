/*

// 1829. Maximum XOR for Each Query


// Problem Statement: 

    -> We are given sorted array nums of n, non-negative integer and an integer maximumBits
    -> you have to perform query n times:

    -> find a non-negative integer: k < 2^maximumBits, such that nums[0] XOR nums[1] XOR...nums[nums.length - 1] XOR k is maximized.
        -> K is the given answer to the ith query
        -> remove the last element from the current array 'nums'.

    -> Return an array, where answer[i] is the answer to the ith query.

            Example 1:

            Input: nums = [0,1,1,3], maximumBit = 2
            Output: [0,3,2,3]
            Explanation: The queries are answered as follows:
            1st query: nums = [0,1,1,3], k = 0 since 0 XOR 1 XOR 1 XOR 3 XOR 0 = 3.
            2nd query: nums = [0,1,1], k = 3 since 0 XOR 1 XOR 1 XOR 3 = 3.
            3rd query: nums = [0,1], k = 2 since 0 XOR 1 XOR 2 = 3.
            4th query: nums = [0], k = 3 since 0 XOR 3 = 3.

            Example 2:

            Input: nums = [2,3,4,7], maximumBit = 3
            Output: [5,2,6,5]
            Explanation: The queries are answered as follows:
            1st query: nums = [2,3,4,7], k = 5 since 2 XOR 3 XOR 4 XOR 7 XOR 5 = 7.
            2nd query: nums = [2,3,4], k = 2 since 2 XOR 3 XOR 4 XOR 2 = 7.
            3rd query: nums = [2,3], k = 6 since 2 XOR 3 XOR 6 = 7.
            4th query: nums = [2], k = 5 since 2 XOR 5 = 7.

    
// Visualization: 

                    XOR Logic: 
                            T T = F
                            F F = F
                            T F = T
                            F T = T


        Example:

            nums = [0,1,1,3]    maximumBits = 3

                    2^3 = 8 so, k should be less than 8, k can be "1 2 3 4 5 6 7"

                    -> One thing we are sure that the maximum k value is: (2^(maximumBit) - 1)

                    -> Also the patterns that we are observing from the given example is: 
                        -> Every time we are taking XOR Operations like:
                            query[n-1] = nums[0] XOR k
                            query[n-1] = nums[0] XOR nums[1] XOR k
                            query[n-2] = nums[0] XOR nums[1] XOR nums[2] XOR k
                            query[n-4] = nums[0] XOR nums[1] XOR nums[2] XOR nums[3] XOR k
                            query[..]  = ....
                            query[..]  = ....
                            query[0th] = nums[0] XOR nums[1] XOR nums[2] XOR nums[3] XOR ...... XOR nums[nums.size()-1] XOR k


                    -> These operations looks something simillar to "prefix sum type"
                    -> Similarly, if we found "Prefix XOR"

                        nums = [0,1,1,3]

                        PrefixXOR: [0, 1, 0, 3]

                        Now, we only have to do 

                            prefixXOR[i] XOR k -> In order to find the maximum XOR result...
                        
                        The maximum k value is (2^(maximumBit) - 1)

                        So, if we take

                                    prefixXOR[i] XOR (2^(maximumBit) - 1)

                        & We will have to do for all values of nums ^ store the result into some array & return..

                
        Also Given Hints in Question:
            hint 1: maximum possible XOR result is always 2^(maximumBit) - 1
            hint 2: So the answer for a prefix is the XOR of that prefix XORed with 2^(maximumBits) -1

                -> From this given hints, we understand that first we have to find the prefixXOR, then
                -> We can take PrefixXOR[i] ^ (2^(maximumBit) - 1)


// Complexity: 
    * TC: O(n)
    * AS: O(n)


*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();

        // Finding Prefix XOR:
        vector<int> prefXOR(n);
        prefXOR[0] = nums[0];   
        for(int i=1;i<n;i++){
            prefXOR[i] = prefXOR[i-1] ^ nums[i];
        }


        // Then we can find XORed with 2^(maximumBit) - 1
        vector<int> res;
        int k = pow(2, maximumBit) - 1; // maximum possible value of 'k'
        // We are iterating backward, because are using "PrefixXOR" array, & the last value will store the xor of entire array, & that will be our first query for 'k'
        for(int i=n-1;i>=0;i--){
            int x = k ^ prefXOR[i]; // taking XOR with every Prefix XOR
            res.push_back(x);   // every time we are pushing result into backward, because we have used "prefixXOR" array, & at every iterations last values will be removed, & new query generated........             Think logically
        }

        return res; // last return answer
    }
};