/*


//  118. Pascal's Triangle


//  Problem Statement: 
    -> Given an integer numRows, return the first numRows of Pascal's triangle.
    -> In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
 

// Example: 
    Example 1:
        Input: numRows = 5
        Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

    Example 2:
        Input: numRows = 1
        Output: [[1]]



// Observations: 


        nums = [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

        Visualizations:

                    1
                  1   1
                1   2   1
              1   3   3   1
            1   4   6   4   1
          1   5   10  10  5   1
        1   6   15  20  15  6   1
      1   7   21  35  35  21  7   1


    -> Start from index 1 to currRow.size - 1
        -> put starting & ending index as 1
        -> fill the rest value by fetching above values


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        if(numRows == 1) return {{1}};
        if(numRows == 2) return {{1}, {1, 1}};

        vector<vector<int>> mat;
        mat.push_back({1});
        mat.push_back({1,1});
        for(int i = 2; i < numRows; i++) {
            int itr = i + 1;    // Current 1-based index number

            vector<int> temp(itr);
            temp[0] = 1, temp[itr-1] = 1;
            for(int j = 1; j < itr - 1; j++) {
                temp[j] = mat[i-1][j-1] + mat[i-1][j];
            }

            mat.push_back(temp);
        }
        
        return mat;
    }
};