/*
//  A. Boring Apartments



// Observations: 
    * We have to count the number of digit of the sequence : 
            1 11 111 1111
            2 22 222 2222
            3 33 333 3333
            ...
            9 99 999 9999

    * We are given the some number let say x = 22
    * Now, we have to count the no of digit of the sequence...
        * for x = 22, sequence will be: 
                    1 11 111 1111 2 22 
                    1+ 2 +3 + 4 + 1+2 = 13 digit's total....

// Intrusion: 
    * first we will count the column: 
        * We are sure from the constrains x <= 9999
            * first we extract last digit, so that we know what will be the range...
            * example : if x = 777, ld = 7, means we have to count till 7th row...
        * We are sure that, for each row the count is 10,
        * so by simply getting the last digit, we can iterate till last_digit times & add 10 in ever iteration...
        
    * Now we have to count the column: 
        * we simply count the digit, & iterate that much times & simply add that iteration number into the count....

    
    * Example: 
          x = 55
            ld = 5 -> iterate (1 to < 5) -> and add 10 in every iteration...
    
            * Now count the number of digit in x -> which is 2 
                * iterate 2 times (1 to 2) & count the number of iteration into count..

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
    cin >> n;

    // First we will count the number of row:
    int ld = n % 10;        // extract the last digit
    int cnt = 0;
    for(int i=1;i<ld;i++){      // iteration from 1 to < last_digit..
        cnt = cnt + 10;         // at every iteration we will add 10..
    }

    // Second we will count the number of column:
    int totalDigitCount = log10(n) + 1;      // getting the count of digit...
    for(int i=1;i<=totalDigitCount;i++){     // iteration from 1 to totalDigitCount
        cnt = cnt + i;  // simply add the iteration number to it...
    }

    cout << cnt << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}