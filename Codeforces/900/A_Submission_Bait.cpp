/*

//  A. Submission Bait


// Observations: 
    * alice & bob are playing games of array of size n.
    * they take turns to do operations. with alice start first.
    * the player who not operate will loose. At first variable mx is set as 0. 
    * In one operations a player can do:
        * choose an index i (1 <= i <= n) such that ai > mx & set mx to ai, & then set ai to 0.
    * Determine the alice has winning strategy or not?


// Key observations:
    * First turn is alice.
    * second turn is bob.
       
    Example: 
        arr: 1 2 2 2, mx = 0     -> "YES"
         
            1 2 2 0    alice, mx = 2
            1 2 0 0    bob, mx = 2
            1 0 0 0    alice, mx = 2
            it's not possible to change mx at bob turns, so alice wins..


        arr: 3 3 4 4, mx = 0 -> "NO"

            3 3 4 0     alice, mx = 4
            3 3 0 0     bob, mx = 4
            It's not possible to change mx at alice turns, so alice loss..

    * for turns when alice wins "YES"
    * for turns when bob wins "NO"


// Key Observations: 
    * We have to determine if alice has wins strategy or not?
    * For any array element
        * If alice will choose a number from even set of same numer always bob will win, because at last term bob have the chance..
        * we alice will choose from odd set of elements alice will wins always..
        * Example:
            3 3 4 4 
                * For this case {3, 3} & {4, 4} whatever we choose, always bob will wins
            3 3 3 4 4
                * For this case alice will wins if he start from 3 set..
                    3 3 3 4 4   Initially, mx = 0
                    0 3 3 4 4   alice, mx = 3
                    0 0 3 4 4   bob, mx = 3
                    0 0 0 4 4   alice, mx = 3
                    0 0 0 0 4   bob, mx = 4
                    0 0 0 0 0   alice wins, mx = 4

    * So, from this we can observe that if alice will select any number form the odd set of same numbers he wins.
    * Else he will not..
    * From this we can conclude that if we have any odd set of same numbers, we can say "YES" : Else "NO"


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
    int arr[n];
    unordered_map<int, int> mp;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        mp[arr[i]]++;
    }

    for(auto i=mp.begin();i!=mp.end();i++){
        if(i->second % 2 != 0){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}