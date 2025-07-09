/*

//  367. Valid Perfect Square | Binary Search on answer

//  Problem Statement: 
    -> Given a positive integer num, return true if num is a perfect square or false otherwise.
    -> A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.
    -> You must not use any built-in library function, such as sqrt.

 
// Example: 
    Example 1:
        Input: num = 16
        Output: true
        Explanation: We return true because 4 * 4 = 16 and 4 is an integer.

    Example 2:
        Input: num = 14
        Output: false
        Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.

 
// Observations: 
    -> We are given number, we need to find the perfect square root, if it exists.
    -> Try finding the range b/w (1--n)
    -> Implement Binary Search on answer
    -> If we found Perfect square root, return answer, else 

    // Complexity: 
        -> TC: O(logN)
        -> SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Binary Search:
class Solution {
private: 
    typedef long long ll;
public:
    bool isPerfectSquare(int num) {

        int low = 1;
        int high = num;

        while(low <= high) {
            ll mid = low + (high - low) / 2;    // get mid
            ll square = mid * mid;  // get square 

            if(square == num) return true;  // Perfect square

            // if square is lesser => move right
            else if(square < num) {
                low = mid + 1;
            } else {    // move left
                high = mid - 1;
            }
        }

        return false;   // not found
    }
};