/*
//  A. Panoramix's Prediction





// Observations: 
    * There is two number given...
    * we need to check, are these number are prime or not?
    * we also need to check are these number the next to each other or not...
    * If both the condition satisfied, print "YES" : else print "NO"


// Intrusion: 
    * We can first check are these 2 number are prime or not?
    * Then we will check are these number are next to each other or not?


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


bool isPrime(int n){
    if(n == 1) return false;
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(int i=5;i*i<=n;i=i+6){
        if(n % i == 0 || n % (i+2) == 0) return false;
    }
    return true;
}

void solve(){
    int a, b;
    cin >> a >> b;
    bool flag1 = isPrime(a);
    bool flag2 = isPrime(b);

    if(flag1 == 1 && flag2 == 1){
        // let's check next prime number:
        for(int i=a+1;i<b;i++){
            // checking b/w any prime number
            if(isPrime(i) == 1){
                flag1 = false;
                break;
            }
        }
        if(!flag1){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }else{
        cout << "NO" << endl;
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