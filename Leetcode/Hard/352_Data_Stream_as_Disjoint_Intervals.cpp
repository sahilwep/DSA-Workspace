/*

//  352. Data Stream as Disjoint Intervals


//  Problem Statement: 
    - Given a data stream input of non-negative integers a1, a2, ..., an, summarize the numbers seen so far as a list of disjoint intervals.
    - Implement the SummaryRanges class:
        - SummaryRanges() Initializes the object with an empty stream.
        - void addNum(int value) Adds the integer value to the stream.
        - int[][] getIntervals() Returns a summary of the integers in the stream currently as a list of disjoint intervals [starti, endi]. The answer should be sorted by starti.

 
// Example:
    Example 1:

        Input: 
            ["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals"]
            [[], [1], [], [3], [], [7], [], [2], [], [6], []]
        Output: 
            [null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7, 7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]
        Explanation: 
            SummaryRanges summaryRanges = new SummaryRanges();
            summaryRanges.addNum(1);      // arr = [1]
            summaryRanges.getIntervals(); // return [[1, 1]]
            summaryRanges.addNum(3);      // arr = [1, 3]
            summaryRanges.getIntervals(); // return [[1, 1], [3, 3]]
            summaryRanges.addNum(7);      // arr = [1, 3, 7]
            summaryRanges.getIntervals(); // return [[1, 1], [3, 3], [7, 7]]
            summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
            summaryRanges.getIntervals(); // return [[1, 3], [7, 7]]
            summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
            summaryRanges.getIntervals(); // return [[1, 3], [6, 7]]

// Constraints:
    0 <= value <= 1e4
    At most 3 * 1e4 calls will be made to addNum and getIntervals.
    At most 1e2 calls will be made to getIntervals.


// Observations: 
    - Straight forward implement the instruction
    - When it's addNum(): 
        - insert element, we only have to make sure that we should'nt be inserting duplicate value.
        - Get interval asks for all the intervals from all the number that being inserted earlier.
        - We will use Set, stores elements in sorted order.
            - Insertion: O(logn)
        - When interval() called: 
            - Only takes O(n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class SummaryRanges {
public:
    set<int> st;
    SummaryRanges() {
        // Initalize
    }
    
    void addNum(int value) {    // TC: O(logn)
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {    // TC: O(n * logn)

        if(st.size() == 0) {
            return {};  // return empty array.
        }
        
        // Sort:
        vector<int> nums(begin(st), end(st));       // TC: O(n * logn)
        vector<vector<int>> ans;

        // Find intervals:     // TC: O(n)
        int n = nums.size();
        int start = nums[0];
        int end = nums[0];

        for(int i = 1; i < n; i++) {
            if(nums[i - 1] + 1 == nums[i]) {
                end = nums[i];
            } else {
                ans.push_back({start, end});
                start = nums[i];
                end = nums[i];
            }
        }

        ans.push_back({start, end});

        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */