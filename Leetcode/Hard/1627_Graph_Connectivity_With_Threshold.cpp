/*

//  1627. Graph Connectivity With Threshold

//  Problem Statement: 
    -> We have n cities labeled from 1 to n. Two different cities with labels x and y are directly connected by a bidirectional road if and only if x and y share a common divisor strictly greater than some threshold. 
    -> More formally, cities with labels x and y have a road between them if there exists an integer z such that all of the following are true:
        -> x % z == 0,
        -> y % z == 0, and
        -> z > threshold.
    -> Given the two integers, n and threshold, and an array of queries, you must determine for each queries[i] = [ai, bi] if cities ai and bi are connected directly or indirectly. (i.e. there is some path between them).
    -> Return an array answer, where answer.length == queries.length and answer[i] is true if for the ith query, there is a path between ai and bi, or answer[i] is false if there is no path.

 
// Example: 

    Example 1:

                    [1]     [2]     [3]
                                     |
                                     |
                    [4]     [5]     [6]

        Input: n = 6, threshold = 2, queries = [[1,4],[2,5],[3,6]]
        Output: [false,false,true]
        Explanation: 
            The divisors for each number:
                1:   1
                2:   1, 2
                3:   1, 3
                4:   1, 2, 4
                5:   1, 5
                6:   1, 2, 3, 6
            Using the underlined divisors above the threshold, only cities 3 and 6 share a common divisor, so they are the only ones directly connected. 
            The result of each query:
                [1,4]   1 is not connected to 4
                [2,5]   2 is not connected to 5
                [3,6]   3 is connected to 6 through path 3--6


        Example 2:

                    {Complete Graph Formations}

            Input: n = 6, threshold = 0, queries = [[4,5],[3,4],[3,2],[2,6],[1,3]]
            Output: [true,true,true,true,true]
                Explanation: The divisors for each number are the same as the previous example. However, since the threshold is 0,
                all divisors can be used. Since all numbers share 1 as a divisor, all cities are connected.

        Example 3:
                        [1]             [2]
                                         |
                        [3]             [4]
                                [5]

            Input: n = 5, threshold = 1, queries = [[4,5],[4,5],[3,2],[2,3],[3,4]]
            Output: [false,false,false,false,false]
                Explanation: Only cities 2 and 4 share a common divisor 2 which is strictly greater than the threshold 1, so they are the only ones directly connected.
                Please notice that there can be multiple queries for the same pair of nodes [x, y], and that the query [x, y] is equivalent to the query [y, x].


// DSU Solution:
    -> From the given graph, we have multiple query which we have to check wether the graph is connected is not?
    -> If graph is connected only by following the valid given constrains, then return ans[i] = true : else false
    -> DSU will help us to join the components & check efficiently wether given two nodes are connected or not, by following valid given constrins..

    // Find common Divisor from both the nodes (u, v), & should be greater than the given threshold point.

        [Way 1]:
            -> Write custom function to check the common divisor from both the number..
                bool isDivisorGrater(int u, int v, int thr) {   // find all the divisor
                    // For U:
                    unordered_set<int> st;  // set will help us to know about the common divisor from both the nodes
                    for(int i = thr + 1; i <= u; i++) { // start from threshold point, insted of starting at '1'
                        if(u % i == 0) {    // We are starting after threshold point, so we only need to check divisibility with nodes
                            st.insert(i);   // store all the divisor of u, that are above than the threshold points.
                        }
                    }
                    // Same for V:
                    for(int i = thr + 1; i <= v; i++) {
                        if(v % i == 0) {
                            if(st.count(i)) {   // find for common divisor
                                return true;    // found, return true.
                            }
                        }   
                    }

                    return false;   // not greater.
                }

            -> From the above function, we can find the common divisor for both the nodes, & check wether it should be greater than threshold or not?

        [Way 2]:
            -> If we observe carefully, in mathematical term, GCD(u, v) => Greatest common divisor
            -> GCD: 
                -> This will us greatest common divisor from both the number,
                -> IF GCD Value is greater than the threshold point => we can connect these two nodes.
                -> In simple,       if(GCD(u, b) > threshold) -> Connect that.


    // Instead of checking GCD for all (i, j) pairs which is expensive, we realize that:
        -> For any integer `i > threshold`, all multiples of `i` will have GCD ≥ i > threshold with `i`.
        -> Thus, we can iterate through each `i` from (threshold + 1) to n and union it with its multiples.
        -> This results in efficient component building using Disjoint Set Union (DSU).

    -> Now coming back, we only need to connect the component first & then we can check the query...
    

// Complexity: 
    -> TC: O(n * log(n))
    -> SC: O(Q)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// DSU Impl.
class DSU {
private: 
    vector<int> size, parent;
public: 
    DSU(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(parent[node] == node) return node;
        return parent[node] = ultPar(parent[node]);
    }
    void Union(int u, int v) {
        int ulp_u = ultPar(u);
        int ulp_v = ultPar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// Efficient Solution: Instead of checking all the nodes using nested loop, check only required nodes using multiples instead of GCD():
/*
    Instead of checking all (i, j) pairs and computing gcd(i, j), we reverse the logic:
        For each number i from threshold + 1 to n, we know that all multiples of i will have gcd(i, multiple) >= i > threshold. 
        So we can union i with all its multiples.
    This gives us the same result much faster, in ~O(n log n) time.

*/
class Solution {
public:
    vector<bool> areConnected(int n, int thr, vector<vector<int>>& queries) {

        // Initialize Disjoint Set Union (DSU) with size n + 1
        DSU ds(n + 1);
        vector<bool> ans;

        /*
         * Step 1: Union nodes based on the GCD condition.
         *
         * Instead of checking all pairs (i, j), which is too slow,
         * we iterate through numbers greater than the threshold.
         * 
         * For each number `i > threshold`, all its multiples (2*i, 3*i, ...) 
         * will have GCD(i, multiple) >= i > threshold. So we union them.
         *
         * This reduces time complexity to ~O(n log n).
         */

        if (thr == 0) {
            // Special case: if threshold is 0, then every pair with GCD >= 1 is valid.
            // So for every number i, union it with all its multiples.
            for (int i = 1; i <= n; ++i) {
                for (int j = 2 * i; j <= n; j += i) {
                    ds.Union(i, j);
                }
            }
        } else {
            // For threshold > 0, we only consider numbers greater than the threshold.
            for (int i = thr + 1; i <= n; ++i) {
                for (int j = 2 * i; j <= n; j += i) {
                    ds.Union(i, j);
                }
            }
        }

        //  Step 2: Answer the queries.
        for (auto &it : queries) {
            int u = it[0], v = it[1];
            ans.push_back(ds.ultPar(u) == ds.ultPar(v));
        }

        return ans;
    }
};




