/*

//  G-44. Minimum Spanning Tree - Theory

            2       3
        [0]-----[1]-----[2]
         |     / |      /
         |  8 /  |     /7
       6 |   /  5|    /
         |  /    |  /
         [3]     [4]

// MST: 
    -> We will be given undirected weighted graph, edge will have different or equal weight.
    -> This Graph contains n nodes & m edges.
    -> MST: A tree in which we have n nodes & n - 1 edges and all nodes are reachable from each other.

                [0]
                / \
               /   \
              /     \
              [1]     [2]
                      / \               N nodes 
                     /   \              N-1 Edges
                    /     \             Everyone is connected to each other.
                 [3]      [4]


                -> Or we can say every nodes are in a single componenets.

    
    -> For this Graph:
        
            2       3
        [0]-----[1]-----[2]
         |     / |      /
         |  8 /  |     /7
       6 |   /  5|    /
         |  /    |  /
         [3]     [4]


        -> We can try drawing out all the MST's & their edges weight sum is lesser will be our MST

            // 1st Spanning Tree:
            

                    2       3
                [0]-----[1]-----[2]
                 |       |      
                 |       |
               6 |      5|
                 |       |
                 [3]     [4]

                        -> For this tree: "n" nodes & (n - 1) edges
                        -> Sum of all the edges: 16

            // 2nd Spanning Tree:

                    2       3
                [0]-----[1]-----[2]
                        /        /
                     8 /        /7
                      /        /
                     /        /
                    [3]     [4]


                        -> For this tree: "n" nodes & (n - 1) edges
                        -> Sum of all the edges: 20

        -> So, the 2nd graph is the Minimum Spanning Tree (MST) which has the least sum.
        -> In, simple the graph which has the least sum among all the spanning tree is known as Minimum Spanning tree (MST).

// How do we find the MST:
    -> For find the MST we will use:
        -> prim's algorithm
        -> kruskal's algorithm
            -> Disjoint set is the data-structure which is needed to find..
            

*/
