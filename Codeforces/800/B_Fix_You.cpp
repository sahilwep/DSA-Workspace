/*
// B. Fix You


// Observations: 
        * Conveyor belt represent using grid, consisting n rows & m columns
        * The cell ith row from top, & jth column from the left is labeled (i, j)
        * every cell expect (n, m) has direction, R-> Right, D-> Down
        * if cell (i, j) is assign direction R, any luggage keep move to cell (i, j+1), similarly
        * if cell (i, j) is assign direction D, any luggage keep move to cell (i+1, j)...
        * if at any movement, luggage move out of grid, it considered to be lost.

        * There is counter at (m,m), from all the luggage is picked...
        * A conveyor belt is called functional if and only if any luggage reaches counter regardless of which cell is to place in initially.
        * more formally, every cell(i, j) any luggage placed is this cell should be eventually end up in cell (m,n).
        * This may not hold initially, however we are allowed to change direction of some of some cells to make conveyer belt functional..
        * We have to determine the minimum no of cell we will change to satisfied this condition..
        * Input value: 
            * R-> Right, D-> Down, C-> Counter
            * Take n, m size array.
        * Output: 
            * we have to print the minimum number of direction should be change to make all the value to the conveyer belt.

// Intrusion: 
    * We don't have to count all the box's on the conveyor, as we have given the condition, that some box may be lost..
    * So, instead we will count only those box's which has possibility to go on the counter...
    * If we carefully observe, the box's goes to the conveyor belt is only those box's which are in the last column & last row..
    * We only have those box in that way so that they can reach to Counter...

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
    int n, m;   // n = times, m = size
    cin >> n >> m;
    string s[n];
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    // last value will be counter, Counter in this case: (nxm) -> dest will be (n-1, m-1)
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j >= 0 || i <= m-2){
                if(j == m-1){
                    if(s[i][j] == 'R')  cnt++;
                }
            }
            if(i == n-1){
                if(s[i][j]){
                    if(s[i][j] == 'D')  cnt++;
                }
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