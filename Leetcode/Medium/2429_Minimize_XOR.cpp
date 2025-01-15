/*

//  2429. Minimize XOR


//  Problem Statement: 
    -> Given two positive integers num1 and num2, find the positive integer x such that:
        -> x has the same number of set bits as num2, and
        -> The value x XOR num1 is minimal.
    -> Note that XOR is the bitwise XOR operation.
    -> Return the integer x. The test cases are generated such that x is uniquely determined.
    -> The number of set bits of an integer is the number of 1's in its binary representation.

 

// Example:

    Input: num1 = 3, num2 = 5
    Output: 3
    Explanation:
    The binary representations of num1 and num2 are 0011 and 0101, respectively.
    The integer 3 has the same number of set bits as num2, and the value 3 XOR 3 = 0 is minimal.

    Input: num1 = 1, num2 = 12
    Output: 3
    Explanation:
    The binary representations of num1 and num2 are 0001 and 1100, respectively.
    The integer 3 has the same number of set bits as num2, and the value 3 XOR 1 = 2 is minimal.



// Steps in the Approach:
    -> The task is to minimize the XOR value between num1 and another number x such that the number of set bits (1s) in x matches the number of set bits in num2.

        // Understand the Problem Requirements:
            num1 and num2 are given integers.
            We need to construct a new number x:
                x should have the same number of set bits (1s) as num2.
                x should be chosen such that the XOR between num1 and x is minimized.

        // Key Observations:
            To minimize the XOR value, the new number x should match num1 as closely as possible in terms of bit positions.
            The number of set bits (1s) in x must equal the number of set bits in num2. We can calculate this using the built-in function __builtin_popcount(num2).

        // Plan the Logic:
            Case 1: num1 has fewer set bits than required (currSetBitCount < requiredSetBitCount).
                Start from the least significant bit (LSB) of num1.
                For every bit that is not set (0), set it until the required number of set bits is reached.
            Case 2: num1 has more set bits than required (currSetBitCount > requiredSetBitCount).
                Start from the least significant bit (LSB) of num1.
                For every bit that is set (1), unset it until the required number of set bits is reached.

        // Implementation Details:
            Traverse through the bit positions of num1 from the least significant bit.
            Use bit manipulation to:
                Check if a bit is set (using x & (1 << bit)).
                Set a bit (using x |= (1 << bit)).
                Unset a bit (using x &= ~(1 << bit)).
            Adjust the bit count of x as required, either by setting or unsetting bits, while iterating through all possible bit positions.

        // Return the Result:
            After ensuring that x has the required number of set bits and matches num1 as closely as possible, return x.


// Complexity:
    -> TC: O(1)
    -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private:
    bool isSet(int &x, int bit) { 
        return x & (1 << bit);
    }
    void setBit(int &x, int bit) { 
        x |= (1 << bit);
    }
    void unsetBit(int &x, int bit) { 
        x &= ~(1 << bit);
    }
public:
    int minimizeXor(int num1, int num2) {
        int x = num1;  // Copy `num1` to `x` to modify its bits.

        // Calculate the required number of set bits in `x` (same as `num2`).
        int requiredSetBitCount = __builtin_popcount(num2); 
        // Calculate the current number of set bits in `x`.
        int currSetBitCount = __builtin_popcount(x);

        int bit = 0; // Variable to track the bit position we are processing.

        // Case 1: If the current number of set bits in `x` is less than required.
        if (currSetBitCount < requiredSetBitCount) {
            // Add additional set bits until the count matches the required number.
            while (currSetBitCount < requiredSetBitCount) {
                if (!isSet(x, bit)) { // Check if the current bit is not set.
                    setBit(x, bit);  // Set the current bit.
                    currSetBitCount++; // Increment the count of set bits.
                }
                bit++; // Move to the next bit position.
            }
        }
        // Case 2: If the current number of set bits in `x` is greater than required.
        else if (currSetBitCount > requiredSetBitCount) {
            // Remove extra set bits until the count matches the required number.
            while (currSetBitCount > requiredSetBitCount) {
                if (isSet(x, bit)) { // Check if the current bit is set.
                    unsetBit(x, bit); // Unset the current bit.
                    currSetBitCount--; // Decrement the count of set bits.
                }
                bit++; // Move to the next bit position.
            }
        }

        // Return the modified number `x` which satisfies the conditions.
        return x;
    }
};
