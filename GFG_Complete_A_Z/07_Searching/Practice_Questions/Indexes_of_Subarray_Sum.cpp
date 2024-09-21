/*

//  Indexes of Subarray Sum

//  Observations:
    * We are given array of size n that contains non-negative number, find a sub-array that has equal to s.
    * We mainly return the left & right index of subarray,(1-based index).
    * In case of multiple sub-array, we have to return the first subarray.
    * If no such subarray matched with given sum we have to return -1

// Example:

    Input: arr[] = [1,2,3,7,5], n = 5, s = 12
    Output: 2 4
    Explanation: The sum of elements from 2nd to 4th position is 12.

    Input: arr[] = [1,2,3,4,5,6,7,8,9,10], n = 10, s = 15,
    Output: 1 5
    Explanation: The sum of elements from 1st to 5th position is 15.

    Input: arr[] = [7,2,1], n = 3, s = 2
    Output: 2 2
    Explanation: The sum of elements from 2nd to 2nd position is 2.

    Input: arr[] = [5,3,4], n = 3, s = 2
    Output: -1


Explanation: There is no subarray with sum 2

// Intrusion: 
    // Bruteforce Approach:
        * We can select every element one by one, & try to find the sub-array, & when we got matched sum, we will return the starting & ending index.
        * TC: O(n^2)    -> TLE


    // Sliding Window Approach:
        * We will use sliding window approach, 
        * In this approach we will continuously increase window size until we will reach the subarray size.
        * If our window size is increased above than the subarray size, we will start removing the elements from the start until we got equal or lesser size of that window.
        * this is how we can find the subarray sum of window, if there is available, else we will return -1.
        * Example Working
            * We will maintain two pinter start & end:
                * start pointer used to remove element if our window size more than the curent sum.
                    * Note: While current sum is greater than the Given Subarray sum & start pointer is less than the end till we remove the start elements from the array.
                * end pointer adds element one by one, & try to get equal to the subarray sum size.
            * At the end we will match the window size with given subarray, if it's get matched we will return the [start, end] index, else return -1.

        * TC: O(n)
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
    // Bruteforce Approach: O(n^2)
    vector<int> subarraySum_Brute(vector<int> arr, int n, long long s){
        vector<int> res;
        for(int i=0;i<n;i++){
            int curSum = arr[i];
            if(curSum == s){
                res.push_back(i+1);
                res.push_back(i+1);
                break;
            }
            bool isFound = 0;
            for(int j=i+1;j<n;j++){
                curSum += arr[j];
                if(curSum == s){
                    res.push_back(i+1);
                    res.push_back(j+1);
                    isFound = 1;
                    break;
                }
                // Optimizations: if current sum is greater than the given subarray sum break
                if(curSum > s){
                    break;
                }
            }
            if(isFound) break;
        }
        if(res.empty()){
            res.push_back(-1);
        }

        return res;
    }

    // Sliding Window: O(n)
    vector<int> subarraySum(vector<int> arr, int n, long long s){
        int start = 0;  // starting index
        long long currSum = 0;  // this will maintain the window sum
        vector<int> res;

        for(int end=0;end<n;end++){
            // Expanding window size by adding arr[end]
            currSum += arr[end];

            // Shrink the currSum while currSum is grater than s, & start less than end
            while(currSum > s && start < end){
                currSum -= arr[start];
                start++;
            }

            // Check if we'he found the subarray with the target sum
            if(currSum == s){
                // 1-based index
                res.push_back(start+1);
                res.push_back(end+1);
                return res;
            }
        }

        res.push_back(-1);
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long s;
        cin >> n >> s;
        vector<int> arr(n);
        // int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}