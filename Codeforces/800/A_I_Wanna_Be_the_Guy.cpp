/*
//  A. I Wanna Be the Guy


// Observations; 
Input: 
4 ---> n
3 1 2 3
2 2 4
* first we have to take n size array input, then n-1 size input
* we have to check the if they both combined can complete all the level, -> level == 4

* We can use hashing for this problem..


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
    // input of level
    int level;
    cin >> level;
    int hash[level] = {0};  // making hash array to store frequency

    // input in first array:
    int a1size;
    cin >> a1size;
    int arr1[a1size];
    for(int i=0;i<a1size;i++){
        cin >> arr1[i];
        hash[arr1[i]-1]++;  // storing frequency
    }

    // input in second array: 
    int a2size;
    cin >> a2size;
    int arr2[a2size];
    for(int i=0;i<a2size;i++){
        cin >> arr2[i];
        hash[arr2[i]-1]++;  // storing frequency
    }

    // checking frequency
    for(int i=0;i<level;i++){
        if(hash[i] == 0){
            cout << "Oh, my keyboard!" << endl;
            return;
        }
    }
    cout << "I become the guy." << endl;
}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}