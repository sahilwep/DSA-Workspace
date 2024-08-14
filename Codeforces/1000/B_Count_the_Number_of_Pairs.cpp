/*

//  B. Count the Number of Pairs

// Observations: 
    * we are given string of length n consisting only lowercase & uppercase letter..
    * For each pair lowercase we have uppercase, kristina gets 1 burl, however pair of character cannot overlap, so character can only be in pair.
    * Example: 
        s = "aAaaBACacbE"
            s1 = 'a', s2 = 'A'
            s4 = 'a', s6 = 'A'
            s5 = 'B', s10 = 'b'
            s7 = 'C', s9 = 'c'
    * Kristina want more burles for her string, so he is going to perform no more than k operations.
    * In one operations either she can select one lowercase character & make it uppercase
    * or either select uppercase & make it lowercase.
    * Example: 
        s = "aAaaBACacbE", k = 2
            * In one Operations she can choose s3='a' & make it uppercase, & she get another pair s3='A'
            * and s8='8'
    * we have to find the maximum number of burles kristina can get from the string..

    * Conclusion: 
        * we are given a string & an integer k, we have to form pair, which contains one uppercase & one lowercase..
        * We can change the case of string character by k times only...
        * We have to find the maximum number of pair that we can get from the string...



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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    // using 2d vector to store the frequency of uppercase & lowercase
    vector<vector<int> > cnt(26, vector<int> (2, 0)); // create 2d Vector to hash upper case & lower case

    // Hashing the value
    for(auto i : s){
        // Storing lower case in first dimension
        if(i >= 'a' && i <= 'z'){
            cnt[i - 'a'][0]++;  // increasing lowercase frequency
        }
        // Storing upper case in second dimension
        else{
            cnt[i - 'A'][1]++;  // increasing uppercase frequency
        }
    }

    // once frequency is stored we can fetch the values one by one & Find out the number of pairs we can make by flipping..
    int ans = 0;
    for(int i=0;i<26;i++){
        // to create pair we need to get minimum from both the alphabets case:, eg: a=5, A=3 -> pair(5, 3) -> we can make 3 pairs..
        ans += min(cnt[i][0], cnt[i][1]);   // after this operations we add these to answer..

        // remaining will be abs(5, 3) -> 2 remaining, to create pair we use(X/2), & we have only k operations, so we get the minimum from these..
        int temp = min(k, abs(cnt[i][0] - cnt[i][1])/2);

        // now we add it to answer again
        ans += temp;

        k -= temp;  // at last we subtract the number of times we change the operations from the k, which is we does temp times operations, that's why we subtract it from the k..
    }

    cout << ans << endl;
    unordered_map<int, int> mp;
    // hashing:
    
}



int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}