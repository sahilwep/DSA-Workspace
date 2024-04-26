/*
//  A. Doremy's Paint 3                 https://codeforces.com/problemset/problem/1890/A


* If we observe carefully: 
    array : a, size = n
    [a1, a2, a3, a4, a5, a6...]

    a[1] + a[2] = a[2] + a[3] = a[3] + a[4] = a[4] + a[5] = a[5] + a[6] =....= a[n-1] + a[n] = k

    Case 1: odd
    n = 5
    a[1] + a[2] = a[2] + a[3] = a[3] + a[4] = a[4] + a[5]
    a[1] = a[3] = a[5] --> 1 unique element, as it is same so all the element a1, a3, a5, should be same...
    a[2] = a[4] --> 1 unique element
    # Unique element <= 2
    # freq = {(n/2), (n/2)+1},
        * example: 1 2 1 2 1
            * 1 is three times
            * 2 is two times. 
            * So, freq is : {(n/2), (n/2)+1} = {2, 1}


    Case 2: even
    n = 4
    a[1] + a[2] = a[2] + a[3] = a[3] + a[4] = a[4] + a[5] = a[5] + a[6] 
    a[1] = a[3] = a[5] --> 1 unique element, as it is same so all the element a1, a3, a5, should be same...
    a[2] = a[4] = a[6] --> 1 unique element
    # unique element <= 2
    # freq = (n/2) = same freq for both unique element...

    * Observation: 
        * All the element at the same parity should be equal.
        * We cannot have more than 2 unique elements. => This can be easily keep track of map or hashmap...
        * Bound on frequency

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
#define arrInp for(ll i=0;i<n;i++) cin >> arr[i];
#define arrOut(k) for(int i=0;i<n;i++) cout << arr[i] <<  k;
#define el cout << endl;
#define SQ(a) (a)*(a)



void solve(){
    ll n;
    cin >> n;
    ll arr[n];
    arrInp;
    
    map<ll, ll> freq;   // using map to store freq
    for(auto i : arr) freq[i]++;    // storing freq..
    // as freq map will store the freq of element, with size function we can check the unique elements also..
    // if we have more than 2 unique element, we print "No"
    if(freq.size() > 2){
        cout << "No" << "\n";
        return;
    }
    // if we have only 1 element, means "Yes"
    if(freq.size() == 1){
        cout << "Yes" << "\n";
        return;
    }
    // Now for the case when we have only 2 unique element
    vector<ll> ans; // creating vector to store the freq
    for(auto i : freq) ans.push_back(i.second); // storing freq in vector
    // checking the difference of {(n/2), (n/2)+1}, we know their difference will be 1
    if(abs(ans[0] - ans[1]) <= 1){  // using abs value we neglecting the negative result. & then comparing the value whether it is less than or equal to 1, for the case to be "Yes".
        cout << "Yes" << "\n";
        return;
    }
    cout << "No" << "\n";   // else if the difference is more, we result "No".
}

int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}