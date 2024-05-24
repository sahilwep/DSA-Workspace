/*
//  A. Sereja and Dima



// Observations: 
    * Let odd case for player 1, & even case for player 2
    * Add numbers using two pointer approach..

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
    arrInp;
    int start = 0;
    int end = n-1;
    int player1 = 0;
    int player2 = 0;
    for(int i=0;i<n;i++){
        if(arr[start] > arr[end]){
            // player 1 chance : odd case
            if(i % 2 != 0){
                player1 += arr[start];
                start++;
            }
            // player 2 chance : even case
            else {
                player2 += arr[start];
                start++;
            }
        } else {
            // player 1 chance : odd case
            if(i % 2 != 0){
                player1 += arr[end];
                end--;
            }
            // player 2 chance : even case
            else {
                player2 += arr[end];
                end--;
            }
        }
    }
    cout << player2 << " " << player1 << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}