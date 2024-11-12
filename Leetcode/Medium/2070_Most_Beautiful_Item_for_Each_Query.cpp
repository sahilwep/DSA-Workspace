/*

// 2070. Most Beautiful Item for Each Query


// Problem Statement:
        -> We are given a 2D array consisting of "items", where each item is represented as items[i] = [price[i], beauty[i]].

        -> For each query in "queries[i]", we need to determine the maximum beauty of an item whose price is less than or equal to "queries[j]".
        -> If no such item exists, the answer to that query is '0'.
        
        -> We need to return an "answer" array of the same length as "queries", where answer[j] is the result for the jth query.


// Brute Force Solution:
    * Time Complexity: O(n * m) => May cause Time Limit Exceeded (TLE) for large inputs.


// Efficient Solution:
    -> Instead of checking each query with every item, we can optimize using sorting and binary search.
    -> By sorting the items based on their price, we reduce redundant traversal.
    -> During binary search, we can quickly find the range of valid items whose price is less than or equal to a given query.
    -> To avoid recalculating the maximum beauty repeatedly, we maintain the maximum beauty seen so far at each index.
    -> This allows us to compute the maximum beauty for each query in logarithmic time.

    // Approach:
        -> Sort the items based on their prices.
        -> Update maximum beauty seen so far at each index.
        -> Use binary search to find the maximum beauty for each query efficiently.


    // Time Complexity: O(m * log(n)), where m is the number of queries and n is the number of items.



*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Efficient Solution:
    vector<int> maximumBeauty(vector<vector<int> >& items, vector<int>& q) {
        int n = q.size();   // Number of queries
        int m = items.size();  // Number of items

        // Sort items based on price in ascending order
        sort(items.begin(), items.end());

        // Maintain the maximum beauty seen so far
        int maxBeautySeen = items[0][1];

        // Update maximum beauty in items array
        for (int i = 1; i < m; i++) {
            maxBeautySeen = max(maxBeautySeen, items[i][1]);
            // Update beauty value at index i with max beauty seen so far
            items[i][1] = maxBeautySeen;
        }
        
        // Initialize result vector to store answers for each query
        vector<int> res(n);

        // Use binary search to find the answer for each query
        for (int i = 0; i < n; i++) {
            int queryPrice = q[i];
            res[i] = customBinSearch(items, queryPrice);  // Find max beauty using binary search
        }

        return res;
    }

    // Binary Search Function: O(log(n))
    int customBinSearch(vector<vector<int> >& items, int x) {
        int left = 0;  // Starting index for binary search
        int right = items.size() - 1;  // Ending index
        int maxBeauty = 0;  // Variable to store maximum beauty found

        // Perform binary search to find max beauty for the given price constraint
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (items[mid][0] > x) {  // If item's price exceeds query, move to the left half
                right = mid - 1;
            } else {  // Item's price is less than or equal to the query
                maxBeauty = max(maxBeauty, items[mid][1]);  // Update max beauty seen so far
                left = mid + 1;  // Move to the right half to check for better options
            }
        }

        return maxBeauty;  // Return the maximum beauty found
    }

    // Brute Force Solution: O(n * m)
    vector<int> maximumBeauty_Brute(vector<vector<int> >& items, vector<int>& q) {
        int n = q.size();   // Number of queries
        int m = items.size();  // Number of items
        vector<int> res(n);

        // Iterate over each query
        for (int i = 0; i < n; i++) {
            int tempAns = 0;  // Variable to store max beauty for current query

            // Check each item
            for (int j = 0; j < m; j++) {
                // Include the item's beauty if its price is <= query price
                if (items[j][0] <= q[i]) {
                    tempAns = max(tempAns, items[j][1]);  // Update max beauty for the current query
                }
            }
            // Store the result for the current query
            res[i] = tempAns;
        }

        return res;
    }
};

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> queries(n);
    vector<vector<int> > items(m, vector<int> (2));

    for(int i=0;i<n;i++){
        cin >> queries[i];
    }

    for(int i=0;i<m;i++){
        //      price           beauty
        cin >> items[i][0] >> items[i][1];
    }

    Solution obj;
    vector<int> res = obj.maximumBeauty(items, queries);

    for(auto i: res) cout << i << " ";
    cout << endl;

}

int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}

