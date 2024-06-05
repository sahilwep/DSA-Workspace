/*
//  A. Square String?


// Observations:
    * We have to check is there a string makes pattern like square of strings..
    * Example: 
        * squares:  
                aa      -> a a   
                abcabc  -> abc abc
                abab    -> ab ab
                baabaa  -> baa baa
        * Not a square:
                aaa     -> a a a
                abaaab  -> aba aab  -> not same
                abcdabc -> abc d abc    -> not same...

    * If the size of string is odd, we are sure it's not square...
    * If we carefully observe, for the element's to be square, the size of string should be the even.
        * also It's not sure that every time even size will be the square: 
            * example: 
                    xxyy    -> xx yy    -> not same
                    xyyx    -> xy yx    -> not same..

    * So, we have to check with two pointer one at starting, & one at the mid...
    * we will keep iterating, in-between if we found elements are not equal, we return false...


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
    string s;
    cin >> s;
    // when string size is odd, we are sure it's not square..
    if(s.size() % 2 != 0){
        cout << "NO" << endl;
        return;
    }else{
        int ptr1 = 0;
        int ptr2 = s.size() / 2;
        while(ptr2 <= s.size()-1){

            if(s[ptr1++] != s[ptr2++]){
                cout << "NO" << endl;
                return;
            }
        }
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