/*
//  A. I_love_%username%    https://codeforces.com/problemset/problem/155/A


// Constrains
    * First, it is amazing if during the contest the coder earns strictly more points that he earned on each past contest. 
    * Second, it is amazing if during the contest the coder earns strictly less points that he earned on each past contest. 


// Observations: 
    * The first point should not be count,
    * While counting the best performance, we need to check all the previous back contest, if it's greater than all, we can say it's amazing..
    * same for checking worst performance, we need to check all the previous back contest, it should be less than all of them...


Input: 
5
100 50 200 150 200
Output: 
2
// Explanation: 
    i = 0 -> lowest = highest = 100 (initially)
    i = 1 -> lowest = 50, amazing++
    i = 2 -> hightest = 200, amazing++
    i = 3 -> 150, lie b/w lowest & highest
    i = 4 -> same as highest, ignore

    amazing = 2

Input: 
10
4664 6496 5814 7010 5762 5736 6944 4850 3698 7242
Output: 
4
// Explanation: 
    i = 0 -> lowest = highest = 4664
    i = 1 -> highest = 6496, amazing++
    i = 2 -> skip
    i = 3 -> hightest = 7010, amazing++
    i = 4 -> skip
    i = 5 -> skip
    i = 6 -> skip
    i = 7 -> skip
    i = 8 -> lowest = 3698, amazing++
    i = 9 -> highest = 7242, amazing++

    amazing = 4

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
    int lowest, highest;
    cin >> lowest;
    highest = lowest;
    int amazing = 0;
    int k;
    for(int i=1;i<n;i++){
        cin >> k;
        if(k < lowest){
            lowest = k;
            amazing++;
        } else if(k > highest){
            highest = k;
            amazing++;
        }
    }
    cout << amazing << endl;
}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}