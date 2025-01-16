/*

//  2425. Bitwise XOR of All Pairings


//  Problem Statement: 
    -> You are given two 0-indexed arrays, nums1 and nums2, consisting of non-negative integers. 
    -> There exists another array, nums3, which contains the bitwise XOR of all pairings of integers between nums1 and nums2 (every integer in nums1 is paired with every integer in nums2 exactly once).
    -> Return the bitwise XOR of all integers in nums3.


// Example: 

    Example 1:

        Input: nums1 = [2,1,3], nums2 = [10,2,5,0]
        Output: 13
        Explanation:
        A possible nums3 array is [8,0,7,2,11,3,4,1,9,1,6,3].
        The bitwise XOR of all these numbers is 13, so we return 13.

    Example 2:

        Input: nums1 = [1,2], nums2 = [3,4]
        Output: 0
        Explanation:
        All possible pairs of bitwise XORs are nums1[0] ^ nums2[0], nums1[0] ^ nums2[1], nums1[1] ^ nums2[0],
        and nums1[1] ^ nums2[1].
        Thus, one possible nums3 array is [2,5,1,6].
        2 ^ 5 ^ 1 ^ 6 = 0, so we return 0.





// Observations: 
    Example:
        Input: nums1 = [2,1,3], nums2 = [10,2,5,0]
        Output: 13
        Explanation:
        A possible nums3 array is [8,0,7,2,11,3,4,1,9,1,6,3].
        The bitwise XOR of all these numbers is 13, so we return 13.

        XOR:
            diff = 1
            same = 0

        -> We are taking XOR of these pairs:

                (2^10) ^ (2^2) ^ (2^5) ^ (2^0) ^ 
                (1^10) ^ (1^2) ^ (1^5) ^ (1^0) ^
                (1^10) ^ (3^2) ^ (3^5) ^ (3^0)

            -> Taking XOR:

                    (2^10) ^ (1^10) ^ (1^10)  => 9 ^ 8 ^ 11 => 10
                    (2^2)  ^ (1^2)  ^ (1^2)   => 3 ^ 0 ^ 1 => 2
                    (2^5)  ^ (1^5)  ^ (1^5)   => 4 ^ 7 ^ 6 => 5
                    (2^0)  ^ (1^0)  ^ (1^0)   => 2 ^ 1 ^ 3 => 0      XOR
                                                        ------------
                                                              13

            -> Analyze single pairs:

                            1  = 0001
                            2  = 0010
                            3  = 0011
                            10 = 1010
                            10 = 1010
                            10 = 1010   XOR
                        -----------------------
                                 1 0 1 0 => 10



            Odd times XOR: 
                10 = 1010
                10 = 1010
                10 = 1010   XOR
            ------------------------
                    1 0 1 0    => Same as number
                    if it's odd times: gives same number

        Even times XOR:
                10 = 1010
                10 = 1010
                10 = 1010
                10 = 1010   XOR
            ------------------------
                    0 0 0 0 => 0 
                    if it's even times: gives '0'


    // Key Observations: 
        -> When size is even we don't have to take care, because it will become '0' in pairs
        -> When size is odd, then only we have to check:
            -> When first num1 size is odd:
                => Every element of num1 contribute
            -> When second num2 size is odd:
                => Every element of num2 contribute

        
        // Simplified:
            -> If the num1 size is odd:
                -> doesn't matter what's the size of num2, all the element should be considered
                -> because if num2 is even then num1 will cancel out
                -> and if num2 is of odd, then we will have to include num1 also, which will take care of below condition.
            -> If the num2 size is odd:
                -> then we also have to take all the element of num1, as we are checking only odd case..
                -> & if num2 size is even, then this condition will never run & we won't be considering num1


// Complexity: 
    -> TC: O(n + m)
        -> n = nums1.size();
        -> m = nums2.size();
    
    -> SC: O(1)
    

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Clean Code:
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int result = 0;

        // If the size of nums1 is odd, every element in nums2 will contribute to the XOR result.
        if(n % 2 != 0) {    
            // doesn't matter num2 is odd or even size, all element should be considered,
            // because if it's even then all the element of num1 should be cancel out.
            // and if it's odd, then the below if condition will take care.
            for (int num : nums2) {
                result ^= num;
            }
        }

        // If the size of nums2 is odd, every element in nums1 will contribute to the XOR result.
        if(m % 2 != 0) {
            for (int num : nums1) {
                result ^= num;
            }
        }

        return result;
    }
};



// Explained Version of Code:
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int result = 0;

        if (n % 2 == 0 && m % 2 == 0) {   // If both arrays are of even size, then all element pairs will occur an even number of times, so they will cancel out to '0'.
            result = 0;
        }
        else if (n % 2 != 0 && m % 2 != 0) {  // If both arrays are of odd size, then the elements will not cancel out in pairs. We get the same elements, so we will include all elements from both arrays.
            for (auto &i : nums1) {
                result ^= i;
            }
            for (auto &i : nums2) {
                result ^= i;
            }
        }
        else if (n % 2 != 0 && m % 2 == 0) {  // If the first array is of odd size and the second is of even size, we only need to consider the second array, because the odd-sized array pairs an even number of times and cancels out. The result is determined by the second array (nums2).
            for (auto &i : nums2) {
                result ^= i;
            }
        }
        else if (n % 2 == 0 && m % 2 != 0) {  // If the first array is of even size and the second is of odd size, this is the reverse of the above condition. We only need to consider the first array (nums1).
            for (auto &i : nums1) {
                result ^= i;
            }
        }

        return result;
    }
};


// BruteForce Solution: Gives TLE
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        // Directly generate the result of third array:
        long long int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans ^= nums1[i] ^ nums2[j];
            }
        }

        return ans;
    }
};