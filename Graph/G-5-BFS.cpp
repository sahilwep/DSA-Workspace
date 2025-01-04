/*

//  Graph: BFS Traversal:


// Explanation: 
    -> BFS: Breadth first search -> Traversal Technique
    -> In BFS, we traverse breadth means, from the given starting node we traverse level wise.
    -> This is also known as level wise traversal.

            1-Based Index Graph:        N = 8

                                   [1]
                                  /   \
                          [2]-----     ------[6]
                          / \                / \
                     [3]--   --[4]     [7]--    --[8]
                                 \      / 
                                  \   /
                                   [5]


    -> They will give us starting node, let's assume Starting node is '1'


                                   [1]  -> Starting node, we call it "level 0"
                                  /   \
                          [2]-----     ------[6] -> These nodes are at a distance of 1 from given starting node, so we call them "level 1"
                          / \                / \
                     [3]--   --[4]     [7]--    --[8] -> These nodes are at a distance of 2 from given starting node, so we call them "level 2"
                                 \      / 
                                  \   /
                                   [5] -> level 3 -> These nodes are at a distance of 3 from given starting node, so we call them "level 3"


                
                -> From given starting nodes, we have seen the levels, which can be found in compared with starting node,
                -> So, in traversal, first we visit the starting node, & then we visit all the nodes that are in next level node, and so on..

                        1   2 6   3 4 7 8   5
                       |_| |___| |_______| |_|
                        0    1       2      3   -> Levels
                
                -> In every level, either we can traverse from left to right or right to left, depending upon our needs.
    


    -> Let's assume starting node = 6, Now traverse:


                                   [1]
                                   /  \
                          [2]------    --------[6]Starting_Node
                           |                    |
                     [3]--/ \--[4]     [7]-----/ \---[8]
                                 \     / 
                                  \   /
                                   [5]

                -> If starting nodes is [6], we cannot say [2] is also in same level i.e level 0.
                -> So, only one node can be at level 0, i.e [6]

                -> Now which is at level '1', the nodes that are connected to starting node at distance of '1', So, level 1 = {1, 7, 8}
                -> Similarly, we will found all the level, by mapping the distance from given starting node.
                -> Let's write all the levels in every nodes, starting from node '6'


                                   [1]1
                                   /  \
                         2[2]------    --------[6]0
                           |                    |
                    3[3]--/ \--[4]3    1[7]----/  \---[8]1
                                 \     / 
                                  \   /
                                   [5]2
                
                -> Now we need to traverse at every levels i.e {1, 2, 3}
                
                        6   1 7 8   2 5   3 4
                       |_| |_____| |___| |___|
                        0     1      2     3   -> Levels
                
                -> During traversal it goes equivalent in breadth.
                -> So, we will traverse breadth wise, & everything depending on the starting node.




    -> For BFS traversal, we need to do some initial configurations
            
            N = 9
                                   [1]
                                  /   \
                          [2]-----     ------[6]
                          / \                / \
                     [3]--   --[4]     [7]--    --[9]
                                |       |
                                |       |
                                [5]----[8]


                -> Whatever is the starting node given to us, we take QUEUE-DS (FIFO), & put this inside the queue.
                -> and we will create a visited array, which is used to find whether we have visit the node or not?

                                    |     |  
                                    |     |  
                                    |     |  
                                    |  1  |  
                                    |_____|  Queue

                -> Given N = 9, & nodes start from 1, so we will create a visited array of size '10'
                        k = 10
                        visit[k] = [ |1| | | | | | | | ]
                                    0 1 2 3 4 5 6 7 8 9


                -> Now, go on the starting node, & mark it as '1', & everything else is marked with '0'
                -> '1', means this guy is already in the queue.
            
                        visit[k] = [ |1|0|0|0|0|0|0|0|0]
                                    0 1 2 3 4 5 6 7 8 9

            -> This is going to be our initial configurations.
        

    -> Now next: 

            -> Whatever is in the queue, keep taking it out until queue is not empty.
            -> Remember this -> Whatever is in the queue, "keep taking it out", "keep taking it out", "keep taking it out", until the queue is not empty.
            -> And we will print it.


            -> Graph is stored in some data-structure, and that data-structure is adjacency list.
            -> Now, adjacency list for this particular graph:

                                   [1]
                                  /   \
                          [2]-----     ------[6]
                          / \                / \
                     [3]--   --[4]     [7]--    --[9]
                                |       |
                                |       |
                                [5]----[8]

                    -> Adjacency List:

                        0 -> {}
                        1 -> {2, 6}
                        2 -> {1, 3, 4}
                        3 -> {2}
                        4 -> {2, 5}
                        5 -> {4, 8}
                        6 -> {1, 7, 9}
                        7 -> {6, 8}
                        8 -> {5, 7}
                        9 -> {6}

            -> Whenever we take first element out form the queue & print it, we will go to that element and find their neighbour
                
                // First take out 1 from queue, & print it:
                        First print node -> 1
                        Node [1] -> neighbour {2, 6}

                        -> First take '2' put this in queue DS, & mark it as 1 in visited_array
                                visit[k] = [ |1|1|0|0|0|0|0|0|0]
                                            0 1 2 3 4 5 6 7 8 9

                        -> Second take '6' put this in queue DS, & mark it as 1 in visited_array
                                visit[k] = [ |1|1|0|0|0|1|0|0|0]
                                            0 1 2 3 4 5 6 7 8 9

                        For node [1], we are done, our queue look something like this:
                

                                    |     |  
                                    |     |  
                                    |  6  |  
                                    |  2  |  
                                    |_____|  Queue

                        Printed Order: 1, 

                // Now take out '2' from queue, & print it:
                        First print node -> 2
                        Node [2] -> neighbour {1, 3, 4}

                        -> For '1', when we check the visited array it's already traversed, So, this will not put in the queue.
                                visit[k] = [ |1|1|0|0|0|1|0|0|0]
                                            0 1 2 3 4 5 6 7 8 9

                        -> For '3', not traversed yet, we can find this from visited array,
                                -> take '3' put this in queue DS, & mark it as 1 in visited_array
                                visit[k] = [ |1|1|1|0|0|1|0|0|0]
                                            0 1 2 3 4 5 6 7 8 9

                        -> for '4', not traversed yet, we can find this from visited array,
                                -> take '4' put this in queue DS, & mark it as 1 in visited_array
                                visit[k] = [ |1|1|1|1|0|1|0|0|0]
                                            0 1 2 3 4 5 6 7 8 9

                        For node [2], we are done, & our queue look something like this:
                

                                    |     |  
                                    |  4  |  
                                    |  3  |  
                                    |  6  |  
                                    |_____|  Queue

                        Printed Order: 1, 2

                // Now take out '6' from queue, & print it:
                        First print node -> 6
                        Node [6] -> Neighbour {1, 7, 9}

                        -> Simillar step we will perform as we have done in above illustrations..

                        Visited array look like this:
                                visit[k] = [ |1|1|1|1|0|1|1|0|1]
                                            0 1 2 3 4 5 6 7 8 9

                        For Node [6], we are done, & our queue look something like this:

                                    |     |  
                                    |  9  |  
                                    |  7  |  
                                    |  4  |  
                                    |  3  |  
                                    |_____|  Queue

                        Printed Order: 1, 2, 6

                // Now take out '3', from queue, & print it:
                        First print node -> 3
                        Node [3] -> Neighbour {2}

                        -> Simillar step we will perform as we have done in above illustrations..

                        Visited array look like this:
                                visit[k] = [ |1|1|1|1|0|1|1|0|1]
                                            0 1 2 3 4 5 6 7 8 9

                        For Node [3], we are done, & our queue look something like this:

                                    |     |  
                                    |  9  |  
                                    |  7  |  
                                    |  4  |  
                                    |_____|  Queue

                        Printed Order: 1, 2, 6, 3

                // Now take out '4', from queue, & print it:
                        First print node -> 4
                        Node [4] -> Neighbour {2, 5}

                        -> Simillar step we will perform as we have done in above illustrations..

                        Visited array look like this:
                                visit[k] = [ |1|1|1|1|1|1|1|0|1]
                                            0 1 2 3 4 5 6 7 8 9

                        For Node [4], we are done, & our queue look something like this:

                                    |     |  
                                    |  5  |  
                                    |  9  |  
                                    |  7  |  
                                    |_____|  Queue

                        Printed Order: 1, 2, 6, 3, 4

                // Now take out '7', from queue, & print it:
                        First print node -> 7
                        Node [7] -> Neighbour {6, 8}

                        -> Simillar step we will perform as we have done in above illustrations..

                        Visited array look like this:
                                visit[k] = [ |1|1|1|1|1|1|1|1|1]
                                            0 1 2 3 4 5 6 7 8 9

                        For Node [7], we are done, & our queue look something like this:

                                    |     |  
                                    |  8  |  
                                    |  5  |  
                                    |  9  |   
                                    |_____|  Queue

                        Printed Order: 1, 2, 6, 3, 4, 7

                // Now take out '9', from queue, & print it:
                        First print node -> 9
                        Node [9] -> Neighbour {6}

                        -> Simillar step we will perform as we have done in above illustrations..

                        Visited array look like this:
                                visit[k] = [ |1|1|1|1|1|1|1|1|1]
                                            0 1 2 3 4 5 6 7 8 9

                        For Node [9], we are done, & our queue look something like this:

                                    |     |  
                                    |     |  
                                    |  8  |  
                                    |  5  |  
                                    |_____|  Queue

                        Printed Order: 1, 2, 6, 3, 4, 7, 9

                // Now take out '5', from queue, & print it:
                        First print node -> 5
                        Node [5] -> Neighbour {4, 8}

                        -> Simillar step we will perform as we have done in above illustrations..

                        Visited array look like this:
                                visit[k] = [ |1|1|1|1|1|1|1|1|1]
                                            0 1 2 3 4 5 6 7 8 9

                        For Node [5], we are done, & our queue look something like this:

                                    |     |  
                                    |     |  
                                    |  8  |  
                                    |_____|  Queue

                        Printed Order: 1, 2, 6, 3, 4, 7, 9, 5

                // Now take out '8', from queue, & print it:
                        First print node -> 8
                        Node [8] -> Neighbour {5, 7}

                        -> Simillar step we will perform as we have done in above illustrations..

                        Visited array look like this:
                                visit[k] = [ |1|1|1|1|1|1|1|1|1]
                                            0 1 2 3 4 5 6 7 8 9

                        For Node [5], we are done, & our queue look something like this:

                                    |     |  
                                    |     |  
                                    |     |  
                                    |_____|  Queue

                        Printed Order: 1, 2, 6, 3, 4, 7, 9, 5, 8


                // Now queue is empty & we have printed our whole graph nodes in BFS Fashion: 

                                   [1]
                                  /   \
                          [2]-----     ------[6]
                          / \                / \
                     [3]--   --[4]     [7]--    --[9]
                                |       |
                                |       |
                                [5]----[8]

                        Starting Node = '1'

                        Printed Order: 1, 2, 6, 3, 4, 7, 9, 5, 8
 
                                        1, 2, 6, 3, 4, 7, 9, 5, 8
                                        -  ----  ----------  ----
                                        0    1        2        3        -> levels


                // This is how we will perform BFS


                NOTE: In visited_array index 0 = 0, because nodes are starting from 1, this is why don't have to look on '0'


// Complexity:
        * TC: O(n) + O(2E)
           O(n) -> A node will come & go into queue
           O(2E) -> Runs on all it's degrees


// Test-cases:

1
9 9
1 2
1 6
2 3
2 4
6 7
6 9
4 5
7 8
5 8


*/

#include<bits/stdc++.h>
using namespace std;


// BFS Traversal:
vector<int> bfsGraph(int V, vector<int> adj[]){ // given n size, and adjacency array, 
    // NOTE: index start from '1'
    int start = 1;  // let's assume starting node is '1'
    vector<int> vis(V+1, 0);   // visited array, mark default value '0' at all the index
    vis[start] = 1; // marks starting node as 1

    queue<int> q;
    q.push(start);  // First push starting node into queue:

    vector<int> res;    // vector to store the traversal order.
    while(!q.empty()){  // while queue is not empty 
        // first get the element from queue & store it in result vector.
        int node = q.front();   // getting the front element from queue
        q.pop();                // popping out the front element from queue
        res.push_back(node);    // storing it into result element


        // Check out the neighbour of current node:
        for(auto it: adj[node]){  // iterate in current node neighbour
            if(!vis[it]){       // if current element is not visited
                q.push(it);     // push it into queue
                vis[it] = 1;    // and mark it as visited
            }
        }
    }

    return res;
}


void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){       // input for undirected graph
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> res = bfsGraph(n, adj);
    for(auto i: res) cout << i << " ";
    cout << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}