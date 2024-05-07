/*
//  A Elephant


// Condition
* In one step the elephant can move 1, 2, 3, 4 or 5 positions forward. 



* If we divide our number by 5 & get remainder 0, then we can print our quotient
* else we can print quotient+1


* Example: 
For distance: 21 => takes 5 steps
    explanation : 5 + 5 + 5 + 5 + 1 (total 5 steps)
            21 % 5 != 0, so 21 / 5 = 4.2 = 4
            so we add one to them (4 + 1) = 5 steps


For distance: 66 => takes 14 steps
    explanation: 5+5+5+5+5+5+5+5+5+5+5+5+5+1  => 13 times 5 and + 1 => 66
            21 % 5 != 0, so 66 / 5 = 13.2
            so we add one to them (13 + 1) = 14 steps


for distance: 40 => takes 8 steps
    explanation: 8 times 5
            40 is divisible by 5, so we print (40 / 5) = 8



n = 5
    5 / 5 = 1
        print else case
n = 12 
    12 / 5 = 2.4 = 2
        print else case
n = 25
    30 / 5 = 6

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
#define SQ(a) (a)*(a)



void solve(){
    int n;
    cin >> n;
    if(n % 5 == 0){
        cout << n/5 << endl;
    } else {
        cout << (n/5) + 1 << endl;
    }
}


int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}