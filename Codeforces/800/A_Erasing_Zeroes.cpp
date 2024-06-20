/*
//  A. Erasing Zeroes


// Observations:
    * we have to find the minimum number of zeroes removing in sequence to form contigious 1's
    * We have to count the no of zeroes to remove..

// Intrusion: 
    * first we will find the first & last 1's in entire sequence...
    * Second we will count the number of zeroes in that sequence..
    * return the count..

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
    if(s.size() == 1){
        cout << 0 << endl;
        return;
    }
    else{
        int ptr1 = 0, ptr2 = 0;
        // finding first occurrence of 1
        for(int i=0;i<s.size();i++){
            if(s[i] == '1'){
                ptr1 = i;
                break;
            }
        }
        // finding second occurrence of 1
        for(int i=s.size()-1;i>=ptr1;i--){
            if(s[i] == '1'){
                ptr2 = i;
                break;
            }
        }
        
        // now we have to count the number of 0's which should be remove to form contigious subsequence of 1's:
        int cnt = 0;
        // we have to go <ptr2, because these two have same value, & if there is no 1's it's still iterate and count one zero.
        for(int i=ptr1;i<ptr2;i++){
            if(s[i] == '0'){
                cnt++;
            }
        }
        cout << cnt << endl;
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