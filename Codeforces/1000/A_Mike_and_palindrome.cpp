/*
//  A. Mike and palindrome


// Observations: 
    * We are given string s, we need to check whether the given string is palindrome by changing exactly one character from the given string.


// Key Observations: 
    * Single string will always be palindrome:
    * if the given string is already palindrome:
        * if that string size even: not possible, because changing one character can disturb the arrangement.
        * If that string size is odd: we can change the middle element that can still be palindrome.
    * We have to count for how many places we have to change so that we can make the string palindrome.
    * if the counter is not equal to 1, we can return false.  

// Intrusion:
    * if the size of given string is 1, return true;
    * we will use counter to count the number the number of digit that are not in the place of palindrome condition.
    * if the counter is 0 & size of string is odd -> return true
    * if the counter is 1 return true
    * else for all the case we are returning false, as per the given question.

// Complexity:
    * TC: O(n)
    * AS: O(n)

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
    // Base condition when size of string is 1, means we have single character
    if(s.size() == 1){
        cout << "YES\n";
        return;
    }
    // using two pointer to check the string palindrome condition.
    int cnt = 0;    // counter that will count the number of places where we have to perform changes.
    int start = 0;
    int end = s.size() - 1;
    while(start <= end){
        if(s[start] != s[end]){
            cnt++;
        }
        start++;
        end--;
    }
    // checking the condition when string is already palindrome:
    // condition when string is already palindrome & it's odd size
    if(cnt == 0 && s.size() % 2 != 0){
        cout << "YES\n";
        return;
    }
    // condition when count == 1: we only need to change one character that are needed to make palindrome.
    if(cnt == 1){
        cout << "YES\n";
        return;
    }
    // else all the cases are false are per the given constrains.
    else{
        cout << "NO\n";
        return;
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