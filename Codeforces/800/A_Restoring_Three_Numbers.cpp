/*
//  A. Restoring Three Numbers


// Observation: 
    * Given pair: a+b, a+c, b+c and a+b+c in random order

    * If a+b+c - ( (a+b) || (a+c) || (b+c) ) => get any one of three number for sure..

    3 6 5 4
            a+b+c = 6, max_value
            letFirst = 3
            letSecond = 5
            letThird = 4
            
            letFirst = 6 - 3 = 3
            letSecond = 6 - 5 = 1
            letThird = 6 - 4 = 2
        
    201 101 101 200

            a+b+c = 201, max_value
            let first = 201 - 101 = 100
            let second = 201 - 101 = 100
            let third = 201 - 200 = 1

    * We can print answer in any order..

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
    int first, second, third, fourth;
    cin >> first >> second >> third >> fourth;
    int sum = max(max(first, second), max(third, fourth));
    if(sum == first){
        first = sum - fourth;
        second = sum - second;
        third = sum - third;
        cout << first << " " << second << " " << third << endl;

    }else if(sum == second){
        first = sum - first;
        second = sum - fourth;
        third = sum - third;
        cout << first << " " << second << " " << third << endl;

    }else if(sum == third){
        first = sum - first;
        second = sum - second;
        third = sum - fourth;
        cout << first << " " << second << " " << third << endl;

    }else if(sum == fourth){
        first = sum - first;
        second = sum - second;
        third = sum - third;
        cout << first << " " << second << " " << third << endl;
    }
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}