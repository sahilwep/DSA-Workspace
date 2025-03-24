/*

//  3169. Count Days Without Meetings


//  Problem Statement: 
    -> You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).
    -> Return the count of days when the employee is available for work but no meetings are scheduled.
    -> Note: The meetings may overlap.


// Example: 

    Example 1:
        Input: days = 10, meetings = [[5,7],[1,3],[9,10]]
        Output: 2
        Explanation: There is no meeting scheduled on the 4th and 8th days.

    Example 2:
        Input: days = 5, meetings = [[2,4],[1,3]]
        Output: 1
        Explanation: There is no meeting scheduled on the 5th day.

    Example 3:
        Input: days = 6, meetings = [[1,6]]
        Output: 0
        Explanation: Meetings are scheduled for all working days.

// Observations: 
    -> We are given days starting from 1, & given an array of meetings denotes [start, end] date both inclusive.

    // BruteForce Solution:
        -> Use a boolean array to mark days that have meetings scheduled.
        -> Iterate through all meeting intervals and mark occupied days.
        -> Count the remaining unmarked days as available workdays.
        
        // Complexity: 
            -> TC: O(days * n)
            -> SC: O(days)


    // Efficient Solution: 
        -> Sort the meeting intervals based on their start times.
        -> Iterate through the meetings, merging overlapping intervals.
        -> Maintain a count of total occupied days due to meetings.
        -> Compute the available workdays as (total days - occupied days).

        // Example: 
            Example: days = 10, meetings: [[5,7],[1,6],[9,10],[2,5]]

                    Sort meetings: [[1,6],[2,5],[5,7],[9,10]]

                        prevStart = 1
                        prevEnd = 6

                        currStart = 2
                        currEnd = 5

                            [1,6],[2,5]
                                \ /
                               (6 >= 2) {
                                    prevEnd = max(prevEnd, currEnd);
                                    prevEnd = max(6, 5);    // here we only update the maximum ending range, from all the previous ranges.
                                }

                              
                        prevStart = 1
                        prevEnd = 6
                              
                            [2,5],[5,7]
                                 \ /
                                (5 >= 5) {
                                    prevEnd = max(6, 7);    // here we only update the maximum ending range, from all the previous ranges.
                                }
                        
                        prevStart = 1
                        prevEnd = 7
                             
                            [5,7],[9,10]
                                \ /
                                (7 < 9) {
                                    // Compute answer:
                                    ans += (prevEnd - prevStart + 1) => 7

                                    // update new Ranges:
                                    prevStart = currStart;
                                    prevEnd = currEnd;
                                }
                        prevStart = 9
                        prevEnd = 10
                        

                                    ans += prevEnd - prevStart + 1 => 2
                        
                        
                        => ans = 7 + 2 => 9
                        FreeDays = Days - ans => 10 - 9 = 1




        // Complexity:
            -> TC: O(n * log(n))
            -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Optimized Solution:
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();

        // Case: when we have single range
        if(n == 1) {
            return days - (meetings[0][1] - meetings[0][0] + 1);
        }

        sort(begin(meetings), end(meetings));   // sort the given ranges
        
        long long cntDays = 0;  // count the days that have meetings in given range
        int prevStart = meetings[0][0], prevEnd = meetings[0][1];

        for(int i = 1; i < n; i++) {
            int currStart = meetings[i][0], currEnd = meetings[i][1];

            if(prevEnd >= currStart) {
                // Extend prevEnd only if needed
                prevEnd = max(prevEnd, currEnd);    // only add the grater value to handel the case: overlapping with smaller value.
            }
            else {
                // Compute answer: 
                cntDays += prevEnd - prevStart + 1;

                // Overwrite the start & ends:
                prevStart = currStart;
                prevEnd = currEnd;
            }
        }

        cntDays += prevEnd - prevStart + 1; // count the remaining days.

        return days - cntDays;
    }
};


// BruteForce Solution: 
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();

        // case when we have only single range:
        if(n == 1) {
            return days - (meetings[0][1] - meetings[0][0]) - 1;
        }

        sort(begin(meetings), end(meetings));

        vector<bool> freeDays(days + 1, true);
        
        int withoutMeeting = 0;
        for(int i = 0; i < n; i++) {
            int start = meetings[i][0];
            int end = meetings[i][1];

            if(freeDays[end] == false) continue;    // if end range is false, skip that pupations.

            for(int j = start; j <= end; j++) {
                freeDays[j] = false;    // mark as false;
            }
        }

        for(int i = 1; i <= days; i++) {
            if(freeDays[i]) withoutMeeting++;
        }

        return withoutMeeting;
    }
};