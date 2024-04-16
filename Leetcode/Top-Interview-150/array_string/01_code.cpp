/*
//88. Merge Sorted Array         https://leetcode.com/problems/merge-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

* As per the question we have to merge the array into sorted fashion & insert into first nums array. 


Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

// Approach: 
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    * We know that fact that nums1 has m element on it, &  there will be n space left in nums1, so we can start inserting from m to (0->n) element..
    * At end, we can sort them...
    * TC : O(nlogn)

// Input: 
3
3 3
1 2 3 0 0 0 
2 5 6
1 0
1
0 1
0
1
// Expected output: 
1 2 2 3 5 6 
1 
1 

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

void merge_arr(vector<int> nums1, int m, vector<int> nums2, int n){
    for(int i=m, j=0;j<n;j++){
        nums1[i] = nums2[j];
        i++;
    }
    sort(nums1.begin(), nums1.end());
    for(auto i : nums1) cout << i << " ";
    el;
}

void solve(){
    int m, n;
    cin >> m >> n;
    vector<int> nums1(m+n);
    vector<int> nums2(n);
    for(int i=0;i<m+n;i++){
        int k;
        cin >> k;
        nums1[i] = k;
    }
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        nums2[i] = k;
    }
    merge_arr(nums1, m, nums2, n);
}


int main(){
    int t;   
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}