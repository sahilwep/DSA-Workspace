/*
//  A. Do Not Be Distracted! 


// Observations: 
    * We have to check wether the same element is occurring in one after another or not...
    * If they are occurring one after another, return true...
    * if they are occurring in a separation, we have to find that...

    * example:
        * AABBCCDDEEBZZ   -> return false = because, B is occurring twice, once after A, & Once after B...
        * FFGZZZY   -> return true, because there is no such element that occurring twice in range...


// Intrusion: 
    * We can use hashing, to hash all the element...
    * When we are hashing any element, if the value is hashed for the first time, we simply hashed..
    * when element is hashed after 1'st time, we have to check two things..
        * first thing will be the previous element, 
        * second we have to check the number of times it hashed previously..
    * If the previous element is not same & it's hash hashed previously we simply return false...
    * Else at end we return true...


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
    string s;
    cin >> s;

    // Using map ds to store the frequency of an element...
    map<char, int> mp;
    bool found = false; // flag..
    for(int i=0;i<n;i++){
        // condition when (i!=0), because we are comparing with previous element, i.e (s[i] & s[i-1])
        if(i != 0){
            // if current element is not equal to previous element, & s[i] is already hashed, we immediately return false...
            if(s[i] != s[i-1] && mp[s[i]] > 0){
                found = true;
                cout << "NO" << endl;
                break;
            }
            
        }   
        // condition when element is hashed first times.....
        mp[s[i]]++;
    }
    if(!found){
        cout << "YES" << endl;
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