/*
//  A. Pangram


// observations: 
    * if sentence contains all the alphabet, then we can say that it is pangram
    * String contains upper & lower case character, we can convert them into either upper or lower case..
    * We can store the frequency, in hash array,
    * later we can check the small case range if they have the frequency is more than 0 or not, if it's contains character with 0 frequency then, we can return false.

// ASCII : 
65 = A         97 = a
90 = Z          122 = z


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
    string s;
    cin >> n >> s;
    int hash[91] = {0}; // create 91 size array that can store the frequency of Upper case
    for(int i=0;i<n;i++){
        if(s[i] > 91){
            s[i] = s[i] - 'a' + 'A' + 0;
            hash[int(s[i])]++;
        }else{
            hash[int(s[i])]++;
        }
    }
    for(int i=65;i<=90;i++){
        if(hash[i] == 0){
            cout << "NO" << endl;
            return;
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