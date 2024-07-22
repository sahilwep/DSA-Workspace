/*
//  A. LCM Problem

// Observations: 
    * LCM of two number x & y is minimum positive number that is divisible by x & y..
    * we are given l & r, we can say left and right range, & we have to find two number x & y
    * y should be grater than x. & LCM of (x,y) these two number should be lies b/w l & r
    * If there is no such number return -1 -1 : else print those numbers x & y

    * If we carefully observe the case of LCM
 
        for two number LCM is 2, 3 -> 6

            (1    2    3    4)
             L              R

            * If the L is 1 next number is multiple of that number with 2..
            * and their next number is again multiple of 2..
                1*2 = 2
                2*2 = 4
                lcm of (2, 4) = 4, and both the number is lies b/e the range...

                 -> for every number if we multiply with 2, we will found the closest multiple of any number...
                3 -> next multiple is 6, which is 3*2
                2 -> next multiple is 4, which is 2*2
                1 -> next multiple is 2, which is 1*2

            * we have taken an example of small number, for any large number if multiply it by 2, we will found the next multiple...

            * So, If we take the smallest number i.e l, & take the next multiple of l, which is 2*l, & if this lies in this range, then the answer is l & 2l
            * else there is no such number...

            * So smallest the number we take and multiply it with 2, more the chance it will lie int the range..
            * If it's go out of the range, we will say not possible..

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
    ll l, r;
    cin >> l >> r;
    if(l*2 <= r){
        cout << l << " " << 2*l << endl;
    }else{
        cout << -1 << " " << -1 << endl;
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