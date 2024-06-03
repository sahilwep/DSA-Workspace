/*
//  A. Plus One on the Subset


// Observations: 
    * We have a list of an array...
    * We have to make all the element of an array is equal..
    * In one operation we can choose some index & increment or decrement that index to make all element equal...

    * If we carefully observe, the max element of that array, & the min element of that array..
    * this two element of array that have maximum distance...
    * means, if we want to make equal these two element equal, we need to add or subtract with one to another in order to make this equal.....
    * example: 
        max = 5,  min = 2

            * We either increment 2 to 5 by adding 3,   -> means 3 operations...
            * Or either decrement 5 to 2 by subtracting2, -> means 3 operations...
            * because, in operation we either increment or decrement by 1...
                * if you think about the mid element....
                * They will take less operation than these two(min & max) for sure...

        * So we can say if we do : (max - min) we get the number of operations that atleast need to make all element equal...
    
    * Example: 
        arr: [3 4 2 4 1 2]
        index:0 1 2 3 4 5
                * here min = 1, max = 4     ->       diff => 4-1 = 3 operations minimum we need to make all element equal..
            
            1st => add 1 to index(0, 2, 4, 5) makes array : [4, 4, 3, 4, 2, 3]
            2nd => add 1 to index(2, 4, 5) makes array : [4, 4, 4, 4, 3, 4]
            3rd => add 1 to index(4) makes array : [4, 4, 4, 4, 4, 4]

                * this take 3 operation atleast...

        * If we do any other permutation & combination also, it will take atleast 3 or more operation, but not less than 3...

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
    int max = INT_MIN, min = INT_MAX;
    while(n--){
        int k;
        cin >> k;
        if(k > max){
            max = k;
        }
        if(k < min){
            min = k;
        }
    }
    cout << max - min << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}