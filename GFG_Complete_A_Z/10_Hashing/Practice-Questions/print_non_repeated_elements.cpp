/*

// Print Non-Repeated Elements:
    * print the non-repeated elements as they appear in the array.




// Examples:

Input:
n = 10
arr[] = {1,1,2,2,3,3,4,5,6,7}
Output: 4 5 6 7
Explanation: 4, 5, 6 and 7 are the only 
elements which is having only 1 
frequency and hence, Non-repeating.

Input:
n = 5
arr[] = {10,20,40,30,10}
Output: 20 40 30
Explanation: 20, 40, 30 are the only 
elements which is having only 1 
frequency and hence, Non-repeating.


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

 vector<int> printNonRepeated(int arr[],int n){
    unordered_map<int, int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    vector<int> res;

    for(int i=0;i<n;i++){
        if(mp[arr[i]] == 1){
            res.push_back(arr[i]);
        }
    }
    return res;
}


void solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin>> arr[i];
    vector<int> res = printNonRepeated(arr, n);
    for(auto i : res) cout << i << " ";
    el;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}