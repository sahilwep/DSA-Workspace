/*


//  3160. Find the Number of Distinct Colors Among the Balls


//  Problem Statement: 
    -> You are given an integer limit and a 2D array queries of size n x 2.
    -> There are limit + 1 balls with distinct labels in the range [0, limit]. Initially, all balls are uncolored. For every query in queries that is of the form [x, y], you mark ball x with the color y. After each query, you need to find the number of distinct colors among the balls.
    -> Return an array result of length n, where result[i] denotes the number of distinct colors after ith query.
    -> Note that when answering a query, lack of a color will not be considered as a color.


// Example:

    Example 1:

        Input: limit = 4, queries = [[1,4],[2,5],[1,3],[3,4]]
        Output: [1,2,2,3]
        Explanation:
            After query 0, ball 1 has color 4.
            After query 1, ball 1 has color 4, and ball 2 has color 5.
            After query 2, ball 1 has color 3, and ball 2 has color 5.
            After query 3, ball 1 has color 3, ball 2 has color 5, and ball 3 has color 4.

    Example 2:

        Input: limit = 4, queries = [[0,1],[1,2],[2,2],[3,4],[4,5]]
        Output: [1,2,2,3,4]
        Explanation:
            After query 0, ball 0 has color 1.
            After query 1, ball 0 has color 1, and ball 1 has color 2.
            After query 2, ball 0 has color 1, and balls 1 and 2 have color 2.
            After query 3, ball 0 has color 1, balls 1 and 2 have color 2, and ball 3 has color 4.
            After query 4, ball 0 has color 1, balls 1 and 2 have color 2, ball 3 has color 4, and ball 4 has color 5.


// Observation:
    -> We are given a set of balls and need to process a series of queries that either color a ball or change its color.
    -> The goal is to determine the number of distinct colors present after each query.
    

    // Approach:
        1. If a ball is colored for the first time, a new color is introduced.
        2. If a ball is recolored, we need to:
            -> Reduce the count of its previous color.
            -> Remove that color from tracking if its count becomes zero.
        3. We must track:
            -> The color assigned to each ball.
            -> The frequency of each color across all balls.


    // Optimizing Space Complexity (Avoiding MLE):
        -> A direct 'vector<int>' of size 'limit + 1' (up to '10^6') leads to Memory Limit Exceeded (MLE).
        -> Instead, we use two unordered_maps to efficiently track:
        -> 'colorCount': Maps each color to its frequency.
        -> 'ballColor': Maps each ball to its assigned color.

// Complexity Analysis:
    -> Time Complexity: 'O(n)' (Each query performs 'O(1)' operations using unordered_map)
    -> Space Complexity: 'O(n)' (Only stores relevant data, avoiding unnecessary memory usage)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Improved MLE
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int numQueries = queries.size();
        vector<int> result(numQueries);

        unordered_map<int, int> colorCount; // Tracks the frequency of each color
        unordered_map<int, int> ballColor;  // Maps each ball to its current color

        for (int i = 0; i < numQueries; i++) {
            int ballIndex = queries[i][0]; // Ball to be updated
            int newColor = queries[i][1];  // New color for the ball

            // If the ball was previously colored, update the frequency of its previous color
            if (ballColor.count(ballIndex)) { 
                int previousColor = ballColor[ballIndex]; 
                colorCount[previousColor]--;

                // If a color is no longer present on any ball, remove it from tracking
                if (colorCount[previousColor] == 0) {
                    colorCount.erase(previousColor);
                }
            }

            // Assign the new color to the ball
            ballColor[ballIndex] = newColor;
            colorCount[newColor]++; // Update the count for the new color

            // Store the number of distinct colors in the result
            result[i] = colorCount.size();
        }

        return result;
    }
};

// Better Approach: Using map -> MLE
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int numQueries = queries.size();
        vector<int> result(numQueries);

        unordered_map<int, int> colorCount; // Tracks the frequency of each color
        vector<int> ballColor(limit + 1, -1); // Tracks the color assigned to each ball, initialized to -1 (no color)

        for (int i = 0; i < numQueries; i++) {
            int ballIndex = queries[i][0]; // Ball to be colored
            int newColor = queries[i][1];  // Color to be assigned

            // If the ball was already colored, remove its previous color count
            if (ballColor[ballIndex] != -1) { 
                int previousColor = ballColor[ballIndex]; 
                colorCount[previousColor]--;

                // If a color is no longer present, remove it from tracking
                if (colorCount[previousColor] == 0) {
                    colorCount.erase(previousColor);
                }
            }

            // Assign the new color to the ball
            ballColor[ballIndex] = newColor;
            colorCount[newColor]++; // Increment the count of the new color

            // Store the number of distinct colors in the result
            result[i] = colorCount.size();
        }

        return result;
    }
};
    


// BruteForce -> MLE
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();

        vector<int> balls(limit+1, -1);  // we will given -1 to Default Colour of all Balls.
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            int x = queries[i][0];  // ball
            int y = queries[i][1];  // color

            balls[x] = y;

            // Now look back in previous colors & get unique colors:
            set<int> st;
            for(int j = 0; j < limit + 1; j++) {
                if(balls[j] != -1) st.insert(balls[j]);
            }

            ans[i] = st.size();
        }

        return ans;
    }
};