/*

//  2352. Equal Row and Column Pairs


//  Observations: 
    * We are given a matrix of NxN, we need to return number of pairs(ri, ci), such that ri and ci are equal.
    * A row and pair is considered equal if they contains same number of element in same order. (i.e an equal array.)


// Example:

            [3,2,1]
            [1,7,6]
            [2,7,7]

    Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
    Output: 1
    Explanation: There is 1 equal row and column pair:
    - (Row 2, Column 1): [2,7,7]


    Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
    Output: 3
    Explanation: There are 3 equal row and column pairs:
    - (Row 0, Column 0): [3,1,2,2]
    - (Row 2, Column 2): [2,4,2,2]
    - (Row 3, Column 2): [2,4,2,2]


// Intrusion: 
    // We can use hashing Approach:
        * We need to return equal row & column pair:
        * We will hash all the row's into map with their frequency.
        * Then we will look for all the col's in map if they are present or not?
            * If they are already in map, update the counter with their frequency times.
        * TC: O(n^2)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int equalPairs(vector<vector<int> >& grid) {
        int n = grid.size();
        map<vector<int>, int> mp;   // using map to store the frequency of every row:

        // Insertion of row in map & if they are same then we will increment their frequency.
        for(int i=0;i<n;i++){
            vector<int> row;
            for(int j=0;j<n;j++){
                row.push_back(grid[i][j]);
            }
            mp[row]++;  // inserting the row, with their frequency.
        }

        // Insertion of col, & counting the row's that are same with col's..
        int cnt = 0;
        for(int i=0;i<n;i++){
            vector<int> col;
            for(int j=0;j<n;j++){
                col.push_back(grid[j][i]);  // pushing columns in col array.
            }

            // checking if col is already present in map or not? 
            if(mp.find(col) != mp.end()){   // if col is already there:

                cnt += mp[col]; // Updating count with row's frequency, if col's is found...
            
            }
        }

        return cnt; // Last return the count.
    }
};

void solve(){
    int n;
    cin >> n;
    vector<vector<int> > grid(n, vector<int> (n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> grid[i][j];
        }
    }

    Solution obj;
    cout << obj.equalPairs(grid) << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}