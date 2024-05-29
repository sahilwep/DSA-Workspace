/*
//  A. Holiday Of Equality



// Observations: 
    * we have to give the money across the citizens so that they all have equal money..
    * We have to compute the minimum number of money..

// Intrusion: 
    * as we have to separate money across the citizens equally,
    * First, we choose the citizens that has max number of money..
    * now, we will distribute money to every person, so that it's equal to that person that has max money..
    * We can count the number of money that we are distributing....

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
#define SQ(a) (a)*(a);



void solve(){
    int n;
    cin >> n;
    int arr[n];
    int max = -1;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(arr[i] > max){
            max = arr[i];
        }
    }
    int giveMoney = 0;
    for(int i=0;i<n;i++){
        if(arr[i] < max){
            giveMoney += max - arr[i];
        }
    }
    cout << giveMoney << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}