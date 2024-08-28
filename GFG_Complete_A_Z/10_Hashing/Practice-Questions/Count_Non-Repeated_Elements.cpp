/*

// Count Non-Repeated Elements

// Observations:
    * We are given an array that contains duplicate values.
    * We need to count non-repeated elements from an array.

// Intrusion: 
    * We are use map, & return the element that has frequency 1

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int countNonRepeated(int arr[], int n){
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++) mp[arr[i]]++;
        int cnt = 0;
        for(auto i=mp.begin();i!=mp.end();i++){
            if(i->second == 1) cnt++;
        }

        return cnt;
    }

};

int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    cout<<obj.countNonRepeated(arr,n)<<endl;
	    
	}
	return 0;
}