/*

//  374. Guess Number Higher or Lower



//  Problem Statement:
    * We are playing the Guess Game. The game is as follows:
    * I pick a number from 1 to n. You have to guess which number I picked.
    * Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.
    * You call a pre-defined API int guess(int num), which returns three possible results:
        * -1: Your guess is higher than the number I picked (i.e. num > pick).
        * 1: Your guess is lower than the number I picked (i.e. num < pick).
        * 0: your guess is equal to the number I picked (i.e. num == pick).
    * Return the number that I picked.

 
// Example:

    Example 1:
        Input: n = 10, pick = 6
        Output: 6

    Example 2:
        Input: n = 1, pick = 1
        Output: 1

    Example 3:
        Input: n = 2, pick = 1
        Output: 1

// Approach:
    -> We need to guess weather the number is grater lower or equal or not?
        -> While using binary search, we compare mid value with whether we are close to that or not?
        -> Here, we will compare mid value with given function guess(num)
        -> In binary search condition where we use to compare value with mid, we will pass mid in guess() function..

// Complexity:
    * TC: O(logn)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {

        // Binary Search Logic:
        int start = 1;
        int end = n;

        while(start <= end){
            int mid = start + (end - start) / 2;

            // Passing mid value in guess() -> if it's return -1, means (nums > pick) value
            if(guess(mid) == -1){
                end = mid;
            }
            // if passed value is equal to 1, -> if return value is 1, means (num < pick) value
            else if(guess(mid) == 1){
                start = mid + 1;
            }
            // else guess(mid) == 0, means pick value is equal to num
            else{
                return mid; // in that case return mid value, i.e guessed value.
            }
        }

        return 0;
    }
};