/*
//  B. ICPC Balloons


// Observations: 
    * We have string that contains some problems
        * s(i) denotes problem that are solved...
    * If problem solve completely, we will give 2 balloons..
    * else if it is still not solved yet, & present in future parts of array, we will give it 1..
    * we have to count the number for each problem solved..

// Intrusion: 
    * If we carefully observe, the character that comes for the first, we give 2, : else we give 1.
    * We just need to check the occurrence while iterating every items..
        * we can use hashing...

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
    string s;
    cin >> s;
    int cnt = 2;        // for first it always be 1..
    map<char, int> mp;      // create map, to store the frequency..
    for(int i=0;i<n;i++){
        if(i != 0){     // starting from index 1
            // when two consecutive elements are not equal..
            if(s[i] != s[i-1]){ 
                // we have to check, if it is already hashed or this is his first time..
                if(mp[s[i]] == 0){  // for the first time...
                    cnt += 2;
                }else if(mp[s[i]] > 0){     // for already hashed
                    cnt += 1;
                }
            }
            // if two consecutive elements are equal, this means it's already hashed..
            else if(s[i] == s[i-1]){
                cnt += 1;
            }
        }
        mp[s[i]]++;
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