/*
//  1929. Concatenation of Array            https://leetcode.com/problems/concatenation-of-array/description/





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

vector<int> getConcatenation(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(2*n);
    for(int i=0;i<n;i++){
        ans[i] = nums[i]; 
        ans[i+n] = nums[i];
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        nums[i] = k;
    }
    vector<int> res = getConcatenation(nums);
    for(auto i : res) cout << i << " ";
    cout << endl;
}


int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}