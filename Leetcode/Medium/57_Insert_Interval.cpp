/*

//  57. Insert Interval


//  Problem Statement: 
    -> You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
    -> Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
    -> Return intervals after the insertion.
    -> Note that you don't need to modify intervals in-place. You can make a new array and return it.

 
// Example: 
    Example 1:
        Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
        Output: [[1,5],[6,9]]

    Example 2:
        Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
        Output: [[1,2],[3,10],[12,16]]
        Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

 

// Observations: 
    -> We are given sorted intervals & one extra newInterval

    // BruteForce: 
        -> Insert that newIntervals into the given intervals list
        -> Sort them
        -> Perform mergeIntervals

    // Efficient: 
        -> We are given sorted list
        -> find the place where we can insert the newInterval to given intervals
        -> Then insert that & build answer.

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient: 
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();

        vector<vector<int>> ans;
        int i = 0; 

        // Case 1: No overlapping case before the merge intervals:
        // Compare ending point of intervals to starting point of newInterval
        while(i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }

        // Case 2: Overlapping case, and merged of intervals:
        // Compare ending point of newIntervals to starting point of intervals
        while(i < n && newInterval[1] >= intervals[i][0]) {
            // Update newInterval with maximum value by comparing current intervals:
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);  
            i++;
        }

        ans.push_back(newInterval); // Finally push the newInterval range

        // Case 3: No overlapping of intervals after newIntervals being merge:
        while(i < n) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};

// BruteForce: 
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> temp(begin(intervals), end(intervals));
        temp.push_back({newInterval[0], newInterval[1]});

        sort(begin(temp), end(temp));

        // Perform Merge Intervals:
        vector<vector<int>> ans;
        ans.push_back({temp[0][0], temp[0][1]});
        int tSize = temp.size();
        for(int i = 1; i < tSize; i++) {
            int currX = temp[i][0];
            int currY = temp[i][1];

            auto it = ans.back();
            int prevX = it[0];
            int prevY = it[1];

            if(prevY >= currX) {
                // Update the prev interval values:
                int newX = min(currX, prevX);
                int newY = max(currY, prevY);

                ans.pop_back();
                ans.push_back({newX, newY});
            } else {
                ans.push_back({currX, currY});
            }
        }

        return ans;
    }
};