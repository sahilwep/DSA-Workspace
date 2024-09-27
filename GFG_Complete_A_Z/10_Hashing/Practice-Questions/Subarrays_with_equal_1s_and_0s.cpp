/*

//  Subarrays with equal 1s and 0s

//  Observations: 
    * Given an array counting 0's & 1's, Find the number of subarray having equal numbers of 0s and 1s.


// Example: 

    Input:
        n = 7
        A[] = {1,0,0,1,0,1,1}
    Output: 8
    Explanation: The index range for the 8 
        sub-arrays are: (0, 1), (2, 3), (0, 3), (3, 4), 
        (4, 5) ,(2, 5), (0, 5), (1, 6)

    Example 2:

    Input:
        n = 5
        A[] = {1,1,1,1,0}
    Output: 1
    Explanation: The index range for the subarray is (3,4).


// Intrusion: 
    // Bruteforce Approach: 
        * Selecting element one by one & counting number of 0's & 1's, then matching whether they are equal or not, depending on that we will increment the counter..
        * TC: O(n^2)
    
    
    // Hashing Approach:
        * 



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
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n){
        long long int cnt = 0;
        for(int i=0;i<n;i++){
            int Zcnt = 0;
            int Ocnt = 0;
            for(int j=i;j<n;j++){
                if(arr[j] == 1) Ocnt++;
                else if(arr[j] == 0) Zcnt++;
                
                if(Ocnt == Zcnt) cnt++;
            }
        }
        
        return cnt;
        
    }
};

int main(){
	int t;
	cin>>t;
	while(t--){
        int n,i;
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++) cin>>arr[i];
        Solution obj;
        cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}