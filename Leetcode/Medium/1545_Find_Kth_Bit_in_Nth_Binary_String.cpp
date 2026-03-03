/*

//  1545. Find Kth Bit in Nth Binary String


//  Problem Statement: 
    - Given two positive integers n and k, the binary string Sn is formed as follows:
        S1 = "0"
        Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1
    - Where + denotes the concatenation operation, reverse(x) returns the reversed string x, and invert(x) inverts all the bits in x (0 changes to 1 and 1 changes to 0).
    - For example, the first four strings in the above sequence are:
        S1 = "0"
        S2 = "011"
        S3 = "0111001"
        S4 = "011100110110001"
    - Return the kth bit in Sn. It is guaranteed that k is valid for the given n.

 
// Example:

    Example 1:
        Input: n = 3, k = 1
        Output: "0"
        Explanation: S3 is "0111001".
        The 1st bit is "0".

    Example 2:
        Input: n = 4, k = 11
        Output: "1"
        Explanation: S4 is "011100110110001".
        The 11th bit is "1".

//  Observations:
    - We are given n & k
    - We have to generate the nth string using this s[i]:
        s[1] = '0'
        Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1
        NOTE: Indexing start with '1'

    - When we have nth string, return the 1-based index.


    // Complexity:
        - TC: O(2^n)
        - SC: O(2^n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    string generateNext(string& s) {    // Generate Next string sequence

        // Generate the reverse inverted of the string:
        string inv = s;
        for(auto &ch: inv) {
            if(ch == '1') ch = '0';
            else ch = '1';
        }
        reverse(begin(inv), end(inv));

        // Generate the string from the given Conditions:
        string res = s + "1" + inv;

        return res;
    }
public:
    char findKthBit(int n, int k) {

        string s = "0";

        for(int i = 1; i <= n; i++) {
            s = generateNext(s);
        }

        return s[k - 1];    // return the kth string, 1-based index.
    }
};