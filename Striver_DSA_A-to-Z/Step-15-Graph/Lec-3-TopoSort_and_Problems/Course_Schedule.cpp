/*

//  Course Schedule

//  Problem Link: https://leetcode.com/problems/course-schedule/description/

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        vector<int> id(numCourses, 0);
        for(auto &course: prerequisites) {
            int u = course[1], v = course[0];
            adj[u].push_back(v);
            id[v]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(!id[i]) q.push(i);
        }

        int cnt = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            cnt++;

            for(auto &it: adj[node]) {
                id[it]--;
                if(!id[it]) q.push(it);
            }
        }

        return (cnt == numCourses) ? true : false;
    }
};