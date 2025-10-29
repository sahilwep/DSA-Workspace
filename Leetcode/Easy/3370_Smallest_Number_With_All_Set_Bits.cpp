/*

//  3370. Smallest Number With All Set Bits


//  Problem Statement: 
    -> You are given a positive number n.
    -> Return the smallest number x greater than or equal to n, such that the binary representation of x contains only

 
// Example:
    Example 1:
        Input: n = 5
        Output: 7
        Explanation: The binary representation of 7 is "111".

    Example 2:
        Input: n = 10
        Output: 15
        Explanation: The binary representation of 15 is "1111".

    Example 3:
        Input: n = 3
        Output: 3
        Explanation:The binary representation of 3 is "11".


// Observations: 
    -> we need smallest number x grater or equal to 'n'

    // Approach:
        -> Convert the given number into binary string.
            -> Check if it's all bits are set, if then return that same number
            -> Else: make as string of same size & mark all '1'
            -> Convert that binary string into decimal number, & return.

    // Complexity:
        // Theoretical Complexity:
            -> TC: O(logn)
            -> SC: O(logn)
            
        // Practical Complexity: only processing for 32-64 bit-int
            -> TC: O(1)
            -> SC: O(32) = O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private:
    bool isAllBitsSet(string s) {
        for(auto &it: s) if(it == '0') return false;
        return true;
    }
    string getBinary(int n) {
        if(n == 0) return "0";
        string s = "";

        while(n > 0) {
            s += to_string(n % 2);
            n /= 2;
        }

        reverse(begin(s), end(s));
        return s;
    }
    int getDecimal(string s) {
        int n = s.size();

        reverse(begin(s), end(s));
        int res = 0;

        for(int i = 0; i < n; i++) {
            int currVal = pow(2, i) * (int)(s[i] - '0');   // (2^i * digit) => typecast into integer
            res += currVal;
        }

        return res;
    }
public:
    int smallestNumber(int n) {
        
        // check if the current num has all set bits..
        string num = getBinary(n);
        if(isAllBitsSet(num)) return n;

        // else set all bits of string num, (as we set all bits, the size let say 4 or 5 or 6... any, will be the nearest set bit value..)
        for(auto &it: num) it = '1';
        return getDecimal(num); // return decimal value of it.
    }
};