/*

//  B. Not Quite Latin Square


// Observations: 
    * we will have to make this symmetric, means there is one value is missing, we need to find that...
    * We can hash the values & check the missing value..


*/

#include<bits/stdc++.h>
using namespace std;

void solve(){
    unordered_map<char, int> mp;
    char k;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> k;
            mp[k]++;
        }
    }
    for(auto i=mp.begin();i!=mp.end();i++){
        if(i->second == 2){
            cout << i->first << endl;
        }
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