/*

//  Minimum Number in a sorted rotated array

//  Observations: 
    * We are given an array of sorted element, which was sorted initially, The array may be rotated at some unknown point
	* Task is to find the minimum element in the given sorted rotated array.



// Example:

	Input:
		N = 10
		arr[] = {2,3,4,5,6,7,8,9,10,1}
	Output: 1
	Explanation: The array is rotated 
	once anti-clockwise. So minimum 
	element is at last index (n-1) 
	which is 1.

	Input:
		N = 5
		arr[] = {3,4,5,1,2}
	Output: 1
	Explanation: The array is rotated 
	and the minimum element present is
	at index (n-2) which is 1.



// Intrusion:
	// Linear search: 
		* TC: O(n)


	// Binary Search: 
		* TC: O(logn)


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


// Linear Search:
int minNumber_Linear(int arr[], int low, int high){
	int min = 10e7 + 1;
	for(int i=low;i<=high;i++){
		if(arr[i] <= min){
			min = arr[i];
		}
	}
	
	return min;
}


// Binary Search: log n
int minNumber(int arr[], int low, int high){
	while(low <= high){
		// The current subarray is already sorted, the maximum is at the low index:
		if(arr[low] <= arr[high]){
			return arr[low];
		}

		// we reach here when we have at least two element and the current subarray is rotated:
		int mid = (low + high) / 2;

		// The right half is not rotated. So the minimum element must be in the right half.
		if(arr[mid] > arr[high]){
			low = mid + 1;
		}
		// The right half is sorted. Note that in this case, we do not change to mid - 1, but keep it to mid.
		// And the mid element itself can be the smallest.
		else{
			high = mid;
		}
	}

	return arr[low];
}

int main(){
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i) cin>>a[i];	
		cout << minNumber(a,0,n-1) << endl;
	}
	return 0;
}