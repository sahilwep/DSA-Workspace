/*

//  2033. Minimum Operations to Make a Uni-Value Grid


//  Problem Statement: 
    -> You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.
    -> A uni-value grid is a grid where all the elements of it are equal.
    -> Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.


// Example:
    Example 1:
        Input: grid = [[2,4],[6,8]], x = 2
        Output: 4
        Explanation: We can make every element equal to 4 by doing the following: 
            - Add x to 2 once.
            - Subtract x from 6 once.
            - Subtract x from 8 twice.
            A total of 4 operations were used.

    Example 2:
        Input: grid = [[1,5],[2,3]], x = 1
        Output: 5
        Explanation: We can make every element equal to 3.

    Example 3:
        Input: grid = [[1,2],[3,4]], x = 2
        Output: -1
        Explanation: It is impossible to make every element equal.

    
// Observations: 
    -> If we analyze this question with little maths, we can crack the pattern..
        -> Example: 
            x = 2
            nums = [2, 4, 6, 8]

            -> Convert the given 2D matrix into 1D vector
            -> sort the values.
            -> Get the middle values.
            -> Now we just need to check how much we need to add & subtract by 'x' in order to make all the array elements equal.
            -> If every number is divisible by 'x' or every number subtracted by mid is divisible by 'x' => then only we achieve uni-Value.

                mid = 4
                2:
                    2 - 4 = 2
                    2 / 2 = 1
                    ans = 1
                4: 
                    4 - 4 = 0
                    0 / 2 = 0
                    ans = 1
                6:
                    6 - 4 = 2
                    2 / 2 = 1
                    ans = 1 + 1
                8:
                    8 - 4 = 4
                    4 / 2 = 2
                    ans = 1 + 1 + 2 => 4

        TestCase:
            grid = [[931,128],[639,712]]
            x = 73

            -> This test case Explains why we need to subtract mid from every number Then we have to check the divisibility with 'x'

// Complexity: 
    -> TC: O(k * log(k))
    -> SC: O(k)
        -> k = (n * m)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Clear Code Implementations: 
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size(), m = grid[0].size();
        
        // Edge case: If the grid has only one element, it's already a uni-value grid.
        if (n == 1 && m == 1) return 0;
        
        vector<int> temp(n * m); // Flattening the 2D grid into a 1D array
        int k = 0;
        
        // Copy grid elements into the 1D vector
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                temp[k++] = grid[i][j];
            }
        }
        
        // Sort the array to find the median element
        sort(temp.begin(), temp.end());
        
        // The median minimizes the sum of absolute differences
        int mid = temp[temp.size() / 2];
        int ans = 0;
        
        // Iterate through the array and calculate required operations
        for (int i = 0; i < temp.size(); i++) {
            int diff = abs(temp[i] - mid); // Absolute difference from median
            
            // If difference is not divisible by x, making all elements equal is impossible
            if (diff % x != 0) return -1;
            
            ans += diff / x; // Number of operations needed for this element
        }
        
        return ans; // Return total operations required
    }
};


// Naive Implementations: 
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size(), m = grid[0].size();

        // Edge Case:
        if(n == 1 && m == 1 ) return 0; // '0' steps required to make all equal if we have single element in our array

        vector<int> temp(n*m);
        int k = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                temp[k++] = grid[i][j];
            }
        }

        sort(begin(temp), end(temp));
        
        // Get the middle value:
        int tSize = temp.size();
        int mid = temp[(tSize / 2)];    // mid value

        int ans = 0;
        for(int i = 0; i < tSize; i++) {
            if((temp[i] - mid) % x == 0) {
                int y = abs(temp[i] - mid); // get the difference from the result
                ans += y / x;   // divide it by y and store answer.
            }
            else {  // if it left remainder then we can't able to make all equal..
                return -1;
            }
        }

        return ans;
    }
};