/*

//  3876. Construct Uniform Parity Array II


//  Problem Statement: 
    - You are given an array nums1 of n distinct integers.
    - You want to construct another array nums2 of length n such that the elements in nums2 are either all odd or all even.
    - For each index i, you must choose exactly one of the following (in any order):
        - nums2[i] = nums1[i]​​​​​​​
        - nums2[i] = nums1[i] - nums1[j], for an index j != i, such that nums1[i] - nums1[j] >= 1
    - Return true if it is possible to construct such an array, otherwise return false.

 
// Example:
    Example 1:
        Input: nums1 = [1,4,7]
        Output: true
        Explanation:​​​​​​​​​​​​​​
            Set nums2[0] = nums1[0] = 1.
            Set nums2[1] = nums1[1] - nums1[0] = 4 - 1 = 3.
            Set nums2[2] = nums1[2] = 7.
            nums2 = [1, 3, 7], and all elements are odd. Thus, the answer is true.

    Example 2:
        Input: nums1 = [2,3]
        Output: false
        Explanation: It is not possible to construct nums2 such that all elements have the same parity. Thus, the answer is false.


    Example 3:
        Input: nums1 = [4,6]
        Output: true
        Explanation:
            Set nums2[0] = nums1[0] = 4.
            Set nums2[1] = nums1[1] = 6.
            nums2 = [4, 6], and all elements are even. Thus, the answer is true.

    // Constraints:
        1 <= n == nums1.length <= 1e5
        1 <= nums1[i] <= 1e9
        nums1 consists of distinct integers.



// Observations:
    - Given nums1 of n distinct integer.
    - want to construct array num2 of length n, such that the element in num2 are either odd or even.
    - For each index i, you must choose exactly one of the following (in any any order)
        - nums2[i] = nums1[i]
        - nums2[i] = nums1[i] - nums1[j], j != i, such tat nums1[i] - nums1[j] >= 1

    - return true if it's possible..

    // Approach:
        - If all odd or all even: we can make..
        - If there are some odd and even elements:

            nums1[i] - nums1[j] >= 1
            
        - If min element is odd:
                for odd element we do the nums2[i] = nums1[i];
                for even element we can subtract that minOddElement:
                    4(even)
                    3(min odd in our array)
                    4 - 3 >= 1
                    and we can make it odd..

        - So, if minElement is odd => we can make all the element to odd..

        - This follows because: 
                even - odd = odd => so minElement is odd, we can make anyway all odd..

            - if Minimum element is even, let say 2, and even = 5 => 5 - 2 = 3(odd)
            - anyway we subtract 
                
                odd - even = odd => parity still remains..

        // Clear Observations:
            OriginalNum - MinNum
                    odd - even = odd (no parity change of original num)
                    even - odd = odd (parity changed of original num)


    //  Complexity:
        - TC: O(n)
        - SC: O(n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        
        bool hasOdd = false, hasEven = false;
        int minEl = nums1[0];
        for(auto &i: nums1) {
            if(i % 2 == 0) hasEven = true;
            else hasOdd = true;

            minEl = min(i, minEl);
        }

        // all odd || all even
        if(!hasOdd || !hasEven) return true;

        return (minEl % 2 != 0);
    }
};