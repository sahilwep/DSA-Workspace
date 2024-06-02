/*
//  A. Required Remainder



// Observations: 
    * We need to find k for, (k % x == y), where (0 <= k <= n)..

    * We have x, y, n   -> given
   
    * We have to find k for (k % x == y),   maximum int k such that (0 <= k <= n)
    
    * Number Observations:
                * Example: x=7, y=5, n=12345

                * CASE 1: 
                    * if we do n % x
                      rem = 12345 % 7 = 4,       we need 5 at the place of 4 right... 

                    * First let's make remainder 0, if we subtract 4 from 12345 we get 0 as remainder..
                        (12345 - 4 ) % 7 = 0

                    * Now we need remainder as 5 for the condition.., if we will add 5 to upper operations it makes remainder 5
                        (12345 - 4 + 5 ) % 7 = 5
                        ------k------    % x = y        -> We made this condition...

                        * We have to print this: 
                                (12345 -  4  + 5 )
                                (n     - rem  + y ) = result


                    * But In this case:
                        * if we sum up, it's not satisfied condition: (12345 - 4 + 5 ) = 12346, which is grater than n, so going to (CASE 2)


                * CASE 2: 
                        * In this case when result > n:

                            * if we do : 
                             rem =  (12345) % 7 = 4 
                                    (12345 - 7) % 7 = 4, because if we subtract same dividing factor, we get the same remainder...
                            
                            * Now, we have to make remainder 0, simple subtract 4 because it's the remainder we get from previous operations..
                                    (12345 - 7 - 4) % 7 = 0
                            
                            * Now, we need remainder as 5, simply add 5
                                    (12345 - 7 - 4 + 5) % 7 = 5
                                    --------k---------  % x = y
                            
                            * we get the k, & this time k is smaller than previous condition...
                                                    (12345  - 7 -  4  + 5) = 12239
                                * we have to print: (   n   - x - rem + y) = Result



// Pseudo code:
    if((n - (n % x) + y) <= n){
        print((n - (n % x) + y))
    }else{
        print: (n - x - (n%x) + y)
    }


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

// Naive Method: TLE
// void solve(){
//     int x, y, n;
//     cin >> x >> y >> n;
//     int k = n;
//     bool flag = true;
//     while(k >= 0){
//         if(k % x == y){
//             cout << k << endl;
//             break;
//         }
//         k--;
//     }
// }


void solve(){
    int x, y, n;
    cin >> x >> y >> n;
    // getting the remainder of simply (n % x)
    int someRem = n % x;            // this is rem, also used in else case:
    // Now let's make this remainder of previous as 0, & then making it as expected remainder:
    int zeroRem =  (n - someRem + y) % x;       // expected remainder:
    // printing the number: 
    int res = (n - someRem + y);
    // case when result is less or equal n:
    if(res <= n){
        cout << res << endl;
        // cout << (n - someRem + y) << endl;       // we can also print this will give same result...
    }else{
        // Case when result is higher than n itself: 
        cout << (   n   - x - someRem + y) << endl;
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