/*
//  C. Target Practice
 
 
// Observation: 
 
        for i & j :  0 & 9 values, -> 1 points.
        for i & j :  1 & 8 values, -> 2 points.
        for i & j : 2 & 7 values, -> 3 points.
        for i & j : 3 & 6 values, -> 4 points.
        for i & j : 4 & 5 values, -> 5 points.
 
    * While iterating, we simply count the values, that satisfies this position conditions...
 
 
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
 
 
 
void solve(){
    char arr[10][10];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin >> arr[i][j];
        }
    }
    int cnt = 0;
    // condition check : 
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(arr[i][j] == 'X'){
                // one point: 
                if(i == 0 || i == 9  &&  j >= 0 || j <= 9)  cnt = cnt + 1;
                else if(i == 1 || i == 8 &&  j >= 1 || j <= 8)  cnt = cnt + 2;
                else if(i == 2 || i == 7 &&  j >= 2 || j <= 7)  cnt = cnt + 3;
                else if(i == 3 || i == 6 &&  j >= 3 || j <= 6)  cnt = cnt + 4;
                else if(i == 4 || i == 5 &&  j >= 4 || j <= 5)  cnt = cnt + 5;
            }
        }
    }
    cout << cnt << endl;
}
 
 
int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}