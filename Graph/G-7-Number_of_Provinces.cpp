/*

//  G-7. Number of Provinces

//  Problem Statement: 
    * Given an undirected Graph With V vertices. We say two vertices u & v belongs to a single provinces if there is a path from u to v or v to u, your task is to find number of provinces.
    * NOTE: A provinces is a group of directly or indirectly connected cities or no other cities outside of the group.

// Example:

    Input:
    [[1, 0, 1],
    [0, 1, 0],
    [1, 0, 1]]
                
    Output: 2

            [1]     [2]
             \
              \
               [3]

    Explanation:
    The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single province. City 2 has no path to city 1 or city 3 hence it belongs to another province.

    Input:
    [[1, 1],
    [1, 1]]

    Output: 1

            [1]-----[2]


// Observation:

    -> We are given adjacency matrix: 

            [1]     [2]
             \
              \
               [3]


                   1  2  3 -> m
            1  ->  1  0  1
            2  ->  0  1  0
            3  ->  1  0  1
            |
            n

            n => lines, m = edges that are connected.
                (n,m) if (n == m) => represent single node
                (n,m) if (n != ) => represent connection

    
    -> Now coming back to question:

            [1]-----[2]     [4]-----[5]     [7]
                    /               /        |
                  /               /          |
                /               /            |
              [3]            [6]            [8]


        Output: 3

            In first component(1,2,3):
                From every other node in this provence, we can go every other node.

            In second component(4,5,6):
                From every other node in this provence, we can go every other node.

            But we can't go 2->4, because there is no connectivity.


        We need to visit in every component, & count the total number of component
        We visit all the element in any component, we can use BFS/DFS any of the traversing technique.

        All we have to do is maintain a visited array[], which will mark the visited elements:
        Create a visited array of size no of Vertices, and initialize this by '0' 

                vis = [0, 0, 0, 0, 0, 0, 0, 0, 0]
                       0  1  2  3  4  5  6  7  8

        During the traversal, if we visit any element mark it as '1'
        Let's analyze this by example: 
       
            [1]-----[2]     [4]-----[5]     [7]
                    /               /        |
                  /               /          |
                /               /            |
              [3]            [6]            [8]

            -> Start iterating from vis[] array from i = 1, because indexing is from '1'
                
                i = 1:
                    call dfs() -> this will visit "1->2->3"
                    mark all these element to visited in visited array.

                    vis = [0, 1, 1, 1, 0, 0, 0, 0, 0]
                           0  1  2  3  4  5  6  7  8

                i = 2: 
                    already visited: skip

                i = 3, 4: 
                    already visited: skip

                i = 4: 
                    Not visited Yet: call dfs() -> this will visit "4, 5, 6"
                    mark all these element in visited array.

                    vis = [0, 1, 1, 1, 1, 1, 1, 0, 0]
                           0  1  2  3  4  5  6  7  8

                i = 5: 
                    already visited: skip

                i = 6: 
                    already visited: skip

                i = 7: 
                    Not visited Yet: call dfs() -> this will visit "7, 8"
                    mark all these element in visited array.

                    vis = [0, 1, 1, 1, 1, 1, 1, 1, 1]
                           0  1  2  3  4  5  6  7  8

                i = 8: 
                    already visited: skip

            -> Iteration completed in visited array[]

                In total we have called dfs() 3 times, during the iterations in visited array[].
                So, total number of component is 3, & to count this we can use an counter in check condition.



// Complexity:
    * SC: 
        O(n) -> visited array
         +
        O(n) -> This much recursion calls in stack.
            => O(n)

    * TC: 
        O(n) -> to iterate in visited array
        O(v + 2E) -> DFS traversal.
            => O(n) + O(v + 2E)

        // NOTE: O(n) * O(v + 2E) is wrong,
            because 3 time dfs executed form visited array
                But whenever dfs() is executes for '1', it go for 3 move calls.
                whenever dfs() is executes for '4', it go for 3 more calls.
                Whenever dfs() is executes for '7', it go for 2 more calls.

                In Total it goes for n dfs() calls.
            
            Thereby, 
                Partial dfs()
                    dfs(1)  | 
                    dfs(3)  |  => gives O(n)
                    dfs(7)  | 
                
                In total dfs traversal goes for O(n) & TC: O(v + 2E) is for Graph.

                So, we can say that:
                        
                    O(n) + O(v + 2E)
                        ||
                        \/
    
                    Gives near about, O(n).


// Input TestCase:

2
3
1 0 1
0 1 0
1 0 1
2
1 1
1 1




*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// BFS Function: 
void bfs(int node, vector<int> adj[], vector<int> &vis){

    vis[node] = 1;  // mark current node as visited.
    queue<int> q;
    q.push(node);   // push starting inode in queue:

    while(!q.empty()){  // while q is not empty:
        int val = q.front();
        q.pop();

        for(auto it: adj[val]){ // iterate in current node neighbour:
            if(!vis[it]){   // if neighbour is not visited:
                vis[it] = 1;   // mark current node as visited.
                q.push(it); // push the current node in queue.
            }
        }
    }
}


// DFS code: 
void dfs(int node, vector<int> adj[], vector<int> &vis){
    vis[node] = 1;  // mark current node as visited

    // iterate in current node neighbour:
    for(auto it: adj[node]){
        if(!vis[it]){   // if node is not visited:
            dfs(it, adj, vis);  // call for dfs(), with current selected neighbour.
        }
    }
}

// Function to find the number of Provinces:
int numProvinces(vector<vector<int> > adj, int V) {
    
    // We are given adj matrix, not adj list, Let's convert this into adj list:
    vector<int> adjLis[V];

    // Convert adj matrix to adj list:
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(i != j && adj[i][j] == 1){
                adjLis[i].push_back(j);
                adjLis[j].push_back(i);
            }
        }
    }

    // Now find number of provinces:
    vector<int> vis(V, 0);  // create visited array with default value '0'
    int cnt = 0;    // this will count the number of provinces.

    for(int i=0;i<V;i++){
        if(!vis[i]){    // current element from visited array is not visited yet, we will call dfs() for that.
            cnt++;  // count the number of provinces
            dfs(i, adjLis, vis);    // call dfs() for unvisited node:
        }
    }

    return cnt; // return the count of provinces.
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;

        vector<vector<int> > adj;
        for(int i=0; i<V; i++){
            vector<int> temp;
            for(int j=0; j<V; j++){
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        cout << numProvinces(adj,V) << endl;
    }

    return 0;
}