// Better Implementations: Directly checking the gcd()
class Solution {
private: 
public:
    vector<bool> areConnected(int n, int thr, vector<vector<int>>& queries) {

        // Build Answer from DSU:
        DSU ds(n + 1);
        vector<bool> ans;

        // Step 1: Build the graph and components:
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                // Check Valid given Constrains & join:
                if(gcd(i, j) > thr) {
                    ds.Union(i, j);
                }
            }
        }
        
        // Build Answer from DSU:
        for(auto &it: queries) {
            int u = it[0], v = it[1];
            if(ds.ultPar(u) == ds.ultPar(v)) {
                ans.push_back(1);
            } 
            else ans.push_back(0);
        }

        return ans;        
    }
};


// Naive Implementations: Checking common divisor manually
class Solution {
private: 
    bool isDivisorGrater(int u, int v, int thr) {   // find all the divisor
        // For U:
        unordered_set<int> st;
        for(int i = thr + 1; i <= u; i++) { // start from threshold point, insted of starting at '1'
            if(u % i == 0) {
                st.insert(i);   // store all the divisor of u, that are above than the threshold points.
            }
        }
        // for V:
        for(int i = thr + 1; i <= v; i++) {
            if(v % i == 0) {
                if(st.count(i)) {   // find for common divisor
                    return true;
                }
            }   
        }

        return false;   // not greater.
    }
public:
    vector<bool> areConnected(int n, int thr, vector<vector<int>>& queries) {
        
        // Step 1: Build the graph and components:
        DSU ds(n + 1);
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                // Check Valid given Constrains & join:
                if(isDivisorGrater(i, j, thr)) {
                    ds.Union(i, j);
                }
            }
        }
        
        // Build Answer from DSU:
        vector<bool> ans;
        for(auto &it: queries) {
            int u = it[0], v = it[1];
            if(ds.ultPar(u) == ds.ultPar(v)) ans.push_back(1);
            else ans.push_back(0);
        }

        return ans;        
    }
};



// Wrong Logic Implementations -> learning
class Solution {
private: 
public:
    vector<bool> areConnected(int n, int thr, vector<vector<int>>& queries) {

        // Build Answer from DSU:
        DSU ds(n + 1);
        vector<bool> ans;

        /*
            Learning:

            I was thinking about this approach, but the problem is we may missed the transitive dependency:
                This only considers direct connections between u and v in each query. 
                It does not union other nodes that might link u and v indirectly.
                So it misses transitive components entirely.

        */

        for(auto &it: queries) {
            int u = it[0], v = it[1];
            if(ds.ultPar(u) == ds.ultPar(v)) {  // yes connected
                ans.push_back(1);   
            } else {    // not connected
                // Check & connect: 
                if(gcd(u, v) > thr) {
                    ds.Union(u, v); // connect that.
                    ans.push_back(1);   // now connected for this query.
                }
                else {
                    ans.push_back(0);   // not in valid constrains...
                }
            }
        }

        return ans;        
    }
};