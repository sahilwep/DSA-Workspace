/*

//  Nth Fibonacci Number

//  Problem Statement: 
    - Given a non-negative integer n, your task is to find the nth Fibonacci number.
    - The Fibonacci sequence is a sequence where the next term is the sum of the previous two terms. The first two terms of the Fibonacci sequence are 0 followed by 1. The Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21
    - The Fibonacci sequence is defined as follows:

        F(0) = 0
        F(1) = 1
        F(n) = F(n - 1) + F(n - 2) for n > 1

// Examples :

    Input: n = 5
    Output: 5
    Explanation: The 5th Fibonacci number is 5.

    Input: n = 0
    Output: 0 
    Explanation: The 0th Fibonacci number is 0.

    Input: n = 1
    Output: 1
    Explanation: The 1st Fibonacci number is 1.


// Approach:
    - To find nth fibonacci number using recursion:

        n = 6

            6th fib number is: 8

                fib: 0 1 1 2 3 5 [8] 13 ...

                f(0) = 0
                f(1) = 1
                f(6) = 8

            Our code start from n = '6'
            it goes deeper & when it's hit base case it return the base case value to (n - 1)
            similarly it retruns the values for base case (n - 1), and at last for f(n), we will get the fib value.
            f(n) = f(n -1) + f(n - 2)
            these (n - 1) & (n - 2) are recursively found by reaching to their base case..

            Recursion calls:

                f(6)                                            return 8
                 |---f(5)                                       return 5
                 |    |---f(4)                                  return 3
                 |    |     |---f(3)                            return 2
                 |    |     |    |---->f(2)                     return 1
                 |    |     |    |      |---->f(1) = 1
                 |    |     |    |      |---->f(0) = 0
                 |    |     |    |
                 |    |     |    |---->f(1) = 1                 return 1
                 |    |     |
                 |    |     |---->f(2)                          return 1
                 |    |             |---->f(1) = 1
                 |    |             |---->f(0) = 0
                 |    |
                 |    |----f(3)                                 return 2
                 |          |----f(2)                           return 1
                 |          |      |----f(1) = 1
                 |          |      |----f(0) = 0
                 |          |      
                 |          |----f(1) = 1              
                 |
                 |
                 |---f(4)                                       return 3   
                       |---f(3)                                 return 2
                       |    |---->f(2)                          return 1
                       |    |      |---->f(1) = 1
                       |    |      |---->f(0) = 0
                       |    |
                       |    |---->f(1) = 1
                       |
                       |---->f(2)                               return 1
                               |---->f(1) = 1                           
                               |---->f(0) = 0
*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private:
    int solve(int n) { 
        if(n <= 1) return n;
        return solve(n - 1) + solve(n - 2);
    }
public:
    int nthFibonacci(int n) {
        return solve(n);
    }
};