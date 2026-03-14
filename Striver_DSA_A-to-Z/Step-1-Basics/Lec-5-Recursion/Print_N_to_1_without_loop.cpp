/*

//  Print N to 1 without loop


//  Problem Statement: 
    - Print numbers from N to 1 (space separated) without the help of loops.

// Example 1:
    Input:
    N = 10
    Output: 10 9 8 7 6 5 4 3 2 1

    Your Task:
    This is a function problem. You only need to complete the function printNos() that takes N as parameter and prints number from N to 1 recursively. Don't print newline, it will be added by the driver code.

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
  public:
    void printNos(int N) {
        if(N == 0) return;
        cout << N << " ";
        printNos(N - 1);
    }
};