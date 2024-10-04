/*

//  334. Increasing Triplet Subsequence

//  Observations: 
    * we are given an array nums, return true if there exist triple indices (i, j, & k), 
    * such that (i < j < k) and nums[i] < nums[j] < nums[k], otherwise return false.


// Example: 

    Input: nums = [1,2,3,4,5]
    Output: true
    Explanation: Any triplet where i < j < k is valid.

    Input: nums = [5,4,3,2,1]
    Output: false
    Explanation: No triplet exists.

    Input: nums = [2,1,5,0,4,6]
    Output: true
    Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.

// IntrusioN: 
    // Using Greedy Approach:
        * we will use two pointers, left & mid, and iterate throughout the array:
        * If (arr[i] <= left) -> left = arr[i]
        * else if(arr[i] <= mid) -> mid = arr[i]
        * else -> return true -> means we found that element & increasing sequence

        arr[] = 2   1   5   0   4   6

            left = +Infinity
            mid = +Infinity

                2   1   5   0   4   6
                |

                if(arr[i] <= left) -> YES       -> left = 2

                2   1   5   0   4   6
                    |
 
                if(arr[i] <= left) -> YES       -> left = 1
                
                2   1   5   0   4   6
                        |
 
                if(arr[i] <= left) -> NO 
                else if(arr[i] <= mid) -> YES      -> mid = 5
                

                2   1   5   0   4   6
                            |
 
                if(arr[i] <= left) -> YES       -> left = 0
                
                
                2   1   5   0   4   6
                                |
 
                if(arr[i] <= left) -> NO      
                else if(arr[i] <= mid) -> YES   ->  mid = 4


                2   1   5   0   4   6
                                    |
 
                if(arr[i] <= left) -> NO      
                else if(arr[i] <= mid) -> NO
                else -> return true -> means    -> right = 5

            Increasing Sequence: left = 0, mid = 4, right = 5


        * TC: O(N)
        * AS: O(1)


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
    // Using greedy Approach:
    bool increasingTriplet(vector<int>& nums) {
        int left = INT_MAX;
        int mid = INT_MAX;

        for(auto i: nums){
            // If current element is grater than previous left
            if(i <= left){
                left = i;
            }
            // if above condition is not true, then we comes into this condition, where left is smaller than the current element, & we are checking whether current i is smaller than the previous mid or not.
            else if(i <= mid){
                mid = i;
            }
            // if all the above condition no true, means left < mid & i is grater than all of them, so we came to else statement.
            else{
                // we have found the third increasing element
                return 1;
            }
        }

        return 0;   // else return false, if we don't go on the else part
    }

    // Bruteforce Solution: -> TLE
    bool increasingTriplet_Brute(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(arr[i] < arr[j] && arr[j] < arr[k]){
                        return 1;
                    }
                }
            }
        }

        return 0;
    }
};


void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    arrInp;

    Solution obj;

    (obj.increasingTriplet(arr)) ? cout << "True" : cout << "False";
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