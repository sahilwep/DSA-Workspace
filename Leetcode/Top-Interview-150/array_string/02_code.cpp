/*
// 27. Remove Element  https://leetcode.com/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-150

* There is an array of size n {a1, a2....an-1}, & there will be k value passed...
* We need to remove the k element from the an array....
* return the new size of an array...


// Input: 
2
8 2
0 1 2 2 3 0 4 2
4 3
3 2 2 3

// Expected output: 
0 1 3 0 4 
2 2 


 */ 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define arrInp for(int i=0;i<n;i++) cin >> arr[i];
#define arrOut(k) for(int i=0;i<n;i++) cout << arr[i] <<  k;
#define el cout << endl;
#define SQ(a) (a)*(a)

int removeElement(int arr[], int n, int k){
    int l = 0;
    for(int i=0;i<n;i++){
        if(arr[i] != k){
            arr[l++] = arr[i];
        }
    }
    return l;
}

void solve(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    arrInp;
    n = removeElement(arr, n, k);
    arrOut(" ");
    el;
}


int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}