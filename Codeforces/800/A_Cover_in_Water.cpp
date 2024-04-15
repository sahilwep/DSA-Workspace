/*
//  A. Cover in Water


// Observation: 
    * if there consecutive '.', are there then we can put two (water.water) & middle one will filled up automatically...
    * Also in this case when middle filled up, we are allowed to move one block of water to another place...
    * We can say if we have "...", three consecutive empty place, we only have to place 2 waters, & we can extract middle one infinite times, as it filled automatically...
    * Rest we have to filled one by one...

// Approach: 
    * we can use loop to iterate over the blocks...
    * We can use a counter to count the empty place..
    * we can use the condition where if "...", three consecutive place are empty, then in this case we put counter value = 2, & break out from loop...
    * Else we will count each '.' individually..
    * End we print the counter value....

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
    int n;
    cin >> n;
    char s[n];
    int res = 0;
    for(int i=0;i<n;i++) cin >> s[i];
    for(int i=0;i<n;i++){
        if(s[i-1] == '.' && s[i] == '.' && s[i+1] == '.' ){
            res = 2;
            break;
        }
        if(s[i] == '.'){
            res++;
        }
    }
    cout << res << endl;
}


int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}