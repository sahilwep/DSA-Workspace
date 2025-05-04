/*


//  Matrix chain multiplication Introduction Identification and General Format


// Question Variations:
    * We will solve all the question by using both the method -> (recursive & memoization)
        1. MCM
        2. Printing MCM
        3. Evaluate Expr to tree / boolean Parenthesization
        4. min/max value of an expression.
        5. Palindromic Partitioning
        6. Scramble String.
        7. Egg Dropping Problem.


// MCM Identification:

    * We are given an array or a string, and the task is to break it down.
    * We will consider indices i and j:

                ---|----------------------|--   -> array/string
                   i                      j     -> We will have to take i & j


    * The goal is to break this section into segments using an intermediate index kk:
    
                ---|---|---|---|---|---|---|---|--   
                   i   k   k   k   k   k   k   j
            
        * At each index, we will break the array/string into subproblems at different values of k, 
        * where k moves from i to j.

                   |----------]|[----------]   
                   i           k           j
            
        * Every time we break the string into kk, we face two subproblems:
            * One subproblem for the segment from i to k
            * Another subproblem for the segment from k+1 to j

                            (i to k) & (k+1 to j)
            
        * These two subproblems will be solved recursively:                        

                        [---------]    [---------]      -> solve both the problem recursively.
                        i         k    k+1       j


        * After solving both subproblems, we return the results to the parent call.
        * This process continues for every possible value of 'k' in the range 'i' to 'j'.
        * At each step, we store the results of these recursive solutions as temporary answers.
        * Once we have all temporary answers, we will apply a function to compute the overall result.
        * Using this function, we generate the final answer based on the temporary results obtained from each segment.

        * ConclusioN: 
            * In given array or string, we will select two index 'i' and 'j'
            * Usually i & j are at last index.
                            |--------------|
                  (left end)i              j(Right end)   
            * Then we will break it into multiples 'k
                            |---|---|----|----|
                  (left end)i   k   k    k    j(Right end)   
            
            * After breaking it into multiple, for every 'k' we will have two subproblem:
                [---]|[-----------]
                i   k k+1         j
            
            * We will Solve these problem recursively & we will be getting temporary answer from these two subproblem..
            * then will increase the value of k & similarly we will find answer for all the k..
            * all of these answers of every 'k' are temporary..
            * So, we will apply any function (let say max/mid or any) and from this all the temporary answer we will find the final answer & return it.


// MCM Format: 
    // Recursive Code: 
        * let say function name "Solve()"
        * This function will return in integer
        * Let say this function is taking array, & two indices 'i' & 'j'

                    int solve(int arr[], int i, int j){
                        // Base condition   

                        // Recursive Code:
                    
                    }

        * Now, let's look on the base condition: 
            * Base Condition: Think of the Smallest valid input OR Think of the invalid input. 
                        Invalid     valid
                       ... -2 -1 0 1 2 3 4...
                      |--------[-|-]----------|   
                                 |
                        Recursive Base condition

                    * We will be looking on invalid input:

                        |----------|
                        i          j

                    * Smallest valid input will be when (i == j) -> there will be one element -> which is making sense..

                            |-----|-----|
                                  ij


                    * We will taking when (i > j) -> which is not making sense -> because when i & j pointer move each other, means all the elements are exhausted.

                            |-----|-|----|
                                  j i


                    // base condition: 
                        if(i > j) return 0

                
        * Now we will have to break this on every 'k':
            * We will be breaking i & j at every index with k...
            * And then we will be computing the result..

                    // Breaking i - j into multiple k's

                        // during the defintion of for loop (initialization, condition, & increment/decrement) 
                            -> these all can differ upon the condition,
                            -> (k++ can be k+2)
                            -> (k<j can be k <= j) etc...
                        for(int k=i;k<j;k++){
                            // calculate answer: into temp answer
                            temp answer = solve(arr, i, k)
                                             +      // this can be anything depending upon the questions.
                                          solve(arr, k+1, j)

                            // Now from this temp answer, we will apply some function & find the final answer:

                            int ans = Func(){
                                // logic    -> this logic can be anything, maximum/minimum etc..
                                ... 
                            }

                        }   


            // Final Format:

                int solve(int arr[], int i, int j){
                    // base condition: 
                    if(i > j){
                        return 0;
                    }
                    // Recursive code: 
                    for(int k=i;k<j;k++){
                        int tempAns = solve(arr, i, k) + solve(arr, k+1, j);

                        ans = func(tempAns);    // function that will calculate the final answer from tempAnswer
                    }

                    return answer
                }

*/
