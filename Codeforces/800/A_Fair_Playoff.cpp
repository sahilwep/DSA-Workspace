/*
//  A. Fair Playoff



// Observations: 
    * We have to check the looser member from winner team, with looser in final tournament.


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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    // first tournament
    int team1Max = max(a, b);   // winner
    int team1Min = min(a, b);   // looser

    int team2Max = max(c, d);   // winner
    int team2Min = min(c, d);   // looser


    // final tournament
    bool flag = false;     // this flag will tell about which team we have to check..
    // team 1 win
    int finalWinner, finalLooser;
    if(team1Max > team2Max){
        finalWinner = team1Max;        // winner in final tournament
        finalLooser = team2Max;        // looser in final tournament
        flag = false;       // check team 1 looser with final looser
    }
    // team 2 win
    else if(team1Max < team2Max){
        finalWinner = team2Max;        // winner in final tournament
        finalLooser = team1Max;        // looser in final tournament
        flag = true;       // check team 2 looser with final looser
    }

    // we have to check looser from final tournament with looser with first tournament.
    // check team 1, false case
    if(!flag){
        if(team1Min > finalLooser)  cout << "NO" << endl;
        else  cout << "YES" << endl;
    }
    // check team 2, true case
    else{
        if(team2Min > finalLooser)  cout << "NO" << endl;
        else cout << "YES" << endl;
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