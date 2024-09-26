/*

//  Subarray with 0 sum



//  Observations: 
        * We are given an array, we need to find the subarray, of atleast size 1 that has sum = 0.


// Example:

    Input:
        n = 5
        arr = {4,2,-3,1,6}
    Output: Yes
    Explanation: 2, -3, 1 is the subarray with sum 0.


    Input:
        n = 5
        arr = {4,2,0,1,6}
    Output: Yes
    Explanation: 0 is one of the element in the array so there exist a subarray with sum 0.

// Intrusion:
    // Bruteforce Solution: 
        * We will select every element one by one & try to find the subarray that is equal to the given sum.
        * TC: O(n^2)  -> TLE


    // Using Sliding Window Approach:
        * we will maintain subarray with atleast window size 1, & try to find the subarray of any size k <= n, which is equal to sum
        * TC: O(n)



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

class Solution{
public:
    // Bruteforce Solution: O(n^2)
    bool subArrayExists(int arr[], int n){
        for(int i=0;i<n;i++){
            int sum = arr[i];
            for(int j=i+1;j<n;j++){
                if(sum == 0) return 1;
                sum += arr[j];
            }
        }
        return 0;
    }
};

int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++) cin>>arr[i];
	    Solution obj;
        if(obj.subArrayExists(arr, n)) cout << "Yes\n";
        else cout << "No\n";
	}
	return 0;
}