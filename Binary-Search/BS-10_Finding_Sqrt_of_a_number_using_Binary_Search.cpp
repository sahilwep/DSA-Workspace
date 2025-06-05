/*

// BS-10. Finding Sqrt of a number using Binary Search  => (Pattern: Binary Search on answer)


//  Problem Link: https://www.geeksforgeeks.org/problems/square-root/1


//  Problem Statement: 
    -> Given a positive integer n, find the square root of n. If n is not a perfect square, then return the floor value.
        -> Floor value of any number is the greatest Integer which is less than or equal to that number

// Examples:

    Input: n = 4
    Output: 2
    Explanation: Since, 4 is a perfect square, so its square root is 2.

    Input: n = 11
    Output: 3
    Explanation: Since, 11 is not a perfect square, floor of square root of 11 is 3.

    Input: n = 1
    Output: 1


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


class Solution {
public:
    int floorSqrt(int n) {
        
        int low = 1, high = n;
        int ans = 1;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            
            if(mid * mid <= n) {    // smaller or equal
                low = mid + 1;
                ans = mid;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};