/*

//  238. Product of Array Except Self


//  Observations: 
    * We are given an array & we have to return an array which has arr[i] is product of all element except itself.
    * Means:        arr[i] = arr[0]*..*[i-1]*arr[i+1]*...arr[n-1]


// Example:
    Input: nums = [1,2,3,4]
    Output: [24,12,8,6]

    Input: nums = [-1,1,0,-3,3]
    Output: [0,0,9,0,0]


// Approach:
    // Using Prefix & Suffix Product
    We will use prefix product & suffix product, & find find the product of all the arr[i]
        * Idea is to maintain two array, prefix product, & suffix product, and then we will try to find the value..

        * Example:
            arr[] = 1 2 3 4 
            pre[]  = 1 2 6 24
            suff[] = 24 24 12 4

                res[i] = prefix[i-1] * suffix[i+1]

            res:
                0 => Noting * 24 = 24
                1 => 1 * 12 = 12
                2 => 2 * 4 = 8
                3 => 6 * Nothing = 6

            * Note: we can take care for these two values by: 
                    res[0] = suffix[1]
                    res[n-1] = prefix[n-2]

        * Example:

            arr[] = -1  1  0 -3  3
            pre[] = -1 -1  0  0  0
            suf[] =  0  0  0 -9  3

            res[] = 0 0 9 0 0

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

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        // finding prefix product
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] * nums[i];
        }
        // Finding Suffix product
        vector<int> suffix(n);
        suffix[n-1] = nums[n-1];
         for(int i=n-2;i>=0;i--){
            suffix[i] = suffix[i+1] * nums[i];
        }

        // Now we will find the product of arr[i];
        vector<int> res(n);
        // Fist & last values of result will be:
        res[0] = suffix[1];         // first value will be the suffix[1]
        res[n-1] = prefix[n-2];     // last value of result will be the prefix[n-2]

        // Calculating product of all arr[i]
        for(int i=1;i<n-1;i++){
            res[i] = prefix[i-1] * suffix[i+1];
        }

        return res;
    }
};

void solve(){
    int n;
    cin>> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    Solution obj;
    vector<int> res = obj.productExceptSelf(v);

    for(auto i: res) cout << i << " ";
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