/*

//  D. 1D Eraser


// Observations: 
    * We are given strip of paper s, of n cells long. Each cell is either white or long.
    * In one operations we can take k consecutive cells & make them all white.
    * Find the minimum numbers of operations to remove all blacks.


// Intrusion: 
    * We can use two pointer approach, which uses range k is difference between the pointers.
    * At every iteration when we encounter 'B', we check the range..
    * If we get black in b/w the range, increment the iteration pointer to k, & increment the counter that uses to count the number of operations..
    * TC: O(n)

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

bool checkBlack(string s, int start, int end){
    for(int i=start;i<=end;i++){
        if(s[i] == 'B'){
            return 1;
        }
    }
    return 0;
}

// Improved Solution: 
void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int i = 0;
    int cnt = 0;
    while(i < n){
        if(s[i] == 'B'){
            i = min(n, i+k);    // we found black, we need to increment i by k, & it should be less than n, which is size of string.
            cnt++;
        }
        else{
            i++;
        }
    }
    cout << cnt << endl;
}


// Bruteforce Solution: TLE
void solve_(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ptr = k-1;
    int cnt = 0;
    
    for(int i=0;i<n;i++){
        if(s[i] == 'B'){
            int ptr = i + k-1;
            bool isFound = checkBlack(s, i, ptr);
            if(isFound){
                cnt++;
                i = ptr;
            }
        }
    }

    cout << cnt << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}