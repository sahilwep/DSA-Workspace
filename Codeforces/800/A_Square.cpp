/*
//  A. Square

// Observations: 
    * We are given the coordinate of squares..
    * We need to find the area of square...
    * If we get one side size, we can easily get the area...

// Key observations: 


                                        |             3
                                        |  (1,5)|----------|(4,5)
                                        |       |          |
                                        |     3 |          |  3
                                        |       |          |
                                        |  (1,2)|----------|(4,2)
                                        |            3
                                        |
                                        |(0, 0)(x, y)
          ------------------------------|---------------------------------
                                        |
                                        |
                                        |
                                        |
                                        |
                                        |
                                        |
                                        |
                                        |
                                        |
        * Area of square: a^2
        * We are given square coordinates...
        * So, if we can find the one sides, 
        * we can easily find their area...

        * 1 2 -> top left
        * 4 5 -> top right
        * 1 5  -> bottom left
        * 4 2 -> bottom right

// Intrusion: 
    * We get the min of x & max of x & calculate the distance...
    * or we can do this on y also..
    * Problem when we have -ve & positive value, if we take the difference, we the value we get is not suitable in some case, when square coordinates lies in two different part of x & y...
    * Instead we can calculate distance by counting from minimum to maximum, by increment it by one each time & count...


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

    int minValue = INT_MAX, maxValue = INT_MIN;
    int a, b;
    for(int i=0;i<4;i++){
        cin >> a >> b;
        minValue = min(minValue, a);
        maxValue = max(maxValue, a);

    }

    int cnt = 0;
    while(minValue < maxValue){
        cnt++;
        minValue++;
    }
    cout << (cnt*cnt) << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}