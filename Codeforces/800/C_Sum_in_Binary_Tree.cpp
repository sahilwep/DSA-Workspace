/*
//  C. Sum in Binary Tree

// Observations: 
    * We are given a vertex n, & we have to find the path from 1 to n, & sum up all the vertices..
    * The path will be look something like this: 

                                                       [1]
                                                        |
                                    [2]-------------------------------------[3]
                                     |                                       |
                        [4]--------------------[5]              [6]-------------------------[7]
                         |                      |                |                           |
                    [8]-----------[9]  [10]----------[11]  [12]-------[13]              [14]----------[15]


// Example: 
    n = 3 
        -> path will be: 3 + 1 = 4
    
    n = 10
        -> path will be 10 + 5 + 2 + 1 = 18


// Key Observations: 
    * IF we half the value & sum up we will get the answer.


// Intrusion:   
    // Bruteforce Solution: 
        * At every iterations we will make our value to half.
        * We will sum it up, & return the answer.
        * TC: O(logn)


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
    ll n;
    cin >> n;
    ll sum = 0;
    while(n > 0){
        sum += n;
        n = n/2;
    }
    
    cout << sum << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}