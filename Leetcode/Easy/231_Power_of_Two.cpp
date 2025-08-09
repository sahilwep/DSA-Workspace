/*

//  231. Power of Two


//  Problem Statement: 
    -> Given an integer n, return true if it is a power of two. Otherwise, return false.
    -> An integer n is a power of two, if there exists an integer x such that n == 2x.

 
// Example: 
    Example 1:
        Input: n = 1
        Output: true
        Explanation: 20 = 1

    Example 2:
        Input: n = 16
        Output: true
        Explanation: 24 = 16

    Example 3:
        Input: n = 3
        Output: false


// Observations: 
    -> We have to check wether the given number is power of 2 or not?
    -> power of 2:  

            2^0  =  2   =  00001
            2^1  =  4   =  00010
            2^2  =  8   =  00100
            2^3  =  16  =  01000
            2^4  =  32  =  10000
            2^....

        -> One thing, we can observe that every power of 2, has only single set-bits.
        -> Any other number like: 5 = 101, 3 = 11, 7 = 111, has multiple set-bits
        -> We can count the set-bits, if it's grater than 1, we can say it's not the power of '2'
    -> In simple, any number which has only single set-bits, we can say it's power of '2'


    // How to count the set-bits
        -> iterate while number not become '0'
            -> fetch the last bits & add it into setBitsCount
                -> setBits += (n & 1)   => If last significant bit is set, it will add 1, else add 0
                -> shift 1 positions to right: n >>= 1
    
    // Complexity:  
        -> TC: O(logN)
            -> Because, at every iterations we are making that number as half.
        -> SC: O(1)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false; // negative & '0' can't be power of '2'
        if(n == 1) return true; 

        // Count set bits:
        int setBits = 0;
        while(n > 0) {
            setBits += n & 1;   // checks the last significant bits, adds 1 if last bit is true : else add 0
            n >>= 1;    // right shift to 1

            if(setBits > 1) return false;   // check if setBits is grater than 1, mean's it's not the power of '2'
        }

        return true;    // else return true
    }
};