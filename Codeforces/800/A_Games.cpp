/*
//  A. Games

// Observations: 
    * If we carefully observe the pattern, 
    * There are n teams : 
    * There are total n(n-1) games
    * Each team has their own set's of team uniform for home_ground & guest_ground match
    * We have to count the number of many team's uniform match during the home_ground match & guest_ground match..


Input: 
3
1 2
2 4
3 4
output: 1
// explanations: 
                let team be  :   A  B  C
                    home uni :   1  2  3
                    home uni :   2  4  4
                * as the match goes :
                                    A-->A = skip
                                    A-->B = unique
                                    A-->C = unique
                                    B-->A = match
                                    B-->B = skip
                                    B-->C = Unique
                                    C-->A = Unique
                                    C-->B = Unique
                                    C-->c = skip
                        * Here only 1 games has their uniform match...
                        * we have to skip the same match..

// Approach: 
    * We can use two different array to store uniform color..
    * them we can match them & compare the color...
    * If we got the color matching of home & guest we will increase counter...


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
    // input: 
    int n;
    cin >> n;
    int cnt = 0;
    vector<int> h(n), g(n); 
    for(int i=0;i<n;i++){
        cin >> h[i] >> g[i];
    }

    // Operations:
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                if(i == j)  continue;
                if(h[i] == g[j])    cnt++;
        }
    }
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