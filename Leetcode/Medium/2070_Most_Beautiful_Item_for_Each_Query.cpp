/*

// 2070. Most Beautiful Item for Each Query


// Problem Statement:
        -> We are given a 2D array consisting of "items", where each item is represented as items[i] = [price[i], beauty[i]].

        -> For each query in "queries[i]", we need to determine the maximum beauty of an item whose price is less than or equal to "queries[j]".
        -> If no such item exists, the answer to that query is '0'.
        
        -> We need to return an "answer" array of the same length as "queries", where answer[j] is the result for the jth query.


// Example:

    Example 1:

        Input: items = [[1,2],[3,2],[2,4],[5,6],[3,5]], queries = [1,2,3,4,5,6]
        Output: [2,4,5,5,6,6]
        Explanation:
        - For queries[0]=1, [1,2] is the only item which has price <= 1. Hence, the answer for this query is 2.
        - For queries[1]=2, the items which can be considered are [1,2] and [2,4]. 
        The maximum beauty among them is 4.
        - For queries[2]=3 and queries[3]=4, the items which can be considered are [1,2], [3,2], [2,4], and [3,5].
        The maximum beauty among them is 5.
        - For queries[4]=5 and queries[5]=6, all items can be considered.
        Hence, the answer for them is the maximum beauty of all items, i.e., 6.

    Example 2:

        Input: items = [[1,2],[1,2],[1,3],[1,4]], queries = [1]
        Output: [4]
        Explanation: 
        The price of every item is equal to 1, so we choose the item with the maximum beauty 4. 
        Note that multiple items can have the same price and/or beauty.  

    Example 3:

        Input: items = [[10,1000]], queries = [5]
        Output: [0]
        Explanation:
        No item has a price less than or equal to 5, so no item can be chosen.
        Hence, the answer to the query is 0.

// Brute Force Solution:
    * Bruteforce Solution is quite easy, we just need to write the given condition, & form the solution:
        // Pseudo code:
                    items[0][k] -> k = 0-1
                            0 -> price
                            1 -> beauty
                        
                        ans[] {} -> size = queries.size()   -> storing answer for each queries

                        for(i - 0 to queries.size()):
                            tempAns = 0;
                            for(j = 0 to items.size()):
                                if(items[i][0] <= queries[j]){
                                    tempAns = max(tempAns, items[i][1]);    -> compare with the previous items beauty with current beauty.
                                }
                            
                            ans.push_back(tempAns); -> storing answer for each queries.

    * Given constrains for items -> 10^9, which will fall into TLE
    * Time Complexity: O(n * m) => May cause Time Limit Exceeded (TLE) for large inputs.




// Efficient Solution:

    // Observe the pattern: 
        -> For each query we are iterating the whole items[price][beauty], which we have to improve on.
        -> If we sort the items[price][beauty] -> based on the price -> We may have no need to iterate the whole items for finding the whole beauty.
        -> After sorting we can use Binary-Search & find the query result in log(n) time
        -> Problem: 
            -> We may improve this complexity, but we need the maximum item beauty if (items[price] <= queries[i])
            -> So this leads to O(n) -> again linear time complexity, which makes no sens for writing the above logic, because overall TC: O(n^2)

        -> Solution:
            -> We need maxBeauty from the above search, what we can do, during the searching we can use a temp Variable to store the "maxBeautySoFar", & this will, be overwrite if value is greater, during the binary search at every index.
            -> Second What we can do, After sorting items, we can fix the maxBeauty values, if grater value has lesser beauty than the smaller value has maximum beauty.
            -> These two logic will fix our maxBeautySoFar, & we can get the maximum beauty during the Binary Search in O(1) time.


    // Example: 

                items = [[1,2],[3,2],[2,4],[5,6],[3,5]], queries = [1,2,3,4,5,6]

                After Sorting items: [[1,2],[2,4],[3,2],[3,5],[5,6]]
                                        0     1     2     3     4       -> Index

                    -> First Observations: 
                        Let's assume: we are doing query '3', Till now ignore item at index 3

                            -> for item at index 2: [3, 2] has beauty '2' -> say item_2
                            -> for item at index 1: [2, 4] has beauty '4' -> say item_1
                            
                            -> item_1 has maximum beauty than the item_2
                            -> Logical thing if we were on this query item_2, we need to select the maximum 'beauty', so in order to select that we may need to iterate back to "item_2" & get the maximum beauty.
                            -> NOTE: You may be thinking that item_3 has maximum beauty, then why we are selecting the item_2 when we are at query '3', this is just a case, what if item_3 has different price.
                            -> what i want to say if the maximum beauty is seen for smaller price than the larger price, we will have to select that, so it's better we overwrite with maximum value until we not found another maximum value.
                        Solution to this is we will overwrite our items array with maximum so far: 
                                    
                                    items: [[1,2],[2,4],[3,4],[3,5],[5,6]]

                            -> We have overwrite "item_1" with '4', because maximum items found before items_1's maximum.

                NOW, We can simply iterate in query & Use custom Binary Search which will find our maximum beauty for each query if the condition satisfy.

                    // Logic of Binary Search:


                                let say: items: [[1,2],[2,4],[3,4],[3,5],[5,6]], query[i] = '3'
                                l => left
                                r => right
                                m => mid,    mid = l + (r-l) / 2 

                                                [[1,2],[2,4],[3,4],[3,5],[5,6]]
                                                  0     1      2     3     4
                                                  l            m           r

                                                    mid = 0 + (4 - 0)/2 => 2
                                                    (items[mid][0] <= q)        query value is grater equal to the current price
                                                    we will have to move right, but we will store maxBeautySeenSoFar: '4' -> items[mid][1]
                                                    change left pointer to (mid + 1)



                                                [[1,2],[2,4],[3,4],[3,5],[5,6]]
                                                  0     1      2     3     4
                                                                     l     r
                                                                           m

                                                    mid = 3 + (4 - 3)/2 => 4
                                                    (items[mid][0] > q)        query value is less than the current price.
                                                    we will have to move left.
                                                    move right pointer to (mid - 1)




                                                [[1,2],[2,4],[3,4],[3,5],[5,6]]
                                                  0     1      2     3     4
                                                                     lr
                                                                     m
                                                    
                                                    mid = 3 + (3 - 3)/2 = 3 + 0 => 3
                                                    (items[mid][0] <= q)        query value is grater equal to the current price.
                                                    we will have to move right, but we will store the maxBeautySoFar: '5' -> item[mid]
                                                    move left pointer to  (mid + 1)



                                                [[1,2],[2,4],[3,4],[3,5],[5,6]]
                                                  0     1      2     3     4
                                                                     r     l
                                                                       
                                                        here -> (l > r) which will break the iterations.



                        -> Write simple binary search logic, with additional maintained variable "maxBeautySoFar" -> this will find the maximumBeautySoFar.

                                // Binary Search Function: O(log(n))
                                int customBinSearch(vector<vector<int> >& items, int x) {
                                    int left = 0;  // Starting index for binary search
                                    int right = items.size() - 1;  // Ending index

                                    int maxBeauty = 0;  // Variable to store maximum beauty found

                                    // Perform binary search to find max beauty for the given price constraint
                                    while (left <= right) {         // while left is less or equal to right.
                                    
                                        int mid = left + (right - left) / 2;    // at every iterations we will be getting the min value

                                        // if item's price is exceeds query, move to the left half -> means it's goes to right
                                        if (items[mid][0] > x) {
                                            right = mid - 1;    // setting right pointer to mid-1, means we have moved to left side.
                                        } 
                                        // if Items's price is less or equal to the query:  The condition we have given in question (items_Price <= query[i])
                                        else {
                                            maxBeauty = max(maxBeauty, items[mid][1]);  // Update max beauty seen so far
                                            left = mid + 1;  // We will have to move right side => Move to the right half to check for better options.
                                        }
                                    }

                                    return maxBeauty;  // Return the maximum beauty found
                                }

                    -> Iteration in query: O(n)
                    -> Iteration in Binary_Search: O(log(n))
                    -> For getting maxBeautySoFar: O(1)

                    -> Overall Complexity: O(n*log(n))

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
            } 
            else {  // Item's price is less than or equal to the query
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

