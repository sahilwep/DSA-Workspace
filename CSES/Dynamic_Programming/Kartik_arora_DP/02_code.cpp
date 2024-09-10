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


// Top-Down & Bottom-Up:




*/