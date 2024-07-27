/*
//  C. Clock Conversion

// Observations: 
    * We are given 24 hour format clock, & we have to convert it into 12 hour format...

// Intrusion: 
    * Idea is to extract the hour & minute values, & then convert it by comparing the rules...
    * For extraction of minute & hour from string: 
            59
            ik
                k + (i * 10)
                9 + (5 * 10)
    * Same we will perform for hour..
    * Now we have to compare it with 12 hours rule:

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
    string s;
    cin >> s;
    // minutes index: 3 & 4
    int minutes = (s[4] - '0') + ((s[3] - '0') * 10);

    // hours index: 0 & 1
    int hour = (s[1] - '0') + ((s[0] - '0') * 10);

    if(hour >= 1 && hour <= 11){
        cout << s[0] << s[1] << ":" << s[3] << s[4] << " AM" << endl;
    }
    else if(hour == 12){
        cout << s[0] << s[1] << ":" << s[3] << s[4] << " PM" << endl;

    }
    else if(hour > 12){
        if(hour - 12 < 10){
            cout << '0' << hour - 12 << ":" << s[3] << s[4] << " PM" << endl;
        }else{
            cout << hour - 12 << ":" << s[3] << s[4] << " PM" << endl;
        }
    }
    else if(hour == 0){
        cout << 12 << ":" << s[3] << s[4] << " AM" << endl;
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