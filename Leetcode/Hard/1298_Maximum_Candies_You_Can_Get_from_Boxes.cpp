/*

//  1298. Maximum Candies You Can Get from Boxes


//  Problem Statement: 
    -> You have n boxes labeled from 0 to n - 1. You are given four arrays: status, candies, keys, and containedBoxes where:
        -> status[i] is 1 if the ith box is open and 0 if the ith box is closed,
        -> candies[i] is the number of candies in the ith box,
        -> keys[i] is a list of the labels of the boxes you can open after opening the ith box.
        -> containedBoxes[i] is a list of the boxes you found inside the ith box.
    -> You are given an integer array initialBoxes that contains the labels of the boxes you initially have. You can take all the candies in any open box and you can use the keys in it to open new boxes and you also can use the boxes you find in it.
    -> Return the maximum number of candies you can get following the rules above.


// Example: 

    Example 1:
        Input: status = [1,0,1,0], candies = [7,5,4,100], keys = [[],[],[1],[]], containedBoxes = [[1,2],[3],[],[]], initialBoxes = [0]
        Output: 16
        Explanation: You will be initially given box 0. You will find 7 candies in it and boxes 1 and 2.
        Box 1 is closed and you do not have a key for it so you will open box 2. You will find 4 candies and a key to box 1 in box 2.
        In box 1, you will find 5 candies and box 3 but you will not find a key to box 3 so box 3 will remain closed.
        Total number of candies collected = 7 + 4 + 5 = 16 candy.

    Example 2:
        Input: status = [1,0,0,0,0,0], candies = [1,1,1,1,1,1], keys = [[1,2,3,4,5],[],[],[],[],[]], containedBoxes = [[1,2,3,4,5],[],[],[],[],[]], initialBoxes = [0]
        Output: 6
        Explanation: You have initially box 0. Opening it you can find boxes 1,2,3,4 and 5 and their keys.
        The total number of candies will be 6.


// Observations: 
    -> From the given problem, if we observe the example, Only things we have to consider is about the "containedBoxes" & "keys"
    -> Also boxes are inside some box
    -> There is a connectivity, means every other box which is being opened, they have some sort of relations..
    -> This gives us direct hints of dfs or bfs, which itself identify graph question
    -> We can use any BFS or DFS to solve this question
    -> It's just we have to take care of all the conditions..
    -> To open any box we need both: (keys & box)
    -> If any of them is not there, we can't open that box...
    
    // Solution: 
        -> Start with BFS
        -> Store the inital given boxes, with checking wether it's open or not?
        -> make sure to visit every box at only once.
        -> process every box with iterating in "ContainedBoxes" & "keys"
        -> With simple checking the visited & boxAvailability condition we can process every box...


// Complexity: 
    -> TC: O(n)
    -> SC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// BFS Solution: 
// More Cleaner Code: 
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        
        queue<int> q;
        vector<int> vis(n, 0);          // use to process every node only once..
        unordered_set<int> haveBox;     // use to maintain the list of box which are available
        int tCandy = 0;

        for(auto& box: initialBoxes) {
            haveBox.insert(box);    // include that box into our available list
            if(status[box] == 1) {  // if that box is unlocked, then only process that
                q.push(box);
                vis[box] = 1;
                tCandy += candies[box];
            }
        }

        while(!q.empty()) {
            int box = q.front();    // get every box
            q.pop();


            // Step 1: Explore "containedBoxes" for the current box:
            for(auto& bx: containedBoxes[box]) {
                haveBox.insert(bx);     // push that current box as available.

                // If current box is unlocked && not yet visited: means we can look for that box.
                if(status[bx] == 1 && !vis[bx]) {
                    q.push(bx);             // push that into queue
                    vis[bx] = 1;            // mark that box
                    tCandy += candies[bx];  // store that candy in our answer
                }
            }

            // Step 2: Explore in "keys" for the current box: 
            for(auto& key: keys[box]) {
                status[key] = 1;    // mark that box as unlocked
                
                // If the current key box is available in "haveBox" & not yet visited:  means we can look for that box..
                if(haveBox.count(key) && !vis[key]) {
                    q.push(key);            // push that into queue
                    vis[key] = 1;           // mark that box
                    tCandy += candies[key];  // store that candy in our answer
                }
            }
        }
        
        return tCandy;
    }
};

// Messy Implementations
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();

        unordered_set<int> boxSeen;    // used to maintain a list of box that we have seen so far..
        vector<int> vis(n, 0);

        queue<int> q;
        for(auto& box: initialBoxes) {
            boxSeen.insert(box);
            q.push(box);  
        }


        int tCandy = 0;
        while(!q.empty()) {
            int size = q.size();
            bool found = false;

            while(size--) {
                int box = q.front();
                q.pop();

                if(vis[box]) continue;  // box already processed:

                if(status[box] == 0) {
                    // still locked, wait until we don't have key:
                    q.push(box);
                    continue;
                }

                vis[box] = 1;   // mark that box as visited
                found = true;   // mark that box as true

                tCandy += candies[box];

                // explore in keys for this box: 
                for(auto& key: keys[box]) {
                    status[key] = 1;    // mark that status for that box as 1, as open.
                    if(boxSeen.count(key)) { // if we have that box already 
                        q.push(key);
                    }
                }

                // Now Explore the available boxes for this current box:
                for(auto& bx: containedBoxes[box]) {
                    boxSeen.insert(bx);  // store that box which we are processing..
                    q.push(bx); // push that box into the queue.
                }
            }
            if(!found) break;   // nothing new box open in this round..
        }
        
        return tCandy;
    }
};