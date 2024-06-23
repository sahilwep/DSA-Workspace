/*
//  3191. Minimum Operations to Make Binary Array Elements Equal to One I




Example 1:
    Input: nums = [0,1,1,1,0,0]
    Output: 3

    Explanation:
    We can do the following operations:

        Choose the elements at indices 0, 1 and 2. The resulting array is nums = [1,0,0,1,0,0].
        Choose the elements at indices 1, 2 and 3. The resulting array is nums = [1,1,1,0,0,0].
        Choose the elements at indices 3, 4 and 5. The resulting array is nums = [1,1,1,1,1,1].


Example 2:
    Input: nums = [0,1,1,1]
    Output: -1

    Explanation:
    It is impossible to make all elements equal to 1.



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
    int minOperations(vector<int>& nums) {
        /*
        // approach: 
            * We will start iterating each element & for each element:
                * at any time we found '0' increase counter &, we will start flipping consecutive 3 elements.
                * We will do this till (i <= n-3), beacuse (n-3) is last position, & from there we will check 3 values
                * So, this is why we are going till (n-3), if we go more than n-3 like n-2, or n-1(last element) 
                    * it will check 3 values after the array range..
                * At last when this is done, we will check array with O(n), & if we encounter '0' at any movement return -1
                * else return cnt.

        
        */
        int n = nums.size();
        int cnt = 0;
        for (int i=0;i<=n-3;++i) {
            // whenever we have 0, we will start flipping 3 consecutive values.
            if (nums[i] == 0) {
                cnt++;    // increase counter
                for (int j=0;j<3;++j) {
                    nums[i+j] = 1 - nums[i+j];  // inverting bits
                }
            }
        }
        // checking if all the values are flipped or not?
        for (int i=0;i<n;++i) {
            if (nums[i] == 0) {
                return -1;  // return -1, at any time we encounter "0"
            }
        }
        return cnt;   // else return no of operations 
    }
};


void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];
    Solution obj;
    cout << obj.minOperations(nums) << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}