/*

//  G-39. Minimum Multiplications to Reach End

//  Problem Statement: 



// Observation: 
    -> we are given starting value
    -> we are given destination value.
    -> At every step we can multiply with any number of array input value.
    -> We need to find how many steps were taken to reach destination value.
    -> Looks like graph type:
        -> At every steps we will try to multiply with all the values & get the minimum steps required to reach destination value.

        //  Key Observation: 
            -> Why mod every-time ?
            -> For any smaller number, if we take mod with 10^5, it will always be that number..
            -> if number exceed that mod value, then it gets roundup.
            -> We are independent to multiply with same number as many time as we want.
            -> It's just we need to minimize the number of steps.
            -> Also: 
                if we carefully observe, we were checking the multiplication number in mod-list of 10^5.
                -> This is nothing, but it's nodes from 0 to 100000
                -> In simple, we are checking the nodes...

        
        -> We can take help that mod-value, to keep track what values we have multiplied earlier...
        -> We will use queue to solve this problem, because everytime we are growing level-wise, & increment is constant throughout, until source not reaches to destination.
        -> We will use Simple BFS, with queue, which will makes our job done.

        // Approach 1:
            -> Simple Plain BFS..

        // Approach 2:
            -> We will similar approach, but with some change, of maintaining the distance of every node.
            -> Every time new node will form by previous node * edge distance to reach new node.


// Complexity:
    -> TC: O(10000 * n)
    -> TC: O(mod)

*/


#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define mod 100000


// Approach 2:
class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int n = arr.size();
        
        if(start == end) return 0;  // case when start & ends are same, return '0' steps taken.
        
        queue<pair<int, int>> q;
        vector<int> dist(mod, INT_MAX);   // initialize distance array with INT_MAX value of size given mod, because at max we have 100000 nodes.
        
        q.push({start, 0}); // push starting node & steps as '0' into queue.
        dist[start] = 0;    // mark source distance as '0'
        
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int node = it.first;
            int steps = it.second;
            
            // Check a ll possible multiplication value:
            for(auto &i: arr){
                int newNode = (i * node)  % mod;
            
                if(steps + 1 < dist[newNode]){
                    dist[newNode] = steps + 1;  // update new distance.
                    
                    if(newNode == end) return steps + 1; // Check, if we are at destination & return steps   
                    
                    q.push({newNode, steps + 1});
                }
            }
        }

        return -1;
    }
};


// Approach 1:
class Solution_ {
private:
    typedef pair<int, int> ppr;
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int n = arr.size();
        
        if(start == end) return 0;  // case when start & ends are same, return '0' steps taken.
        

        queue<pair<int, int>> q;   // using queue, Structure: <steps, nodes>
        vector<int> vis(mod, false);
        
        q.push({0, start});    // push initial steps & starting node into queue.
        vis[start] = true;      // mark that starting node as visited.
        
        
        while(!q.empty()){
            // auto it = pq.top();
            auto it = q.front();
            q.pop();
            
            int step = it.first;
            int value = it.second;
            
            // Check all possible multiplication value:
            for(auto &i: arr){
                int val = (i * value)  % mod;   // get the new multiplied value
            
                if(val == end){ // checking if new value is equal to the end
                    return step + 1;    // return steps directly.
                }
                                
                if(!vis[val]){  // else if new value is not yet visited:
                    vis[val] = true;    // mark as visited
                    q.push({step + 1, val});   // and push it into queue.
                }
            }
        }

        return -1;
    }
};
