/*

//  3528. Unit Conversion I


//  Problem Statement: 
    -> There are n types of units indexed from 0 to n - 1. You are given a 2D integer array conversions of length n - 1, where conversions[i] = [sourceUnit[i], targetUnit[i], conversionFactor[i]. 
    -> This indicates that a single unit of type sourceUnit[i] is equivalent to conversionFactor[i] units of type targetUnit[i].
    -> Return an array baseUnitConversion of length n, where baseUnitConversion[i] is the number of units of type i equivalent to a single unit of type 0. 
    -> Since the answer may be large, return each baseUnitConversion[i] modulo 1e9 + 7.



// Example: 
    Example 1:
        Input: conversions = [[0,1,2],[1,2,3]]
        Output: [1,2,6]
        Explanation:
            Convert a single unit of type 0 into 2 units of type 1 using conversions[0].
            Convert a single unit of type 0 into 6 units of type 2 using conversions[0], then conversions[1].

    Example 2:
        Input: conversions = [[0,1,2],[0,2,3],[1,3,4],[1,4,5],[2,5,2],[4,6,3],[5,7,4]]
        Output: [1,2,3,8,10,6,30,24]
        Explanation:
            Convert a single unit of type 0 into 2 units of type 1 using conversions[0].
            Convert a single unit of type 0 into 3 units of type 2 using conversions[1].
            Convert a single unit of type 0 into 8 units of type 3 using conversions[0], then conversions[2].
            Convert a single unit of type 0 into 10 units of type 4 using conversions[0], then conversions[3].
            Convert a single unit of type 0 into 6 units of type 5 using conversions[1], then conversions[4].
            Convert a single unit of type 0 into 30 units of type 6 using conversions[0], conversions[3], then conversions[5].
            Convert a single unit of type 0 into 24 units of type 7 using conversions[1], conversions[4], then conversions[6].

            


// Observations: 
    -> given n types of unit indexed from 0 to n-1.
    -> given 2D conversion: {srcUnit, dstUnit, ConversionFactor}
    -> return an array baselineConversion for each nodes: 
    -> return answer in mod 1e9 + 7


        Input: conversions = [[0,1,2],[0,2,3],[1,3,4],[1,4,5],[2,5,2],[4,6,3],[5,7,4]]
        Output: [1,2,3,8,10,6,30,24]

                      2         4
                [0]------>[1]------->[3]
                   \        \
                    \        \
                     \3       \5
                      \        \       3
                      [2]       [4]-------->[6]
                        \
                         \
                          \2
                           \        4
                            [5]----------->[7]


                    => {1,2,3,8,10,6,30,24}


        Input: [[0,3,4],[3,2,7],[2,1,12]]
        Output: [1,336,28,4]

                    4          7           12
                [0]------>[3]------->[2]-------->[1]

                    => {1,336,28,4}

    -> Every node we are traveling, we are multiplying the previous Computed result with current weight to it...

// BFS Approach: 
    -> multiply it by previous computed results...


// Complexity: 
    -> TC: O(V + E)
    -> SC: O(V + E)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private: 
    typedef long long ll;
    int mod = 1e9 + 7;
    typedef pair<ll, int> pr;
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        // Build Graph adj list: 
        int V = -1;
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto &it: conversions) {
            int u = it[0], v = it[1], wt = it[2];
            adj[u].push_back({v, wt});
            V = max(V, max(u, v));
        }

        // Process BFS & find answer for every weights:
        queue<pr> q;
        vector<int> ans(V + 1, 1);

        q.push({1, 0}); // push starting node with their conversions factor.
        ans[0] = 1;

        while(!q.empty()) {
            auto [lvl, node] = q.front();
            q.pop();

            ans[node] = (int)lvl;
            
            for(auto &[v, wt]: adj[node]) {
                ll newConv = (wt * lvl) % mod;
                q.push({newConv, v});
            }
        }

        return ans;
    }
};