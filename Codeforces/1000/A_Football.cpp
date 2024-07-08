/*
//  A. Football

// Observations: 
    * we need to print the maximum time occurrence team in leader-board..
    * We can use moors voting algorithm:
        * we need to set first element as candidate...
        * we need to maintain counter, that will count the most occurrence element..
        * we will match set first element with every element, if in between the counter is equal to 0, we need to change the set value, i.e we will move the set value to the current value..
        * once we will iterate throughout the array, we will find the most occurrence elements..
    * Last we just need to return most occurrence element...

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



void solve(){
    int n;
    cin >> n;
    string arr[n];
    arrInp;
    // using moors voting algorithm:
    int res = 0;  // Making the candidate as the first index of the array.
    int cnt = 1;    // initial counter as 1
    for(int i=1;i<n;i++){
        if(arr[res] == arr[i]){
            cnt++;
        }else{
            cnt--;
        }
        if(cnt == 0){
            res = i;    // changing the candidate
            cnt = 1;    // making counter = 1
        }
    }
    // we find the maximum occurrence element in list...
    cout << arr[res] << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}