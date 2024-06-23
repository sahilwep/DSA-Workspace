/*
//   3190. Find Minimum Operations to Make All Elements Divisible by Three


Example 1:
    Input: nums = [1,2,3,4]
    Output: 3

    Explanation:

        All array elements can be made divisible by 3 using 3 operations:

            Subtract 1 from 1.
            Add 1 to 2.
            Subtract 1 from 4.

Example 2:
    Input: nums = [3,6,9]
    Output: 0



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
#define SQ(a) (a)*(a);

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] % 3 != 0){
                cnt++;
            }
        }
        return cnt;
    }
};


void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];
    Solution obj;
    cout << obj.minimumOperations(nums) << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}