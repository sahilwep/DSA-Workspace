/*
//  1672. Richest Customer Wealth           https://leetcode.com/problems/richest-customer-wealth/description/


Example 1:

Input: accounts = [[1,2,3],[3,2,1]]
Output: 6
Explanation:
1st customer has wealth = 1 + 2 + 3 = 6
2nd customer has wealth = 3 + 2 + 1 = 6
Both customers are considered the richest with a wealth of 6 each, so return 6.

Example 2:

Input: accounts = [[1,5],[7,3],[3,5]]
Output: 10
Explanation: 
1st customer has wealth = 6
2nd customer has wealth = 10 
3rd customer has wealth = 8
The 2nd customer is the richest with a wealth of 10.

Example 3:

Input: accounts = [[2,8,7],[7,1,3],[1,9,5]]
Output: 17


// Intrusion: 
    * we will sum for each inner iterations & at the end we will compare with the Final sum & store maximum among them..


// TC : O(n*m)


*/

#include<bits/stdc++.h>
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

int maximumWealth(vector<vector<int> > &acc) {
    int sum = 0;
    for(int i=0;i<acc.size();i++){
        int currSum = 0;
        for(int j=0;j<acc[i].size();j++){
            currSum += acc[i][j];
        }
        sum = max(currSum, sum);
    }
    return sum;
}

void solve(){
    int n, m;
    cin >> n >> m;  // input of row & cols
    vector<vector<int> > nums(n, vector<int>(m));    // decelerations of 2d array:
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> nums[i][j];
        }
    }

    cout << maximumWealth(nums) << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}