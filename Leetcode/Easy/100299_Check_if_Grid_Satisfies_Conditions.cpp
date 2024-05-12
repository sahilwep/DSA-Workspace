/*
//  100299. Check if Grid Satisfies Conditions




 */ 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define arrInp for(int i=0;i<n;i++) cin >> arr[i];
#define arrOut(k) for(int i=0;i<n;i++) cout << arr[i] <<  k;
#define el cout << endl;
#define SQ(a) (a)*(a)

bool satisfiesConditions(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    if(n == 1 && m == 1) return true;

    int cnt = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            // condition for row check
            if( i < n-1 && grid[i][j] != grid[i + 1][j]){
                return false;
            }
            // condition for col check
            if( j < m-1  && grid[i][j] == grid[i][j + 1]){
                return false;
            }
        }
    }
    return true;
}

/*
    Equal to the cell below it, i.e. grid[i][j] == grid[i + 1][j] (if it exists).
    Different from the cell to its right, i.e. grid[i][j] != grid[i][j + 1] (if it exists).

    [2,1]
    [2,1]


    [1, 7]
    [1, 1]


    [1, 2, 3]
    [1, 2, 3]
    [1, 2, 3]

*/

void solve(){

    vector<vector<int>> grid = {{1, 0, 2},{1, 0, 2}};        // true
    // vector<vector<int>> grid = {{1, 1, 1},{0, 0, 0}};    // false
    // vector<vector<int>> grid = {{1}, {2}, {3}}; // false
    // vector<vector<int>> grid = {{0}}; // true
    // vector<vector<int>> grid = {{1,4},{6, 6}};    // false
    // vector<vector<int>> grid = {{1, 7}, {1, 1}};    // false
    // vector<vector<int>> grid = {{1, 7}, {1, 7}, {1, 7}};    // true
    // vector<vector<int>> grid = {{2, 1}, {2, 1}};    // true 
    


    bool result = satisfiesConditions(grid);

    cout << boolalpha << result << endl;
}


int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}