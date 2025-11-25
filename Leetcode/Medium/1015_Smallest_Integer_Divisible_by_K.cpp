/*

//  1015. Smallest Integer Divisible by K


//  Problem Statement: 
    - Given a positive integer k, you need to find the length of the smallest positive integer n such that n is divisible by k, and n only contains the digit 1.
    - Return the length of n. If there is no such n, return -1.
    - Note: n may not fit in a 64-bit signed integer.

 
// Example: 
    Example 1:
        Input: k = 1
        Output: 1
        Explanation: The smallest answer is n = 1, which has length 1.

    Example 2:
        Input: k = 2
        Output: -1
        Explanation: There is no such positive integer n divisible by 2.

    Example 3:
        Input: k = 3
        Output: 3
        Explanation: The smallest answer is n = 111, which has length 3.

        
// Observations:
    - we are given positive integer 'k'
    - we need to find the length of smallest positive integer 'n', such that n is divisible by k,
    - and n only contains the digit '1'
    - return the length of 'n', if there is no such 'n', return -1

    // Approach:
        - start with n = '1' & keep increasing it by:
            use: {n * 10 + 1}
            1 * 10 + 1 = 11
            11 * 10 + 1 = 111
            111 * 10 + 1 = 1111
            1111 * 10 + 1 = 11111
            ...

        - let say k = 7:
            num = 1            =  1 % 7      = 1
            1 * 10 + 1         =  11 % 7     = 4
            11 * 10 + 1        =  111 % 7    = 6
            111 * 10 + 1       =  1111 % 7   = 5
            1111 * 10 + 1      =  11111 % 7  = 2
            ...


            num = 1                  = 1 % 7      = 1
            (1 * 10 + 1)             = 11 % 7     = 4
            (4 * 10 + 1)             = 41 % 7     = 6
            (6 * 10 + 1)             = 61 % 7     = 5
            (5 * 10 + 1)             = 51 % 7     = 2
            ...

            n = (n * 10 + 1) => n = n % k   => WE GOT NEW 'n'
            in simple: 
                n = (n * 10 + 1) % k

        - Instead of multiplying 1, 11, 111, 1111,..., if we simply multiply {(n * 10 + 1) % k}, and it will be in range..
        - we can maintain one counter cnt start from '1'
        - As we are rounding our n with given 'k', so we only need to iterate till 'k'

    // Complexity: 
        - TC: O(k)
        - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        
        int n = 1 % k;  // take starting number '1' mod with 'k'
        int len = 1;
        while(len <= k) {   // because we are rounding whatever we got with 'k', so length will alwasy we (<= k)
            if(n == 0) return len;  // if (n == 0), means it's already divisible in previous calls, so return len.

            n = (n * 10 + 1) % k;

            len++;
        }

        return -1;  // no valid answer found
    }
};