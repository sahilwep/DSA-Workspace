/*

//  Brackets in Matrix Chain Multiplication


//  Problem Statement: 
    -> Given an array arr[] of length n used to denote the dimensions of a series of matrices such that the dimension of i'th matrix is arr[i] * arr[i+1]. There are a total of n-1 matrices. Find the most efficient way to multiply these matrices together. 
    -> As in MCM, you were returning the most effective count but this time return the string which is formed of A - Z (only Uppercase) denoting matrices & Brackets( "(" ")" ) denoting multiplication symbols. For example, if n =11, the matrixes can be denoted as A - K as n<=26 & brackets as multiplication symbols.

    -> NOTE:
        -> Each multiplication is denoted by putting open & closed brackets to the matrices multiplied & also, please note that the order of matrix multiplication matters, as matrix multiplication is non-commutative A*B != B*A
        -> As there can be multiple possible answers, the console would print "true" for the correct string and "false" for the incorrect string. You need to only return a string that performs a minimum number of multiplications.


// Examples:

    Input: arr[] = [40, 20, 30, 10, 30]
    Output: true
    Explanation: Let's divide this into matrix(only 4 are possible) [ [40, 20] -> A, [20, 30] -> B, [30, 10] ->C, [10, 30] -> D ]
    First we perform multiplication of B & C -> (BC), then we multiply A to (BC) -> (A(BC)), then we multiply D to (A(BC)) -> ((A(BC))D)
    so the solution returned the string ((A(BC))D), which performs minimum multiplications. The total number of multiplications are 20*30*10 + 40*20*10 + 40*10*30 = 26,000.

    Input: arr[] = [10, 20, 30]
    Output: true
    Explanation: There is only one way to multiply two matrices: (AB): The cost for the multiplication will be 6000

    Input: arr = [3, 3, 3]
    Output: true
    Explanation: The solution returned the string (AB), which performs minimum multiplications. The total number of multiplications are (3*3*3) = 27.


*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
private: 
    pair<string, int> solve(int i, int j, vector<int> &arr, vector<vector<pair<string, int>>> &t){
        if(i == j){ // if we have left with only one matrix:
            string temp = "";
            temp += char('A' + i-1);    // get the correct index, as it's start with '0' based index..
            return {temp, 0};   
        }
        
        if(t[i][j].second != -1) return t[i][j];
        
        int ans = INT_MAX;
        string str;
        // Partitions Scheme:
        for(int k=i;k<=j-1;k++){
            // Generate Temp-answers:
            pair<string, int> left = solve(i, k, arr, t);
            pair<string, int> right = solve(k+1, j, arr, t);
            
            int curr = left.second + right.second + (arr[i-1] * arr[k] * arr[j]);
            
            
            if(curr < ans){
                ans = curr;
                str = '(' + left.first + right.first + ')';
            }
        }
        
        return t[i][j] = {str, ans};
    }
public:
    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size();
        int i = 1;  // because of A[i] = arr[i-1] * arr[i], which needs previous index...
        int j = n - 1;  // last index always valid to form matrix.
        
        vector<vector<pair<string, int>>> t(n, vector<pair<string, int>> (n, {"", -1}));
        
        pair<string, int> ans = solve(i, j, arr, t);
        
        return ans.first;
    }
};
