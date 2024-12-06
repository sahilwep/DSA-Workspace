/*

//  2554. Maximum Number of Integers to Choose From a Range I


// Problem Statement:

    * You are given an integer array banned and two integers n and maxSum. You are choosing some number of integers following the below rules:
        * The chosen integers have to be in the range [1, n].
        * Each integer can be chosen at most once.
        * The chosen integers should not be in the array banned.
        * The sum of the chosen integers should not exceed maxSum.

    * Return the maximum number of integers you can choose following the mentioned rules.


// Example:

    Example 1:
        Input: banned = [1,6,5], n = 5, maxSum = 6
        Output: 2
        Explanation: You can choose the integers 2 and 4.
        2 and 4 are from the range [1, 5], both did not appear in banned, and their sum is 6, which did not exceed maxSum.

    Example 2:
        Input: banned = [1,2,3,4,5,6,7], n = 8, maxSum = 1
        Output: 0
        Explanation: You cannot choose any integer while following the mentioned conditions.

    Example 3:
        Input: banned = [11], n = 7, maxSum = 50
        Output: 7
        Explanation: You can choose the integers 1, 2, 3, 4, 5, 6, and 7.
        They are from the range [1, 7], all did not appear in banned, and their sum is 28, which did not exceed maxSum.



// Observation: 
    -> we are given an array banned [] -> this array contains elements that are banned, means we can't choose any element from this array.

    -> We are given an integer n:
        -> we can choose element from range 1 to n
    
    -> We are given an integer maxSum:
        -> The element that we are choosing, should not exceed this maxSum limit.
    

// Approach:

    // BruteForce Approach:
        -> start iteration from 1 to n
        -> Check whether that element is banned or not?
        -> if that element is not banned, include in list, & it should not exceed the limit of maxSum, & count included element & return that in answer.

        -> TC: O(n^2)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution_Brute{
private:
    // Function to check whether selected element is banned or not? TC: O(n)
    bool isNotBanned(vector<int> &banned, int val){
        for(auto i: banned) if(i == val) return 0;
        return 1;
    }
public:
    // Function to compute the maxCount: O(n^2)
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int totalSum = 0;
        int elementCnt = 0;
        
        for(int i=1;i<=n;i++){  // takes O(n)
            // check if value is exceeded maxSum or not?
            if(i <= maxSum){    // we can consider this element:
                if(isNotBanned(banned, i) == true){    // if that element is not banned -> O(n)
                    // check if including that element will exceed the maxSum limit or not, if not then include that element in total Sum & increment elementCount
                    if(totalSum + i <= maxSum){
                        totalSum += i;  // include that in total sum
                        elementCnt++;   // increment element counter
                    }
                }
            }
        }

        return elementCnt;
    }
};