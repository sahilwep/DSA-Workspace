/*
//  C. Can I Square?


// Observations: 
    * We need to make square of given ai
    * We can sum all the element, then find the square if it's possible or not?..


    for any number we can check till square root of that number...
        
        // 1*1  = 1  
        // 2*2  = 4  
        // 3*3  = 9  
        // 4*4  = 16  
        // 5*5  = 25  
        // 6*6  = 36  

        i = 1 -> (i*i <= sum_of_all_the_number)

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

bool isPerfectSquare(ll n)
{
    ll temp = sqrt(n);  // we get the sqrt value,

    if (temp * temp == n) return true;  // if it's perfect square, return true
    else return false;  // else false..
}

void solve(){
    ll n;
    cin >> n;
    ll arr[n];
    arrInp;
    ll sum = 0;
    for(ll i=0;i<n;i++){
        sum += arr[i];
    } 

    if(isPerfectSquare(sum)){
        cout << "YES";
    }else{
        cout << "NO";
    }
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