/*

//  A. Two Elevators

// Observations: 
    * vlad is on 1st floor, when he goes inside the apartment entrance
    * He want to call the elevator to go up to his apartment
    * there are only two elevator in his house..
    * First elevator is currently on floor a(it is currently motionless)
    * Second elevator is locate on floor b and goes to floor c (b != c)
    * NOTE: if b = 1, then elevator is already leaving floor 1 & vlad do not have time to enter..
    * If we call the 1st elevator it will immediately start to go on floor 1, 
    * if we call second then first it will reaches to floor c & only then it will go to floor 1.
    * It will take |x - y| second to each elevator to move from floor x to floor y
    * Vlad want to call elevator that come to him faster, we need to find that elevator..
    * Output the elevator number
        * if it's first 1
        * if it's second 2
        * if doesn't matter which elevator to call 3


// Example: 
    1 2 3   -> 1
        a = 1, b = 2, c = 3
        * First elevator is already on floor 1

    3 1 2   -> 3
        a = 3, b = 1, c = 2
        * first elevator is on third floor
        * second elevator is leaving from floor 1 & going to floor 2
        * at one second the second elevator will move to 2 & first elevator will also move to 2..
        * So, doesn't matter which one we are going to call...
        * So answer is 3

    3 2 1   -> 2
        a = 3, b = 2, c = 1
        * first elevator is already on floor 3rd
        * Second elevator is on floor 2 & going to floor 1..
        * So we need to call 2nd elevator because in one second 2nd elevator will come at 1st & first elevator will come at 2nd floor...

// Key point to observe: 
        * First elevator: if called it will take |a-1| second to reach the 1st floor..
        * Second elevator: if called it will take |b-c| second to reach floor c, then it will take |c-1| second to reach the 1st floor.


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
    int a, b, c;
    cin >> a >> b >> c;

    int firstElevatorTime = abs(a - 1);
    int secondElevatorTime = abs(b - c) + abs(c - 1);

    if(firstElevatorTime < secondElevatorTime){
        cout << 1 << endl;
    }else if(firstElevatorTime > secondElevatorTime){
        cout << 2 << endl;
    }else{
        cout << 3 << endl;
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