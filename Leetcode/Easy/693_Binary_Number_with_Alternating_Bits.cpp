/*

//  693. Binary Number with Alternating Bits


//  Problem Statement: 
    - Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.
 

// Example:
    Example 1:
        Input: n = 5
        Output: true
        Explanation: The binary representation of 5 is: 101

    Example 2:
        Input: n = 7
        Output: false
        Explanation: The binary representation of 7 is: 111.

    Example 3:
        Input: n = 11
        Output: false
        Explanation: The binary representation of 11 is: 1011.

        
// Observations:


    // Approach 1:
        - Convert the given num into binary string & check if it's valid or not?

        // Complexity:  
            - TC: O(logn)
            - SC: O(logn)


    // Approach 2:
        - we need to check wether the given number has alternating bits or not?
        - 1 <= n <= 2^31-1
        - We can get the last bit of the number every time
        - if it's alternating from the previous one, it's true
        - else false.
        - we will use right shift operations..
        - we will do the operations until "n > 0", if n == 0, means we are out of range.


        // Complexity:  
            - TC: O(logn)
            - SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Approach 1:
class Solution {
private: 
    string toBinary(int n) {
        string s = "";

        while(n > 0) {
            int ld = n % 2;
            s += ld + '0';
            n /= 2;
        }

        reverse(begin(s), end(s));

        return s;
    }
public:
    bool hasAlternatingBits(int n) {    // TC: O(logn)
        
        string num = toBinary(n);   // TC: O(logn)

        // get the first '1'
        int i = 0;
        for(; i < num.size(); i++) {    // O(logn)
            if(num[i] == '1') break;
        }

        char prev = '1';
        i++;    // move forward

        // now check alternating bits:
        for(; i < num.size(); i++) {    // O(logn)
            char curr = num[i];

            if(curr == prev) return false;

            prev = curr;
        }

        return true;    // all bits are alternating.
    }
};


// Approach 2:
class Solution {
public:
    bool hasAlternatingBits(int n) {    // TC: O(logn)
        
        int prev = n & 1;   // last bit
        n >>= 1;            // remove last bit.

        while(n > 0) {  // while n is grater than '0'   // O(logn)
            int curr = n & 1;

            if(curr == prev) return false;

            prev = curr;
            n >>= 1;
        }

        return true;    // all bits are alternating.
    }
};