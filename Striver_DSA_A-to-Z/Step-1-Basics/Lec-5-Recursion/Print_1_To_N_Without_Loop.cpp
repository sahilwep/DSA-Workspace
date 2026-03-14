/*

//  Print 1 To N Without Loop

//  Problem Statement: 
    - You are given an integer n. You have  to print all numbers from 1 to n.
    - Note: You must use recursion only, and print all numbers from 1 to n in a single line, separated by spaces.

// Examples:
    Input: n = 10
    Output: 1 2 3 4 5 6 7 8 9 10

    Input: n = 5
    Output: 1 2 3 4 5

    Input: n = 1
    Output: 1



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
  public:
    void printNos(int n) {
        if(n == 0) return;
        
        printNos(n - 1);
        cout << n << " ";
    }
};