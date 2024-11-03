/*

//  Egg Dropping Problem Recursive 


//  Problem Statement:
    * We are given N identical eggs, and we have access to K-floored building from 1 to K.
    * There exist a floor 'f' where 0 <= f <= k, such that any egg dropped from a floor higher than 'f' will break, 
    * and any egg dropped from or below floor f will not break.
        * An egg that survives a fall can be used again.
        * A broken egg must be discarded.
        * The effect of a fall is the same for all eggs.
        * If the egg doesn't break at a certain floor, it will not break at any floor below.
        * If the egg break at a certain floor, it will break at any floor above.
        
    * Return the minimum number of moves you need to determine with certainly what the value of 'f' is.



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int eggDrop(int e, int f){

    if(f == 0 || f == 1) return f;
    
    // if we have single egg, then we will return f floor in worse case.
    if(e == 1) return f;

    // k Partitions:
    int ans = INT_MAX;
    for(int k=1;k<=f;k++){
        int tempAns = 1 + max(eggDrop(e-1, k-1), eggDrop(e, f-k));

        ans = min(ans, tempAns);
    }

    return ans;
}

void solve(){
    int egg, floor;
    cin >> egg >> floor;
    
    cout << eggDrop(egg, floor) << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}