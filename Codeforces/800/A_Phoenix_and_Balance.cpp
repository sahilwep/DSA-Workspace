/*

//  A. Phoenix and Balance

// Observations: 
    * we have n coins with weights 2^1, 2^2, 2^3, 2^4,....2^n
    * We need to split these into exactly n/2 pile.
    * Difference of weights should be minimized.
    * a is denoted as sum of first pile, & b is denoted as sum of second pile.
    * we need to minimize the |a - b|, the absolute value of a - b
    * NOTE: As per constrains n will be even.


// Example: 
    2 => 2^1 2^2
            2 4 -> absolute diff = 2

    4 => 2^1 2^2 2^3 2^4
            2 4 8 16
            (2+16) - (4+8) = 6



    6 => 2^1 2^2 2^3 2^4 2^5 2^6

            2 4 8 16 32 64

            (64+2+4) - (32+16+8) 
               70           56   =   14

// Key observations: 
    * for every n integer we have n numbers...
            we just have to split it into half, but we need to split in a way so that we can have minimum difference..


    for n  =  6
            2 4 8 16 32 64
            // First insert values into G2
                * Starting from n-2
                * While inserting values into G2, we will decrement the range..
                    Original Value: 2 4 8 16 32 64
                        i = n-1 to 0
                    i = n-2 to 0   =>   2 4 8 16 32,     G2 = {32}, remove 2
                    i = n-3 to 1   =>   4 8 16,     G2 = {32+16}, remove 4
                    i = n-4 to 1   =>   8,     G2 = {32+16+8}, break;

                * Now, we need to insert values into G1
                    * first we have to insert (n-1)th values into G1 = {64}
                    * Now, we will have to insert values till (n-3), as the pointer shifts...

            



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
    vector<ll> res(n);
    int k = 1;
    for(int i=0;i<n;i++){
        res[i] = pow(2, k++);
    }

    for(auto i: res) cout << i << " ";
    el;

    // Forming Groups:
    int G1 = 0, G2 = 0;
    // Insertion of elements in G1
    int r = 0;
    int i;
    for(i=n-2;i>=r;i--){
        G1 += res[i];
        r++;
    }
    // Insertion of elements in G2
    G2 = res[n-1];
    for(int j=0;j<=i;j++){
        G2 += res[j];
    }

    // Finding absolute difference:
    // cout << G1 << " " << G2 <<  endl;
    cout << abs(G2 - G1) << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}