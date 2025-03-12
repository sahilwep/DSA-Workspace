/*

//  G-46. Disjoint Set | Union by Rank | Union by Size | Path Compression 


// DSU: 
    -> DSU helps us to determine whether two nodes belonging to a same components or not in Dynamic Graph in Constant time.


// Use-case of DSU:
    -> When dynamic connectivity and merging of sets are needed.
    -> Finding whether two nodes belong to the same connected component in an undirected graph.
    -> Find the minimum cost to connect all nodes in a graph.
    -> Checking if a graph contains a cycle in an undirected graph.
    -> Maintaining components when elements are dynamically merged.
    -> Maze Generation, Clustering, Image Processing, Percolation



// ---------------------------------Union By Size--------------------------------------------

// DSU: Union By Rank:

    // Union (u, v):
        -> STEP 1: find ultimate parent of u & v, i.e => pu & pv
        -> STEP 2: find rank of pu & pv
        -> STEP 3: Connect smaller rank to larger rank always.
                -> In case of equality we can connect anyone to anyone & increase the rank of larger guy or parent by 1.
    


    // Initial Configurations: 
        -> Create two array with size (N + 1) to handel 1-based indexing.
        -> Index start from 1, because of 1-based indexing.


                rank[]  { 0 | 0 | 0 | 0 | 0 | 0 | 0}
                          1   2   3   4   5   6   7     -> Index


                parent  { 1 | 2 | 3 | 4 | 5 | 6 | 7}
                          1   2   3   4   5   6   7     -> Index
    



    // Path Compression: we directly attach every node directly to their ultimate parent.
        -> This will save us to find parent node of every node in Constant time instead of logarithmic time.
        -> NOTE: During path compression the rank cannot be reduced..
        -> During the path compression, the height will shrink, but this doesn't means the rank will be changed..



    // Complexity:
        // union()
            -> TC: O(4 α ) ≈ O(1)
        // Find parent()
            -> TC: O(4 α ) ≈ O(1)



    // Example:
            (1, 2)
            (2, 3)
            (4, 5)
            (6, 7)
            (5, 6)
            (3, 7)

                -> Initially rank of every node will be 0, & parent of every node will be themselves.

                        rank[]  = { 0 | 0 | 0 | 0 | 0 | 0 | 0 }
                                    1   2   3   4   5   6   7 
                                   
                        parent[] = {1 | 2 | 3 | 4 | 5 | 6 | 7}
                                    1   2   3   4   5   6   7 
                

                (1, 2) => 

                            -> Find ultimate parent of u & v => pu & pv
                            -> Find rank of pu & pv

                            u = 1, v  = 2       => u & v
                            pu = 1, pv = 2      => Ultimate parent
                            ru = 0, rv = 0      => Rank

                            -> Same rank: Connect any of them to any.

                                    [1]
                                    /
                                  [2]


                        rank[]  = { 1 | 0 | 0 | 0 | 0 | 0 | 0 }     =>  rank increased because the height is increased as we have connected.
                                    1   2   3   4   5   6   7 
                                   
                        parent[] = {1 | 1 | 3 | 4 | 5 | 6 | 7}
                                    1   2   3   4   5   6   7 
                
                (2, 3) => 

                            u = 2, v  = 3
                            pu = 1, pv = 3 
                            ru = 1, rv = 0 

                            -> rank of u is grater than rank of v => Smaller guy ultimate parent gets connected to larger guy ultimate parent i.e connect pv to pu 


                                    [1]
                                    / \
                                  [2]  [3]


                        rank[]  = { 1 | 0 | 0 | 0 | 0 | 0 | 0 }
                                    1   2   3   4   5   6   7 
                                   
                        parent[] = {1 | 1 | 1 | 4 | 5 | 6 | 7}
                                    1   2   3   4   5   6   7 


                (4, 5) => 

                            u = 4, v  = 5
                            pu = 4, pv = 5
                            ru = 0, rv = 0 

                                    [1]           [4]
                                    / \           /
                                  [2]  [3]      [5]
                                  
                                    


                        rank[]  = { 1 | 0 | 0 | 1 | 0 | 0 | 0 }
                                    1   2   3   4   5   6   7 
                                   
                        parent[] = {1 | 1 | 1 | 4 | 4 | 6 | 7}
                                    1   2   3   4   5   6   7 


                (6, 7) => 

                            u = 6, v  = 7
                            pu = 6, pv = 7
                            ru = 0, rv = 0 


                                    [1]           [4]   [6]
                                    / \           /     /
                                  [2]  [3]      [5]   [7]


                        rank[]  = { 1 | 0 | 0 | 1 | 0 | 1 | 0 }
                                    1   2   3   4   5   6   7 
                                   
                        parent[] = {1 | 1 | 1 | 4 | 4 | 6 | 6}
                                    1   2   3   4   5   6   7 

        
                
                (5, 6) => 

                            u = 5, v  = 6
                            pu = 4, pv = 6
                            ru = 1, rv = 1 

                            -> Same Rank we have so, either 4 can be attached with 6 |OR| 6 can be attached with 4

                                    [1]           [4]
                                    / \           /  \
                                  [2]  [3]      [5]   [6]
                                                        \
                                                         [7]

                            -> We have attached 6 with 4 => so parent[6] = 4
                            -> Also, we have attach the same rank guys each other, so the height will be increased, so the rank of 4 should also be increased by 1.


                        rank[]  = { 1 | 0 | 0 | 2 | 0 | 1 | 0 }
                                    1   2   3   4   5   6   7 
                                   
                        parent[] = {1 | 1 | 1 | 4 | 4 | 4 | 6}
                                    1   2   3   4   5   6   7 


                (3, 7) => 

                        -> Assume someone will come and ask will '1' & '7' belongs to same components ?
                        -> This is where findParent() function will help us to know whether they belong in same components or different components?
                            -> If we look both the parent: 
                                parent[1] = 1
                                parent[7] = 6
                            -> They were not same, can we say they don't belong in same component => Answer is NO.
                            -> Imagin we have one extra node: '8' is connected with '5'

                                                  [4]
                                                  /  \
                                               [5]   [6]
                                               /       \
                                             [8]        [7]
                        
                            -> Sahil, Keep in mind We are not creating a graph, we are creating a data-structure.

                            -> Now, if we asked 8 & 7 connected to same component => idelay they should, but:
                                parent[8] = 5
                                parent[7] = 6

                            -> Both would have different parent, so answer will NO => But we are wrong here.


                            -> If we find the ultimate parent of both the nodes:

                                Ultimate Parent of 7: Keep finding parent until we not reach parent of node is themselves.

                                    parent[7] = 6
                                    parent[6] = 4
                                    parent[4] = 4   ->  we reached (parent[node] == node), So, 4 is the ultimate parent.


                                ultimate_parent[8] = 4
                                ultimate_parent[7] = 4

                            -> Yes Both ultimate parent is same, So, YES they are in same components.

                    

                        -> Since we are creating tree like structure, when more & more nodes gets attached, the tree will increased in depth..

                            -> So, it will endup taking logarithmic time log(n) to find every ultimate parent of any node.
                            -> But, We are using unionByRank which should take O(1) constant time to find ultimate parent.
                            -> Solution: This is where the "PATH COMPRESSION" comes in picture.

                            // Path Compression:
                                -> If someone is asked us to find the parent of '7'
                                        [7] -> [6] -> [4]
                                                      parent

                                        Since we know 7's parent is 4
                                        While backtracking in path from 4 -> 6 -> 7, set every one's parent is 4 in path.

                                So, node something look like this:

                                                  [4]
                                                  / | \
                                               [5] [6] [7]
                                               /       
                                             [8]       

                                        In, Simple we removed the connected edge from 6 to 7 & we directly connected 7 to 4
                                        NOTE: We don't have done any modification on left side of tree, the path which we don't taken...
                                
                                So, Next time if someone comes and ask for parent of '7', we can directly return parent of 7 in constant time O(1)
                                NOTE: I have taken small graph example, but if we have big long connected graph, the visualization will be much better, because all the nodes b/w the Ultimate parent & the node we are searching, directly connected to ultimate parent when we backtrack the path after finding the ultimate parent...


                        -> Coming back to Example:

                            -> for finding the ultimate parent of 7 -> we will end up doing path compression & nodes connectivity looks something like this:
                                    
                                    [1]            [4]       
                                    / \           / | \       
                                  [2]  [3]     [5] [6] [7]
                                           

                            u = 3, v  = 7
                            pu = 1, pv = 4  => Find ultimate parent of each node:
                            ru = 1, rv = 0


                        -------------------------IMPORTANT--------------
                        |
                        |    // NOTE:
                        |        -> Ideally when we do the path compression the rank cannot be decreased after path compression, 
                        |        -> because we are not sure about the the other section of the tree length, 
                        |        -> Example: Let's say Initially we have tree: 
                        |
                        |                          [4]
                        |                          /  \
                        |                       [5]   [6]
                        |                       /       \
                        |                     [8]        [7]
                        |
                        |        -> Now, when someone ask for '7', we done the path compression & tree looks something like this:
                        |
                        |                          [4]
                        |                          / | \
                        |                       [5] [6] [7]
                        |                       /       
                        |                     [8]       
                        |
                        |        -> Now if we decrease the rank of the node '4' because we have done path compression, it's wrong because the other side of the tree has still the same height that it had previously.
                        |        -> This is why the rank cannot be decreased after the path compression.
                        |
                        ------------------------------------------------


                        -> Back to Example again:

                            u = 3, v  = 7
                            pu = 1, pv = 4  => Find ultimate parent of each node:
                            ru = 1, rv = 2


                                    (rank_v > rank_u) connect ultimate_parent_of_u to ultimate_parent_of_v:


                                                     [4]       
                                                  / / | \
                                               [1] [5] [6] [7]
                                               / \    
                                            [2]  [3]     

                                    NOTE: Rank should not be changed, because we are attaching smaller guy to the larger guy..
                                    NOTE: Rank only will be changed when the rank of both the ultimate parents of nodes u & v are same -> rank increased by 1 to whomever we connected or the parent we have in that connections.


                        rank[]  = { 1 | 0 | 0 | 2 | 0 | 1 | 0 }
                                    1   2   3   4   5   6   7 
                                   
                        parent[] = {4 | 1 | 1 | 4 | 4 | 4 | 4}
                                    1   2   3   4   5   6   7 

    






    // Why we are connecting smaller to larger?
        -> If we have two graph with smaller height & larger height:
            -> If we connect larger to smaller => Height will be increased & we will be endup taking longer distance to finding any node ultimate parent. 

            // Connecting larger to smaller:

                        [2]             [4]
                        /                 \
                     [3]                  [5]
                     /                      \
                   [7]                      [6]
                                              \
                                              [8]
                                                \
                                                [9]

                => Connecting Larger to smaller => height will be increased

                        [2]             
                        /  \
                     [3]   [4]
                     /        \
                   [7]        [5]
                                \
                                [6]
                                  \
                                  [8]
                                    \
                                    [9]
                    
                    -> Here travel time for all the node will be increased.
                    -> if we keep connecting larger node to more smaller node again-n-again over the time => Overall travel time will be increased.
            
                => But if we connect smaller to larger => height will not be increased.
                         
                          [4]
                          /  \
                        [2]   [5]             
                        /       \
                     [3]        [6]
                     /            \
                   [7]            [8]
                                    \
                                    [9]
                           
                    -> Doesn't matter if we keep connecting more smaller components to larger ones, height will not be increased.
                    -> Overall travel time will not be increased.
                    -> Yes, smaller components time will be increased, but overall if we observe it will not be increased.. 
                           


// ---------------------------------Union By Size--------------------------------------------

// DSU: Union By Size:
    -> NOTE: Height is distorted after path compression.
    -> With Union by size we can keep track of size of the components.
    -> Same as union by rank, with slight modifications:
        -> We will have size array of same size with everyone will have size = 1
        -> and parent with parent will be themselves.
    
    // Union (u, v):
        -> Go ahead and attach u to v
        -> The movement we will be attaching u to v => size of v will be increased by 1.
        -> and parent of 'u' will be 'v'.

        // Example:
            (1, 2)
            (2, 3)
            (4, 5)
            (6, 7)
            (5, 6)
            (3, 7)

                -> Initially size of every node will be 1, because that will be treated as individual components..


                        size[]  = { 1 | 1 | 1 | 1 | 1 | 1 | 1 }
                                    1   2   3   4   5   6   7 
                                   
                        parent[] = {1 | 2 | 3 | 4 | 5 | 6 | 7}
                                    1   2   3   4   5   6   7 

                (1, 2) => 

                            [1]
                              \
                              [2]

                        size[]  = { 2 | 1 | 1 | 1 | 1 | 1 | 1 }
                                    1   2   3   4   5   6   7 
                                   
                        parent[] = {1 | 1 | 3 | 4 | 5 | 6 | 7}
                                    1   2   3   4   5   6   7 


                (2, 3) => 
                            [1]
                            /  \
                          [3]  [2]

                        size[]  = { 3 | 1 | 1 | 1 | 1 | 1 | 1 }
                                    1   2   3   4   5   6   7 
                                   
                        parent[] = {1 | 1 | 1 | 4 | 5 | 6 | 7}
                                    1   2   3   4   5   6   7 

                (4, 5) => 

                            [1]              [4]
                            /  \             /
                          [3]  [2]         [5]

                        size[]  = { 3 | 1 | 1 | 2 | 1 | 1 | 1 }
                                    1   2   3   4   5   6   7 
                                   
                        parent[] = {1 | 1 | 1 | 4 | 4 | 6 | 7}
                                    1   2   3   4   5   6   7 

                        
                (6, 7) => 

                            [1]              [4]            [6]
                            /  \             /              /
                          [3]  [2]         [5]            [7]

                        size[]  = { 3 | 1 | 1 | 2 | 1 | 2 | 1 }
                                    1   2   3   4   5   6   7 

                        parent[] = {1 | 1 | 1 | 4 | 4 | 6 | 6}
                                    1   2   3   4   5   6   7 

                        
                        
                (5, 6) => 

                            [1]              [4]
                            /  \             / \
                          [3]  [2]         [5]  [6]
                                                  \
                                                  [7]

                        size[]  = { 3 | 1 | 1 | 4 | 1 | 2 | 1 }
                                    1   2   3   4   5   6   7 

                        parent[] = {1 | 1 | 1 | 4 | 4 | 4 | 6}
                                    1   2   3   4   5   6   7 


                        
                (3, 7) =>

                            [1]              [4]
                            /  \             / \
                          [3]  [2]         [5]  [6]
                                                  \
                                                  [7]

                        -> after path compression & connection ultimate parent of 3 to ultimate parent of 7 together:

                                               [4] 
                                             /  |  \ \
                                          [1] [5] [6] [7]
                                          / \
                                        [3]  [2]

                        size[]  = { 3 | 1 | 1 | 7 | 1 | 2 | 1 }
                                    1   2   3   4   5   6   7 

                        parent[] = {1 | 1 | 1 | 4 | 4 | 4 | 4}
                                    1   2   3   4   5   6   7 

                    NOTE: Here some of the node like 1, 


        -> Union By size is much more intuitive than the union by rank.
        -> Because with path compression rank is distorted
                                    

    // Complexity:
        // union()
            -> TC: O(4 α ) ≈ O(1)
        // Find parent()
            -> TC: O(4 α ) ≈ O(1)



// Extra:

    NOTE: If we are using disjoint set, either use by size or by rank, don't use both at the same time Because:

    // Union by Rank vs. Union by Size

        // Union by Rank:
            -> The rank represents the approximate depth of the tree.
            -> When merging two sets, the tree with lower rank is attached to the tree with higher rank.
            -> If both have the same rank, the rank of the new root is incremented.

        // Union by Size:
            -> The size represents the number of elements in the set.
            -> When merging two sets, the smaller set is always attached to the larger set.
            -> The size of the new root is updated accordingly.
        

    // Why Should You NOT Use Both at the Same Time?

        // They Serve the Same Purpose:
            -> Both optimizations try to keep the tree as flat as possible to speed up findUPar().
            -> Union by Rank minimizes depth using ranks.
            -> Union by Size minimizes depth using sizes.
            -> Using both is redundant and does not provide extra benefits.

        // Conflicting Logic:
            -> Union by Rank updates the rank[] array, while Union by Size updates the size[] array.
            -> If you mix them, the logic becomes inconsistent:
                -> Should you compare rank or size when merging?
                -> If rank says attach A to B, but size says attach B to A, which one should you follow?

        // Increased Space Complexity:
            -> Using both requires maintaining both rank[] and size[] arrays, which increases memory usage unnecessarily.

            
    // Which One Should We Use?
        -> "Union by Size" is often preferred in practical scenarios because:
            -> It directly considers the number of elements in a set.
            -> It has slightly better cache efficiency.
        -> Union by Rank is theoretically just as good, but rank values are not as intuitive to track as sizes.
        -> Both methods ensure nearly constant time complexity O(α(n)) (inverse Ackermann function), so the choice is mostly based on implementation preference.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Union By Rank & Size:
class DisjointSet {
private:
    vector<int> rank, parent, size;
public:
    // Constructor:
    DisjointSet(int n) {
        // initial Configurations:
        rank.resize(n + 1, 0);  // declarations it with n + 1, will work with both 0-based and 1-based indexing.
        
        size.resize(n + 1, 1);  // size default value = 1, because of every node initially treated as single component.

        // for every node parent is themselves => parent[i] = i
        parent.resize(n + 1);
        for(int i = 0; i < n + 1; i++) {
            parent[i] = i;
        }
    }

    // Find ultimate parent => with path compression
    int findUPar(int node) {
        if(parent[node] == node){
            return node;
        }

        // else go parent -> parent -> parent until we not reach to a node which is the ultimate parent.
        return parent[node] = findUPar(parent[node]);      // send parent[node] in recursive call to reach ultimate parent & save in parent[node] to use path compression => takes O(1)
        // return findUPar(parent[node]);      // Takes O(log(n)) logarithmic time, without path compression.
    }

    // Union By Rank => which we have to combine or attach (u & v)
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);    // find ultimate parent of u
        int ulp_v = findUPar(v);    // find ultimate parent of v
        

        // if both ultimate parents are same => they are already in same components.
        if(ulp_u == ulp_v) return;  // they are belonging to the same components => already attached.
        


        // If they were not in same components:
        if(rank[ulp_u] < rank[ulp_v]) { // check rank:
            parent[ulp_u] = ulp_v; // smaller goes & get's attached to the greater guy. => ultimate parent of smaller guy will be the ultimate parent of greater guy.
        }
        else if(rank[ulp_v] < rank[ulp_u]) {    // v ultimate parent is lesser rank than u ultimate parent: attach 
            parent[ulp_v] = ulp_u;  // smaller goes & get's attached to the greater guy.
        }
        else {  // if they have same rank:   we can assign anyone to anyone, but make sure the we should increase the rank of greater guy.
            parent[ulp_v] = ulp_u;      // we have attached ultimate parent of v to ultimate parent of u.
            rank[ulp_u]++;  // rank of ultimate parent of u will be increased, because that is where i am attaching it.
        }
    }


    // Union By Size: 
    void unionBySize(int u, int v) {

        int ulp_u = findUPar(u);    // find ultimate parent of u
        int ulp_v = findUPar(v);    // find ultimate parent of v
        

        // if both ultimate parents are same => they are already in same components.
        if(ulp_u == ulp_v) return;  // they are belonging to the same components => already attached.
        

        // If they were not in same components:
        if(size[ulp_u] < size[ulp_v]) { // check size:
            parent[ulp_u] = ulp_v; // smaller goes & get's attached to the greater guy. => ultimate parent of smaller guy will be the ultimate parent of greater guy.
            size[ulp_v] += size[ulp_u]; // size will be added, because the componenets gets connected.
        }
        else {  // else if ultimate parent of v is smaller than ultimate parent u |OR| size[ulp_u] == size[ulp_v] it's equal
            parent[ulp_v] = ulp_u;  // attach the larger 'u' to smaller 'v'.
            size[ulp_u] += size[ulp_v]; // add the size to ultimate parent of 'u'
        }
    }

};

int main() {

    // Union By Rank:
    DisjointSet ds(7);  // create a disjoint set of size 7

    // Union By Rank:
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // Before attaching (3, 7), Check if 3 & 7 belongs to same components or not?
    (ds.findUPar(3) == ds.findUPar(7))  ? cout << "same\n" : cout << "Not-Same\n";

    ds.unionByRank(3, 7);

    // After-attaching (3, 7) => check whether they belong to same components or not?

    (ds.findUPar(3) == ds.findUPar(7))  ? cout << "same\n" : cout << "Not-Same\n";


    // Union By Size:

    DisjointSet ds1(7);  // create a disjoint set of size 7

    // Union By Rank:
    ds1.unionBySize(1, 2);
    ds1.unionBySize(2, 3);
    ds1.unionBySize(4, 5);
    ds1.unionBySize(6, 7);
    ds1.unionBySize(5, 6);

    // Before attaching (3, 7), Check if 3 & 7 belongs to same components or not?
    (ds1.findUPar(3) == ds1.findUPar(7))  ? cout << "same\n" : cout << "Not-Same\n";

    ds1.unionBySize(3, 7);

    // After-attaching (3, 7) => check whether they belong to same components or not?

    (ds1.findUPar(3) == ds1.findUPar(7))  ? cout << "same\n" : cout << "Not-Same\n";


    return 0;
}