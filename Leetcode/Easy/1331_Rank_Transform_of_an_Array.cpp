/*

//  1331. Rank Transform of an Array


//  Problem Statement:
    - Given an array of integers arr, replace each element with its rank.
    - The rank represents how large the element is. The rank has the following rules:
        - Rank is an integer starting from 1.
        - The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
        - Rank should be as small as possible.

 
// Example:
    Example 1:
        Input: arr = [40,10,20,30]
        Output: [4,1,2,3]
        Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.

    Example 2:
        Input: arr = [100,100,100]
        Output: [1,1,1]
        Explanation: Same elements share the same rank.

    Example 3:
        Input: arr = [37,12,28,9,100,56,80,5,12]
        Output: [5,3,4,2,8,6,7,1,3]

// Observations:
    - From the given array, we need to transform all the elements to their rank.
    - We can start from 1, and later on we can increase the rank as our value increases..
    - for same value rank is also same..
        

// Complexity:  
    - TC: O(n*logn)
    - SC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        if(arr.empty()) return {};

        // Preserve the given array index, so that we won't struggle while building answers.
        vector<pair<int, int>> temp;
        for(int i = 0; i < n; i++) {
            temp.push_back({arr[i], i});
        }

        sort(begin(temp), end(temp));   // sort the value..

        // Build answer:
        vector<int> ans(n);
        ans[temp[0].second] = 1;    // First value as rank '1'

        for(int i = 1; i < n; i++) {
            if(temp[i].first == temp[i - 1].first) {    // if we have same value:
                ans[temp[i].second] = ans[temp[i -1].second];   // same rank
            } else {    // distinct value:
                ans[temp[i].second] = ans[temp[i -1].second] + 1;   // increment rank
            }
        }

        return ans;
    }
};