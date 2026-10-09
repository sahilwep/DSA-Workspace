/*

//  841. Keys and Rooms



//  Problem Statement: 
    - There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.
    - When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.
    - Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.

 
// Example:
    Example 1:
        Input: rooms = [[1],[2],[3],[]]
        Output: true
        Explanation: 
        We visit room 0 and pick up key 1.
        We then visit room 1 and pick up key 2.
        We then visit room 2 and pick up key 3.
        We then visit room 3.
        Since we were able to visit every room, we return true.

    Example 2:
        Input: rooms = [[1,3],[3,0,1],[2],[0]]
        Output: false
        Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.

 

// Constraints:
    n == rooms.length
    2 <= n <= 1000
    0 <= rooms[i].length <= 1000
    1 <= sum(rooms[i].length) <= 3000
    0 <= rooms[i][j] < n
    All the values of rooms[i] are unique.


// Observations:
    - Given rooms: 
        - rooms the keys for next rooms
    - room '0' is only open..
        - we will start from here.
        - and as we collect keys, we will explore other rooms.
    - we will have to find wether we can open all the rooms or not?


    // BFS/DFS Approach:
        - Start from node '0':
            - explore adj_neighbors:
                - as explore mark their nodes as visited.

        - last check which node are visited and which are not yet?

        // Complexity:
            - TC: O(n)
            - SC: O(n)

    // DSU Approach:
        - I'm curious, as can it be solved using DSU?
            - as if we connect those rooms and their adj_neighbors, and connect them..
                - last if we check the size of node '0': if it's equal to total number of room then we can say all path is visited..
        - This Doesn't work, because to go into certain room, you will require key, and DSU only connect node_and adjacent_node, but if we don't have key, how we can connect them?


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// BFS/DFS Approach:
class Solution {
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for(auto &i: adj[node]) if(!vis[i]) dfs(i, adj, vis);
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<int> vis(n, 0);
        dfs(0, rooms, vis);
        
        for(auto &i: vis) if(i == 0) return false;
        return true;
    }
};