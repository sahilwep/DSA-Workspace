/*

//  326. Power of Three


//  Problem Statement: 
    -> Given an integer n, return true if it is a power of three. Otherwise, return false.
    -> An integer n is a power of three, if there exists an integer x such that n == 3x.

 
// Example:
    Example 1:
        Input: n = 27
        Output: true
        Explanation: 27 = 33

    Example 2:
        Input: n = 0
        Output: false
        Explanation: There is no x where 3x = 0.

    Example 3:
        Input: n = -1
        Output: false
        Explanation: There is no x where 3x = (-1).

        
// Observations: 
    -> We are given a num, & we need to find the number x for which 3^x = n


// BruteForce: 
    -> Use linear iterations to find the value of x, for which (3^x == n)
    -> Last range for which 3^x fits in integer is 3^19 = 1162261467

    // Complexity: 
        -> TC: O(n)
        -> SC: O(1)


// Better Solution:
    -> We can use Binary Search to find the value x.
    -> Last range for which 3^x fits in integer is 3^19 = 1162261467

    // Complexity: 
        -> TC: O(logn)
        -> SC: O(1)


// Efficient Solution:
    -> Last range for which 3^x fits in integer is 3^19 = 1162261467
    -> We know that the last value for which 3^x, & if we divide n with that number, that number is completely divisible.
    -> In simple: (3^19 % n == 0)

    // Complexity: 
        -> TC: O(1)
        -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient Solution: Linear time by dividing the largest number
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && ((int)pow(3, 19) % n) == 0;
    }
};


// Better Solution: Binary Search Solution
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;

        int low = 1;
        int high = 19;  // take high = 19, because INT will fit in

        while(low <= high) {
            int mid = (low + high) / 2;

            int val = pow(3, mid);  // get the power value

            if(val == n) {
                return true;
            } else if(val < n) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return false;
    }
};

// BruteForce: TLE
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;

        int lastRange = pow(3, 19); // last value of 3^x for which integer fits in.
        for(int i = 1; i < lastRange; i++) {
            if(pow(3, i) == n) return true;
        }

        return false;
    }
};