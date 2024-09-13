/*
//  Peak Element:

// Observations: 
    * We are given an array, & we need to find it's peak element & return it's index.
    * Peak Element: a value is considered as peak if it's value is grater than or equal to value of it's adjacent element.


// Example: 
    Input: n = 3, arr[] = {1, 2, 3} 
    Output: 1
    Explanation: If the index returned is 2, 
        then the output printed will be 1. 
        Since arr[2] = 3 is greater than its adjacent elements, 
        and there is no element after it, we can consider it as a peak element. 
        No other index satisfies the same property, so answer will be printed as 0.

    Input: n = 7, arr[] = {1, 1, 1, 2, 1, 1, 1}
    Output: 1
    Explanation: In this case there are 5 peak elements with indices as {0,1,3,5,6}.
        Returning any of them will give you correct answer.

// Intrusion: 
    * handle First & last element explicitly
        * if(arr[0] >= arr[1]) return 0
        * if(arr[n-1] >= arr[n-2]) return n-2
    * Iterate from index 1 to n-2, & check the condition that whether element is grater or equal to their adjacent element or not?
        * if(arr[i] >= arr[i-1] && arr[i] >= arr[i+1]) return i


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

class Solution{
public:
    int peakElement(int arr[], int n){
        // Case of Corner Element:
        if(arr[0] >= arr[1]){
            return 0;
        }
        else if(arr[n-1] >= arr[n-2]){
            return n-1;
        }
        for(int i=1;i<n-1;i++){
            if(arr[i] >= arr[i-1] && arr[i] >= arr[i+1]){
                return i;
            }
        }
    }
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n], tmp[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
			tmp[i] = a[i];
		}
		bool f=0;
		Solution ob;

		int A = ob. peakElement(tmp,n);
		if(A<0 and A>=n) cout<<0<<endl;
		else{
    		if(n==1 and A==0) f=1;
    		else if(A==0 and a[0]>=a[1]) f=1;
    		else if(A==n-1 and a[n-1]>=a[n-2])  f=1;
    		else if(a[A]>=a[A+1] and a[A]>= a[A-1]) f=1;
    		else  f=0;
    		cout<<f<<endl;
		}
	}

	return 0;
}