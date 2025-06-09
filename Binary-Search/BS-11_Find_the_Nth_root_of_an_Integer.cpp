/*

//  BS-11. Find the Nth root of an Integer

//  Problem Statement: 
    -> You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then returns -1.


// Examples:

    Input: n = 2, m = 9
    Output: 3
    Explanation: 32 = 9

    Input: n = 3, m = 9
    Output: -1
    Explanation: 3rd root of 9 is not integer.

    Input: n = 1, m = 14
    Output: 14


// Observations: 
    -> We are give integer n & m
    -> We have to find the nth root of m:
    -> Example: 
        n = 3, m = 27
            3Sqrt(27) => 9

            1 * 1 * 1 = 1   -> false
            2 * 2 * 2 = 8   -> false
            3 * 3 * 3 = 9   -> true
            
            Ans = 3
        
        n = 4, m = 69

            1 * 1 * 1 * 1 = 1   False
            2 * 2 * 2 * 2 = 16  False
            3 * 3 * 3 * 3 = 81  Exceed & false

            ans = -1

    -> We can observe that we are given answer
    -> we need to find whether the answer lie on range 1 to m
        => 1 because if we start with 0 it's multiplies to 0
        => m because if in worse case if n = 1, & m = anything, we landed up-till m
    -> We can write simple binary seach to find valid range.
    
// Complexity: 
    -> TC: O(logN * logM)
    -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// TC: O(logN * logM) => Handling Overflow case:
class Solution {
public:
    // Helper function to calculate a^b with early stopping if it exceeds m
    long long power(int a, int b, int m) { // Binary Exponentiation
        long long result = 1;
        long long base = a;

        while (b > 0) {
            if (b % 2 == 1) {
                result *= base;
                if (result > m) return result;  // early overflow check
            }
            base *= base;
            if (base > m) return base;  // early overflow check
            b /= 2;
        }

        return result;
    }

    int nthRoot(int n, int m) {
        int low = 1;
        int high = m;

        while (low <= high) {
            int mid = (low + high) / 2;
            long long midPower = power(mid, n, m);

            if (midPower == m) return mid;
            else if (midPower < m)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }
};


// Naive Impl:
class Solution {
  public:
    int nthRoot(int n, int m) {
        int low = 1;
        int high = m;
        
        while(low <= high) {    // logM
            int mid = (low + high) / 2;
            
            int num = pow(mid, n);  // logN
            
            if(m == num) return mid;
            
            if(num < m) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return -1;
    }
};

