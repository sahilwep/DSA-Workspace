/*

//  Rod Cutting Problem


//  Problem Statement:
    * We are given a rod of size n, & also we are given what's the price of each length of the rod..
    * We need to cut this rod in a way that we can maximize the profit.
    * We are allowed to cut a rod with same length..

            N = 8
     length[] = {1, 2, 3, 4,  5,  6,  7,  8}
      price[] = {1, 5, 8, 9, 10, 17, 17, 20}


// Observations: 

    * We are given a rod of length N = 8 (let say 8m)


                <-----------------8m--------------->
                |----------------------------------| 


    * we can cut this rod in given length
        * Let say we can cut this in (2, 6):

                <--2m--->   <----------6m--------------->
                |-------|   |---------------------------| 

                    5                   17               => price

        * Now, price will be: 5 + 17 = 22

    * We are allowed to cut this rod with same length also:


                <--2m--->   <--2m--->   <--2m--->   <--2m--->   <--2m--->
                |-------|   |-------|   |-------|   |-------|   |-------| 

                    5           5           5           5            5      => price

        * Now, price will be: 5 + 5 + 5 + 5 + 5 = 25

    * So, we need to cut this rod, in such a way that price will be maximize, when price will be maximum, we have maximum profit.

    * Note: 
        * Sometimes we have only given N, & price array, length array is not given, then we will consider length array as N.

    * Comparision: 
        * In O-1 Knapsack we are given:

            W = 
            val[] = 
            wt[] = 

        * In Unbounded knapsack:

            N = 
            len[] = 
            price[] =

        * So, these can be matched with:

                N -> W
                len[] -> wt[]
                price[] -> val[]

                    -> We have to maximize the profit in both..


// Code Variations:
    * This Question is same as the unbounded knapsack problem, they just give us this problem in rod cutting format.
    * Here, we just have to change wt[] array to len[] array, & val[] array to price[] array, & capacity W to Length of rod N.


// Complexity:
    * TC: O(n^2)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int rodCutting(int len[], int price[], int n){

    // initialization: all element with 0
    vector<vector<int> > t(n+1, vector<int> (n+1, 0));

    for(int i=1;i<n+1;i++){ // price array
        for(int j=1;j<n+1;j++){ // len array
            // if the length[] element is less or equal to rod length:
            if(len[i-1] <= j){
                // Include(Not-Processed) / reject(Processed)
                t[i][j] = max(
                    price[i-1] + t[i][j-len[i-1]], t[i-1][j]
                );
            }
            else{
                // reject
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][n]; // returning the profit.
}

void solve(){
    int n;
    cin >> n;
    int length[n];
    int price[n];
    for(int i=0;i<n;i++) cin >> length[i];
    for(int i=0;i<n;i++) cin >> price[i];

    cout << rodCutting(length, price, n) << endl;

}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}