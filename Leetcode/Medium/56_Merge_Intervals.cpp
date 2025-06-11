/*

//  56. Merge Intervals


//  Problem Statement: 
    -> Given an array of intervals where intervals[i] = [start[i], end[i]], 
    -> merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 
// Example:
    Example 1:
        Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
        Output: [[1,6],[8,10],[15,18]]
        Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

    Example 2:
        Input: intervals = [[1,4],[4,5]]
        Output: [[1,5]]
        Explanation: Intervals [1,4] and [4,5] are considered overlapping.

    
// Observations: 


        X             Y
        |-------------|
        1             3
                |--------------------|
                2                    6
                                            |----------|
                                            8          10
                                                                |-------|
                                                                15      18


    -> By looking at the diagram view, we can simply build our logic without thinking much.


// Complexity:
    -> TC: O(N * logN)
    -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(begin(intervals), end(intervals));
        
        vector<vector<int>> ans;
        ans.push_back({intervals[0][0], intervals[0][1]});
        for(int i = 1; i < n; i++) {
            int currX = intervals[i][0];
            int currY = intervals[i][1];

            auto it = ans.back();
            int prevX = it[0];
            int prevY = it[1];

            // Now Compute Intervals check: 
            if(prevY >= currX) { // if Previous last pointer is grater or equal to current Starting pointer, Then we have to update last pushed value.
                // Update the prev interval values:
                int newX = min(prevX, currX);
                int newY = max(prevY, currY);
                ans.pop_back();
                ans.push_back({newX, newY});
            } 
            else {   // Insert new intervals
                ans.push_back({currX, currY});
            }
        }

        return ans;
    }
};