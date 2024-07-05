/*
//  A. Make it White

// Observations: 
    * we just have to get first & last position of black tile..
    * & then from that range we can count the numbers...


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
    string s;
    cin >> n >> s;
    // first B from starting
    int start = 0;
    bool flag = false;
    for(int i=0;i<n;i++){
        if(s[i] == 'B'){
            flag = true;
            start = i;
            break;
        }
    }
    if(!flag){   
        cout << 0 << endl;
        return;
    }
    // First B from ending
    int end = 0;
    for(int i=n-1;i>=0;i--){
        if(s[i] == 'B'){
            end = i;
            break;
        }
    }
    // counting the numbers of 
    int cnt = 0;
    for(int i=start;i<=end;i++) cnt++;
    cout << cnt << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}