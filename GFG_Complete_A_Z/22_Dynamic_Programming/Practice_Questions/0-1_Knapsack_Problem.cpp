/*

//  0 - 1 Knapsack Problem

//  Observations: 
    * We are given some items that has some values & weight, & we are given a capacity of bag
    * We need to find the maximum possible values that can store in bag..

// Solution:
    // Efficient Solutions: Using Bottom Up DP
        * We can use Bottom Up DP to improve the complexity of the solutions.
        * TC: O(n*W)

*/ 

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    // Function to return max value that can be put in knapsack of capacity W.
    // Bottom Up DP: Tabulation
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        // initialization:
        int t[n+1][W+1];
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<W+1;j++){
                if(i == 0 || j == 0){
                    t[i][j] = 0;
                }
            }
        }
        
        // Making choice diagram: filling up table:
        for(int i=1;i<n+1;i++){
            for(int j=1;j<W+1;j++){
                if(wt[i-1] <= j){
                    t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        return t[n][W];
    }
};


int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}