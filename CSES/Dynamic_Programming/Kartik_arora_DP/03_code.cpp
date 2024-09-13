/*

// Dynamic Programming: Elements of DP



// DAG: Directed Acyclic Graph:
    * Graph:
        * Nodes: Dp state
        * Edges: Represent Dependency among the states.
            dp(u) = {dp(v)}  -> there should be no cycle in graph.
            * IF there is a cycle in graph: this means  
                        dp(u)------>dp(v)
                          |<----------|
                    * To know the answer for v, we need to know u and
                    * To know the answer of u, we need to know v.
                    * This stuck in a deadlock
                    * If There is a cycle in our graph then we cannot evaluate the answer.
        * It hash to be Directed Acyclic Graph, then only we can evaluate the answer for every node.

// Visualize:
    * Top down creates the graph, when it's needed some nodes.
    * Example: fibonacci f(7)
             
                f(7)
                |
            f(6)----->f(5)
             |          |
            f(4)<-------|
             |          |
             --------->f(3)
             |          |
            f(2)<-------|
             |          |
             |-------->f(1)



// Space & Time Complexity:
    * For one node that we have to evaluate let's assume TC: O(1)
    * To evaluate DP of s(n) we need [V1 + V2 + V3 +....+ Vn]
    * O(1) * Vn -> which is near to edges in DAG
    * E(v) = Summation of vi/n  -> x = ∑vi/n
    * TC: O(Nx)
    * SC: O(N)
    * Instead of finding tight upper_bound we will find the loose bound, & think of that node that will be most costly to evaluate.


*/