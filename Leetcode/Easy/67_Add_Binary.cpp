/*

//  67. Add Binary


// Problem Statement:
    -> Given two binary strings a and b, return their sum as a binary string.
 

// Example: 
    Example 1:
        Input: a = "11", b = "1"
        Output: "100"

    Example 2:
        Input: a = "1010", b = "1011"
        Output: "10101"


// Observations: 
    -> we need to perfrom binary addition of two number
    -> use simllar addition technique which we use in decimal additions.


        1   0   1   0       ->      10
        1   0   1   1       ->      11
    ----------------------------

        -> Start from right right hand side
        -> Perform additions just like decimal
        -> maintain carray variable..

            10 + 11 = 21
            21 in binary = 10101

        -> Start adding bits: 
            sum = s[i] + s[j] + carry
            sum = 0 + 1 + 0 = 1
            
            res += (sum % 2) + '0'  -> Store the rightmost bits in result & convert it into string.
            carry = (sum / 2) -> store leftmost bits as carray

    // Complexity: 
        -> TC: O(max(a.size(), b.size()))
        -> SC: O(max(a.size(), b.size()))


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {

        string res = "";

        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while(i >= 0 || j >= 0 || carry) {

            // Get the sum: carry + s1(bit) + s2(bit)
            int sum = carry;
            if(i >= 0) sum += a[i] - '0';
            if(j >= 0) sum += b[j] - '0';

            // Move both the pointers:
            i--;
            j--;

            res += (sum % 2) + '0';     // Store sum -> right most bit
            carry = sum / 2;            // store the carry -> left most bits
        }

        reverse(begin(res), end(res));

        return res;
    }
};