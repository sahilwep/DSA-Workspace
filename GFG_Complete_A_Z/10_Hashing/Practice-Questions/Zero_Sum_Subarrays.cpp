/*

//  Zero Sum Subarray

//  Observations: 
    * We are given an array arr[] of size n, & we need to count the number of subarray that has sum equals to 0

// Examples:

    Input: n = 6, arr[] = {0,0,5,5,0,0}
    Output: 6
    Explanation: The 6 subarray are [0], [0], [0], [0], [0,0], and [0,0].

    Input: n = 10, arr[] = {6,-1,-3,4,-2,2,4,6,-12,-7}
    Output: 4
    Explanation: The 4 subarray are [-1 -3 4], [-2 2], [2 4 6 -12], and [-1 -3 4 -2 2]


// Intrusion: 
    // Bruteforce Approach: 
        * We will use nested loop to find the number of subarray with sum '0'
        * TC: O(n^2)
    
    // Hashing Approach:
        * We will use map to store cumulative sum & the frequency of their occurrence, & count the frequency while storing.
        * Note: When we have sum occurring again in hashmap, we will store the frequency in count.
        * Note: We have to insert (mp[0] = 1) first so that if we have 0 in starting of an array, we can include these case.
        * TC: O(n*logn)


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

class Solution{
public:
    // Bruteforce Approach:
    long long int findSubarray_Brute(vector<long long int> &arr, int n){
        long long int cnt = 0;

        for(int i=0;i<n;i++){
            long long int sum = 0;
            for(int j=i;j<n;j++){
                sum += arr[j];
                if(sum == 0){
                    cnt++;
                } 
            }
        }

        return cnt;
    }

    // Hashing Approach: 
    long long int findSubarray(vector<long long int> &arr, int n){

        long long int cnt = 0;
        long long int sum = 0;
        // Using map that store cumulative sum as key & frequency as occurrence.
        unordered_map<long long int, long long int> map;

        // Edge case: Initialize with sum = 0(for subarray starting from index 0)
        map[0] = 1;

        for(int i=0;i<arr.size();i++){
            sum += arr[i];

            // element is occurred again or sum is equal to 0:
            if(map.find(sum) != map.end()){
                // If the sum has occurred, add the frequency of sum to the count.
                cnt += map[sum];
            }

            // Increment frequency count
            map[sum]++;
        }

        return cnt;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++) cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}