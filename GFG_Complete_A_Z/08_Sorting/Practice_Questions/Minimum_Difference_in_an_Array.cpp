/*

// Minimum Difference in an Array

// Observations: 
    * We are given an array, & we have to find the minimum difference b/w any pair of element.

// Intrusion:
    * Sort the array, & find the difference b/w two consecutive elements.
    * TC: O(nlogn)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int MinimumDifference(int arr[], int n){
        // Sort the array:
        sort(arr, arr+n);
        int minVal = INT_MAX;
        for(int i=1;i<n;i++){
            minVal = min(minVal, (arr[i] - arr[i-1]));
        }

        return minVal;
    }
};

int main() {
	
	int t;
	cin>>t;
	while(t--){
	    int n; cin>>n;
	    int arr[n]; 
	    for(int i = 0; i < n; i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int diff = ob.MinimumDifference(arr, n);
	    cout << diff << endl;
	}
	return 0;
}