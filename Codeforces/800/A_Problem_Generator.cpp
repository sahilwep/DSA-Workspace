/*

//  A. Problem Generator

// Observations: 
    * Vlad is planning to hold m rounds, next month. each round should contains problem with difficulty level 'A', 'B', 'C', 'D', 'E', 'F' & 'G'
    * He has bank of n problem
    * ith problem are given with difficulty with a[i], there may not be enough of these problems, so he may came up with a few problems.
    * he want to came up with as few problem as possible, so he asked to find the minimum number of problem he need to came up with in order to hold m rounds.
    * Example:
        a = BGECDCBDED, m = 1, n = 10
        * Then he need to came up with two problem, one with difficulty level 'A' & one with difficulty level 'F'

    * In conclusion: 
        * we are given set of problem, with difficulty..
        * Some question are missing..
        * We are given m, which is round..
        * We need to find the for each round if any question is lesser than, we need to return that, by subtracting from round..

// Intrusion: 
    * we can use map for for hashing the string characters..
    * At last we can match the character which has frequency less than m,
    * we can sum up those numbers, by subtracting from m...


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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    // hashed string characters:
    map<char, int> mp;
    for(char ch = 'A';ch<='G';ch++){
        mp[ch] = 0;
    }
    for(int i=0;i<n;i++){
        mp[s[i]]++;  
    }

    // checking the need:
    int need = 0;
    for(char i='A';i<='G';i++){
        if(mp[i] < m){
            need += (m - mp[i]);

        }
    }
    cout << need << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}