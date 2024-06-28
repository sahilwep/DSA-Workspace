/*
//  B. Ordinary Numbers

// Observations:
    * We will have to find the decimal notation of all the number containing same digits..
    * Constrains: 
        * 1 <= n <= 10^5

// Intrusion: 
    * For every digits, we will have 
        // 1, 2, 3, 4, 5, 6, 7, 8, 9
        // then 11, 22, 33, 44, 55, 66, 77, 88, 99
        // 111, 222, 333, 444, 555, 666, 777, 888, 999,
        // 1111, 2222, 3333, 4444, 5555, 6666, 7777, 8888, 9999,
        // 11111, 22222, 33333, 44444, 55555, 66666, 77777, 88888, 99999
        // so on...
    * We just have to count the number of number of digits
    * We can iterate row wise & multiply that number with number of rows..
    * Then we iterate column wise & count the number of

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
    int n;
    cin >> n;
    int digits = log10(n) + 1;
    // Condition for single digit.
    if(digits == 1){
        cout << n << endl;
        return;
    }
    // condition for more than single digit.
    else{
        // we will have to count such number that digits are same..
        // we know for single digit, such number are in total 9
        int solu = 0;
        for(int i=1;i<digits;i++){
            solu = solu + 9;    // calculating solution before that range..
        }

        // getting the starting value of upcoming range:
        int start = 1;
        for(int j = 1;j<digits;j++){
            start = start * 10 + 1;
        }

        // now counting the number of same digits elements horizontally..
        int i = 1;
        while(i* start <= n){
            i++;
            solu++;
        }
        cout << solu << endl;
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