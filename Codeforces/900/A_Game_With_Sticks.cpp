/*
//  A. Game With Sticks

// Observations: 
    * If there is any intersection point on the grid, Then the players are able to remove...
    * A player will lose if there is no intersection point left & they are not able to remove the sticks..
    * the first move will start from Akshat, & then then Malvika turns..
    * So, 1 2 3 4 ....
    * if we observe the testcase..
        * when any of the n or m stick become 0, we don't have any intersection point left..
        * So, we can say if any values become 0, the player wins..
    * Also, if we carefully observe, first Akshat, second Malvika, third Akshat, Fourth Malvika, and so on..
    * For odd number of turns Akshat wins..
    * For even number of turns Malvika wins..

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
    pi p;
    cin >> p.first >> p.second;
    int minVal =  min(p.first, p.second);
    (minVal % 2 == 0) ? cout << "Malvika" : cout << "Akshat";
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