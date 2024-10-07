/*

//  7 Subset Sum Problem


//  Observations: 
    * We are given an array of size n, & 
    






*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


bool subsetSum(vector<int>& nums, int sum){
    int n = nums.size();
    // Initialization:
    vector<vector<int> > t(n+1, vector<int> (sum+1));
    t[0][0] = 0;
    for(int i=1;i<sum;i++){
        t[0][i] = 0;
    }

}

void solve(){
    int n, sum;
    cin >> n >> sum;
    vector<int> nums(n);
    for(int i=0;i<n;i++)  cin >> nums[i];

    (subsetSum(nums, sum)) ? cout << "Yes" : cout << "No";
    cout << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}