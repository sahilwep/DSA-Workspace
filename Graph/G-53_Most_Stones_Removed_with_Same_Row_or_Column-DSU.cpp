/*

//  G-53. Most Stones Removed with Same Row or Column - DSU


//  Problem Statement: 
    -> On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.
    -> A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.
    -> Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.
 

// Example:

    Example 1:

        Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
        Output: 5
        Explanation: One way to remove 5 stones is as follows:
            1. Remove stone [2,2] because it shares the same row as [2,1].
            2. Remove stone [2,1] because it shares the same column as [0,1].
            3. Remove stone [1,2] because it shares the same row as [1,0].
            4. Remove stone [1,0] because it shares the same column as [0,0].
            5. Remove stone [0,1] because it shares the same row as [0,0].
            Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.

    Example 2:

        Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
        Output: 3
        Explanation: One way to make 3 moves is as follows:
            1. Remove stone [2,2] because it shares the same row as [2,0].
            2. Remove stone [2,0] because it shares the same column as [0,0].
            3. Remove stone [0,2] because it shares the same row as [0,0].
            Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.

    Example 3:

        Input: stones = [[0,0]]
        Output: 0
        Explanation: [0,0] is the only stone on the plane, so you cannot remove it.



// Observations: 
    -> We are given n stones which are placed on some coordinates point.
    -> Each Coordinate point may have at most one stone.
    -> Stones can be removed if it shares either the "same-row" or the "same-column" as another stones that has not been removed.
    -> Given an array "stones" of length where 'n'  where stones[i] = [x[i], y[i]] represent the locations of the i'th stones, return the largest possible number of stones that can be reomved.

    // Key Observations: 
        -> We are bound to remove only sameRow or sameCol stones.
        -> also we can only remove one stone if other is available in that row.
        -> means last stone of row will be left on that row/col...
        // Visualizations: 
            -> Example: [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]

                      0   1   2
                    |---|---|---|
                 0  | * | * |   |
                    |---|---|---|
                 1  | * |   | * |
                    |---|---|---|
                 2  |   | * | * |
                    |---|---|---|

                -> If we observe carefully & try to draw from "stones to stones" -> We will found all stones connect together.
                -> We are given total '6' stones
                -> And when we trying removing the stones, we will left with only one remaining stone.
                -> Consider the group of connected stones as a components & then observe this in way of graph...
                -> For this Group/Component: (0, 0), (0, 1), (1, 0), (1, 2), (2, 1), (2, 2)
                    -> If we start removing all the stones we onl  left with 1 stones. => (Total Removal = 5)


                -> Let's take another example..

                
            -> Another Example: [[0,0],[0,2],[1,1],[2,0],[2,2]]

                      0   1   2
                    |---|---|---|
                 0  | * |   | * |
                    |---|---|---|
                 1  |   | * |   |
                    |---|---|---|
                 2  | * |   | * |
                    |---|---|---|

                -> Given '5' stones & if we connect same row-col stones together:
                    -> We will find 2 groups/Components: 
                        Group 1: (0,0), (0,2), (2,0), (2,2)
                        Group 2: (1,1)
                    
                    -> If we remove stones in first group: we will only left with 1 group, (Total Removal: 3)
                    -> for Group 2, we don't have any other stone, which we can use to remove this stone..
                    -> So, in total Removal => '3'


            -> So, from this observations, we get that we need to find components of graph.
            -> Lastly, subtract total number of component/group from the total number of given graph, that will be our total number of stone removed.
    

    // DSU Approach: 
        // Why DSU:     
            -> We are finding the relation b/w stones whether they are in same-row / same-col.
            -> and from that we are removing the stones, DSU will help us to connect the stones coordinate (row, col)
            -> and later on, we can find the total number of components.
        

        // Approach: 
            -> we are given coordinates of stones which is in 2D
            -> Flatten the 2D coordinates into 1-D coordinates:

                -> Example:

                              column
                                |
                            [[3,2],[3,1],[4,4],[1,1],[0,2],[4,0]]
                              |  
                            row

                        -> From this given coordinates the maximum row/col = 4, So 0 to 4 => 5 numbers total
                        -> Take a buffer zone of '5' b/w the row & col:
                        -> leave row as it is..
                        -> Increment 5 to every value of col.

                            [[3,7],[3,6],[4,9],[1,6],[0,7],[4,5]]

                        -> Now Every row & col value is unique not-overlapping

            -> Using DSU merge these row & col & form Components
            -> Check the total Number of Valid component, & count that
                -> What is "valid Component" : Component which have only those row-value / col-value which is available in our given graph.

            -> How to count total Valid Component:
                -> Iterate from 1 to last bound of DSU size:
                    check if(parent[i] == i && size[i] > 1)  component++;
                        -> Why (Size[i] > 1) : because we are iterating from 0 to last bound value of DSU size, & there are values which are initially assign individual component, & Stones Coordinates have tow unique value, so size should be grater than '1'.


        // Few - Optimization:
            -> We can store our valid (row, col) in set & then only inetrate in set & found ultimate parent & count that components.
            -> with set can save the unusual iteration of check parent.

// Complexity: 
    -> TC: O(N)
    -> SC: O(1) for Naive & O(N) for Optimized




*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class DSU {
public:
vector<int> parent, size;
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(parent[node] == node) return node;
        return parent[node] = ultPar(parent[node]);
    }
    void Union(int u_, int v_) {
        int u = ultPar(u_), v = ultPar(v_);
        if(u == v) return;
        if(size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};


// Clean Code With tight grid dimensions bound
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int totalStones = stones.size();  // total stones in grid

        // Find the Dimensions of Grid:
        int maxRow = -1;
        int maxCol = -1;
        for(auto &it: stones) {
            maxRow = max(it[0], maxRow);
            maxCol = max(it[1], maxCol);
        }

        // Connect the components:
        DSU ds(maxRow + maxCol + 2);    // create DSU of size (maxRow + maxCol + 2)
        unordered_set<int> nodes;       // use to store valid nodes
        for(auto &it: stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;   // buffer Point -> (maxRow + 1)
            
            ds.Union(nodeRow, nodeCol);         // merge them
            nodes.insert(nodeRow);
            nodes.insert(nodeCol);
        }

        // Count total number of components from grid.
        int totalComp = 0;
        for(auto &node: nodes) {
            if(ds.ultPar(node) == node) {
                cout << node << endl;
                totalComp++;
            }
        }
        
        return totalStones - totalComp; // total removal
    }   
};


// DSU Size of (2 * 1e4 + 1) as per the constrains.
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();  // total number of stone:

        // Flatten 2D-Grid into 1D by adding '1e4 + 1' for valid Union-Operations:
        DSU ds(2 * (1e4 + 1));  // creating buffer zone from given constrains "10000"

        // Merge coordinates:
        unordered_set<int> validCandidate;  // store only valid candidate or (row, col)
        for(auto &it: stones) {
            int u = it[0];
            int v = it[1] + (1e4 + 1);  // creating a buffer zone of size '1e4 + 1)

            ds.Union(u, v);
            validCandidate.insert(u);   // store valid row
            validCandidate.insert(v);   // store valid col
        }

        // Finding the total number of components & generating answer:
        int totalComp = 0;
        for(auto &i: validCandidate) {  // Iterate in valid (row, col) & store total valid component
            if(ds.parent[i] == i) {     // check if that node itself the ultimate parent, & if it's then count that as component.
                totalComp++;
            }
        }

        return n - totalComp;   // total number of given stones - total valid component found.
    }
};

