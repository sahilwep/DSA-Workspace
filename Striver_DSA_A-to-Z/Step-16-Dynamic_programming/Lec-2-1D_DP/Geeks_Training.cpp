/*

//  Geek's Training


//  Problem Statement: 
    - Geek is going for a training program for n days. He can perform any of these activities: Running, Fighting, and Learning Practice. 
    - Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. 
    - Given a 2D array arr[][] of size n where arr[i][0], arr[i][1], and arr[i][2] represent the merit points for Running, Fighting, and Learning on the i-th day, determine the maximum total merit points Geek can achieve .


    Example:
        Input: arr[]= [[1, 2, 5], [3, 1, 1], [3, 3, 3]]
        Output: 11
        Explanation: Geek will learn a new move and earn 5 point then on second day he will do running and earn 3 point and on third day he will do fighting and earn 3 points so, maximum merit point will be 11.

        Input: arr[]= [[1, 1, 1], [2, 2, 2], [3, 3, 3]]
        Output: 6
        Explanation: Geek can perform any activity each day while adhering to the constraints, in order to maximize his total merit points as 6.

        Input: arr[]= [[4, 2, 6]]
        Output: 6
        Explanation: Geek will learn a new move to make his merit points as 6.


// Observations:
    - We can't the same index option on ith day:
        - If previously we have choosen some jth index on ith time
        - In current ith time, we can't choose jth index on current ith time.
            - Example: 
                          0    1  2     -> j
                    i:0  [{1}, 2, 5]
                    i:1  [3,   1, 1]

            At i:0, if we choose j = 0
            Then at i:1, we can't choose j = 0,
            though we can choose j = 1 || j == 2 at i:1

    - We need to return the maximum we can choose by following these given constrains..

    // Approach:
        - For idx, we need to maintain prevIdx which let us know about the previous index.
        - We can start looking into current idx options, making sure it's not prevIdx
        - Recursion will help us to explore all the possible solution:
        // Function Signature:
            - Our function will return int type answer which is the maximum we can choose..
            - we will be needed two parameter, idx & prevIdx
                int solve(idx, prevIdx) {
                    ...
                }
            
        // base case:
            - we can't go beyond the "n-1" idx for looking any answer.
            if(idx >= n) return 0;  // no further finding..

        // Decision Tree:
            - for every idx: 
                - we have '3' values: running:arr[idx][0], fighting:[idx][1], and learning:arr[idx][2]  
                - We will iterate in curr idx of array from (0 <= i <= 2)
                - for every call we need the maximumFinding, so initallsize that with INT_MIN as of now.

                    maxFinding = INT_MIN;
                    for(int i = 0; i < 3; i++) {
                        if(i != prevIdx) {  // make sure that we are not looking into same index.
                            maxFinding = max(
                                maxFinding,
                                nums[idx][i] + solve(idx + 1, i);       // add current & explore further, with making sure prevIdx changed to 'i'
                            );
                        }
                    }

        // Inital Call:
            - idx = 0
            - prevIdx = '-1'    // this works fine, but when we use memo-table we need to change that with something out-of-constrains valid value.
            - prevIdx = '3' -> This is safe & out of our range iterations range for array...
            - On controller logic:
                return solve(0, 3);     -> calling with prevIdx = 3, so that we can identify it's the first time..

        // Complexity:
            - TC: O(2^n)
                - for every call, we are exploring 2 branch, because prevIdx will restrict us to explore 1.
                - Only for the first call when preIdx = 3/-1, we will have 3 branches..
            - SC: O(n)
                - for recursion depth..

    // Memoization:
        - We are recomputing the same subproblem multiples times, which let's us to DP.
        - Variable values:
            0 <= idx <= n-1
            0 <= prevIdx <= 2
        - Create memo-table of size:
            vector<vector<int>> t(n + 1, vector<int> (4, 0));
            - created of size '4', just to handel the first time prevValue, which is '3'

    // Tabulations:
        - DP State:
            idx, prevIdx
        
        - DP Transitions;

            t[idx][prevIdx] = max({arr[idx][0] + t[idx + 1][0], arr[idx][1] + t[idx + 1][1], arr[idx][2] + t[idx + 1][2]})

            OR we can say:

            t[idx][prevIdx] =
                max over i ∈ {0,1,2}, i != prevIdx
                (arr[idx][i] + t[idx + 1][i])

        - Iterations Range: 
            n - 1 <= idx <= 0
            0 <= prevIdx <= 3
        
        - DP table size:
            t.resize(n + 1, vector<int> (4, 0));

        - Base case:
            t[n][*] = 0


    // Complexity:
        - TC: O(n)
        - SC: O(n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Tabulation:
class Solution {
private:
    int n;
    vector<vector<int>> t;
public:
    int maximumPoints(vector<vector<int>>& arr) {
        n = arr.size();
        
        t.resize(n + 1, vector<int> (4, 0));
        
        // base case: t[n][*] = 0   already.
        
        
        for(int idx = n - 1; idx >= 0; idx--) {
            for(int prevIdx = 0; prevIdx < 4; prevIdx++) {
                
                int maxFinding = INT_MIN;
                for(int i = 0; i < 3; i++) {
                    if(i != prevIdx) {
                        maxFinding = max(maxFinding, arr[idx][i] + t[idx + 1][i]);
                    }
                }
                
                t[idx][prevIdx] = maxFinding;
            }
        }


        //  prevIdx = 3, because on 0th day there's no previous index we have
        return t[0][3];   
    }
};

// Memoization:
class Solution {
private:
    int n;
    vector<vector<int>> t;
    int solve(int idx, int prevIdx, vector<vector<int>>& arr) {
        if(idx >= n) return 0;

        if(t[idx][prevIdx] != -1) {
            return t[idx][prevIdx];
        }
        
        // Decision Tree:
        int maxFinding = INT_MIN;
        for(int i = 0; i < 3; i++) {
            if(i != prevIdx) {
                maxFinding = max(maxFinding, arr[idx][i] + solve(idx + 1, i, arr));
            }
        }
        
        return t[idx][prevIdx] = maxFinding;
    }
public:
    int maximumPoints(vector<vector<int>>& arr) {
        n = arr.size();
        
        t.resize(n + 1, vector<int> (4, -1));
        
        return solve(0, 3, arr);
    }
};


// Recursion:

class Solution {
private:
    int n;
    int solve(int idx, int prevIdx, vector<vector<int>>& arr) {
        if(idx >= n) return 0;
        
        // Decision Tree:
        int maxFinding = INT_MIN;
        for(int i = 0; i < 3; i++) {
            if(i != prevIdx) {
                maxFinding = max(maxFinding, arr[idx][i] + solve(idx + 1, i, arr));
            }
        }
        
        return maxFinding;
    }
public:
    int maximumPoints(vector<vector<int>>& arr) {
        n = arr.size();
        
        return solve(0, 3, arr);
    }
};