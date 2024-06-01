/*
//  A. Team Olympiad


// observations: 
    * we have to print the number of maximum team we can make for an event with ordering of the position..

// Intrusion: 
    * as we have only 3 sub, we can make 3 array of dynamic size...
    * we can store their position...
    * now we can print the team & their order...
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
    vector<int> math, prog, pe; // create 3 different array, to store their position..
    int x;
    for(int i=1;i<=n;i++){
        cin >> x;
        // storing their position as per the constrains of given question...
        if(x == 1) prog.push_back(i);
        else if(x == 2) math.push_back(i);
        else if(x == 3) pe.push_back(i);
    }

    // for making team we can have the min no of stored player across different stream...
    int ans = min(math.size(), min(prog.size(), pe.size()));
    cout << ans << endl;
    // printing the order in similar fashion: 
    for(int i=0;i<ans;i++){
        cout << prog[i] << " " << math[i] << " " << pe[i] << endl;
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