/*
//  Count 1's in binary array

// Observations: 
    * We are given a binary array sorted in non-increasing order, we need to print the count of 1's in binary array.


// Intrusion: 
    // Approach 1: Bruteforce
        * Using counter variable that count the number of 1's in an array.
        * TC: O(n)



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
    int countOnes(int arr[], int n){
            int cnt = 0;
            for(int i=0;i<n;i++){
                if(arr[i] == 1) cnt++;
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
        int *arr = new int[n]; 
        for(int i = 0; i < n; i++)
            cin>>arr[i];
            
        Solution ob;
        cout <<ob.countOnes(arr, n)<<endl;
    }
    return 0;
}