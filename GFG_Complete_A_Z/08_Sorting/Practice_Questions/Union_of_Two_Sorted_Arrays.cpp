/*

// Union of Two Sorted Arrays

// Observations: 
    * We are given two array, & we have to find the union of it.
    * Union: all the element that are distinct & duplicates from both the array.

// Intrusion: 
    * We can use set data structure that will store the unique values from both the array, & store  all the values from both the array.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m){
        set<int> s;
        for(int i=0;i<n;i++){
            s.insert(arr1[i]);
        }
        for(int i=0;i<m;i++){
            s.insert(arr2[i]);
        }
        vector<int> res;
        for(auto i: s){
            res.push_back(i);
        }

        return res;
    }
};

int main() {
	
	int T;
	cin >> T;
	
	while(T--){

	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	}
	
	return 0;
}