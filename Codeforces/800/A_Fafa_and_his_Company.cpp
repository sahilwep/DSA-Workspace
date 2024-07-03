/*
//  A. Fafa and his Company

// Observations:
    * we will have to divide the n employs into 1 team leader & rest of their team members..
    * we have to find the total number of combinations from which we can split the team..
    * As we have given the constrains, that each team has equal no of members..
    * each leader have their own groups of employee..
    * Example: 
        n = 10
            1 leader -> 9 employee
            2 leader -> 4 employee
            5 leader -> 1 employee

    * Others combinations are not possible, like:
            3 leaders -> 
                g1 -> 1, 1, 1
                g2 -> 1, 1
                g2 -> 1, 1
            * Equal members combinations not possible..

    // If we carefully observe, we just need to check the divisibility of numbers...
    // there is no test cases, so we can use this solutions...

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
    int cnt = 0;
    for(int i=1;i<n;i++){
        if(n % i == 0) cnt++;
    }
    cout << cnt <<endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}