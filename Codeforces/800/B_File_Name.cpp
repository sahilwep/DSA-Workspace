/*
//  B. File Name

// Observations:
    * We have to remove check if there is more than 2 consecutive 'x' occur or not?
    * If we have more than 2 'x', then we have to count it...




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
    int n;
    cin >>n;
    string s;
    cin >> s;
    int remove = 0;
    int tempCnt = 1;
    for(int i=1;i<n;i++){
        // condition to check if we have 'x' & two consecutive elements are same.
        if(s[i] == 'x' && s[i] == s[i-1]){
            tempCnt++;
            // if cnt is grater than 2, increment the remove variable.
            if(tempCnt > 2){
                remove++;
            }
        }
        // else when we encounter with any other element, we will count make it 1
        else if(s[i] != 'x'){
            tempCnt = 1;
        }
    }
    
    cout << remove << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}