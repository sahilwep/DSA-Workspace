/*
//  A. Fancy Fence


// Observations: 
    * All the sides of internal angle is equal it is known as regular polygon.
    * We have given the the angle at the corner degree a
            -------------------------
                        -   )  given degree
                            -   
                                -
                                    -
    * for fence to be made, we need to find the internal degree,
        180 - given degree
            let a = 60
            internal angle= 180 - 60 = 120
        * For polygon to be form, all the sum of internal angle should be 360.
        * means it should be completely divisible by 360 with 0 remainder left..
        * we can say if 120 + 120 + 120 => 360, means it's polygon..
        * or we can say: (360 % 120 == 0) => means it's polygon..
        * else for any remaining value left we say it's not..
        * example: 
             a = 30
             internal angle = 180 - 30 = 150...
             150 + 150 + 60 = 360    here all the angles are not same...
             or we can check by (360 % 150) = 60...


    * Property of polygon:
        * Minimum regular polygon is triangle
        * each angle should be equal
        * each side should be equal

    * Resource: https://byjus.com/maths/what-is-a-regular-polygon/
    
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
    n = 180 - n;
    if(360 % n == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}