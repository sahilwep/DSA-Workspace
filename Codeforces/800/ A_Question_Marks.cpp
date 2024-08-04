/*
//  A. Question Marks

// Observations: 
    * We have to count the number of attempt question that are correct...

// Intrusion: 
    * We can store the frequency of all the number...
    * once we have frequency of all the number we can sum the frequency of all the answer except '?'
        * we also need to take care of maximum marks that we can get & the score that we have...
        * So we have to store the min(frequency, given max marks)



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
    unordered_map<char, int> mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }

    int solu = 0;
    for(auto i=mp.begin();i!=mp.end();i++){
        if(i->first != '?'){
            solu += min(i->second , n); 
        }
    }
    
    cout << solu << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}