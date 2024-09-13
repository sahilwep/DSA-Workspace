/*

// Dynamic Programming: 


// DP State: 
    * 
    * We are using some parameter to represent some problem.
    * Example:
        * Let say we are using two parameter to characterizing some problem, with this two parameter we can also characterizing all the subproblem.
        * General idea is that, a problem P should be represented by some parameters P : (p1, p2, p3,...pk)
        * Example: P(1, N)
                                 P(1, N)
                                    |
                    (1, N/2)---------------------(N/2+1, N)
                       |
            (1, N/4)--------(N/4+1, N/2)        .....
            ....
        
        * These parameter are completely define what the problem is.
        * Different values for those parameter define will define different subproblems.


// Recurrence:
    * There is a relations that relates a particular dp state to some other dp state and that relation is known is recurrence.

// Top-Down & Bottom-Up:
    * Top Down: 
        * In top down we are breaking the big problem into smaller sub-problem, & we will keep breaking it until we found a smaller problem that we can solve it directly.
        * Write a recursive codes, that all the parameter defining sub problem & also keep memoizing the result those we get, we keep storing the result in an array, so that we are not solving same subproblem again.
        * We start with final solution, & recursively break it into smaller subproblem, To avoid redundant calculations we store the result of solved subproblem into the memoization table.
    
    * Bottom Up: 
        * First we are solving easier problem, & use their solutions to go upwards.
        * First we will solve the most easiest problem & then use these result to solve hardest problem, & use their result to solve even hardest problem, until we solve the whole problem.
        * Also known as tabulations, we start with smallest subproblem & gradually build up the final solution. we store the result into a table to avoid redundant calculations.


*/