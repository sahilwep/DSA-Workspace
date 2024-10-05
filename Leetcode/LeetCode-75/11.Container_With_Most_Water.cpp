/*

//  11. Container With Most Water


//  Observations: 
    * We are given an array height of length n, & there are n vertical lines drawn such that the two endpoints of the ith lines are (0, 1) and (i, height[i]).
    * Find two lines together with x-axis from a container such that container contains most of the water.
    * Return the maximum amount of water that container can store.
    * Note: we may not slant the container.

// Example: 

    Input: height = [1,8,6,2,5,4,8,3,7]
    Output: 49
    Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
    In this case, the max area of water (blue section) the container can contain is 49.


    Input: height = [1,1]
    Output: 1

// Intrusion: 
    // Bruteforce Solution: 
        * We will try to find every possible combinations, from start to end.
        * By selecting every element one by one, we will try to find the maximum water that container can hold.
        * TC: O(n^2) -> TLE

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
    // Bruteforce Solution:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int maxCap = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int idxDiff = j-i;
                int minHei = min(height[i], height[j]);
                int currCap = idxDiff * minHei;
                maxCap = max(maxCap, currCap);
            }
        }

        return maxCap;
    }
};


void solve(){
    int n;
    cin >> n;
    vector<int> height(n);
    
    for(int i=0;i<n;i++) cin >> height[i];

    Solution obj;
    cout << obj.maxArea(height) << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}