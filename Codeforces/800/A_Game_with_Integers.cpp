/*
//  A. Game with Integers               https://codeforces.com/problemset/problem/1899/A


// Observation: 
    * As the game says, player have to increase or decrease 1 to the number, in order to win...
    * both player are playing optimally, in order to win...
    * if Vanya wins we have to print first : else second for Vova
    * Note : if 10 moves has passed Vanya has not won, then vova wins..

    * IF we observe carefully: 
        n % 3 = 0 : 3, 6, 9, 12, 15, 18, 21, 24....
        when remainder is 0 : these are the numbers..

        r = 0 -> 3, 6, 9, 12,..... Vanya not wins
        
        r = 1 -> 4, 7, 10, 13,.....  Vanya wins -> because it can decrease the number by 1
        r = 2 -> 5, 8, 11, 14,.....  Vanya wins -> because it can increase the number by 1
        
        r = 3 -> 6, 9, 12, 15,.......  Vanya not wins


        'Vanya goes first'

        r = 0 : 3, 6, 9, 12,.....

        if number i.e given itself is divisible by 3 eg : 6

        n = 6, in Vanya move she have to increase or decrease that number one in order to win, 
            let say she decrease by 1 -> 5, buy in vova term he will again increase by 1 in order to neutralize, so vanya didn't win...
            or if she increase same things happens...
            (va vo) (va vo) (va vo) (va vo) -> in 10th turn vo wins...
        * Note : if number is divisible by 3 before the vanya move vova wins'
        * Else in other case, if we see & observe vova wins..

        * 10 is just a number that is given to 
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
    if(n % 3 == 0){
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
    }
}


int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}