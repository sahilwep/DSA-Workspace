/*

//  G-37. Path With Minimum Effort

//  Problem Statement: 
You are a hiker preparing for an upcoming hike. You are given heights[][], a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find the route with minimum effort.
Note: A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.



// Example: 
    Example 1:
        Input:
            row = 3
            columns = 3 
            heights = [[1,2,2],[3,8,2],[5,3,5]]
        Output: 2
        Explanation: The route 1->3->5->3->5 has a maximum absolute difference of 2 in consecutive cells. 
        his is better than the route 1->2->2->2->5, where the maximum absolute difference is 3.


    Example 2:
        Input:
            row = 2
            columns = 2 
            heights = [[7,7],[7,7]]
        Output: 0
        Explanation: Any route from the top-left cell to the bottom-right cell has a maximum absolute difference of 0 in consecutive cells.




// Observations: 

        Example: 

            [[1,2,2],
             [3,8,2],
             [5,3,5]]

                src = (0, 0), dest = (n-1, m-1)

                Now there can be many possible path:
                let's take one of them:
                    1 -> 2 -> 2 -> 2 -> 5
                     \  / \  / \  / \  /    -> Take absolute diff b/w all the heights:
                      1    0    0    3      -> '3' is the maximum effort taken in this particular path.

                
                let's take another one: 

                    1 -> 3 -> 8 -> 2 -> 5
                    \  / \  / \  /  \  /    -> Take absolute diff b/w all the heights:
                     2    5    6     3      -> '6' is the maximum effort taken in this path.
                    

                let's take one more: 
                    
                    1 -> 3 -> 5 -> 3 -> 5
                    \  / \  / \  /  \  /    -> Take absolute diff b/w all the heights:
                     2    2    2     2      -> '2' is the maximum effort taken in this path.
                    
                
                Now, there can be many possible path....
                We have to choose those path, which computes the minimum effort:
                among these three path, the minimum effort was '2', so we return '2'
                This is what we have to find.


        -> We are given source node
        -> We are given destinations node
        -> They have asked for the minimum effort.
        -> from these informations, we can apply Dijkstra's algorithm to find the minimum efforts.


// Approach:
    -> We will use Dijkstra's algorithms.
    -> we will use priority queue for that.
    -> Priority queue structure: <efforts< row, col >>
    -> source node effort will be '0', because there will be no effort to reach at source if we are at source, logical....


// Complexity: 
    -> TC: O(n * m * log(n * m))
    -> SC: O(n * m)


*/
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


class Solution {
private: 
    vector<vector<int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    // Directions from (0,0):   left     right    up      down
    typedef pair<int, pair<int, int>> ppr;
public:
    int MinimumEffort(int n, int m, vector<vector<int>> &heights) {
        
        vector<vector<int>> dis(n, vector<int> (m, INT_MAX));   // store the distance:
        priority_queue<ppr, vector<ppr>, greater<>> pq;
        pq.push({0, {0, 0}});       // insert source node & the the effort, which is abs(nodeA - nodeB) => Here we are taking '0' because we are subtracting (0, 0)current node from (0, 0)source node
        dis[0][0] = 0; // marking source node distance as '0'
        

        // Dijkstra's algo:
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            if(row == n-1 && col == m-1) return diff;   // return our answer, once we reach to end:
            
            
            // Traverse it's neighbors:
            for(int i=0;i<4;i++){
                int r_ = row + dir[i][0];
                int c_ = col + dir[i][1];
                
                // Check valid bound:
                if(r_ >=0 && r_ < n && c_ >= 0 && c_ < m){
                    
                    // Calculate new effort: abs diff b/w both the node heights, & previous difference taken, from both of them we will take maximum among them.
                    int newEffort = max(abs(heights[row][col] - heights[r_][c_]),  diff);   // we are taking max(), because we want maximum effort taken from every possible path.
                    
                    if(newEffort < dis[r_][c_]){    // if new effort is lesser than the previous computed result,
                        dis[r_][c_] = newEffort;    // update new distance.
                        
                        pq.push({newEffort, {r_, c_}}); // push that new effort & that node into priority queue.
                    }
                }
            }
        }
        
        return dis[n-1][m-1];
    }
};


int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}
