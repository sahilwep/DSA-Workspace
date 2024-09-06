/*

// Binary Array Sorting


// Observations: 
    * We are given a binary array arr[] of size n, we need to sort them in increasing order.

// Example: 
    Input: 
    5
    1 0 1 1 0

    Output: 
    0 0 1 1 1

    Explanation: 
    After arranging the elements in 
    increasing order, elements will be as 
    0 0 1 1 1.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void binSort(int arr[], int n){
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(arr[i] == 0) cnt++;
        }
        int i = 0;
        for(i;i<cnt;i++){
            arr[i] = 0;
        }
        for(int j=cnt;j<n;j++){
            arr[j] = 1;
        }
    }
};

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int A[N]; 
	    
	    for(int i = 0; i  < N; i++) cin>>A[i];
	      
	    Solution obj;
	    obj.binSort(A,N);
	    
	    for(int x:A)
	    cout<<x<<" ";
	      
	    cout<<endl;
	}
	return 0;
}