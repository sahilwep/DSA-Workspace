/*
//  A. Anton and Letters


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
    string value;
    getline(cin, value);
    set<char> hash;
    for(int i=0;i<value.length();i++){
        if(value[i] >= 'a' && value[i] <= 'z'){
            hash.insert(value[i]);
        }
    }
    // to print the element of hash values: 
    // for(set<char>::iterator it = hash.begin();it != hash.end();it++){
    //     cout << *it;
    // }
    cout << hash.size() << endl;
    
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;   

    cin.ignore();   // Ignore the newline character left in the buffer

    while(t--){
        solve();
    }
    
    return 0;
}