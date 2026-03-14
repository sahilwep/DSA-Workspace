/*

//  Sum of Natural Numbers


//  Problem Statement: 
    Given an integer n. Your task is to calculate the sum of all natural numbers from 1 up to n (inclusive). If n is 0, the sum should be 0.

// Examples:
    Input: n = 3
    Output: 6
    Explanation: The numbers from 1 to 3 are 1, 2, and 3. Their sum is 1 + 2 + 3 = 6.

    Input: n = 5
    Output: 15
    Explanation: The numbers from 1 to 5 are 1, 2, 3, 4, and 5. Their sum is 1 + 2 + 3 + 4 + 5 = 15.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findSum(int n) {
        if(n == 0) return 0;
        return n + findSum (n - 1);
    }
};
