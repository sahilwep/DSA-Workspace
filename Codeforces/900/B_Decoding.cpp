/*
//  B. Decoding

// Observations:
    * Message is encoded in certain format: 
        * If the string size is even, midian letter is the middle left,
        * else if it's odd, the midian letter is middle once.
    * We are given an encoded string, we have to decode it...
    * Example: 
        * Original string: "volga" encoded to "logva"
            volga -> odd, l removed -> voga
            voga -> even o removed -> vga
            vga -> odd, g removed -> va
            va -> even, v removed -> a
            a -> odd, a removed -> ""

            Strings are removed in certain order: -> "logva" that's the encoded string.
    * We just have to reverse this process..
        * We have to start removing elements 
        "logva"
        
            l -> odd
            ol -> even
            olg -> odd
            volg -> even
            volga -> even

// Intrusion: 
    * For even element we are inserting values to left, & for odd we are inserting it to right
    * We will start iteration from 0 to n-1 in s[i]...
    * for each element we will check for odd & even case, & insert the elements..
    * At end we need to check the final size
    * we are iteration value from 0, se we need to check even case & handle explicitly..


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
    string s;
    cin >> n >> s;
    string res = "";
    for(int i=0;i<n;i++){
        // even insertion at right
        if(i % 2 == 0){
            res += s[i];
        }
        // odd insertion at left
        else{
            string temp = res;
            res = s[i];
            res += temp;
        }
    }
    // checking for even case, & reverse it...
    if(res.size() % 2 == 0){
        reverse(res.begin(), res.end());
    }
    cout << res << endl;
}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
     
    return 0;
}