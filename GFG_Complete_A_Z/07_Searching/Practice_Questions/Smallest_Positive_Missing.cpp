/*

//  Smallest Positive Missing

//  Observations: 
    * We are given an array with integer, we need to find the smallest missing positive integer.

// Key Observations: 
    * Positive integer: 1, 2, 3, 4, 5, 6,.....


// Example:

    Input:
        N = 5
        arr[] = {1,2,3,4,5}
    Output: 6
    Explanation: Smallest positive missing 
    number is 6.


    Input:
        N = 5
        arr[] = {0,-10,1,3,-20}
    Output: 2
    Explanation: Smallest positive missing 
    number is 2.


// Intrusion:
    * We will use hashing, & store all the element of array into the hashmap.
    * then we will iterate from 1 to 10e7+1 (10^7 is constrain value).
    * TC: O(n)
    * AS: O(n)


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
    int missingNumber(int arr[], int n){ 
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++) mp[arr[i]]++;

        // constrains: 10^6
        int res = 10e7+1;
        for(int i=1;i<=10e6+1;i++){
            if(mp.find(i) == mp.end()){
                res = i;
                break;
            }
        }

        return res;
    } 
};

int main() { 
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        int arr[n];
        
        for(int i=0; i<n; i++)cin>>arr[i];
        Solution ob;
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 