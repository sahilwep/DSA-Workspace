/*
// Intro to Dynamic Programming: 

* Dynamic Programming in simple word is optimization over plain recursion.
    * Plain recursion: We are given an input of size n, we use the solution of sub problems.
        * Sub problems: if our input size is of n, a sub-problem is may be of size n-1, n-2, n-a, n-b, n/a, n/b, etc..
        * We recursively calls the same problem for sub-problem, we use their solution & i.e is how we compute our problem,
        *  this is what we do in plain recursion...
* Example: 
    * If we have plain recursion, & in plain recursion if we are solving sub-problems again & again, then we can optimize this recursion by,
    * Storing these solution, & when we needed that problem solution next time, we use that stored solution that's the main idea of dynamic programming..

// So, in simple word, it is an optimization over plain recursion.
// The idea of dynamic programming is to reuse the solution of sub-problems, when there are overlapping sub-problems.

// There are two ways to implement dynamic programming: 
    1. Memoization(Top down)
    2. Tabulation(Bottom up)

// Application of Dynamic Programming: 
    1. Bellman Ford Algorithm : used to find the shortest path from source to destination.
    2. Floyd Warhall algorithm : used to find the shortest path between every pair of vertices in a graph.
    3. Diff Utility (based on problem of DP called LCS = Longest common sub-sequence) : When we want to know the difference b/w two files, git version control system.
    4. Search Closed word (edit distance) : When we are finding some word in dictionary & we miss spelled the name, this it's helpful there.
    5. Resource Allocation(0-1 Knapsack problem) : help in optimal decision making during the acquiring something based on the cost..
    6  etc.....



*/

