/*
//  A. Dislike of Threes


// Observations: 
    * As per the question: 
    * the we hate to print the kth number of series which follow the condition
        * (k % 3 != 0) means number is not divisible by 3
        * (k % 10 != 3) means the last digit of number is not 3
        * We can print all the numbers by using this conditions: 
                    if((i % 3 != 0) &&  (i % 10 != 3))   print(i)
        * Now we have to print the kth position of the number

// Intrusion: 
    * As per the constrains: 
        * kth is from 0 to 1000
        * for the 1000th position : number is 1666
    * We can start iterating from 1 to 1666, because 1666 is the last number in the list, as per the constrains 1000
    * we apply the condition that are given, if this condition satisfies, we increment the kth counter...
        * when kth counter is matches with number 1000, we will print the kth number of that iterations i.e: i 

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
    int n;
    cin >>n;    // storing the number
    int res;
    int kth = 0;    // start pointer from 0 goes up till 1000
    for(int i=1;i<=1666;i++){
        // condition as per the question
        if((i % 3 != 0) && (i % 10 != 3)){
            kth++;  // increment the counter, means kth position
            // cout << kth << " = " << i << endl;   // printing each kth of that number
            // if kth is become the n, then print the i & break
            if(kth == n){
                cout << i << endl;
                break;
            }
        }
    }


    // cout << res << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}