/*

//  2843. Count Symmetric Integers


//  Problem Statement: 
    -> You are given two positive integers low and high.
    -> An integer x consisting of 2 * n digits is symmetric if the sum of the first n digits of x is equal to the sum of the last n digits of x. 
    -> Numbers with an odd number of digits are never symmetric.
    -> Return the number of symmetric integers in the range [low, high].

// Example: 

    Example 1:

        Input: low = 1, high = 100
        Output: 9
        Explanation: There are 9 symmetric integers between 1 and 100: 11, 22, 33, 44, 55, 66, 77, 88, and 99.

    Example 2:

        Input: low = 1200, high = 1230
        Output: 4
        Explanation: There are 4 symmetric integers between 1200 and 1230: 1203, 1212, 1221, and 1230.

// Observations: 
    -> For odd sized number skip
    -> For even sided number check the first half sum & last half sum
    -> include that number only the sum were same..

// Complexity: 
    -> TC: O(high - low)
    -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Clean Implementations;
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i = low; i <= high; i++) {
            string num = to_string(i);
            int n = num.size();
            if(n % 2 != 0) continue;
            // check first & last half sums:
            int j = 0;
            int lHalfSum = 0;
            int rHalfSum = 0;
            while(j < n/2) {
                lHalfSum += int(num[j] - '0');
                rHalfSum += int(num[n - j - 1] - '0');
                j++;
            }

            if(lHalfSum == rHalfSum) cnt++;
        }

        return cnt;
    }
};

// Naive implementations:
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i = low; i <= high; i++) {
            string num = to_string(i);
            int n = num.size();
            if(n % 2 != 0) continue;    // odd size number are not symmetric
            else {
                // Split half  & second half & check the sums:
                // first half sum:
                int temp = i;
                int fHalfSum = 0;
                for(int k = 0; k < n/2; k++) {
                    int ld = temp % 10;
                    fHalfSum += ld;
                    temp /= 10;
                }

                // Last half sum:
                int sHalfSum = 0;
                for(int k = 0; k < n/2; k++) {
                    int ld = temp % 10;
                    sHalfSum += ld;
                    temp /= 10;
                }

                if(fHalfSum == sHalfSum) cnt++; // check sums
            }
        }

        return cnt;
    }
};