/*

//  A. Musical Puzzle

// Observations: 
    * we are given a string containing 'a', 'b', 'c', 'd', 'e', 'f', & 'g'
    * We are given a melody that contains two characters, Example: 
        ab, ba, are two melody, we can merge together to make: aba, & merge 'ab' to get abab
    * We have to determine the minimum number of melody consisting two nodes that he needs to record in order to obtain the melody s.
    * As we have to get characters in pair..
    * and we have to get all the combinations, we don't need duplicates
    * We can use set data structure..

*/

#include<bits/stdc++.h>
#include<set>

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
    set<pair<char, char> > res;

    for(int i=0;i<s.size()-1;i++){
        pair<char, char> sub;
        sub.first = s[i];
        sub.second = s[i+1];
        res.insert(sub);
    }
    cout << res.size() << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}