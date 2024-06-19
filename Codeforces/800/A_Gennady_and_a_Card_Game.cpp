/*
//  A. Gennady and a Card Game


// Observations: 
    * 52 cards Total
    * Each card has suit: 
        * Diamond - D
        * Club - C
        * Spread - S
        * Hearts - H
    * Rank: 2 3 4 5 6 7 8 9 A T J Q K A
    * At start, one card is on table, & five cards in our hand,
    * We can play a card from our hand only if, the same rank or same suit as the card on the table..
    * We have to check if we can play atleast one card..

// Intrusion: 
    * for any s[i] on hand, if there exist in any of the card in table we return 1 : else 0

// Complexity: 
    * TC: O(n)
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
    string s;
    cin >> s;
    string k;
    bool flag = 0;
    for(int i=0;i<5;i++){
        cin >> k;
        if(k[0] == s[0] || k[1] == s[0] || k[1] == s[1] || k[0] == s[1]){
            flag = 1;
        }
    }
    (!flag) ? cout << "NO" : cout << "YES";
    el;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}