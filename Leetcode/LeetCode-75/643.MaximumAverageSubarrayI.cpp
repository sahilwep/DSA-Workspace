/*

//  643. Maximum Average Subarray I

//  Observations: 
    * We are given an array consisting n integer, & given an integer k,
    * We need to find the contigious subarray of size k, whose size maximum among all the others subarray.
    * Return that maximum subarray.



// Example:

    Input: nums = [1,12,-5,-6,50,3], k = 4
    Output: 12.75000
    Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

    Input: nums = [5], k = 1
    Output: 5.00000

// Intrusion: 
    // Sliding window approach:
        * We will use k size sliding window approach, & slide it along the way..
        * First we will store the sum of k size window.
        * then start iterating from k till end:
        * While iterating add upcoming element into sum, & subtract the starting element of window

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
    double findMaxAverage(vector<int>& nums, int k) {
        double win = 0;
        
        // Finding the sum of first k size window
        for(int i=0;i<k;i++) win += nums[i];

        double maxAvg = win;
        for(int i=k;i<nums.size();i++){
            win += nums[i];     // Adding the next element into window.
            win -= nums[i-k];   // Removing the starting element from the window
            maxAvg = max(win, maxAvg);  // getting the maximum among all
        }

        // last we are getting the avg of the window size & returning the result
        maxAvg = maxAvg / double(k);

        return maxAvg;
    }
};


void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    Solution obj;
    cout << fixed << setprecision(5) << obj.findMaxAverage(v, k) << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}