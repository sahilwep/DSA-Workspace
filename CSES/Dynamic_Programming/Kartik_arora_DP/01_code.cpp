/*

// Introduction to DP:


// DnC: Divide & Conquer
    * Break : break the problems into subproblems
    * Merge : Once the smaller part of problems are solved, merge them & generate the solution for parent subproblem.
    * Base : base case or simple instance of problem which can be solved directly without further division.

// Dynamic Programming: 
    * Idea is to store the solution of subproblems, in order to prevent resolving the same subproblem again & again.
    * The idea is to avoid solving same subproblem again.
    * In Conclusion: 
        * Store result for subproblem.
        * Reuse the result when needed.
        * Never solve subproblem again.


// Example Of Dynamic Programming:
    * Fibonacci Number Problem:

                F(n) = f(n-1) + f(n-2),     f(1) = 1, f(0) = 0

        * Normal Recursive Approach: 


                                                      fib(5)
                                                        |
                                 fib(4)--------------------------------------fib(3)
                                    |                                           |
                            fib(3)-------------fib(2)               fib(2)------------fib(1)
                            |                   |                     |
                    fib(2)-----fib(1)    fib(1)----fib(0)       fib(1)----fib(0)
                        |
                fib(1)----fib(0)

                * The total number of calls made by fib(n) is the sum of calls made all level of recursion tree.
                * The sum grows exponentially with n, leading a time complexity of O(2^n), as you can see many subproblems like(fib(3), fib(2)) are being solved multiple times, the redundancy contribute to the exponential growth in the numbers of calls, hence the O(2^n) time complexity.
                * TC: O(2^n)


        * After using the DP approach, and  Maintaining memo array:

                                                fib(5)
                                                 |
                                   fib(4)-------------------fib(3)
                                      |
                            fib(3)--------fib(2)
                              |
                      fib(2)-----fib(1)
                        |
                fib(1)----fib(0)

                * TC: O(n)

        * By using DP approach, memoization each fib number from (0-n) calls exactly once.
        * and when they need to solve same subproblems again, the answer is fetched form the memo array.
        * This leads to time Complexity O(n)

// Types Of DP Problems:
    * Optimization problems: 
        * We are given a function f(), we have to either maximize the value of f or minimize the value of f.
    * Counting Problems or combinatorics problems:
        * We are given some problem, we will have to find the numbers of ways to do that problems.


*/