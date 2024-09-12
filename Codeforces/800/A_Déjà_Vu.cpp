/*
//  A. Déjà Vu


// Observations: 
    * There is string s, we must insert exactly one character 'a' somewhere in string
    * if it's possible to create string that is not a palindrome, 
    * you should find one example, otherwise you should report that it is impossible.


// Intrusion: 
    * Edge case: 
        * When we have only single character 'a' in string -> not possible
        * When we have only 'a' character throughout the string -> not possible
    * Else we can check for palindrome with 'a' in starting if it's not palindrome will wil print that, else we will print 'a' at the end..

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

bool isPlaindrome(string s){
    int start = 0, end = s.size() - 1;
    while(start <= end){
        if(s[start] != s[end]){
            return 0;
        }
        start++;
        end--;
    }

    return 1;
}

string makeCombinations(string res, char ch, int idx){
    string solu = "";
    for(int i=0;i<res.size();i++){
        if(idx == i){
            solu += ch;
        }
        solu += res[i];
    }

    return solu;
}

void solve(){
    string s;
    cin >> s;
    // Condition when we have single element & only 'a'
    if(s.size() == 1 && s == "a"){
        cout << "NO" << endl;
        return;
    }
    else if(s.size() == 1 && s != "a"){
        cout << "YES" << endl;
        cout << s << 'a' << endl;
        return;
    }

    // Condition when we have only 'a' in our string.
    bool isOthers = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] != 'a'){
            isOthers = 1;
            break;
        }
    }
    if(!isOthers){
        cout << "NO" << endl;
        return;
    }


    // No Need to check for every combinations:

    // // if string is not palindrome:
    // if(!isPlaindrome(s)){
    //     cout <<  "YES" << endl;
    //     // inserting 'a' at every position until we form such string that is not palindrome.
    //     string res = s;
    //     for(int i=0;i<s.size();i++){
    //         string temp = makeCombinations(res, 'a', i);
    //         if(!isPlaindrome(temp)){
    //             res = temp;
    //             break;
    //         }
    //     }
    //     cout << res << endl;
    // }
    // else{
    //     cout <<  "YES" << endl;
    //     // inserting 'a' at every position until we form such string that is not palindrome.
    //     string res = s;
    //     for(int i=0;i<s.size();i++){
    //         string temp = makeCombinations(res, 'a', i);
    //         if(!isPlaindrome(temp)){
    //             res = temp;
    //             break;
    //         }
    //     }
    //     cout << res << endl;
    // }


    // We can directly check with first & last position: because we already checked a condition when string has only 'a' in it.
    // if 'a' with start is not palindrome, we can print 'a' with start
    if(!isPlaindrome('a'+s)){
        cout << "YES" << endl;
        cout << 'a'+s << endl;
    }
    // else we will print 'a' at the end of string.
    else{
        cout << "YES" << endl;
        cout << s+'a' << endl;
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