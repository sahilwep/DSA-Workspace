/*

//  721. Accounts Merge


//  Problem Link: https://leetcode.com/problems/accounts-merge/description/



// Observations: 
    -> Given list of emails with names
    -> we need to find out the emails that resides to same person..
    -> return the list containing the unique person containing all the matched emails..

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class DSU {
private: 
    vector<int> parent, size;
public: 
    DSU (int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = ultPar(parent[node]); // path compression
    }
    void Union(int u_, int v_) {
        int u = ultPar(u_), v = ultPar(v_);
        if(u == v) return;  // already connected
        if(size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        // Build depended list: 
        unordered_map<string, int> mp;
        DSU ds(n);
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                // if email found in map:
                if(mp.count(email)) {
                    int v = mp[email];
                    ds.Union(i, v); // connect the component
                } else {
                    mp[email] = i;
                }
            }
        }

        // Build temp Answer list:
        vector<vector<string>> tempAns(n);
        for(auto &[key, val]: mp) {
            int node = ds.ultPar(val);
            tempAns[node].push_back(key);
        }

        // Build Final Answer:
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++) {
            // If we have some values:
            if(!tempAns[i].empty()) {
                sort(tempAns[i].begin(), tempAns[i].end());

                vector<string> temp;
                temp.push_back(accounts[i][0]);
                for(auto &email: tempAns[i]) {
                    temp.push_back(email);
                }

                ans.push_back(temp);
            }
        }

        return ans;
    }
};