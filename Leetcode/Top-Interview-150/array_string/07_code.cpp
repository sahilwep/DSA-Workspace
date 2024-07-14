/*
//  121. Best Time to Buy and Sell Stock        https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=study-plan-v2&envId=top-interview-150


Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

// Brute Force Solution: 
    * We need to find the maximum profit for one day we can buy and another day we can sell.
    * We will maintain two variables: 'Profit' to store the maximum difference, and 'currProfit' to find the difference in every iteration.
    * This solution leads to TLE (Time Limit Exceeded) because the Time Complexity (TC) is O(n^2).

// Efficient Approach:
    * If we carefully observe, we need to find the maximum difference where the smaller element is always on the left and the larger element is on the right.
    * This way, we can get the maximum difference.
    * We can use the Two Pointer approach:
        * We will maintain two pointers: one pointing to the minimum element index and the other to the maximum element index.
        * We will look at the array from the last index to the first, meaning iterations will go from n-1 to 0.
        * Initially, we will set both pointers to the last index (n-1).
        * Whenever we find a larger element, we will change both pointers because we need to look left for the minimum pointer.
        * This is why we will change both pointers.
        * Otherwise, when we find an element that is lesser than the minimum pointer, we will change the minimum pointer to that position.
        * Finally, we will store the maximum difference between arr[maxPointer] - arr[minPointer] and the previously found maximum value.

    * TC: O(n)

*/

#include<bits/stdc++.h>
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

// Bruteforce Solutions: O(n^2), TLE
int maxProfit_(vector<int>& p) {
    int profit = 0;
    for(int i=0;i<p.size();i++){
        int currProfit = 0;
        for(int j=i+1;j<p.size();j++){
            currProfit = p[j] - p[i];
            profit = max(profit, currProfit);
        }
    }
    return profit;
}

// Efficient Solutions: O(n)
int maxProfit(vector<int>& arr) {
    int n = arr.size(); // size of an array
    int minPtr = n-1, maxPtr = n-1; // maintaining both the pointer at last position of array...
    int maxDiff = 0;    // variable to store the maxDifference
    for(int i=n-1;i>=0;i--){    // iteration start from last & goes to first..
        // when the element is greater than the maxPointer, we will change both the pointer..
        if(arr[i] >= arr[maxPtr]){
            maxPtr = i;
            minPtr = i; // we also need to change the minPtr, as it always should be left to maxPtr
        }
        // when the element is lesser than the minPointer, we will change the minPointer...
        else if(arr[i] < arr[minPtr]){
            minPtr = i;
        }
        // finding the max Diff at the end of every iterations:
        maxDiff = max(maxDiff, (arr[maxPtr] - arr[minPtr]));
    }
    return maxDiff;
}

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    cout << maxProfit(v) << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}