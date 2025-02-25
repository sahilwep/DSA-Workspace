/*

//  1524. Number of Sub-arrays With Odd Sum

//  Problem Statement: 
    -> Given an array of integers arr, return the number of subarrays with an odd sum.
    -> Since the answer can be very large, return it modulo 109 + 7.


// Example: 

    Example 1:
        Input: arr = [1,3,5]
        Output: 4
        Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
        All sub-arrays sum are [1,4,9,3,8,5].
        Odd sums are [1,9,3,5] so the answer is 4.

    Example 2:
        Input: arr = [2,4,6]
        Output: 0
        Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
        All sub-arrays sum are [2,6,12,4,10,6].
        All sub-arrays have even sum and the answer is 0.

    Example 3:
        Input: arr = [1,2,3,4,5,6,7]
        Output: 16

// Constraints:

    1 <= arr.length <= 10^5
    1 <= arr[i] <= 100


// Observations: 
    -> 



// Complexity:


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



void solve(){
    int n;
    
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}