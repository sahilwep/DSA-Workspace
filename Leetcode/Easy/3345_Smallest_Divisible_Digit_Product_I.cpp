/*

//  3345. Smallest Divisible Digit Product I


//  Problem Statement: 
    - You are given two integers n and t. Return the smallest number greater than or equal to n such that the product of its digits is divisible by t.
 

// Example:
    Example 1:
        Input: n = 10, t = 2
        Output: 10
        Explanation: The digit product of 10 is 0, which is divisible by 2, making it the smallest number greater than or equal to 10 that satisfies the condition.

    Example 2:
        Input: n = 15, t = 3
        Output: 16
        Explanation: The digit product of 16 is 6, which is divisible by 3, making it the smallest number greater than or equal to 15 that satisfies the condition.

// Observations:
    - we are given integer n & t
    - we need to find the number 'x' >= n, and product of all the digits of 'x' should be divisible by 'k'
    - we need to return the smallest possible number..

    // Approach:
        - We will start from the number 'n', and keep increasing until we not found a number that satisfied our conditions.
            - at every number we will check their digit product is divisible by 't', and if it's divisible then returning that number.


    // Complexity:
        - TC: O(A * logx)
        - sc: O(1)
            - A = (answer - n), this is the exact number which we are incrementing from n until we not found our intended number...

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    int getDigitProduct(int x) {    // O(logx)
        int ans = 1;

        while(x > 0) {  
            ans *= x % 10;  // get the last digit, and multiply into ans
            x /= 10;        // everytime remove last digit
        }

        return ans;
    }
public:
    int smallestNumber(int n, int t) {
        
        int k = n;
        while(getDigitProduct(k) % t != 0) { // O(A * logx)
            k++;
        }

        return k;
    }
};
