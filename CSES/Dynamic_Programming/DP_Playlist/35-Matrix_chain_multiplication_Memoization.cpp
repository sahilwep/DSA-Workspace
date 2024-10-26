/*

//  Matrix chain multiplication Memoization 


// Problem Statement: 
    * We are given an array that contains dimension of (n-1) matrix & we need to find the minimum cost to multiply these all matrix...


// Example:

    Input: N = 5
    arr = {40, 20, 30, 10, 30}
    Output: 26000
    Explanation: There are 4 matrices of dimension 
        40x20, 20x30, 30x10, 10x30. Say the matrices are 
        named as A, B, C, D. Out of all possible combinations,
        the most efficient way is (A*(B*C))*D. 
        The number of operations are -
        20*30*10 + 40*20*10 + 40*10*30 = 26000.


    Input: N = 4
    arr = {10, 30, 5, 60}
    Output: 4500
    Explanation: The matrices have dimensions 
        10*30, 30*5, 5*60. Say the matrices are A, B 
        and C. Out of all possible combinations,the
        most efficient way is (A*B)*C. The 
        number of multiplications are -
        10*30*5 + 10*5*60 = 4500.

// IntrusioN: 
    * We will improve our Matrix chain multiplications Recursive solution..
    * We will use memo matrix to store the subproblem of repetitive problem..
    * and directly return the result instead of going into recursive calls..


// Complexity:
    * TC: O(N^3)    -> Quadratic
    * AS: O(N^2)


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


// DP Memoization Approach:
int mcm(vector<int> &arr, int i, int j, vector<vector<int> > &t){
    
    // Base case: 
    if(i >= j) return 0;    // invalid for size = 0 & 1

    // checking memo matrix for result: 
    if(t[i][j] != -1){
        return t[i][j];
    }

    int minCost = INT_MAX;
    // breaking i to j range with every k:
    for(int k=i;k<=j-1;k++){
        int tempAns = mcm(arr, i, k, t) 
                    + mcm(arr, k+1, j, t) 
                    + (arr[i-1] * arr[k] * arr[j]);

        if(tempAns < minCost){
            minCost = tempAns;
        }
    }

    return t[i][j] = minCost;
}

// MCM Handler Code:
int mcmHandler(vector<int> &arr, int n){
    // Initialization: 
    vector<vector<int> > t(n+1, vector<int> (n+1, -1));


    // calling mcm with (i = 1 & j = n-1)
    return mcm(arr, 1, n-1, t);
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    // Calling for MCM: using DP Memoization
    cout << mcmHandler(arr, n) << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}