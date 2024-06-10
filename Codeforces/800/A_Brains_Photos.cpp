/*
//  A. Brain's Photos


// Observations: 
    * Simple comparision..

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
    int n, m;
    cin >> n >> m;
    char ch = 'B';
    bool flag = false;
    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> ch;
            if(ch == 'C' || ch == 'M' || ch == 'Y') flag = true;
        }
    }
    
    if(!flag){
        cout << "#Black&White" << endl;
    } else{
        cout << "#Color" << endl;
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