/*
//  A. Minimal Square


// square that contains two parallel rectangle...

// Observations: 
    * When both side is same: 
        * for fitting two square in one square:
            * we have to multiply with 4, because, when same size square is combined together in parallel it makes a rectangle.
            a = 10, b = 10
            * Rectangle 1st:
                        a = 10
                        |------|
                        |      |
                  b = 10|------|
            * Rectangle 2nd :
                        a = 10
                        |------|
                        |      |
                  b = 10|------|

            * Final, if we fit together..
                           a = 20
                           |-----------------|
                           | |------|        |
                           | |      |        |
                           | |------|        |
                           | |------|        |
                           | |      |        |
                           | |------|        |
                           |-----------------| b = 20

    * Else when the side are not same,
        * We have to check two condition: 
            * when we are multiply min(a, b) with 2, if it's is great or equal to max(a,b)
                * we print (min*2) * (min*2)
            * else : 
                * we print max*max   
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

int square(int n){
    return n*n;
}

void solve(){
    int a, b;
    cin >> a >> b;
    if(a == b){ // if a & b are same:
        cout << (a*b)*2*2 << endl;
    }else{  // when a & b are distinct:
        int minNum = min(a,b);
        int maxNum = max(a,b);
        if(minNum * 2 >= maxNum){
            cout << (minNum*2)*(minNum*2) << endl;
        }else{
            cout << maxNum*maxNum << endl;
        }
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