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
    
    // Efficient Solutions: 
        * We will use two pointer & greedy approach.
        * We will move the pointer according to our preference..
        * first pointer is at 0
        * second pinter is at n-1
                
                if(height[ptr1] <= height[ptr2]) ptr1++ // move first pointer
                else ptr2-- // move second pointer
        * By this way we can find all the combinations where, we can hold the maximum water..
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
    // Bruteforce Solution:
    int maxArea_Brute(vector<int>& height) {
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
    // Efficient Solution: 
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxCap = 0;
        
        int i = 0;
        int j = n-1;
        while(i < j){
            int minH = min(height[i], height[j]);
            int width = j - i;
            int area = minH * width;
            maxCap = max(maxCap, area);
            // when height of right side element is grater
            if(height[i] <= height[j]){
                i++;
            }else{
                j--;
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