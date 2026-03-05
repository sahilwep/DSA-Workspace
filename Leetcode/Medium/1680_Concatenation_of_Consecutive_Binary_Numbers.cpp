/*

//  1680. Concatenation of Consecutive Binary Numbers


//  Problem Statement: 
    - Given an integer n, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 109 + 7.
 

// Example:
    Example 1:
        Input: n = 1
        Output: 1
        Explanation: "1" in binary corresponds to the decimal value 1. 

    Example 2:
        Input: n = 3
        Output: 27
        Explanation: In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
        After concatenating them, we have "11011", which corresponds to the decimal value 27.

    Example 3:
        Input: n = 12
        Output: 505379714
        Explanation: The concatenation results in "1101110010111011110001001101010111100".
        The decimal value of that is 118505380540.
        After modulo 109 + 7, the result is 505379714.


// Observations:
    - Given n
    - we need to concatenate the binary string from 1 to n & take mod 1e9+7
    - we need to return the result.


    // Binary Observations:

        1
        10      110
        11      11011
        100     11011100        =>      220 
        101     11011100101     =>      1765

        We have number              11011100        =>      220
        We left shift by 3 pos      11011100000     =>      1760
        then add next number value  11011100101     =>      1765


    // Optimization:
        - from 1 to n:
            - we will have to connate all the bits.
            - for every number we have to find what's the size of that binary number
                eg
                    3:  11       -> 2
                    7:  111      -> 3
                    10: 1010     -> 4

            - So we will make space for that position:
                - We can do this bt left shift by the size of that binary number.
                - eg
                    If our number is 5 => 101
                    next number is 6: 110, and it's size is 3

                    So, we left shift by 3 position.
                    New number will be: 101000

                    Now we will add that number 6 = 101 with that:

                        101000
                           110 +
                    ------------
                        101110  => Concatenated number

                - Insted of doing all this operations in binary we will do this in decimal..
                       
    // Complexity:
        - TC: O(n)
        - SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    typedef long long ll;
    int mod = 1e9 + 7;
public:
    int concatenatedBinary(int n) {
        
        ll num = 0;
        for(int i = 1; i <= n; i++) {
            // Find the size of binary number 'i'
            int size = log2(i) + 1;         // this will give the binary size of number 'i', like we used to do in decimal number for finding how many digits (log10(n) + 1)

            // left shift by size times so that we can have space.
            num = (num << size) % mod;

            // add that number 'i'
            num = (num + i) % mod;
        }

        return (int)num;
    }
};