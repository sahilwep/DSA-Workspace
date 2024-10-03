/*

//  2215. Find the Difference of Two Arrays

//  Observations: 
    * We are given two array, & we need to find the difference b/w these two array: 
    * We need to store these result in 2D array, & integer in the list can be returned in any order.


// Example:

    Input: nums1 = [1,2,3], nums2 = [2,4,6]
    Output: [[1,3],[4,6]]
    Explanation:
    For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
    For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].


    Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
    Output: [[3],[]]
    Explanation:
    For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
    Every integer in nums2 is present in nums1. Therefore, answer[1] = [].

 
// IntrusioN: 
    * We can use two set to hash all value from the array, Then we can iterate in set find the difference..
    * TC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
#include<unordered_set>
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
    vector<vector<int> > findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int> > res(2, vector<int>());
        
        // Hashing all the values of nums1 into s1
        unordered_set<int> s1;
        for(auto i: nums1) s1.insert(i);


        // Hashing all the values of nums2 into s2
        unordered_set<int> s2;
        for(auto i: nums2) s2.insert(i);
        

        // Filling unique values from first set:
        for(auto i: s1){
            // if element is not found second set, store this into res[0]
            if(s2.find(i) == s2.end()){
                res[0].push_back(i);
            }
        }
        
        // Filling unique values from second set:
        for(auto i: s2){
            // if element is not found in first set, store this into res[1]
            if(s1.find(i) == s1.end()){
                res[1].push_back(i);
            }
        }

        return res;
    }
};


void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n);
    vector<int> nums2(m);

    for(int i=0;i<n;i++) cin >> nums1[i];
    for(int i=0;i<m;i++) cin >> nums2[i];

    Solution obj;
    vector<vector<int> >  res = obj.findDifference(nums1, nums2);

    for(auto i: res){
        for(auto j: i){
            cout << j << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}