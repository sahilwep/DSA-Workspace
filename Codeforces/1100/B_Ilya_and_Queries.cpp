/*
//  B. Ilya and Queries


// Observations: 
    * We have given a string of size n, string consist of '.' and '#' character only..
    * We have also given a pair of query(li, ri) and we need to find answer to the query (li, ri) is the number of such integer i(li <= i <= ri) that si = si+1
        * we are given a string, that has some sort of patter consisting '.' & '#', & from that pattern we need to find such integer i, which are formed from  b/w (li, ri)

    * test-cases observations: 
        * NOTE, as per question index-starting from (1 <= li <= ri <= n)
        s = #..###
        q = 5
        q1 = 1 3    -> result = 1
                string from 1 to 3 are: 
                    # . .
                    1 2 3
                    # = 1
                    . = 2
                    2 - 1 = 1

        q2 = 5 6    -> result = 1
                Starting from 5 to 6 are:
                    ##
                    # = 1
                    . = 0
                    * here, no such conditions form..
                    * we also have given condition (s[i] = s[i] + 1), so if we think..
                        * Input:  s = #..###
                        * Approach: 
                            * we will start counter from 0, and we will start compare two consecutive elements 
                            * if the previous element is same, we will store their counter value + 1
                            * else if the two consecutive values are distinct we will store the previous values..
                            * if the value are distinct, then we make it 0...
                                Input:    # . . # # #
                                counter:  0 0 1 1 2 3
                                index:    1 2 3 4 5 6
                                    li = 5, ri = 6
                                            # #
                                            2 3
                                            (3 - 2) = 1
                            * for same consecutive element we will increase counter & store it...
                            * & whenever we encounter different element, we make counter = 0 & store it on that positions...
                            * Let's check for next querys..

        q3 = 1 5    -> result = 2
                li = 1, ri = 5
                            Input:    # . . # # #
                            counter:  0 0 1 1 2 3
                            index:    1 2 3 4 5 6
                     ri - li
                      2 - 0 = 2
                li = 1, ri = 5
                            Input:    # . . # # #
                            counter:  0 0 1 1 2 3
                            index:    1 2 3 4 5 6
                     ri - li
                      2 - 0 = 2

        q4 = 3 6    -> result = 2

                li = 3, ri = 6
                            Input:    # . . # # #
                            counter:  0 0 1 1 2 3
                            index:    1 2 3 4 5 6
                     ri - li
                      3 - 1 = 2

        q5 = 3 4    -> result = 0

                li = 3, ri = 4
                            Input:    # . . # # #
                            counter:  0 0 1 1 2 3
                            index:    1 2 3 4 5 6
                     ri - li
                      1 - 1 = 0
    * Basically we can say we need to maintain an array that store this computations..
    * once we get this, we will simply return the result of query..
    * This approach is known as DP, where we precompute the result, & we will get the result of sub-problems...


    * Constrains:   
    s = (2 <= n <= 10^5)
        means size will be atleast 2 & max: 10^5
        * let's create (10^5 + 10) size for safe hand..


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
    int n;
    cin >> s >> n;
    // making an array that store the computations...
    int dp[100010];
    dp[0] = 0;  // as the first value will be 0, so we explicitly assign..
    for(int i=1;i<s.size();i++){
        if(s[i] == s[i-1]){
            dp[i] = dp[i-1] + 1;  // adding 1 to previous value & storing it into the current positions..
        }
        else{
            dp[i] = dp[i-1];  // else we will store the previous value without increment it..
        }
    }

    // returning the result of query..
    pair<int, int> p;
    while(n--){
        cin >> p.first >> p.second; // taking input..
        cout << dp[p.second-1] - dp[p.first-1] << endl; // subtract 1, because the index start from 1, & dp stores at from index 0...
    }
    el;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}