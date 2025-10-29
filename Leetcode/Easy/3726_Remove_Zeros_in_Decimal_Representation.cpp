/*

//  3726. Remove Zeros in Decimal Representation


//  Problem Statement: 
    -> You are given a positive integer n.
    -> Return the integer obtained by removing all zeros from the decimal representation of n.

 
// Example: 
    Example 1:
        Input: n = 1020030
        Output: 123
        Explanation: After removing all zeros from 1020030, we get 123.

    Example 2:
        Input: n = 1
        Output: 1
        Explanation: 1 has no zero in its decimal representation. Therefore, the answer is 1.


// Observations:
    - from the given num remove 0's from the nums & return the left number...


    // Complexity:
        -> TC: O(logn)
        -> SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Approach 1: Integer Processing
class Solution {
public:
    long long removeZeros(long long n) {
        
        long long res = 0;
        while(n > 0) {
            int ld = n % 10;
            if(ld != 0) {
                res = (res * 10) + ld;
            }
            n /= 10;
        }

        long long ans = 0;
        while(res > 0) {
            int ld = res % 10;
            ans = (ans * 10) + ld;
            res /= 10;
        }

        return ans;
    }
};


// Approach 2: String conversion
class Solution {
public:
    long long removeZeros(long long n) {

        string s = to_string(n);
        string res = "";
        for(auto &ch: s) {
            if(ch != '0') res += ch;
        }
        
        long long ans = strtoll(res.c_str(), nullptr, 10);

        return ans;
    }
};