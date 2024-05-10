/*
//  A. Fox And Snake



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
    int n, m;
    cin >> n >> m;
    bool flag = false;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i % 2 != 0){
                cout << "#";
            }
            else{
                if(flag == false){
                    if(j<m){
                        cout << ".";
                    }else{
                        cout << "#";
                        flag = true;
                    }
                } else {
                    if(j == 1){
                        cout << "#";
                    } else {
                        cout << ".";
                    }
                    if(j == m){
                        flag = false;
                    }
                }
            }
        }
        el;
    }

    
    
}


int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
        el;
    }
    
    return 0;
}