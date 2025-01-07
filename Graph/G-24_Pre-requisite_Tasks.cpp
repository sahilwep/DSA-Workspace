/*

//  G-24. Pre-requisite Tasks


//  Problem Statement:
    -> There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
    -> Given the total number of tasks N and a list of P prerequisite pairs, find if it is possible to finish all tasks.



// Examples:
    Input: N = 4, P = 3, prerequisites = [[1,0],[2,1],[3,2]]
    Output: Yes
    Explanation: To do task 1 you should have completed task 0, and to do task 2 you should have finished task 1, and to do task 3 you should have finished task 2. So it is possible.

    Input: N = 2, P = 2, prerequisites = [[1,0],[0,1]]
    Output: No
    Explanation: To do task 1 you should have completed task 0, and to do task 0 you should have finished task 1. So it is impossible.




// Observation: 
    -> If we can co-relate it with Topological Sort
    -> In Topological sort, if there is a directed node u to v, then u must occur before v
    -> Also Topological sort only work with DAG -> Directed acyclic Graph

    // Now Corelate with question:
        -> Given numCourse = Number of nodes
                0 to n-1 => Total Nodes

        -> We are given a list of prerequisites: [[a[i], b[i]]]
                must take b[i] first if we want to take a[i]
                similarly, u = b[i] -> v = a[i]
                must take u -> v, must take u before v



    // Conclusion: 
        -> Build Graph
        -> Use Topo-sort
        -> Check weather it has cycle or not, if it has return false : else return true



// Complexity:
    -> TC: O(V + E)
    -> SC: O(V)




*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    bool isPossible(int V, int P, vector<pair<int, int> >& prerequisites) {
        // Generate Graph Nodes;
        vector<vector<int>> adj(V);
        for(auto it: prerequisites){
            adj[it.first].push_back(it.second);
        }

        // Topo sort:
        // Process Indegree
        vector<int> indegree(V, 0);
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0) q.push(i);
        } 

        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        // if cnt == V, means there is no-cycle & we have completed topo-sort, so return 1
        if(cnt == V) return 1;  // we have complete the course.
        return 0;   // else can't complete course.
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends