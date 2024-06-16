/*
//  A. Dragons


// observations: 
    * there are n dragons, & s strength
    * if he start dealing with ith dragons (1 <= i <= n) & his strength is not grater than dragon strength xi, then he loose..
    * But if his strength is grater than dragon strength, then he defeat dragon & gets a bonus strength by yi
    * he can fight in any order...
    * Determine wether he can move on the next level of the game, that is, defeat all dragon without single loss...
    

       s = strength
       n = no of dragons
            start dealing with ith -> (1 <= i <= n);
       x = dragon strength
       y = bonus.


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
    int s, n;   // input of initial strength & number of level
    cin >> s >> n;  
    int x, y;
    bool flag = true;
    pair<int, int> arr[1000];       // create an array of pair, to store the level & their strength.
    for(int i=0;i<n;i++){
        cin >> arr[i].first >> arr[i].second;   // taking input...
    }
    sort(arr, arr+n);       // we know we can move from any level, so we sort them in order to iterate from 0->n
    for(int i=0;i<n;i++){
        // cout << arr[i].first << " " << arr[i].second << endl;
        // condition when man strength is less or equal dragon strength..
        if(s <= arr[i].first){
            flag = false;
            break;
        }
        // condition when man strength is grater than dragon strength..
        else if(s > arr[i].first){
            s += arr[i].second; // add the level strength to original once..
        }
    }
    (flag) ? cout << "YES" : cout << "NO";
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