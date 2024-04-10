/*
//  A. Twins            https://codeforces.com/problemset/problem/160/A

// Approach: 
    * Lets, give all coins to twins first,
    * start taking coins one by one from twins,
    * As if our coins sum value is less than the twins coins sum, keep taking coins from twins..
    * once our coins sum value is grater than the twins coins sum, we are satisfied..


// Example: 
                Coins:  [2 3 4 1 4 6]
    * Sort the values..
                Sorted: [1 2 3 4 4 6]
    * Get the sum of all the elements.
    * Sum of all the element is : 20

                                <--- iterate from last to starting & Subtract from max  
                    [1 2 3 4 4 6] 

                    Twins gets:         I gets              No of coins to be split:
    Initial value       20                  0                       0
    i = 0               14                  6                       1       
    i = 1               10                  10                      2       
    i = 2               6                   14                      3       (Break)

    * Break at i = 2, as we get grater than the twins..
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
#define arrOut(k) for(int i=0;i<n;i++) cout << arr[i] <<  k ;
#define el cout << endl;
#define SQ(a) (a)*(a)



void solve(){
    int n;
    cin >> n;
    int arr[n];
    arrInp; // array input
    sort(arr, arr+n);   // sorting array
    int max = 0;    // adding all the array value..
    for(int i=0;i<n;i++){
        max += arr[i];
    }
    int p2 = 0;
    int counter = 0;    // this will count the number of coins to be split..
    for(int i=n-1;i>=0;i--){
        counter++;      // count number of coins..
        max = max - arr[i]; // decreasing window..
        p2 = p2 + arr[i];   // increasing window..
        // comparing the window, when our pointer is grater than max, we break out..
        if(p2 > max){
            break;
        }
    }
    cout  << counter << endl;
}


int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}