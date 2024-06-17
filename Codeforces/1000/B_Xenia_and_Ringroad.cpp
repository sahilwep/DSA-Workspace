/*
//  B. Xenia and Ringroad

// Observations: 

Input: 
    4 3
    3 2 3
            1 2 3 4 1 2 3 4
            *   *     * * 
            1 2 3 4 5 6 7
                - as it was originally at 1, res = 0, so 7-1 = 6
Input:
    4 3
    2 3 3
            1 2 3 4 1 2 3 4
            * * *
            1 2 3
                - as it was originally at 1, res = 0, so 3-1 = 2


// Path observations...
    4 3
    3 2 3
        Initially at 1, res = 0
            for 3,  3(present) - 1(initial) = 2,    => res += 2 => 2
                    update initial = 3
            for 2,  Now the present is lesser than initial
                    So, we have to go to start & then we can reach on present:
                        for start: 
                            initial = 3, last value = 4, 4-3 = 1,   =>  res += 1 => 3
                            Now the next step will be at position one,
                                so we can directly add the present path to res..
                                res += present  =>      res += 2  => 5
                                update initial = 2
            for 3, we can move forward: 
                    3(present) - 2(initial) = 1        => res += 1 => 6
            * Now we have successfully iterate all the element of an array...
        * we can directly return res, ans = 6 


    4 3
    2 3 3
        Initially at 1, res = 0
            for 2,  2(present) - 1(initial) = 1     => res += 1 => 1
            for 3,  3(present) - 2(initial) = 1     => res += 1 => 2
            for 3,  3(present) - 3(initial) = 0     => res += 0 => 2
            * we have successfully iterate all the element of an array...
        * we can directly return res, ans = 2

    
    * If we carefully observe these two test case...
        * We maintain Initial, Present & res variable...
        * We are iterating throughout an array...
        * when present value is less or equal to initial value, we subtract & add it to the res...
        * When present value is grater than the initial value, we are going to start...
            * In that case, we subtract last index of circle, i.e in this case 4, to initial value...
            * Then we add the present value to res..
            * Then we change initial value to present value...
        * mainly these two operations we are doing...
        * At last when iteration in an array is over..
        * we subtract 1 from res, & return the answer...



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
#define arrInp for(int i=0;i<m;i++) cin >> arr[i];
#define arrOut(k) for(int i=0;i<n;i++) cout << arr[i] <<  k;
#define el cout << endl;
#define SQ(a) (a)*(a);

void solve(){
    int n, m;
    cin >> n >> m;
    int initial = 1;    // maintaining the initial variable, & it's started from 1.
    ll time = 0;    // this is use to compute the result
    for(int i=0;i<m;i++){
        int present;
        cin >> present; // every time, while taking input, we make it as present
        // if present is grater or equal than initial
        if(present >= initial){
            time += present - initial;  // storing result
            initial = present;  // updating initial
        }
        // if present is lesser than initial, then we have to iterate to starting point
        else if(present < initial){
            int x = n - initial;    // subtracting initial from n
            time += x;  // adding into the result
            time += present;    // adding present to result, means we have move iterate to last & gone to start, and now we are our preferred position
            initial = present;  // updating initial
        }
    }

    cout << time << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}