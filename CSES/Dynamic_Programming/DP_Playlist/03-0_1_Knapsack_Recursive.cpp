/*

//  3 01 Knapsack Recursive 


// Identification of Knapsack: 
    * Choice is given, Then
    * Use DP -> First apply Recursion -> Then apply Topdown


// Example:
    Input: 
        wt[]  = {1, 3, 4, 5}
        val[] = {1, 4, 5, 7}
        W = 7
    O/p: Find the maximum profit.


// How to write the code:
    * Write recursive code for given problem.
    * Before writing the recursive code for the given problem, write the choice diagram.
    
    // Choice Diagram:
        * Let's say we have item 1 & we have to put this into bag, what are the choices that we have for item 1.
        * Let, Bag capacity = W = 10 kg
        * Let, item weight =  w1

                                    [w1]
                                      |
                [w1 <= W]-------------------------[w1 > W] 
                    |                                 |
       [Include]---------[reject]                  [reject]

       * If item weight is less or equal to the Bag Capacity, either we can put this into bag or not it's our choice.
       * If item weight is strictly grater than the Bag Capacity, we cannot place item into bag.

    
    // Writing the knapsack function
        * return type is integer
        * we are given two array, size of array, & capacity of bag.
        * Function: 

            int knapsack(int val[], int weight, int n, int W){
            
            } 



*/