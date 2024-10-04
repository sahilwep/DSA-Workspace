/*

//  283. Move Zeroes

//  Observations:
    * We are given an array nums that contains some 0's in it, we need to move all 0's at the end:


// Example:

    Input: nums = [0,1,0,3,12]
    Output: [1,3,12,0,0]

    Input: nums = [0]
    Output: [0]


// Intrusion: 
    * We will use two pointer approach, first pointer use to iterate throughout the array, & second used to store the unique element index.
    * TC: O(n)



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
    void moveZeroes(vector<int>& nums) {

        int p1 = 0; // Use to store the index of unique elements
        int p2 = 0; // Use to iterate throughout the array


        while(p2 < nums.size()){
            // if we encounter with non-zero element
            if(nums[p2] != 0){
                nums[p1++] = nums[p2];  // store at the index of first pointer, & move it forward.
            }

            p2++;   // Increment second pointer at every iterations.
        }

        // Now overwriting index with 0, once all the non-zero element stored in order.
        while(p1 < nums.size()){
            nums[p1++] = 0;
        }
    }
};

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    Solution obj;

    obj.moveZeroes(v);
    
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}