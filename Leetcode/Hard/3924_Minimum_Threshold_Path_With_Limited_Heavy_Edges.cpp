/*

//  3924. Minimum Threshold Path With Limited Heavy Edges


//  Problem Statement: 
There is an undirected weighted graph with n nodes labeled from 0 to n - 1.
The graph is represented by a 2D integer array edges, where each edge edges[i] = [ui, vi, w​​​​​​​i] indicates that there is an undirected edge between nodes ui and vi with weight w​​​​​​​i.
You are also given integers source, target and k.
A threshold value determines whether an edge is considered light or heavy:
    An edge is light if its weight is less than or equal to threshold.
    An edge is heavy if its weight is greater than threshold.
A path from source to target is valid if it contains at most k heavy edges.
Return the minimum integer threshold such that at least one valid path exists from source to target. If no such path exists, return -1.

 
// Example:
    Example 1:​​​​​​​​​​​​​​
        Input: n = 6, edges = [[0,1,5],[1,2,3],[3,4,4],[4,5,1],[1,4,2]], source = 0, target = 3, k = 1
        Output: 4
        Explanation:
            The minimum threshold such that a path from node 0 to node 3 uses at most 1 heavy edge is 4.
                Light edges: [1, 2, 3], [3, 4, 4], [4, 5, 1], [1, 4, 2]
                Heavy edges: [0, 1, 5]
            A valid path is 0 → 1 → 4 → 3. It uses only 1 heavy edge ([0, 1, 5]), which satisfies the limit k = 1.
            Any smaller threshold would make it impossible to reach node 3 without exceeding 1 heavy edge.

    Example 2:

        Input: n = 6, edges = [[0,1,3],[1,2,4],[3,4,5],[4,5,6]], source = 0, target = 4, k = 1
        Output: -1
        Explanation: There is no path from node 0 to node 4. Since the target cannot be reached, the output is -1.

    Example 3:
        Input: n = 4, edges = [[0,1,2],[1,2,2],[2,3,2],[3,0,2]], source = 0, target = 0, k = 0
        Output: 0
        Explanation: The source and target are the same node. No edges need to be traversed, so the minimum threshold is 0.



// Observations:
    - given weighted graph with n nodes ladled from 0 to n - 1
    - given graph undirected edges {u, v, wt}
    - you are also given src, target and k
    - a threshold value determine wether edge is connected light or heavy
    - an edge is light if it's weight less than or equal to threshold,
    - heavy if weight is grater than the threshold.
    - path from src to tareget is valid if it contains at most k heavy edges.
    - return the minium integer threshold, such that atleast one valid path exist from src to target. if no such path exist return -1.

    // ApproacH:
        - we will have to find the path from src to destinations:
            - we can take at-most 'k' heavy wt
            - While finding the path, we will have to make sure that we can only go with k heavy weights.
            - heavy weights are defined as the edge weight that is grater than the threshold value.
            - we will have to find the minimum threshold value for which we can find the path.
        -Few things we will have to check:
            - if(src == dst) return 0;  -> self reachable.
            - we will have to check the reachability of the destinations from src regardless of the threshold value.
            - Once these two checks are done, we can process finding the minimum threshold value.
            - Threshold value range:
                given constrains: 
                    1 <= edgeWt <= 1e9

                        |---|---|---|-----------------------|
                        1   2   3   ..                     1e9

                Or Precisely we can write:

                        |---|---|---|-----------------------|
                        1   2   3   ..                  "maxWt"

                                                        maxWt = maximum weight from all the edges.
                
                - But this can go up till 1e9 in worse, so we can't check it linearly.
                - we can use binary search to find the threshold value.
                - Suppose we have some solve() function which finds wether we will have any path with given solve(src, dst, threshold, k):
                    - if this function returns true, then we can try looking for minimum values.
                    - else false: try looking for maximum values.

                    high = max({wt1, wt2, wt3,... })
                    low = 1

                    while(low <= high) {
                        mid = low + (high - low)/2;

                        if(solve(src, dst, mid, k)) {
                            ans = mid;
                            high = mid - 1; // try looking smaller value.
                        } else {
                            low = mid + 1;  // try looking maximum value.
                        }
                    }

                    return ans;

                - This is our driver code, it takes complexity:
                    (logE * n) => E = maxEdge wt, n = total nodes
                        (1 <= n <= 1e3)
                - So, this solution is acceptable.

        - Now, we only need to write the solve() function which finds the reachability of src to dst with k edge-wt exceeding threshold.

            - Writing the simple DFS:
                    bool solve(src, dst, thr, k, vis, adj) {
                        if(src == dst) return true; // find destination.
                        vis[src] = 1;

                        for(auto &[v, wt]: adj[src]) {
                            // If node is not yet explored:
                            if(!vis[v]) {
                                // If it's light weights
                                if(wt <= thr) {
                                    if(dfs(v, dst, thr, k, vis, adj)) return true;
                                } else (k > 0) {    // if edge weight excess threshold value, check do we have any k left? 
                                    if(dfs(v, dst, thr, k - 1, vis, adj)) return true;
                                }
                            }
                        }

                        vis[src] = 0;   // reverting it 0, so that with other possible path, we are able to visit the same node and explore...
                        return false;   // no valid path found.
                    }

                - This goes into TLE, as we are exploring all the possible paths.


            - We will try writing BFS:
                - BFS because it grows level-wise, and it will find the dst as early as possible, 
                - because we are not concern about the edgeWt to be calculated for moving cost, we only evaluates it's as we can take k edgeWt that are grater than the threshold, else if wt <= threshold, we can move freely...
                - So, throughout it's constant:
                    - means when "wt > threshold":
                        for K edge wt that are > threshold: we only decrement 1 from k.
                        or even in worse case let say, we have a path where all wt > threshold, then in that case also, everytime we decrement 1 from k,
                        So, change factor is 1, and throughout it's constant.

                    - And for the other case, when wt <= threshold:
                        We move on the next node without concerning about the cost..
                        we can not decrementing anything..
                        So, throughout it's constant.

                - This is why BFS will work for our solution.
                - Note: Plain BFS Fails, because:
                    - we will have to check the all possible path, and In plain when used to maintain "visted", and explore the path from src to dsc, then it might be possible that we can have some cases like:

                        src = 1, dst = 5
                        k = 1
                        thr = 5

                                 [2]-------10---------[3] 
                               2/                       \2
                               /                         \
                        src [1]                          [4]-----10-----[5]dst
                               \                         /
                              2 \                       /3
                                [6]---3----[7]----2---[8]

                    Possible path:

                        Path A: 1 ----> 2 --------> 3 -------> 4 ------> 5

                        Path B: 1 ----> 6 --------> 7 --------> 8 ------> 4 --------> 5
                    
                    - We know BFS grows level wise:

                                    Y        Y-k-1       Y          N
                        Path A: 1 ----> 2 --------> 3 -------> 4 ------> 5

                                    Y        Y          Y           N         N
                        Path B: 1 ----> 6 --------> 7 --------> 8 ------> 4 --------> 5 

                        Path A used k on edge "2---4", and k = 0, In future Path A can't cross, edge "4----5", and we won't find any path.
                        But we can see, we have a path B that can gives us a path, but it won't because
                        Path A, early visit node "4", and mark it as visited, so the path B fails at crossing at node "8----4"


                - We will write BFS with little modification.
                    - We will use Best move vector, instead of visited, while will gives us the minimum k-used to reach that node.
                    - best move is nothing but the distance that we used to maintain in dijkstra's, while finding the shortest path.
                        - In dijkstra's we used dist(n, INT_MAX), and while exploring and evaluating moving cost, we only stores the new cost which is lesser than the previous explored.
                    - So, we will use simillar approach here.
                    - Maintain Best(n, INT_MAX), as minimum k-used to reach that node.
                    - Now, we process BFS:
                        src----------------dst
                    - and this time we are not checking the visited, we are evaluating the previous visit that node with total k-used.
                    - we will always make sure that we will store the minimum possible 'k' for every node..
                    - this way we can find the path that leads us to destinations, if we have sufficient 'k'.

                    // Process BFS:
                        For each call: we have {node, currCost}
                        And, while exploring the neighbors:
                            for(auto &[v, wt]: adj[node]) {
                                // Two conditions:
                                if(wt <= thr) { // Valid to move:
                                    // check the previous best to reach this node:
                                    if(currCost < best[v]) {    // the current cost is lesser than the previous explored:
                                        q.push({currCost, v});
                                        best[v] = currCost;
                                    }
                                } else {
                                    // To move we will require 1-cost to be decremented from k(OR other way around, as we started with cost = 0, we can say "currCost + 1 <= k")
                                    // And also check the previous cost to reach this node:
                                    if(currCost + 1 <= k && currCost + 1 < best[v]) {
                                        best[v] = currCost + 1;
                                        q.push({v, currCost + 1});
                                    }
                                    // This way we can use our 'k' wts that are > threshold, and also, making sure that we will use least amount of 'k', as possible.
                                }
                            }
                    
                TC: O(E + ((V + E) * logW)) = O((V + E)logW)
                SC: O(V + E)
                    - V = nodes
                    - E = edges

                
            - We can Also solve this using Dijkstra's.
                - It's just we will use priority queue instead of queue.
                - and we will take considaction factor as cost : <cost, node>
                - But this will increase complexity, as insertion takes LogV
                    - and dijkstra's takes: O(ElogV)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// BFS + BS: Accepted.
class Solution {
private:
    bool solve(int src, int dst, int thr, int k, vector<vector<pair<int, int>>>& adj, int n) {

        vector<int> best(n, INT_MAX);   // best will minimize the options to move OR best path to reach a node with minimum 'k' used.
        queue<pair<int, int>> q;
        
        q.push({src, 0});
        best[src] = 0;

        while(!q.empty()) {
            int size = q.size();
            
            while(size--) {
                auto [node, cost] = q.front();
                q.pop();

                // reached destinations
                if(node == dst) return true;    

                // Explore adj-neighbors:
                for(auto &[v, wt]: adj[node]) {
                    // We have Two Conditions:
                    if(wt <= thr) { // we can go
                        if(cost < best[v]) {
                            best[v] = cost;
                            q.push({v, cost});
                        }
                    } else { // We can't go:
                        int reqMove = cost + 1;  // we required 1 heavy to to move
                        // Check do we have any option left to move in 'k' && also wether it's best?
                        if(reqMove <= k && reqMove < best[v]) {
                            best[v] = reqMove;
                            q.push({v, reqMove});
                        }
                    }
                }
            }
        }

        return false;   // can't reach to destinations.
    }
public:
    int minimumThreshold(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        
        // Build Graph adj list:
        vector<vector<pair<int, int>>> adj(n);
        int low = 0;
        int high = 1;
        for(auto &i: edges) {   // O(E)
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
            high = max(high, i[2]);
        }

        // Check reachability with '0' threshold value:
        if(!solve(src, dst, high, k, adj, n)) return -1;  // dst not reachable.
        if(src == dst) return 0;                    // src and dst is same, reach with '0' threshold.


        // Process Binary search to find the minimum threshold value:
        int ans = 0;
        while(low <= high) {    // O(logW * (V + E))
            int mid = low + (high - low)/2;

            // Explore:
            if(solve(src, dst, mid, k, adj, n)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};

// DFS + BS: TLE
class Solution_ {
private:
    bool solve(int src, int dst, int thr, int k, vector<vector<pair<int, int>>>& adj, vector<int>& vis) {
        vis[src] = 1;
        if(src == dst) return true;
        
        if(src == dst) return true;
        for(auto &[v, wt]: adj[src]) {
            if(!vis[v]) {
                if(wt <= thr) {
                    if(solve(v, dst, thr, k, adj, vis)) return true;
                } else if(k > 0){
                    if(solve(v, dst, thr, k - 1, adj, vis)) return true;
                }
            }
        }

        vis[src] = 0;   // while going back to path, mark it unvisited.
        return false;   // not visited.
    };
public:
    int minimumThreshold(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        
        // Build Graph adj list:
        vector<vector<pair<int, int>>> adj(n);
        int low = 0;
        int high = 1;
        for(auto &i: edges) {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
            high = max(high, i[2]);
        }

        // Check reachability with '0' threshold value:
        vector<int> vis(n, 0);
        if(!solve(src, dst, high, k, adj, vis)) return -1;  // dst not reachable.
        if(src == dst) return 0;                    // src and dst is same, reach with '0' threshold.


        // Process Binary search to find the minimum threshold value:
        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low)/2;

            // Explore:
            vector<int> vis1(n, 0);
            if(solve(src, dst, mid, k, adj, vis1)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};