/*
//  A. Two Friends

// As per the question: 
    * At least 2 of them at his party.
    * The 𝑖-th friend comes to the party if both the 𝑖-th friend and the 𝑝𝑖-th friend receive an invitation
    * Calculate the minimum number of invitations Monocarp has to send so that at least 2 friends come to the party.

// Observation: here (ANY_NUMBER) is let say index
    * Case 1: when both A & B get's invitation
        A(1) -> B(2)      = A get's invitation, & his best friend is B          
        B(2) -> A(1)      = B get's invitation, & his best friend is A
        * Here, both 1, & 2 index satisfied..
        * Condition satisfied here, We need at-least 2, & here, both are coming, so we can say 2

    * Case 2: when non-of their best friend get's invited...
        A(1) -> B(2)      = A get's invitation, & his best friend is B
        B(2) -> C(3)      = B get's invitation, & his best friend is C
        C(3) -> A(1)      = C get's invitation, & his best friend is A
        * Here, non of the index is satisfied, so we need to invite all of them
        * Here, We have to invite at-least 3 friend, because condition says we need at least 2 friend in party, & each of their best friend is not invites as per the rule.

    * Conclusion: If both the index traverse to each other, we say 2 : else we say 3, as we need minimum invitation..

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
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
        arr[i]--;   // adjusting 0th based index:, by subtracting 1 value from them.
    }
    for(int i=0;i<n;i++){
        if(i == arr[arr[i]]){
            cout << 2 << endl;
            return;
        }
    }
    cout << 3 << endl;
}


int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}