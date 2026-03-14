/*

//  Factorial

//  Problem Statement: 
    - Given a positive integer, n. Find the factorial of n.

// Examples :
    Input: n = 5
    Output: 120
    Explanation: 1 x 2 x 3 x 4 x 5 = 120

    Input: n = 4
    Output: 24
    Explanation: 1 x 2 x 3 x 4 = 24


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
  public:
    int factorial(int n) {
        if(n == 1) return 1;
        return n * factorial(n - 1);
    }
};