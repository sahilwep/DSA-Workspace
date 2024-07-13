/*
//  1470. Shuffle the Array             https://leetcode.com/problems/shuffle-the-array/description/

// Intrusion: 
    * We will use two pointers:
        One pointer is i from 0 to k
        second pointer is (i+k), till the i iterate..
    * TC : O(n)

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

vector<int> shuffle(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> res(n);
    int z = 0;
    for(int i=0;i<k;i++){
        res[z++] = nums[i];     // Take element from the first half
        res[z++] = nums[i+k];   // Take element from the second half
    }
    return res;
}

void solve(){
    // Input: vector nums and integer k
    int k;
    cin >> k;
    vector<int> nums(2*k);
    for(int i=0;i<nums.size();i++) cin >> nums[i];

    vector<int> result = shuffle(nums, k);

    for(int i : result) cout << i << " ";
    el;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}