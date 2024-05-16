/*
//  A. George and Accommodation


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
    int rooms;
    cin >> rooms;
    int livingNow;
    int maxCapacity;
    int accommodate = 0;
    for(int i=0;i<rooms;i++){
        cin >> livingNow >> maxCapacity;
        if(maxCapacity - livingNow >= 2) accommodate++;
    }
    cout << accommodate << endl;
}


int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}