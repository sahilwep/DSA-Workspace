/*

//  G-42. Floyd Warshall Algorithm

//  Problem Statement: 
    -> The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. 
    -> The graph is represented as an adjacency matrix. mat[i][j] denotes the weight of the edge from i to j. 
    -> If mat[i][j] = -1, it means there is no edge from i to j.
    -> Note: Modify the distances for every pair in place.


// Examples:

    Input: mat = [[0, 25], 
                  [-1, 0]]
    Output: [[0, 25], 
             [-1, 0]]

    Explanation: The shortest distance between every pair is already given(if it exists).


    Input: mat = [[0, 1, 43],
                  [1, 0, 6], 
                  [-1, -1, 0]]

    Output: [[0, 1, 7], 
             [1, 0, 6], 
             [-1, -1, 0]]

    Explanation: We can reach 2 from 0 as 0->1->2 and the cost will be 1+6=7 which is less than 43.

    
// Question Observations: 
    -> We are given matrix of size nxn, which contains the cost of reaching node u ---> v
    -> '-1' denotes unreachable path cost.
    -> every matrix[i][i] = 0, that is the cost of every nodes to reach itself



// Floyd Warshall Algorithm:
    -> Multisource shortest path algorithm.
    -> Helps to detect negative cycle.

    // Thought Process:
        -> Go via every vertices/nodes & get the shortest one.

    // Approach
        // Initial Configurations: 
            -> We are given directed, graph.
            -> We will be using adjacency matrix to store the node details.
            -> If we are given undirected graph, just split that edges into two directed edges opposite to each other nodes.

                // Graph Conversion to matrix for Floyd Warshall:
                    -> For given n nodes, initialize matrix of size (n x n)
                    -> Now, fill (mat[i][i] = 0) for all the n nodes, because the cost of same node reaching to same node itself will be '0'.
                    -> Now get the value from the directed graph nodes u ------> v & their weight & assign into (matrix[u][v] = weight)..
                    -> Rest values will be assigned as infinity value, because it's not reachable, because we are given directed graph.

                    // NOTE: if we are given undirected graph, then convert that into two directed edge directing to opposite of each other & assign the values in matrix as same (matrix[u][v] = wt, mat[v][u] = wt)..


        // Rest logic:
            -> Initially, fill the value with '0' for every same node to same node (matrix[i][i]) & rest value as infinity.
            -> matrix will look something like this:
            -> let's assume we have 4 nodes in directed graph, i = infinity value.

                                 1
                            <----------
                        [0]  ---------> [1]
                         ↑     2     ↗   |
                       3 |         /     | 3
                         |      / 5      |
                         |   /           ↓
                        [3] ----------> [2]
                                4


                            0  1  2  3
                        0   0  i  i  i
                        1   i  0  i  i
                        2   i  i  0  i
                        3   i  i  i  0

            -> For filling the matrix, "go via every nodes"
                
                        i --> j =>  mat[i][j] =  mat[i][via] + mat[via][j]
                                                 edge_weight + edge_weight
                
                
            -> Go via every nodes & fill the minimum values along the path..
            -> Apparently, we will have minimum cost in our matrix.
                -> Example:
                        for mat[0][1]       ->      (0 ----> 1)
                                
                                        via k    (0 -> k)     +      (k -> 1)    Generalize Format

                                        via 2    (0 -> 2)     +      (2 -> 1)
                                                    2                   3       = 5
                                        via 3    (0 -> 3)     +      (3 -> 1)
                                                    4                   1       = 5
                                        via 4    (0 -> 4)     +      (4 -> 1)
                                                    3                   1       = 4         
                                                                            --------------  
                                                                                  4    <---    min along the all path
                                
            -> We are exploring all the vertices & for every path u to v, and we are storing minimum among them.
            -> These are the follow ups from how the Algorithm logic, But for now let's fill the matrix first, from the given graph:

                        Graph:
                                        1
                                   <----------
                               [0]  --------> [1]
                                ↑     2      ↗  |
                              3 |         /     | 3
                                |      / 5      |
                                |   /           ↓
                               [3] ----------> [2]
                                        4

                        Matrix:

                                    0  1  2  3
                                0   0  2  i  i
                                1   1  0  3  i
                                2   i  i  0  i
                                3   3  5  4  0

            // via '0'
                -> Now, we will start filling value with crosspending to the previous filled values...
                -> Via '0' means 
                    i ---> j => mat[i][j] =  mat[i][0] + mat[0][j]

                -> Let's fill the matrix:

                        Matrix:

                                    0  1  2  3
                                0   0  2  i  i
                                1   1  0  3  i
                                2   i  i  0  i
                                3   3  5  4  0

                            mat[0][0] = 0, filled initially
                            
                            mat[0][1] =>    mat[0][0] + mat[0][1]
                                                0           2       => 2
                            
                            mat[0][2] =>    mat[0][0] + mat[0][2]
                                                0     +    i        => i
                            
                            mat[0][3] =>    mat[0][0] + mat[0][3]
                                                0     +     i       => i
                            
                            mat[1][0] =>    mat[1][0] + mat[0][0]
                                                1     +     0       => 1
                                    
                            mat[1][1] =>    mat[1][0] + mat[0][1]
                                                1     +     2       => 3, but already '0' filled there that is minimum value, so we won't change it..
                            
                            mat[1][2] =>    mat[1][0] + mat[0][2]
                                                1     +     i       => i
                            
                            and so on...
                            till n x n via path '0'

                            At the end, Via '0' our matrix will look something like this:


                                    0  1  2  3
                                0   0  2  i  i
                                1   1  0  3  i
                                2   i  i  0  i
                                3   3  5  4  0
            
            // via '1'
                -> Now, we will again start filling that matrix via path '1'
                -> NOTE: for every Via k Row & col will be same here always.

                            mat[0][1] =>    mat[0][1] + mat[1][1]
                                                2     +     0       => 2
                            
                            mat[0][2] =>    mat[0][1] + mat[1][2]
                                                2     +     3       => 5
                                    
                            mat[0][3] =>    mat[0][1] + mat[1][3]
                                                2     +     i       => i
                            
                            and so on...
                            till n x n via path '1'
                            
                            At the end, Via '1' our matrix will look something like this:
                                

                                    0  1  2  3
                                0   0  2  5  i
                                1   1  0  3  i
                                2   i  i  0  i
                                3   3  5  4  0


            // via '2'
            ...
            ...
            ...
            // via 'n-1'

                -> At the end, we will get the final matrix at the end, which contains all the path from every node to every node..



// Cycle Detection in Floyd Warshall:
    -> If there is a negative cycle in any node, the value will be in negative..
    -> And for cycle we will come back to the original node where we have started..
    -> And according to the given configurations of Floyd Warshall => mat[i][i] = 0, because cost of original node original node itself is always '0'.
    -> So, we can check in matrix after floyd warshall implemented, with a iterations that if (mat[i][i] < 0) -> Cycle Detected..



// Complexity:

    -> TC: O(n^3)
    
    -> SC: O(1) -> this is wrong.
        -> O(n ^ 2), because when we are saying space complexity, it's the space that generally we are using to solve the problem..
        -> Here we are using O(n^2) space matrix...
    
NOTE: 
    -> If the graph does not have negative cycles, then use dijkstra's for all the nodes.
    -> because dijkstra's takes O(E * log(V)), and for all the n nodes: O(n * (E * log(V)))


*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void shortestDistance(vector<vector<int>>& mat) {
        int n = mat.size();
        
        // For not-reachable nodes, converting -1 to 1e9 so that we can compute it carefully in algorithm:
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == -1) mat[i][j] = 1e9;
            }
        }
        
        // Floyd Warshall Algorithm-----------------
        
        for(int k = 0; k < n; k++) {    // via -> 1, 2, 3, 4,...,n
            // Now Matrix Traversal:
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    mat[i][j] = min(
                        mat[i][j],
                        mat[i][k] + mat[k][j]
                    );
                }
            }
        }
        
        //------------------------------------------


        // If there is a cycle, then we can detect it with: 
        for(int i = 0; i < n; i++) {
            if(mat[i][i] < 0) {
                // Do it here, for negative cycle:
                
            }
        }
        
        
        // converting it back to -1 for not-reachable nodes.
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 1e9) mat[i][j] = -1;
            }
        }
    }
};



int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.shortestDistance(matrix);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "~" << "\n";
    }

    return 0;
}