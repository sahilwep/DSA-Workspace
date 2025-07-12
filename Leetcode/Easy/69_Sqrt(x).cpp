/*

// 69. Sqrt(x)


//  Problem Statement: 
    -> Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
    -> You must not use any built-in exponent function or operator
        -> For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

 
// Example: 
    Example 1:
        Input: x = 4
        Output: 2
        Explanation: The square root of 4 is 2, so we return 2.

    Example 2:
        Input: x = 8
        Output: 2
        Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.



// Observations: 
    -> In These type of question, we are generally given the answer to the solution, & we need to find the range on which answer lies..
    -> If we observe this question carefully:
        // Square root: 
                    25 => 5 * 5
                    63 => 6 * 6

    -> We are given some square of number & we need to return the closest square root.
    -> We don't need to return the perfect square, yet we need to return the number which is closest to square root.


    // Approach: 
        -> We can start with 1 & go up till number & try finding the number..
        -> Example: 
            n = 26

            1 * 1 = 1   <---- True   =>  Starting Range
            2 * 2 = 4   <---- True
            3 * 3 = 9   <---- True
            4 * 4 = 16  <---- True
            5 * 5 = 25  <---- ans, Largest possible
            6 * 6 = 36  <---- False
            7 * 7 = 49  <---- False
            8 * 8 = 64  <---- False
            ...
            ...
            26 * 26 = 676 <---- False   =>  Ending range

        -> We can Observe that we have starting & ending range
        -> and answer lies somewhere in b/w
        -> From this Example, we can observe Using Binary Search we can efficiently found the Correct range & return our answer.


// Complexity: 
    -> TC: O(logN)
    -> SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Approach 1: mid * mid -> overflow occur if we don't use long long
class Solution {
private: 
    typedef long long ll;
public:
    int mySqrt(int x) {
        
        int low = 1, high = x;
        int ans = 0;

        while(low <= high) {
            ll mid = low + (high - low) / 2;

            if(mid * mid <= (ll)x) {
                ans = (int)mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};


// Approach 2: using (x / mid) to round within range
class Solution {
public:
    int mySqrt(int x) {

        int low = 1;
        int high = x;
        int ans  = 0;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(mid <= x/mid) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};