/*

//  3363. Find the Maximum Number of Fruits Collected


//  Problem Statement: 
    -> There is a game dungeon comprised of n x n rooms arranged in a grid.
    -> You are given a 2D array fruits of size n x n, where fruits[i][j] represents the number of fruits in the room (i, j). Three children will play in the game dungeon, with initial positions at the corner rooms (0, 0), (0, n - 1), and (n - 1, 0).
    -> The children will make exactly n - 1 moves according to the following rules to reach the room (n - 1, n - 1):
        -> The child starting from (0, 0) must move from their current room (i, j) to one of the rooms (i + 1, j + 1), (i + 1, j), and (i, j + 1) if the target room exists.
        -> The child starting from (0, n - 1) must move from their current room (i, j) to one of the rooms (i + 1, j - 1), (i + 1, j), and (i + 1, j + 1) if the target room exists.
        -> The child starting from (n - 1, 0) must move from their current room (i, j) to one of the rooms (i - 1, j + 1), (i, j + 1), and (i + 1, j + 1) if the target room exists.
    -> When a child enters a room, they will collect all the fruits there. If two or more children enter the same room, only one child will collect the fruits, and the room will be emptied after they leave.
    -> Return the maximum number of fruits the children can collect from the dungeon.

 
// Example: 
    Example 1:
        Input: fruits = [[1,2,3,4],[5,6,8,7],[9,10,11,12],[13,14,15,16]]
        Output: 100
        Explanation:
            In this example:
                The 1st child (green) moves on the path (0,0) -> (1,1) -> (2,2) -> (3, 3).
                The 2nd child (red) moves on the path (0,3) -> (1,2) -> (2,3) -> (3, 3).
                The 3rd child (blue) moves on the path (3,0) -> (3,1) -> (3,2) -> (3, 3).
            In total they collect 1 + 6 + 11 + 16 + 4 + 8 + 12 + 13 + 14 + 15 = 100 fruits.

    Example 2:
        Input: fruits = [[1,1],[1,1]]
        Output: 4
        Explanation:
            In this example:
                The 1st child moves on the path (0,0) -> (1,1).
                The 2nd child moves on the path (0,1) -> (1,1).
                The 3rd child moves on the path (1,0) -> (1,1).
            In total they collect 1 + 1 + 1 + 1 = 4 fruits.


// Observations: 

    -> Moves: 
        -> C1: can move only diagonally to collect maximum fruits because it has only "n - 1" moves
        -> C2: have only "n - 1" moves & can't cross the diagonal line from (0,0) to (n-1, n-1)
        -> C3: have only "n - 1" moves & can't cross the diagonal line from (0,0) to (n-1, n-1)
    -> We have options from every cell where to move
    -> Using these options we can in a way so that we can collect maximum fruit, recursion will help us to explore all possible options with 'n - 1' moves.

    -> Moves: 
            C1(i, j): {(i, j + 1), (i + 1, j + 1), (i + 1, j)}
              (0, 0)

                C1 ---- [x]
                |  \
                |    \
               [X]   [X]



            C2(i, j): {(i + 1, j - 1), (i + 1, j), (i + 1, j + 1)}
              (0, n - 1)

                  C2 
                /  |  \
               /   |    \
            [X]   [X]   [X]



            C3(i, j): {(i - 1, j + 1), (i, j + 1), (i + 1, j + 1)}
              (n-1, 0)

                       / [X]
                     /
                  C3 ----[X]
                     \
                       \ [X]
 

        // C1: 
            -> For C1, since it has only "n - 1" moves available, it can only move diagonally, to get maximum fruit.
            -> We can write a function which will collect fruit from grid[i][i]

        // C2: 
            -> Due to limited "n - 1" move, C2 can't cross diagonal line, because if it's cross, he will not be reach dst(n-1,n-1) with "n-1" moves
            -> It can't be move on "C3 Half"
            -> We can use Recursion to explore all the options of cell which we can move with the constrains it can't cross diagonal line.
            -> Blocked moves: 

                        0   1   2   3
                    0 | \ |   |   | C2|
                      -----------------
                    1 | X | \ |   |   |
                      -----------------
                    2 | X | X | \ |   |
                      -----------------
                    3 | X | X | X | \ |
                      -----------------

                    Restricted Cells: 
                                 i, j
                                (1, 0)
                                (2, 0)
                                (2, 1)
                                (3, 0)
                                (3, 1)
                                (3, 2)
                            Here, (i > j) every times, also (i == j), because Child 1 has already taken these fruits.
                            So, We we will not explore these cells:
                            => On Diagonal: {i == j} C1 has already taken.

                    Base Case:
                        if(i > j || i == j) => Return, no need to explore


                    Decision Tree: Explore These calls & collect maximum from all of them.
                        (i + 1, j - 1)
                        (i + 1, j)
                        (i + 1, j + 1)


        // C3: 
            -> C3 can explore Below the Diagonal line:

                        0   1   2   3
                    0 | \ | X | X | X |
                      -----------------
                    1 |   | \ | X | X |
                      -----------------
                    2 |   |   | \ | X |
                      -----------------
                    3 | C3|   |   | \ |
                      -----------------

                    Restricted Cells:
                                 i, j
                                (0, 1)
                                (0, 2)
                                (0, 3)
                                (1, 2)
                                (1, 3)
                                (2, 3)

                            Here, (j > i) every times, also, (i == j), because Child 1 has already taken these fruits.
                    
                    Base Case: 
                        if(j > i || i == j) => Return, no need to explore

                    Decision Tree: Explore these calls & collect maximum from all of them.
                            (i - 1, j + 1)
                            (i, j + 1)
                            (i + 1, j + 1)

        // Complexity: 
            -> TC: O(3^n)
            -> SC: O(n)

                        

// Memoization: 
    -> As we are finding the maximum optimal path to collect the fruits, several sub-path are re-computed.
    -> we can store the subproblems answer which are computed again-n-again.
    -> memoize the variable parameters, (i & j) are variable parameters.

    // Complexity: 
        -> TC: O(n * n)
        -> SC: O(n * n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Memoization:
class Solution {
private: 
    int n;  // dimensions of grid
    vector<vector<int>> t;
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < n);}   // Function to check valid bound:
    int child1Collection(vector<vector<int>>& fruits) {
        int ans = 0;
        for(int i = 0; i < n; i++) ans += fruits[i][i];
        return ans;
    }
    int child2Collection(int i, int j, vector<vector<int>>& fruits) {
        // Base Case:
        if(!isValid(i, j)) return 0;    // if i & j is not within valid bound return
        if(i == n - 1 && j == n - 1) return 0;   // return 0, because Child 1 has already collected "n - 1"
        if(i == j || i > j) return 0;   // restricted zone for child 2, This will make sure we can move with only "n - 1" moves.

        // Check in memo-table:
        if(t[i][j] != -1) return t[i][j];

        // Decision Tree: Movements
        int bottomLeft = fruits[i][j] + child2Collection(i + 1, j - 1, fruits);
        int bottomDown = fruits[i][j] + child2Collection(i + 1, j, fruits);
        int bottomRight = fruits[i][j] + child2Collection(i + 1, j + 1, fruits);

        return t[i][j] = max({bottomLeft, bottomDown, bottomRight});  // return the maximum collected in path.
    }
    int child3Collection(int i, int j, vector<vector<int>>& fruits) {
        // Base Case:
        if(!isValid(i, j)) return 0;    // if i & j is not within valid bound return
        if(i == n - 1 && j == n - 1) return 0;   // return 0, because Child 1 has already collected "n - 1"
        if(i == j || j > i) return 0;   // restricted zone for child 2, This will make sure we can move with only "n - 1" moves.

        // Check in memo-table:
        if(t[i][j] != -1) return t[i][j];

        // Decision Tree: Movements
        int top = fruits[i][j] + child3Collection(i - 1, j + 1, fruits);
        int right = fruits[i][j] + child3Collection(i, j + 1, fruits);
        int down = fruits[i][j] + child3Collection(i + 1, j + 1, fruits);

        return t[i][j] = max({top, right, down});  // return the maximum collected in path.
    }
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();

        t.resize(n + 1, vector<int> (n + 1, -1));   // Use memo-table to store the sub-problems 

        int c1 = child1Collection(fruits);
        int c2 = child2Collection(0, n - 1, fruits);
        int c3 = child3Collection(n - 1, 0, fruits);

        return c1 + c2 + c3;
    }
};



// Recursive Solution: 
class Solution {    // Version 1: checking the grid valid bound using "isValid()" function.
private: 
    int n;  // dimensions of grid
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < n);}   // Function to check valid bound:
    int child1Collection(vector<vector<int>>& fruits) {
        int ans = 0;
        for(int i = 0; i < n; i++) ans += fruits[i][i];
        return ans;
    }
    int child2Collection(int i, int j, vector<vector<int>>& fruits) {
        // Base Case:
        if(!isValid(i, j)) return 0;    // if i & j is not within valid bound return
        if(i == n - 1 && j == n - 1) return 0;   // return 0, because Child 1 has already collected "n - 1"
        if(i == j || i > j) return 0;   // restricted zone for child 2, This will make sure we can move with only "n - 1" moves.

        // Decision Tree: Movements
        int bottomLeft = fruits[i][j] + child2Collection(i + 1, j - 1, fruits);
        int bottomDown = fruits[i][j] + child2Collection(i + 1, j, fruits);
        int bottomRight = fruits[i][j] + child2Collection(i + 1, j + 1, fruits);

        return max({bottomLeft, bottomDown, bottomRight});  // return the maximum collected in path.
    }
    int child3Collection(int i, int j, vector<vector<int>>& fruits) {
        // Base Case:
        if(!isValid(i, j)) return 0;    // if i & j is not within valid bound return
        if(i == n - 1 && j == n - 1) return 0;   // return 0, because Child 1 has already collected "n - 1"
        if(i == j || j > i) return 0;   // restricted zone for child 2, This will make sure we can move with only "n - 1" moves.

        // Decision Tree: Movements
        int top = fruits[i][j] + child3Collection(i - 1, j + 1, fruits);
        int right = fruits[i][j] + child3Collection(i, j + 1, fruits);
        int down = fruits[i][j] + child3Collection(i + 1, j + 1, fruits);

        return max({top, right, down});  // return the maximum collected in path.
    }
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        
        int c1 = child1Collection(fruits);
        int c2 = child2Collection(0, n - 1, fruits);
        int c3 = child3Collection(n - 1, 0, fruits);

        return c1 + c2 + c3;
    }
};


class Solution {    // Version 2: Manually checking the grid valid bound
private: 
    int n;  // diminutions of grid
    int child1Collection(vector<vector<int>>& fruits) {
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += fruits[i][i];
            fruits[i][i] = 0;
        }
        return ans;
    }
    int child2Collection(int i, int j, vector<vector<int>>& fruits) {
        // Base Case:
        if(i >= n || j >= n || j < 0) return 0;    // check if i & j is within valid bound
        if(i == n - 1 && j == n - 1) return 0;   // return 0, because Child 1 has already collected "n - 1"
        if(i == j || i > j) return 0;   // restricted zone for child 2, This will make sure we can move with only "n - 1" moves.

        // Decision Tree: Movements
        int bottomLeft = fruits[i][j] + child2Collection(i + 1, j - 1, fruits);
        int bottomDown = fruits[i][j] + child2Collection(i + 1, j, fruits);
        int bottomRight = fruits[i][j] + child2Collection(i + 1, j + 1, fruits);

        return max({bottomLeft, bottomDown, bottomRight});  // return the maximum collected in path.
    }
    int child3Collection(int i, int j, vector<vector<int>>& fruits) {
        // Base Case:
        if(i >= n || j >= n || i < 0) return 0;    // check if i & j is within valid bound
        if(i == n - 1 && j == n - 1) return 0;   // return 0, because Child 1 has already collected "n - 1"
        if(i == j || j > i) return 0;   // restricted zone for child 2, This will make sure we can move with only "n - 1" moves.

        // Decision Tree: Movements
        int top = fruits[i][j] + child3Collection(i - 1, j + 1, fruits);
        int right = fruits[i][j] + child3Collection(i, j + 1, fruits);
        int down = fruits[i][j] + child3Collection(i + 1, j + 1, fruits);

        return max({top, right, down});  // return the maximum collected in path.
    }
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        
        int c1 = child1Collection(fruits);
        int c2 = child2Collection(0, n - 1, fruits);
        int c3 = child3Collection(n - 1, 0, fruits);

        return c1 + c2 + c3;
    }
};