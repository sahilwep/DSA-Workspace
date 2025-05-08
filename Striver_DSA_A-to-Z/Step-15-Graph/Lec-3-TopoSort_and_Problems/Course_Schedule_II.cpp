/*

//  Course Schedule II

//  Problem Link: https://leetcode.com/problems/course-schedule-ii/description/

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        // Build Adj:
        vector<int> order;
        vector<vector<int>> adj(numCourses);
        vector<int> id(numCourses, 0);
        for(auto &course: prerequisites) {
            int u = course[1], v = course[0];
            adj[u].push_back(v);
            id[v]++;
        }

        // Process TopoSort:
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(!id[i]) q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            order.push_back(node);

            for(auto &it: adj[node]) {
                id[it]--;
                if(!id[it]) q.push(it);
            }
        }

        if(order.size() != numCourses) return {};
        return order;
    }
};