/*

//  3133. Minimum Array End


// Problem Statement:
    * You are given two integers n and x. 
    * You have to construct an array of positive integers nums of size n where for every 0 <= i < n - 1, nums[i + 1] is greater than nums[i], 
    * and the result of the bitwise AND operation between all elements of nums is x.

    * Return the minimum possible value of nums[n - 1].


// Example: 

    Example 1:
        Input: n = 3, x = 4
        Output: 6
        Explanation: nums can be [4,5,6] and its last element is 6.

    Example 2:
        Input: n = 2, x = 7
        Output: 15
        Explanation: nums can be [7,15] and its last element is 15.


// Visualization:

    * According to the question, we need to find the minimum possible value of nums[n-1], for which (nums[i] > nums[i-1]) & the result of bitwise AND operations b/w all element of nums is equal to 'x'

            nums[0] & nums[1] & nums[2] & .... & nums[n-1] = 'X'

            let x = 1 0 0 1 1 0 1
                    -     - -   -       => These bits should be set in all the nums element if we have to equal our result to 'x'
                
              nums[0] & nums[1] & nums[2] & .... & nums[n-1] = 'X'
                |          |        |               |
                ------------------------.......-------
                                |
                            1 _ _ 1 1 _ 1    for all the element of nums these bits should be fixed..
                        
            
            Now, for this empty places we will have to fill the values:  1 _ _ 1 1 _ 1 
            But there is a given condition that nums[i-1] < nums[i] 
            So we will have to fill our values in a way that we can gradually increase the result..
                                  
                We can't directly fill 1 _ _ 1 1 _ 1 
                                         1 1     1     -> on these position, because this will make our value extreme grater, & we will have to minimum possible value of "nums[n-1]"

                So, instead of filling 1 directly we will fill our values for empty position like: 

                                                        0   -> 0
                                                      0 1   -> 1
                                                      1 0   -> 2
                                                      1 1   -> 3
                                                    1 0 0   -> 4
                                                    1 0 1   -> 5
                                                    1 1 0   -> 6
                                                    1 1 1   -> 7
                                                  1 0 0 0   -> 8
                                                  ....      so on.

                        So, we will fill like: 
                                1 _ _ 1 1 0 1   -> fill 0
                                1 _ _ 1 1 1 1   -> fill 1
                                1 _ 1 1 1 0 1   -> fill 2
                                1 _ 1 1 1 1 1   -> fill 3
                                .... so on...   -> fill up till n time & whatever this number form we will have to return this.


                & we are allowed to fill our values up till 'n' times, & we will have to return "nums[n-1]th" value



            Example: 
                        n = 3, x = 4

                        binary representation of x = 4 => 1 0 0

                                        1 0 0  -> x
                                        | 
                                    This should be fixed in all the nums[i]
                        
                        And we can fill up till 3, means the size of nums[] array is 3, & we will have return our last value..
                                        
                                This is fixed throughout the filling...
                                        |
                                        1 0 0 -> 0      |
                                        1 0 1 -> 1      |   -> n = 3, means we can fill up till 3 times..
                                        1 1 0 -> 2      |

                                and we will have to return "nums[n-1]" value, 

                            
                                1 1 0 -> 6  => nums[n-1]

                        So, output is 6
                        
                        Let's check whether it's satisfy the given condition or not?

                            NOW: AND of all the array: [100, 101, 110]

                                1 0 0 
                                1 0 1
                                1 1 0   AND
                            -------------
                                1 0 0 = 4 = x

                            also
                                    100 = 4     ->      nums[0]
                                    101 = 5     ->      nums[1]
                                    110 = 6     ->      nums[2]

                                    nums[i-1] < nums[i]

                            Both the condition satisfy.

            Example 2:

                        n = 2,   x = 7

                                x = 1 1 1 -> NOTE: this number represent in 64-bit is: 

                                        _ _ _ .... _ _ _ 1 1 1
                                        <-------------------->
                                            In total we have 64 position, as it's 64-bit size


                            so, 
                                    filling is like: 

                                        n = 2, nums[], array have two element:

                                        _ _ _ .... _ _ _ 1 1 1
                                                         | | |  
                                                        these bits are fixed, we will have to fill only 0's



                                        _ _ _ .... _ _ 0 1 1 1   -> 0   | nums[0]
                                        _ _ _ .... _ _ 1 1 1 1   -> 1   | nums[1]

                                    
                                    we will for n = 2, we only have two elements, & nums[n-1]th is:
                                                nums[n-1] _ _ _ .... _ _ 1 1 1 1    -> Don't worry about _ empty places, it will have 0's

                                                    1 1 1 1 = 15
                            
                            Output = 15
                                                

// Approach Overview
    * The key challenge in this problem is to construct an array that meets both the increasing order constraint and the bitwise AND constraint. The solution involves manipulating the binary representations of the given input x and using bits from n - 1 to ensure the values remain valid and as small as possible.
        * Strategy and Explanation
            * Binary Representation of x:
                * First, we represent the given value x in its binary form. This will be used to guide the construction of elements in the array nums since all elements must ensure that their bitwise AND yields x.

            * Binary Representation of n - 1:
                * We also represent n - 1 in binary. This value acts as a source of "adjustment bits" that we can use to fill unset bits (0s) in the binary representation of x.
                * The idea here is to fill the unset bits in a controlled manner, ensuring that the elements in nums remain strictly increasing.

            * Constructing the Array Elements:
                * We use a bit-by-bit approach to modify the binary representation of x. When we encounter unset bits (0s) in x, we replace them with bits from the binary representation of n - 1.
                * This ensures that we are gradually increasing the values while maintaining the desired bitwise AND result.

            * Final Calculation:
                After modifying the bits, we convert the resulting binary value back to a decimal number. This value represents the minimum possible value for nums[n-1].

        * Why This Approach Works
            * By using the bits of n - 1, we ensure that the constructed elements in the array nums are strictly increasing. The use of n - 1 allows for minimal increments, thus guaranteeing that nums[n-1] is as small as possible while satisfying all constraints.
            * The bitwise AND condition is maintained throughout the process by ensuring that the original bits of x are preserved in all elements of the array.

        * This approach efficiently handles the problem using bitwise operations and ensures an optimal solution for the minimum value of nums[n - 1].


*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

#include<bits/stdc++.h>
using namespace std;
#define ll long long  // Defining a macro for long long to shorten the syntax for easier usage later.

class Solution {
public:
    // Function to find the minimum possible value of nums[n - 1]
    long long minEnd(int n, int x) {
        n--;    // Decrementing n to work with n - 1 elements, since we are focused on constructing an array where nums[n - 1] is minimized.

        vector<int> xBit(64, 0);  // Creating a vector to store the binary representation of x, with 64 bits initialized to 0.
        vector<int> nBit(64, 0);  // Creating another vector to store the binary representation of n - 1, with 64 bits initialized to 0.

        // Extracting bits of x and storing in xBit vector
        for(int i = 0; i < 32; i++) {  // Iterating through the first 32 bits (assuming standard integer size)
            xBit[i] = (x >> i) & 1;   // Right shift x by i positions and perform bitwise AND with 1 to get the ith bit. Store it in xBit.
            nBit[i] = (n >> i) & 1;   // Right shift n by i positions and perform bitwise AND with 1 to get the ith bit. Store it in nBit.
        }


        int i = 0, j = 0;  // Initialize two indices: i for traversing xBit and j for traversing nBit.
        // Fill the xBit vector using bits from nBit vector where possible
        while(i < 64) {  // Loop through each bit position up to 64 bits
            if(xBit[i] == 1) {  // If the current bit in xBit is already set (1), move to the next bit.
                i++;
                continue;  // Skip further operations for this iteration as the bit is fixed.
            }
            xBit[i++] = nBit[j++]; // If xBit[i] is 0, copy the bit from nBit[j] to xBit[i] and increment both indices.
        }

        // Calculate the final result by reconstructing the number from xBit
        long long res = 0;  // Initialize the result to 0
        for(int i = 0; i < 64; i++) {  // Loop through all 64 bits
            res += xBit[i] * (1LL << i);  // Multiply each bit by 2^i and accumulate the sum to form the final number.
        }

        return res;  // Return the minimum possible value of nums[n - 1]
    }
};


int main(){

    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;

        Solution obj;
        cout << obj.minEnd(n, x) << endl;
    }

    return 0;
}
