/*

//  Graph: DFS Traversal:


// Explanation: 
    -> DFS -> This will be based on Depth-wise, From the given node we are going depth wise, until the nodes is over or we visit some previously visited node.
    -> Connected Undirected Graph

            1-Based Index Graph:        N = 8


                                   [1]
                                  /   \
                          [2]----      [3]------[4]
                          / \           |        |
                         /   \          |        |
                      [5]    [6]        |        |
                                       [7]------[8]
                                

            Let's assume starting node = '1'
                -> From 1, we can have two choice,
                    -> we can go 1->2->...
                    -> we can go 1->3->...

                -> let's choose first one:
                    from 2 we have 2 choice:
                        1->2->5
                        1->2->6
                -> Let's choose first one: 
            
            Our first traversal look like: 

                    1->2->5
            Now, form here we have no further node. so, we will move back to parent node, i.e '2', & explore any unvisited node: 
            we will have one unvisited node i.e '6', so we will move towards that node.
                    1->2->5->6
            
            Now after that, we don't have any further node, so we will move back to parent node, i.e '2', again there is no further unvisited node, so move back to parent i.e '1'
            Now, at '1', we have one path left i.e unvisited '3'
            So, we will move towards that path.
                    1->2->5->6->3
                -> From '3', we will have two choices to move '7' & '4' both were unvisited, so we can move any of them..
                -> Let's say we are going to '4'
                    1->2->5->6->3->4
            
            From '4' we can go to '8' & from there we can go to '7'
                    1->2->5->6->3->4->8->7
            
            Now, on '7' we don't have any unvisited node, and '3' is already visited and we are coming from '8'.
            So, we will move back to the parent calls...
            Eventually we will be back to the starting node, i.e '1', because there is no any node during the way that we have not visited yet.

            From '1' we have visited all the path, Now our final traversal look like: 
                    1->2->5->6->3->4->8->7


            One thing we can observe that we are moving recursively to find all the nodes that are not visited, & when there is no node left or visited node occurred again, we move back to the parent calls, until we didn't found any unvisited path.


            NOTE: the order in which we visit during the recursive calls, is totally depends upon the nodes that are stored in adjacency list.


        // Configurations for DFS:
            -> Same configurations we will make that we used to make in BFS:
                -> We will maintain visited array[n+1] size if index is 1 based, or 'n' size if it's 0 based.
            -> Rest of the process will be explained in the lines of codes:



// Complexity:
    * SC: 
        O(n) -> at max we are visiting n nodes in our traversal
        O(n) -> for visited
        O(n) -> Recursion stack space.
        => O(n) + O(n) + O(n) =  O(n) if we don't include adjacency list
    
    * TC: O(n) + O(2E)
        -> O(n) -> for every node
        -> O(2E) -> For every node, we are visiting the degree of that node, & for whole is is summations of All the degree, i.e 2E
        => TC: O(n) + O(2E)


// TestCases:

1
9 8
1 2
1 3
2 5
2 6
3 4
4 8
8 7
7 3


*/

#include<bits/stdc++.h>
using namespace std;

// DFS Traversal:
void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &res){
    vis[node] = 1;  // mark the curent node as visited
    res.push_back(node);    // storing that node in our result vector

    // Traverse for all the neighbour of current node:
    for(auto it: adj[node]){
        if(!vis[it]){ // if this neighbour is not visited:
            dfs(it, adj, vis, res);     // calling for the current node
        }
    }
}

vector<int> dfsGraph(int V, vector<int> adj[]){ // given n size, and adjacency array, 
    vector<int> vis(V+1, 0);    // V+1, because i have assumed that index start from '1'
    int start = 1;  // this is why starting node is set as 1
    vis[start] = 1; // mark starting node as 1
    vector<int> res;    // result to store dfs

    dfs(start, adj, vis, res);  // once all the nodes visited by dfs.

    return res; // return result
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

    vector<int> res = dfsGraph(n, adj);
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