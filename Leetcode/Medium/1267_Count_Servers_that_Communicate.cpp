/*

//  1267. Count Servers that Communicate


//  Problem Statement: 
    -> You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. 
    -> Two servers are said to communicate if they are on the same row or on the same column.
    -> Return the number of servers that communicate with any other server.



// Example: 

    Example 1:
        Input: grid = [[1,0],[0,1]]
        Output: 0
        Explanation: No servers can communicate with others.

    Example 2:
        Input: grid = [[1,0],[1,1]]
        Output: 3
        Explanation: All three servers can communicate with at least one other server.

    Example 3:
        Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
        Output: 4
        Explanation: The two servers in the first row can communicate with each other. The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.



// BruteForce Solution: 
    -> For Every server we will check in row or column, if we found any server, then it can communicate...
    -> note we will not include the server itself on that row where we are at right now, we will only increase that count, when we will encounter with any server...
    -> Also, We are given OR, condition, means if we found any server in that row itself, no need to traverse for col, & if we won't find in that row, then only we will traverse for col finding.
    -> Accepted

    // Complexity:
        -> TC: O(n * m * (n + m))
        -> SC: O(1)


// Efficient Solution:
    -> If we preprocess somehow, the number of servers occurring in every row, & numbers of severs occurring in every column.
    -> Our job will be very easy to find the servers occurring in that row or col, with Complexity of O(1)
    -> Then overall time complexity will be drop to only O(n * m)
    -> Accepted with 100%
   
    // Complexity: 
        -> TC: O(n * m)
        -> SC: O(n * m)




// Extra: Queue Based Solution:
    -> When i saw this question, i initially try to solve this by using bfs, but, for that also i were have to store every servers into queue first & then process one by one...
    -> Then, i have to modify the bfs in a way so that, it can go on that whole row direction & that whole col directions, & then get the desired answer...
    -> this work's fine, & accepted with 100%
    // Complexity:
        -> TC : O(n * m + (n + m) * number_of_servers)
        -> SC : O(number_of_servers)
            // Explore Complexity More: 
                -> SC: O(n * m), in worse case all the cells has servers.
                -> TC: O(n * m * (n + m)) Overall, because:
                    -> Let's break down:
                        -> First we store every servers into queue, which takes: O(n * m)
                        -> Now for every server, we are traversing, O(n) || O(m) times, & in worse case O(n + m) times.
                        -> number_of_servers can be at most n * m. Therefore, the worst-case time complexity can be simplified to O(n * m).
                        -> So, overall O(n * m * (n + m))



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient SolutioN: O(n*m)
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Preprocess the matrix servers locations:
        vector<int> indexRowCount(n, 0);
        vector<int> indexColCount(m, 0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){    // if grid has servers: increment row & col count.
                    indexRowCount[i] += 1;
                    indexColCount[j] += 1;
                }
            }
        }

        // Now check for every row & col when we have 
        int totalServers = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){    // for every servers:
                    if(indexRowCount[i] > 1 || indexColCount[j] > 1){   // there is more than 1 server in that row or col: increment total servers.
                        totalServers++;
                    }
                }
            }
        }

        return totalServers;
    }
};


// Queue Based Solution:
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){    // if grid has servers: increment row & col count.
                    q.push({i, j}); // push that into queue:
                }
            }
        }


        // Now check for every row & col when we have 
        int totalServer = 0;
        
        while(!q.empty()){
            auto [i, j] = q.front();    // get every servers
            q.pop();

            // Now check for any row or any col has server or not?
            bool canCommunicate = false;
            // Check row:
            for(int row = 0; row < n; row++){
                if(grid[row][j] == 1 && row != i){  // if we found any server, & it's not itself.
                    canCommunicate = true;
                    break;
                }
            }
            if(canCommunicate){ // if it can communicate in row onlY:
                totalServer++;  // increment servers count.
            }
            else{  // else if won't able to made any connection in that row:
                // Check in col: & same steps as above.
                for(int col = 0; col < m; col++){
                    if(grid[i][col] == 1 && col != j){
                        canCommunicate = true;
                        break;
                    }
                }
                if(canCommunicate){
                    totalServer++;
                }
            }
        }


        return totalServer;
    }
};


// BruteForce Solution: O(n * m * (n + m))
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Now check for every row & col when we have 
        int totalServer = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){    // for every servers:
                    // We have to check whether in that whole row || whole column, if there were any server, then it can communicate with it.
                    bool canCommunicate = false;
                    for(int col = 0; col < m; col++){ // searching in that whole col:
                        if(grid[i][col] == 1 && col != j){  // checking servers, except itself
                            canCommunicate = true;
                        }
                    }
                    // Check if it communicate or not?
                    if(canCommunicate){ // if that can communicate
                        totalServer++;  // increment that count for itself.
                    }else{  // if that can cannot communicate, then only check for column:
                        for(int row = 0; row < n; row++){
                            if(grid[row][j] == 1 && row != i){
                                canCommunicate = true;
                            }
                        }
                        if(canCommunicate){ // if it can communicate in that particular row:
                            totalServer++;  // increment the server count.
                        }
                    }
                }
            }
        }

        return totalServer;
    }
};