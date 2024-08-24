/*

//  B. Seating in a Bus

// Observations: 
    * A bus consist of n row from 1 to n,
    * passengers are advice to follow these rules: 
        * If there are no occupied seats in the bus, a passenger can sit in any free seat.
        * Otherwise a passenger should sit in any free seat that has atleast one neighboring seat occupied.
            * In simple word, seat with index i, only if at least one of the seat occupy seat with index i-1, or i+1 is occupied.
    * We are given an array of size n, i represent the passenger from (1-n), & ai-> represent the seat number.
    * We have to determine whether all passengers follow the recommendations or not?
    * If they have follow the recommendations return "YES" : else return "NO"

    * Example:
        size:  5
        Input: 5 4 2 1 3

            Bus [5|4|2|1|3]
                1 2 3 4 5
    
        * First passenger sit at seat 5, left of seat 5 = empty
        * second passenger sit at seat 4, left of seat 4 = empty
        * third passenger sit at seat 2, which is not left of seat of 4..
        * We will maintain left & right seat pointer, that holds value i+1 & i-1
            * while iterating we can check, if left-1 or right+1 is not equal arr[i], we return "NO" : else "YES"

    * Example:
        size:  3
        array: 2 3 1

        left = 2, right = 2
            * First passenger sit at seat 2, left = 2, & right = 2
            * Second passenger sit at seat 3, left Not matched, right matched, as (right + 1)
            * third passenger sit at seat 1, left matched as (left -1), right not matched..

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
    vector<int> arr(n);
    for(auto &i : arr) cin >> i;
    
    int left = arr[0], right = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i] == right+1){
            right++;
            continue;
        }
        else if(arr[i] == left - 1){
            left--;
            continue;
        }else{
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}