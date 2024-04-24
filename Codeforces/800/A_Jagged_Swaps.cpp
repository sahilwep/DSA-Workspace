/*
//  A. Jagged Swaps             https://codeforces.com/problemset/problem/1896/A


// Observation: 
    * We only have to check this condition : 
        if(arr[i-1] < arr[i] && arr[i] > arr[i+1]){
            swap(arr[i+1], arr[i]);
        }
    * We can use nested loop to solve this question: 
        * for every iteration, we can try to swap the value...
        * At the end we can check the value about it is sorted or not?

    * We are doing nothing but try to sort the values from index 1 to n-2, & at the end we are checking the values i.e sorted or not?
    * At every iteration the largest value will go to last...
    * Example: 
               1 7 6 3 4 5 2,       n = 7
                * Here j goes from 0 to n-1(6) & i goes from 1 to n-2(5)
                j = 0
                    i = 1, 1 7 6 3 4 5 2 =>  1 6 7 3 4 5 2
                    i = 2, 1 6 7 3 4 5 2 =>  1 6 3 7 4 5 2
                    i = 3, 1 6 3 7 4 5 2 =>  1 6 3 4 7 5 2
                    i = 4, 1 6 3 4 7 5 2 =>  1 6 3 4 5 7 2
                    i = 5, 1 6 3 4 5 7 2 =>  1 6 3 4 5 2 7
                j = 1
                    i = 1, 1 6 3 4 5 2 7 => 1 3 6 4 5 2 7
                    i = 2, 1 3 6 4 5 2 7 => 1 3 4 6 5 2 7
                    i = 3, 1 3 4 6 5 2 7 => 1 3 4 5 6 2 7
                    i = 4, 1 3 4 5 6 2 7 => 1 3 4 5 2 6 7
                    i = 5, 1 3 4 5 2 6 7 => 1 3 4 2 5 6 7
                j = 2
                    i = 1, 1 3 4 2 5 6 7 => 1 3 2 4 5 6 7
                    i = 2, 1 3 2 4 5 6 7 => 1 2 3 4 5 6 7
                    i = 3....
                j = 3....

                & Check & return "Yes", because all are sorted...
    * Similarly, when first index value is 
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
#define SQ(a) (a)*(a)

void solve(){
    int n;
    cin >> n;
    int arr[n];
    arrInp;
    if(arr[0] != 1){
        cout << "No" << endl;
        return;
    }
    for(int j=0;j<n;j++){
        int flag = false;
        for(int i=1;i<n-1;i++){
            if(arr[i-1] < arr[i] && arr[i] > arr[i+1]){
                swap(arr[i+1], arr[i]);
                flag = true;
            }
        }
        if(!flag) break;
    }
    // Checking for sorted or not?
    for(int i=1;i<n;i++){
        if(arr[i] < arr[i-1]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}