/*
//  C. Prepend and Append


// Observations:
    * If we have observe carefully, the operations that they made is adding {0(start), 1(end)} or {1(start), 0(end)}  
    * We need to find the original string...
    * As it's given that they have applied the following operations on string..
    * We can match these & Iterate over...
    * Once the two characters didn't match, we can break out & count character count..

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
    cin >> n;
    string s;
    cin >> s;
    
    //Operations: 
    int start = 0;
    int end = s.size()-1;

    while(start <= end){
        if(s[start] == '1' && s[end] == '1'){
            break;
        }
        else if(s[start] == '0' && s[end] == '0'){
            break;
        }
        start++;
        end--;
    }
    cout << (end - start + 1 ) << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}