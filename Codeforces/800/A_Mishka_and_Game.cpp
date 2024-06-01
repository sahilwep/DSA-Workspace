/*
//  A. Mishka and Game


// Observations: 
    * Simply we have to count the number of each round winner...


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
    cin >>n;
    int m, c;   // players
    int mPoint = 0, cPoint = 0; // point of each player
    for(int i=0;i<n;i++){
        cin >> m >> c;
        if(m > c){
            mPoint++;
        }else if(m < c){
            cPoint++;
        }else{
            mPoint++;
            cPoint++;
        }
    }
    if(mPoint > cPoint){
        cout << "Mishka" << endl;
    }else if(mPoint < cPoint){
        cout << "Chris" << endl;
    }else{
        cout << "Friendship is magic!^^" << endl;
    }

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}