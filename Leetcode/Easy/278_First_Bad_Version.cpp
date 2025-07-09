/*

//  278. First Bad Version  | Binary Search on answer


//  Problem Statement: 
    -> You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.
    -> Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
    -> You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.


// Example: 
    Example 1:
        Input: n = 5, bad = 4
        Output: 4
        Explanation:
        call isBadVersion(3) -> false
        call isBadVersion(5) -> true
        call isBadVersion(4) -> true
        Then 4 is the first bad version.

    Example 2:
        Input: n = 1, bad = 1
        Output: 1


// Observations: 
    -> We are given "isBadVersion(x)" function, which return T/F
    -> We have to return the first number in range [1..n] which return F

    // Binary Search On Answer:
        -> We are Given range [1..n]
        -> Implement Binary Search & try finding the minimum value on which we have 'F'

    // Complexity: 
        -> TC: O(logN)
        -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Binary Search solution:
class Solution {
public:
    int firstBadVersion(int n) {

        int low = 1;
        int high = n;
        int ans = n;

        while(low <= high) {
            int mid = low + (high - low) / 2;   // make sure to not use bracket for protecting it from overflow...

            if(isBadVersion(mid)) { // move left side to get smallest false value
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};