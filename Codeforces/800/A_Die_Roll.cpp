/*
//  A. Die Roll


### Steps to Solve:

* Identify the highest roll between Yakko and Wakko:
   * Find the maximum value between Y & W.

* Calculate Dot's winning outcomes
   * Dot wins if she rolls any number equal to or higher than this maximum value.

* Determine the number of winning outcomes for Dot:
   * If the highest roll between Yakko and Wakko is 3, Dot wins if she rolls a 3, 4, 5, or 6. That's 4 possible winning outcomes.
   * If the highest roll is 5, Dot wins if she rolls a 5 or 6. That's 2 possible winning outcomes.
   
* Total possible outcomes:
   * Since Dot rolls a six-sided die, there are always 6 possible outcomes (1 through 6).

* Calculate the probability:
   * The probability of Dot winning is the number of winning outcomes divided by the total number of possible outcomes.
   * This fraction is then simplified to its irreducible form.

* Example: 
    Suppose Y=4 and W=2:
        max_roll = max⁡(4,2)=4
        Dot needs to roll 4, 5, or 6.
        Number of successful outcomes: 6 - 4 + 1 = 3
        Total possible outcomes: 6
        Probability: 3/6 = 1/2

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
    int y, w;
    cin >> y >> w;

    int max_roll = max(y, w);   // Find the maximum roll between Yakko and Wakko

    int successful_outcomes = 6 - max_roll + 1;     // Calculate the number of successful outcomes for Dot


    // using this to simplify fraction in the form of p/q
    switch (successful_outcomes) {
        case 1:
            cout << "1/6" << endl;      // 1/6
            break;
        case 2:
            cout << "1/3" << endl;      // 2/6 = 1/3
            break;
        case 3:
            cout << "1/2" << endl;      // 3/6 = 1/2
            break;
        case 4:
            cout << "2/3" << endl;      // 4/6  = 2/3
            break;
        case 5:
            cout << "5/6" << endl;      // 5/6
            break;
        case 6:
            cout << "1/1" << endl;      // 6/6 = 1/1
            break;
        default:
            break;
    }
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}