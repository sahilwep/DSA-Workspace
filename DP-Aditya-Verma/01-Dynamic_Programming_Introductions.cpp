/*

// Introduction to DP:
    * DP is enhanced recursion..
    * When we have overlapping on recursion, we use DP to remove overlapping of solving subproblem again and again.
    * Types: 
        * Top Down approach: Breaking larger subproblem into smaller subproblem until it is not able to solve individually... 
        * Bottom Up approach: Starting with smaller subproblem & building the logic for larger subproblem..

// Identification of DP: 
    * Choice are given(like we include something or not..) -> recursion -> when recursion has two function call(probability that there are same subproblem calls again) -> consider to use DP.
    * Optimal answer are asked like -> minimum, maximum, largest, lowest...


// How to implement DP:
    * First write recursive solution.
    * Memoize the recursive solution.
    * Then apply top-down approach.
    * When we write the recursive function, we can convert it into memoize or we can convert it into top-down.
        * But there should must be a recursive function written.


// DP Question Variations: 
    * There are some DP question, & they will form multiple variations from that question:
    * Parent Questions & their Variations(numbers): 
        1. 0-1 knapsack (6) 
        2. Un-bounded Knapsack (5)
        3. Fibonacci (7)
        4. LCS(Longest Common Subsequence) (15)
        5. LIS(Longest Increasing Subsequence) (10)
        6. Kadane's Algorithm (6)
        7. Matrix chain multiplications (7)
        8. DP on trees (4)
        9. DP on Grid (14)
        10. Others (5)

* NOTE: DP has patterns, On each patterns there are various question formed on with some variations on it.


*/