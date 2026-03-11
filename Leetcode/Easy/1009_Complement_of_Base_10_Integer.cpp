/*

//  1009. Complement of Base 10 Integer


//  Problem Statement: 
- The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.
    - For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
- Given an integer n, return its complement.


// Example: 

    Example 1:
        Input: n = 5
        Output: 2
        Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.

    Example 2:
        Input: n = 7
        Output: 0
        Explanation: 7 is "111" in binary, with complement "000" in binary, which is 0 in base-10.

    Example 3:
        Input: n = 10
        Output: 5
        Explanation: 10 is "1010" in binary, with complement "0101" in binary, which is 5 in base-10.

 

// Observations:
    - we are given n, and we need to reverse all the binary bits of that..
    - eg:
        n = 5
            5 = 101
            reversed: 010  = 2
        
        // Approach 1:
            - First get the bits from num 'n' & store the flipped bits into string s.
            - reverse the string so that it should be in order.
            - Now insert the bits into by right shift:
                - first make space by left shift by 1
                - then make OR with bits.

            // Complexity:
                - TC: O(logn)
                - SC: O(1)


        // Approach 2:
            - eg: n = 5 = 101
            - first we have to get the size of every binary number
                int size = log2(n) + 1;         =>      3
                
            - Then we can insert the size times into '1'
                int mask = (1 << size);         => 1000         This will insert 3 zeroes left shift into '1'
                mask -= 1;                      =>  111         This will just get the previous, which is all '1'

            - Now we have mask = 111, and n = 101
                - Taking XOR will reverse the bit which are same:
                - XOR:
                    same bit = 0
                    diff bit = 1

                                101         5
                            ^   111         mask
                            -----------
                                010         2

        // Complexity:
            - TC: O(1)
            - SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Approach 2:
class Solution {
public:
    int bitwiseComplement(int n) {
        
        // Edge case:
        if(n == 0) return 1;
        
        // Count total number of bits:
        int size = log2(n) + 1; // we can count total number of bits

        int mask = (1 << size) - 1;
        
        int res = n ^ mask;     // taking xor will reverse the whole bits.

        return res;
    }
};


// Approach 1:
class Solution {
public:
    int bitwiseComplement(int n) {
        
        // Edge case:
        if(n == 0) return 1;
        
        // Get the bianry String of that number
        string bits = "";
        while(n > 0) {
            int bit  = n & 1;
            
            if(bit == 0) bits += '1';   // insert '1'
            else bits += '0';            // else insert '0'

            n >>= 1;
        }

        reverse(begin(bits), end(bits));    // reverse to make them in order

        int res = 0;
        for(auto &c: bits) {
            res <<= 1;              // make position
            res = res | (c - '0');  // Insert bit
        }

        return res;
    }
};