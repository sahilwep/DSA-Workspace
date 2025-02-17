/*

//  CSES: Building Teams


//  Problem Statement: 
    -> There are n pupils in Uolevi's class, and m friendships between them. Your task is to divide the pupils into two teams in such a way that no two pupils in a team are friends. You can freely choose the sizes of the teams.


// Input
    -> The first input line has two integers n and m: the number of pupils and friendships. The pupils are numbered 1,2,\dots,n.
    -> Then, there are m lines describing the friendships. Each line has two integers a and b: pupils a and b are friends.
    -> Every friendship is between two different pupils. You can assume that there is at most one friendship between any two pupils.

// Output
    -> Print an example of how to build the teams. For each pupil, print "1" or "2" depending on to which team the pupil will be assigned. You can print any valid team.
    -> If there are no solutions, print "IMPOSSIBLE".


// Constraints
    1 <= n <= 10^5
    1 <= m <= 2 * 10^5
    1 <= a,b <= n


// Example
    Input:
        5 3
        1 2
        1 3
        4 5

    Output:
        1 2 2 1 2

// Observation:
    -> we are given n nodes 1 to 'n'
    -> there are total m edges.
    -> we need to divide them into two group, such that no two adjacent nodes are in same group.
    -> This question gives us the pattern of Bipartite Graph:
        -> No cycle should be present.
        -> Color nodes with 1 & 2

    -> Note, There should be multiple components in graph, so, we will have to color them saperately.
    -> IF we are able to divide these nodes into two group, then print the group of every number.
    -> else print "IMPOSSIBLE"

// Complexity:
    -> TC: O(V + 2E)
    -> SC: O(V)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef size_t s_t;  // use during string traversal
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define arrInp for(int i=0;i<n;i++) cin >> arr[i];
#define arrOut(k) for(int i=0;i<n;i++) cout << arr[i] <<  k;
#define el cout << endl;
#define SQ(a) (a)*(a);
#define mod 1000000007


class Solution {
private:
    bool bipartite(int node, int color, vector<vector<int>> &adj, vector<int> &group) {
        group[node] = color;
        
        // Explore adjacent nodes:
        for(auto &it: adj[node]) {
            if(group[it] == -1) {   // if it's unvisited:
                if(bipartite(it, !color, adj, group) == false) return false;
            }
            else if(group[it] == group[node]) {     // if adjacnt nodes colors are same, return false
                return false;
            }
        }
        
        return true;    // else return true
    }
public:
    void solve(vector<vector<int>> &adj) {
        int size = adj.size();
        
        vector<int> group(size, -1);
        bool isPossible = true;
        
        for(int i = 1; i < size; i++) {
            if(group[i] == -1) {
                if(bipartite(i, 0, adj, group) == false) {
                    isPossible = false;
                    break;
                }
            }
        }
        
        if(isPossible) {
            for(int i = 1; i < size; i++) cout << group[i] + 1 << " ";  // so that we can print group 1 & 2
            cout << endl;
        }else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
};



int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);    // creating (n + 1) size of graph list, because of 1 based indexing.
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solution obj;
    obj.solve(adj);

}