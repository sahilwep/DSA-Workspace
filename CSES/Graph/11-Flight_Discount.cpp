/*

//  CSES: Flight Discount

//  Problem Statement:
    -> Your task is to find a minimum-price flight route from Syrjälä to Metsälä. 
    -> You have one discount coupon, using which you can halve the price of any single flight during the route. 
    -> However, you can only use the coupon once.
    -> When you use the discount coupon for a flight whose price is x, its price becomes x/2 (it is rounded down to an integer).
    // Input
        -> The first input line has two integers n and m: the number of cities and flight connections. The cities are numbered 1,2,...,n. 
        -> City 1 is Syrjälä, and city n is Metsälä.
        -> After this there are m lines describing the flights. Each line has three integers a, b, and c: a flight begins at city a, ends at city b, and its price is c. Each flight is unidirectional.
        -> You can assume that it is always possible to get from Syrjälä to Metsälä.
    // Output: 
        -> Print one integer: the price of the cheapest route from Syrjälä to Metsälä.

// Constraints
    2 <= n <= 10^5
    1 <= m <= 2 * 10^5
    1 <= a,b <= n
    1 <= c <= 10^9

// Example
    Input:
        3 4
        1 2 3
        2 3 1
        1 3 7
        2 1 5

    Output:2


// Observations: 
    -> We are given n nodes 1 based indexing.
    -> We have m edges denoting: {u, v, wt} => Directed ones of course.
    -> We need to find the cheapest cost to reaching destinations 'n' with using one time coupon in any where in b/w the journey, wherever we feel that we will have maximum edge wt, we can simply half that weights.

    // Dijkstra's Solution: 
        -> First thing that comes in mind after listing "shortest path" is Dijkstra's solution: 
            -> Step 1: Find shortest distance from starting node to all the other nodes.
            -> Step 2: Find Shortest distance from Destinations node to all the other nodes.
            -> Now Compute Cheapest cost: 
                Cheapest cost {u, v} = (srcShortest[u] + wt/2 + dstShortest[v])
            -> This Intrusion is the optimal one to find the cheapest cost during the journey.
            
// Complexity: 
    -> TC: O(E + log(V))
    -> SC: O(V), at max we are storing the V size array

*/



#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


// -------------------------------- Accepted Code --------------------------------
class Solution {
private:
    typedef pair<ll, ll> pr;
    vector<ll> dijkstra(vector<vector<pair<ll, ll>>>& adj, int src, int &n) {    // dijkstra to find shortest distance from src to all the nodes.
        
        vector<ll> dist(n, LLONG_MAX);
        priority_queue<pr, vector<pr>, greater<>> pq;
        
        dist[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();
            
            if(dist[node] < cost) continue; // Improving dijkstra's to skip Costly iterations.
            
            // explore adj nodes: 
            for(auto &[v, wt]: adj[node]) {
                ll newCost = cost + wt;
                if(newCost < dist[v]) {
                    dist[v] = newCost;
                    pq.push({newCost, v});
                }
            }
        }
        
        return dist;
    }
public: 
    void solve(vector<vector<ll>>& edges, int& n, int& e,  vector<vector<pair<ll, ll>>>& adj,  vector<vector<pair<ll, ll>>>& adjRev) {
        
        // Process Dijkstra's
        vector<ll> fromSrc = dijkstra(adj, 0, n);       // shortest distance from source
        vector<ll> fromDst = dijkstra(adjRev, n-1, n);  // shortest distance from destination
        
        
        // Now compute the shortest cost: 
        ll minCost = LLONG_MAX;
        for(auto &it: edges) {
            ll u = it[0], v = it[1], wt = it[2];
            if(fromSrc[u] != LLONG_MAX && fromDst[v] != LLONG_MAX) {    // Check for LLONG_MAX to restrict code to go on integer flow after adding..
                ll currCost = fromSrc[u] + (wt/2) + fromDst[v]; // apply coupon at every possible edge & finding the cheapest cost.
                minCost = min(minCost, currCost);
            }
        }

        cout << minCost << endl;    // print the minimum cost
    }
};


// -------------------------------- Integer Overflow -------------------------------- 
class Solution {
private:
    typedef pair<ll, ll> pr;
    vector<ll> dijkstra(vector<vector<pair<ll, ll>>>& adj, int src, int &n) {    // dijkstra to find shortest distance from src to all the nodes.
        
        vector<ll> dist(n, LLONG_MAX);
        priority_queue<pr, vector<pr>, greater<>> pq;
        
        dist[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();
            
            if(dist[node] < cost) continue; // Improving dijkstra's to skip Costly iterations.
            
            // explore adj nodes: 
            for(auto &[v, wt]: adj[node]) {
                ll newCost = cost + wt;
                if(newCost < dist[v]) {
                    dist[v] = newCost;
                    pq.push({newCost, v});
                }
            }
        }
        
        return dist;
    }
public: 
    void solve(vector<vector<ll>>& edges, int& n, int& e,  vector<vector<pair<ll, ll>>>& adj,  vector<vector<pair<ll, ll>>>& adjRev) {
        
        // Process Dijkstra's
        vector<ll> fromSrc = dijkstra(adj, 0, n);       // shortest distance from source
        vector<ll> fromDst = dijkstra(adjRev, n-1, n);  // shortest distance from destination
        
        
        // Now compute the shortest cost: 
        ll minCost = LLONG_MAX;
        for(auto &it: edges) {
            ll u = it[0], v = it[1], wt = it[2];
            ll currCost = fromSrc[u] + (wt/2) + fromDst[v]; // apply coupon at every possible edge & finding the cheapest cost.
            minCost = min(minCost, currCost);
        }
 
        cout << minCost << endl;    // print the minimum cost
    }
};


// -------------------------------- TLE -------------------------------- 
// This Code gives TLE, due to poor written dijkstra's which is not very efficient for larger input.
class Solution {
private:
    typedef pair<ll, ll> pr;
    vector<ll> dijkstra(vector<vector<pair<ll, ll>>>& adj, int src, int n) {    // dijkstra to find shortest distance from src to all the nodes.
        
        vector<ll> dist(n, LLONG_MAX);
        priority_queue<pr, vector<pr>, greater<>> pq;
        
        dist[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();
            
            // explore adj nodes: 
            for(auto &[v, wt]: adj[node]) {
                ll newCost = cost + wt;
                if(newCost < dist[v]) {
                    dist[v] = newCost;
                    pq.push({newCost, v});
                }
            }
        }
        
        return dist;
    }
public: 
    void solve(vector<vector<ll>>& edges, int n, int e) {
        // Build adj list: 
        vector<vector<pair<ll, ll>>> adj(n);
        vector<vector<pair<ll, ll>>> adjRev(n);
        for(auto &it: edges) {
            adj[it[0]].push_back({it[1], it[2]});       // create adj list
            adjRev[it[1]].push_back({it[0], it[2]});    // create reversed adj list
        }
        
        // Process Dijkstra's
        vector<ll> fromSrc = dijkstra(adj, 0, n);       // shortest distance from source
        vector<ll> fromDst = dijkstra(adjRev, n-1, n);  // shortest distance from destination
        
        
        // Now compute the shortest cost: 
        ll minCost = LLONG_MAX;
        for(auto &it: edges) {
            ll u = it[0], v = it[1], wt = it[2];
            ll currCost = fromSrc[u] + (wt/2) + fromDst[v]; // apply coupon at every possible edge & finding the cheapest cost.
            minCost = min(minCost, currCost);
        }

        cout << minCost << endl;    // print the minimum cost
    }
};


int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<ll>> edges;
    vector<vector<pair<ll, ll>>> adj(n);
    vector<vector<pair<ll, ll>>> adjRev(n);
    for(int i = 0; i < e; i++) {
        ll u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u - 1, v - 1, wt});    // making 0-based index
        
        // Build adj list: 
        adj[u-1].push_back({v-1, wt});
        adjRev[v-1].push_back({u-1, wt});
    }

    Solution obj;
    obj.solve(edges, n, e, adj, adjRev);

    return 0;
}






/*
// ------------------------------------ EXTRA --------------------------------------------- 

    // NOTE: The Solution on Bottom is Wrong, This is just for learning mistake

    -> This solution is the initial one that comes into my mind.
    // My First Thought: 
        -> Question asked for cheapest cost we can travel the destinations.
            -> With only one time using coupon during the path: 
                (u_Src)------->....x----Coupon_Used---->y...------> (v_Dst)

            -> There are many edge weights, but x---->y has maximum among all, so we will use our coupon here.

        -> So, i thought of maintaining one "maximumEdgeWeightSoFar" which will used for coupon redemption..
        -> Whenever we got any maximum we avail our coupon & reset the previous applied coupon edge weight to original weight & recount the overl cheapest cost.
        -> This Approach looks correct, and for almost all the test-case it runs correctly, but it fails for few test cases:
        -> Problem in our approach, early redemptions of coupon, & cost to reach destinations may vary because of 

    // Example Test case: which violates my approach: 
        5 5
        1 2 20
        1 3 50
        2 4 20
        4 3 1
        3 5 100

*/


class Wrong_Solution {
private: 
    typedef pair<ll, pair<ll, ll>> prr;
public: 
    void solve(vector<vector<ll>>& edges, int n, int e) {
        // Build adj list: 
        vector<vector<pair<ll, ll>>> adj(n);
        for(auto &it: edges) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        // Process Dijkstra's
        vector<ll> dist(n, LLONG_MAX);
        priority_queue<prr, vector<prr>, greater<>> pq; // structure: <cost, <maximumVal, node>>

        // Push initial values: 
        pq.push({0, {0, 0}});   // {cost, {maxElement, node}}
        dist[0] = 0;            // source distance is '0'
        
        while(!pq.empty()) {
            auto [cost, vals] = pq.top();
            pq.pop();
            
            ll maxSoFar = vals.first;
            ll node = vals.second;
            
            if(node == n-1)  break;
            
            // Now explore adj nodes:
            for(auto &[v, wt]: adj[node]) {
                if(maxSoFar < wt) { // means we need to use coupon:
                    // first remove the used coupon from the previous: 
                    ll couponPrice = maxSoFar / 2;
                    ll withoutCouponPrice = maxSoFar;
                    ll CostWithoutCoupon = (cost - couponPrice + withoutCouponPrice);
                    // Now check if this cost & wt is less than the previous:
                    ll newCost = CostWithoutCoupon + ll(wt / 2); // get the new cost with applying coupon
                    // Check previous values: 
                    if(newCost < dist[v]) {
                        dist[v] = newCost;
                        pq.push({newCost, {wt, v}});    // push {newcost, {newMaxSoFor, node}}
                    }
                }
                else {
                    // if previous select edge wt' already grater: 
                    // check the final cost to reach this node if lesser than the overall previous assign:
                    ll newCost = cost + wt;
                    if(newCost < dist[v]) {
                        dist[v] = newCost;
                        pq.push({newCost, {maxSoFar, v}});
                    }
                }
            }
        }
    
        // return the cost to reach destinations: 
        cout << dist[n-1] << endl;
    }
};
