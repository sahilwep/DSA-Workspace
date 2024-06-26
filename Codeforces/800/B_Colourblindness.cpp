/*
//  B. Colourblindness

// Observations: 
    * as per the questions vasya can't determine Green & Blue..
    * We need to find wether two rows are filled with same color or not?
    * we can check both the string & while checking we will ignore the case of "Green" & Blue


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
    string s1, s2;
    cin >> s1 >> s2;
    for(int i=0;i<n;i++){
        if(s1[i] != s2[i]){
            if(s1[i] == 'G' && s2[i] == 'B' || s1[i] == 'B' && s2[i] == 'G'){
                continue;
            }else{
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}