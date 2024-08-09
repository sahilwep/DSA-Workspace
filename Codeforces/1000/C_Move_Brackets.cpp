/*
//  C. Move Brackets

// Observations: 
    * we are given a bracket sequence s of length n, where n is even...
    * In One move we can choose exactly one move, & it is the beginning of string or to the end of the string...
    * we have to find the 

// Intrusion: 
    * Ideas is to count the number of opening & closing brackets..
    * if we got closing bracket before encountering the opening bracket we consider it to be flipped..
    * We can use counter approach to count the opening bracket & closing brackets...
    * we need equilibrium value to be regular brackets..
    * If we don't have the equilibrium, means there is some extra brackets..
    * if our value goes lesser than 0, we known we need to remove these values...

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
    cin >> n;
    string s;
    cin >> s;
    int total = 0;
    int flip = 0;
    for(int i=0;i<n;i++){
        if(s[i] == '('){
            flip++;
        }else{
            flip--;
        }
        if(flip < 0){
            total++;
            flip = 0;
        }
    }
    cout << total << endl;
}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}