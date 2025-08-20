/*

//  342. Power of Four

//  Problem Statement:
    -> Given an integer n, return true if it is a power of four. Otherwise, return false.
    -> An integer n is a power of four, if there exists an integer x such that n == 4x.


//  Example:
    Example 1:
        Input: n = 16
        Output: true

    Example 2:
        Input: n = 5
        Output: false

    Example 3:
        Input: n = 1
        Output: true


// Approach 1: 
    -> Range observations: 

        INT_MAX = 2,147,483,647
        4^15    = 1,073,741,824 -> Fit-in Int Range
        4^16    = 4,294,967,296 -> Exceed

    -> Iterate from 1 to pow(4,15) & try finding the value which is power of '4'

    // Complexity: 
        -> TC: O(1)
        -> SC: O(1)


// Approach 2: 
    -> Use Binary search to find the in range 1 to pow(4, 15)

    // Complexity: 
        -> TC: O(1)
        -> SC: O(1)



// Approach 3: 
    -> power of 4:

            4^0     =       1       =   00000000001
            4^1     =       4       =   00000000100
            4^2     =       16      =   00000010000
            4^3     =       64      =   00001000000
            4^4     =       256     =   00100000000
            4^5     =      1024     =   10000000000

    -> Like power of 2, it has only one set bits, it's just their bits position has one extra gap.
    -> Constraints:
            -2^31 <= n <= 2^31 - 1

    -> Constrains fits in int.

            2^31    = 2,147,483,648 - 1 = 2,147,483,647 = INT_MAX
            INT_MAX = 2,147,483,647


    // Approach: 
        -> Iterate from 0 to 31 & check the number of set bits, if we have only 1 set bits => yes power of 4
        -> NOTE: only set bits found at even position.
            -> If we have only single set bits & if it's found in even position, then only we can say it's power of 2
            -> else single set bits at odd position consider as power of '2'
        -> Find the set bits, if it has single set bit & is at even position then only we can say it's power of 4


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Approach 1:
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;

        for(int i = 0; i <= 15; i++) {
            if(pow(4, i) == n) return true;
        }

        return false;
    }
};

// Approach 2:
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;

        int low = 0;
        int high = 15;
        while(low <= high) {
            int mid = (low + high) / 2;
            int power = pow(4, mid);

            if(power == n) return true;
            else if(power < n) {
                low = mid + 1; 
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
};

// Approach 3:
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;

        int pos = -1;
        int num = 1;
        int setBits = 0;

        for(int i = 0; i < 32; i++) {
            setBits += n & 1;   // accumulate the set bits from the last position if it's set, added into result
            
            if(n & 1 == 1 && i % 2 != 0) return false;      // if we found set bits at odd position return false
            if(setBits > 1) return false;   // if we found more than one set bits -> return false;

            n >>= 1;    // right shift by 1
        }

        return true;
    }
};



// Binary Search:


// Linear Iterations: 
