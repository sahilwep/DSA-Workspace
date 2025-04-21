/*

//  3493. Properties Graph


//  Problem Statement: 
    -> You are given a 2D integer array properties having dimensions n x m and an integer k.
    -> Define a function intersect(a, b) that returns the number of distinct integers common to both arrays a and b.
    -> Construct an undirected graph where each index i corresponds to properties[i]. There is an edge between node i and node j if and only if intersect(properties[i], properties[j]) >= k, where i and j are in the range [0, n - 1] and i != j.
    -> Return the number of connected components in the resulting graph.

 
// Example: 
    Example 1:
        Input: properties = [[1,2],[1,1],[3,4],[4,5],[5,6],[7,7]], k = 1
        Output: 3
        Explanation: The graph formed has 3 connected components:

    Example 2:
        Input: properties = [[1,2,3],[2,3,4],[4,3,5]], k = 2
        Output: 1
        Explanation: The graph formed has 1 connected component:

    Example 3:
        Input: properties = [[1,1],[1,1]], k = 2
        Output: 2
        Explanation: intersect(properties[0], properties[1]) = 1, which is less than k. This means there is no edge between properties[0] and properties[1] in the graph.

// Observations: 
    -> We are given an grid of n x m
    -> n = total number of nodes in our graph.
    -> m = array[] which contains some arbitrary number.
    -> Now according to the question, they are talking about intersection point b/w two array & total number of intersection point should be ">= k" then only we can join tow edge (u ----- v) of course undirected edge..

    // Deep Observations: 
        // Example: 
            Input: properties = [[1,2],[1,1],[3,4],[4,5],[5,6],[7,7]], k = 1
            Output: 3
                
                Index: array[]
                   0  : [1,2]
                   1  : [1,1]
                   2  : [3,4]
                   3  : [4,5]
                   4  : [5,6]
                   5  : [7,7]

                // Matching Pairs:

                        0: [1, 2]
                        1: [1, 1]

                            Both the index/node "0" & "1" we have {1} common in both
                                0: [[1], 2]
                                    | \
                                1: [[1],[1]]
                            
                            As per the question duplicate number should be considered, only unique pairs
                            Also, Given conditions "i != j" denoting same index we can't
                            So Connection count is '1'

                        2  : [3,4]
                        3  : [4,5]
                        4  : [5,6]

                            
                            If we observe carefully index "2", "3" & "4" have matching pairs {4, 5}
                                    2  : [3,  [4]]
                                             /
                                    3  : [[4],[5]]
                                             /
                                    4  : [[5] , 6]

                                ** NOTE: Index "2" & "4"  not connected directly, They have transitive Connected dependency. **
                                    Keep this in mind about transitive dependency, this will help us to connect the indirect edge matching pairs..
                        
                        
                        5  : [7,7]

                            Alone, not making pairs with anyone...

                // NOTE: 
                    'k' is Considerations factor.
                    We only connect the nodes whose (edges count) / (connection count) >= "k" given.
                    In all the above case k = 1, and we atleast have one edge, this is why we are able to connect those edges..

                // Final Graph:

                    [0]                       [3]
                     \                        / \
                      \                      /   \              [5]
                       \                    /     \
                        [1]               [2]      [4]

            -> Total number of  components: 3

        -> This question Gives us the pattern simillar to account merge.
        -> In account merge we use to match email & connecting them, Here we just have to carefull about the connection count for every dependent values..
        -> Understand with another Important example: 

            Input: properties = [[1,2,3],[2,3,4],[4,3,5]], k = 2
            Output: 1
                              Index     array[]
                                0   :   [1,2,3]
                                1   :   [2,3,4]
                                2   :   [3,4,5]

                        Remember here k = 2, means we required 2 dependent pairs for every nodes.

                              INDEX     Array[]
                                0   :   [1,  [2],  [3]]
                                            /     /
                                          /      /
                                1   :   [[2], [3], [4]]
                                              /     /
                                            /     /
                                2   :   [[3], [4],   5]

                        Here we can observe all 3 index/nodes "0", "1", & "2" are connected
                        
                            "0" & "1" have direct 2 edges
                            "1" & "2" have direct 2 edges

                        But How "0" & "2" ??????

                            Well we have talked earlier about the transitive dependency.
                            Even they "0"  &  "2" did not share any direct atleast 'k' Count edge. 
                            But they share exactly 'k' edges to some whose in b/w them, i.e "1"

                        This is why we have to consider the transitive dependency checks..
                        
        -> Now we almost cracked the question.
        -> it's just we have to check the dependency pairs & store it in somewhere & check their count, Considering transitive dependency of course
        -> We will have to our own modified Data Structure which will work in situations...

        // Let's Build with example:

            Input: [[2, 1], [2, 3], [1, 2]],    k = 2
            Output: 2

            -> we can use map to store & check the matching paris among the index/nodes..
                map: <Dependency: <nodes>>  // This will track every dependency with their nodes containing them.
                map: <edges: count>         // this will help us to track the edges & their count for valid matching dependency pairs

                 Index: arr[]
                    0:  {2, 1}
                    1:  {2, 3}
                    2:  {1, 2}

            -> Initially: 
                    mp: {dep: nodes/Index}
                    edge:{(u, v): freq}

                Index[0]:
                    val: 2
                        mp: {2: 0}
                        edge:{ : }

                    val: 1

                        mp: {{2: 0},
                             {1: 0}}
                        edge:{ : }

                Index[1]
                    val: 2
                        Find mp[2]: {0}
                            Now store {0 -- 1} into edges
                            & store '1' in mp[2] => by mp[2].push_back(1)
                        Updated: 
                            mp: {{2: 0, 1},
                                 {1: 0}
                                 {2: 1}}
                            edge:{(0 - 1) : 1 } <- updated

                    val: 3
                            mp: {{2: 0, 1},
                                 {1: 0}
                                 {2: 1}
                                 {3: 1}}
                            edge:{(0 - 1) : 1 }

                Index[2]
                    val: 1
                        Find mp[1]: {0}
                            store {0 -- 2} into edges:
                            & store '2' in mp[1] => by mp[1].push_back(2)
                        Updated: 
                            mp: {{2: 0, 1},
                                 {1: 0, 2}
                                 {2: 1}
                                 {3: 1}}
                            edge:{(0 - 1) : 1
                                  (0 - 2) : 1 } <- updated

                    val: 2
                        Find mp[2]: {0, 1}
                            Store: {0, 2}
                                   {1, 2} into edges.
                            & store '2' in mp[2] => by mp[2].push_back(2)
                        Update: 
                            mp: {{2: 0, 1, 2}
                                 {1: 0, 2}
                                 {2: 1}
                                 {3: 1}}
                            edge:{(0 - 1) : 1
                                  (0 - 2) : 1 + 1  <- updated
                                  (1 - 2) : 1}     <- updated

            -> you have observe every time when we found value, we get whole map list & iterate all the node & storing those edges.
            -> This is because these are the transitive dependent values, & we want to create an edge for them:
                -> This is why we are pushing those edges{u, v} everytime in edge list.
                -> So, that when we filtring out the valid 'k' contains count edges, this will help us...
    
            -> Final Edge list: 
                 edge:{(0 - 1) : 1
                       (0 - 2) : 2
                       (1 - 2) : 1}
                k = 2

                Connectin the edges that are in valid 'k' constrains: 
                            
                        [0]
                           \
                            \       [1]
                             \
                             [2]
                -> Total number of components = "2"

    // Final Conclusion: 
        -> First, we will have to filter out array for unique values.
        -> Then we can process the given array & storing their dependency value with respect to their nodes/index.
        -> We will have to carefull about the transitive dependency..
            -> means everytime we will iterate in map for every finding & store all the nodes corresponding to that map values.
            -> This will help us to build edge for transitive dependency..
        -> Once we got the edges: 
            -> Iterate into those edges & from their frequency, include those edges whose frequency is >= 'k'
            -> With DSU join them with Union operations.
        -> Last count the total number of components using DSU ultimate parent method.


// Complexity: 
    -> TC: O(n * m + E * α(n))
    -> SC: O(n * m + E)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class DSU {
private:
    vector<int> parent, size;
public: 
    DSU(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(node == parent[node]) return node;
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

class Solution {
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();  // total number of nodes:

        // Step 1: Filter out the properties: 
        vector<unordered_set<int>> uniqPro(n);
        for(int i = 0; i < n; i++) {
            for(auto &vals: properties[i]) uniqPro[i].insert(vals);
        }

        // Step 2: Find out the dependency b/w the arrays & store dependent edges:
        unordered_map<int, vector<int>> mp;     // store the dependency <Value: node>
        map<pair<int, int>, int> edges;   // store the dependent edges & their count
        for(int i = 0; i < n; i++) {
            for(auto &vals: uniqPro[i]) { // iterate in every array:
                
                for(auto &v: mp[vals]) { // Store all the edges pairs for this vals into edges
                    // We are iterating in map, because of transitive dependency, means: we want to create a edge pair for all the nodes so that we can handel the transitive dependency case.
                    if(i != v) {    // conditions same nodes/index skip..
                        edges[{min(i, v), max(i, v)}]++; // store frequency for edge (u, v), we used simple min() & max() logic to store them in sorted order.
                    }
                }

                // NOTE: after all those operations, we will store the current node for "vals".
                mp[vals].push_back(i);
            }
        }


        // Step 3: connect the edges whose frequency is greater equal to 'k'
        DSU ds(n);
        for(auto &it: edges) {
            auto [u, v] = it.first;
            int freq = it.second;

            if(freq >= k) {
                ds.Union(u, v);
            }
        }

        // Step 4: Count total number of components: 
        int comp = 0;
        for(int i = 0; i < n; i++) {
            if(ds.ultPar(i) == i) comp++;
        }

        return comp;
    }
};