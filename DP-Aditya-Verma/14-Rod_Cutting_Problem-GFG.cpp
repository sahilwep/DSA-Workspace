/*

//  Rod Cutting Problem: Improved for better visualization -> recursion + Memoization + tabulation
    -> Problem Link: https://www.geeksforgeeks.org/problems/rod-cutting0840/1


//  Problem Statement:
    -> Given a rod of length n(size of price) inches and an array of prices, price. 
    -> price[i] denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.


// Example:
        Input: price[] = [1, 5, 8, 9, 10, 17, 17, 20]
        Output: 22
        Explanation: The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5+17=22.

        Input: price[] = [3, 5, 8, 9, 10, 17, 17, 20]
        Output: 24
        Explanation: The maximum obtainable value is 24 by cutting the rod into 8 pieces of length 1, i.e, 8*price[1]= 8*3 = 24.

        Input: price[] = [1, 10, 3, 1, 3, 1, 5, 9]
        Output: 40

//  Observations: 
    -> We are given Price array of n length represent: 
        inches ->  prices
        i      ->  price[i]
    
    -> Rod Length is 'n'
        -> And price[i] size is also 'n'
        -> We can take any price[i] any number of times..
        -> Type of Unbounded Knapsack problem
        -> Assume wt[] array as 'n'
        -> Assume sum value as 'n'
        -> Compute the solution.


// Recursive Solution
    -> Remaining Rod-Size & price[i] size {0...n-1}
    -> base case
    -> Gives TLE

// Memoization Solution:
    -> Optimize Recursive solution by using memo table, to prevent recomputation of subproblem..

// Tabulation Approach:
    -> Remove Recursive Solution Completely.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef size_t s_t;  // use during string traversal
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define arrInp for(int i=0;i<n;i++) cin >> arr[i];
#define arrOut(k) for(int i=0;i<n;i++) cout << arr[i] <<  k;
#define el cout << endl;
#define SQ(a) (a)*(a);
#define mod 1000000007


// Recursive Solution:
class Solution_Rec {
private:
    int solve(vector<int> &price, int n, int sum){
        // base case -> return 0, when price[] size or rodLen is exhausted..
        if(n == 0 || sum == 0) return 0;    
        
        // Recursive Case: 
        // Decision Tree: 
        // if per-inches price of rod is less or equal to remaining knapsack value
        if(n <= sum){
            // Two choices:     Include(Not-Processed)  / Reject(Processed)
            return max( 
                price[n-1] + solve(price, n, sum - n),    // Include case -> Not processed yet
                solve(price, n-1, sum));                    // Reject case -> Processed
        }else{
            return solve(price, n-1, sum);                  // Reject case -> Processed
        }
    }
    
public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        int sum = n;
        
        return solve(price, n, sum);
    }
};

// Memoization Solution:
class Solution_Memo {
private:
    int t[1001][1001];  // memo table:
    int solve(vector<int> &price, int n, int sum){
        if(n == 0 || sum == 0) return 0;    // base case
        
        // Checking Subproblem in memo table:
        if(t[n][sum] != -1) return t[n][sum];
        
        // Recursive Case: 
        // Decision Tree: 
        // if per-inches price of rod is less or equal to remaining knapsack value
        if(n <= sum){
            // Two choices:     Include(Not-Processed)  / Reject(Processed)
            return t[n][sum] = max( 
                price[n-1] + solve(price, n, sum - n),    // Include case -> Not processed yet
                solve(price, n-1, sum));                    // Reject case -> Processed
        }else{
            return t[n][sum] = solve(price, n-1, sum);                  // Reject case -> Processed
        }
    }
public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        int sum = n;
        memset(t, -1, sizeof(t));   // filling memo array with default value '-1'      

        return solve(price, n, sum);
    }
};

// Tabulation Solution:
class Solution_Tab {
public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        int rodLen = n;    // Consider it as rod length
        
        vector<vector<int> > t(n+1, vector<int> (rodLen+1, 0));  // dp table

        for(int i=1;i<n+1;i++){
            for(int j=1;j<rodLen+1;j++){
                // Decision Tree:
                // Comparision happened b/w i-> Remaining rod size & j -> Available Choices
                if(i <= j){    // include case:
                    // Two choices:     Include(Not-Processed) / Reject(Processed)
                    t[i][j] = max(
                            price[i-1] + t[i][j-i], // Not-Processed
                            t[i-1][j]   // Processed
                        );
                }
                else{   // Reject case
                    t[i][j] = t[i-1][j];    // Processed
                }
            }
        }

        return t[n][rodLen];     // return the last value from matrix
        
    }
};


// Driver Code:
void solve(){
    int n;
    cin >> n;
    vector<int> price(n);
    for(int i=0;i<n;i++) cin >> price[i];

    Solution_Tab obj;
    cout << obj.cutRod(price) << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}