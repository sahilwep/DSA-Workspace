/*
//  Kth smallest element

// Observations:
    * We are given an array, & we have to find the kth smallest element from that array.


// Intrusion: 
    * Sort the array, & then return the kth smallest.
    * TC: O(nlogn)


*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int kthSmallest(int arr[], int n, int k){
        sort(arr, arr+n);
        return arr[k-1];
    }
};

int main(){
	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    int arr[n];
	    for(int i = 0; i<n; ++i) cin>>arr[i];
	    Solution ob;
	    cout << ob.kthSmallest(arr, n, k) << endl;
	    
	}
	return 0;
}