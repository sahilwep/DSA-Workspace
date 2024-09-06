/*

// Introduction To dynamic Programming: 


// Mindset Building: 
    * Break a problem into smaller subproblems. -> divide & conquer approach
    * How to get answer for bigger problem from smaller subproblem. -> how do we get the solution from smaller subproblem & develop a relations b/w them to find the solution for the bigger subproblem.
    * What is the smallest subproblem which is trivial to solve -> smallest subproblem which we don't need to break further, this is known as the base case.
    * What is the biggest subproblem. -> at last we need the answer for the bigger subproblem.




// What is Dynamic Programming: 
    * If we are dividing some problems into some smaller subproblems are there some repetition that are happening.
    * Can be we cleaver enough & not try to solve the same subproblem again & again.
    * Idea is to remove the same subproblem again and again.
    * Example:

                        [problem] 
                           |
                ------------------------
                |          |           |
               [p1]       [p2]        [p3]          subproblem Divides into p1, p2 & p3
              ------     ------      ------ 
              |    |     |    |      |    |
             [a1] [a2]  [a1] [a3]   [a2] [a4]       subproblem divides into multiple branch..
              |     |    |     |     |    |
             ...   ...  ...   ...   ...  ...        subproblem divides into multiple branch, and compute further..

            
        * Here some subproblem compute again & again, when we further divide our subproblems.
        * (a1 & a2), these are 



*/