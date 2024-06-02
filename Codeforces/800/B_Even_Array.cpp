/*
//  B. Even Array



// Observations: 
    * as per the question, ther is given an array, which follow this condition to be called good: 
        * ((i mod 2) == (arr[i] % 2))   ->  if this satisfied all the array element, we can say array is good...
        * means there should be same number of parity 
    * Example: 
            [0, 17, 0 ,3]   => this should be good, because
      index: 0  1   2  3

            i % 2 == arr[i] % 2
            0 % 2 == 0 % 2      -> 0
            1 % 2 == 17 % 2     -> 1
            2 % 2 == 0 % 2      -> 0
            3 % 2 == 3 % 2      -> 1

        * For odd number mod with 2 get 1 as parity..
        * For even number mod with 2 get 0 as parity..

        * We say array is good....
            * Because there is equal number of odd & even parity..
    

    * Another Example: 
            [2, 4, 6, 7]    => this is not good, because
      index: 0  1  2  3

            i % 2 == arr[i] % 2
            0 % 2 == 2 % 2      -> (0, 0)
            1 % 2 == 4 % 2      -> (1, 0)   * not match...
            2 % 2 == 6 % 2      -> (0, 0)
            3 % 2 == 7 % 2      -> (1, 1)

        * Note:  There is always equal number of odd & even parity for (i % 2).
        * But here, There is not equal number of odd & even parity for (arr[i] % 2)
        * Because there is no other element with same parity, but wrong position placed...
            * So we can say array is not good..
        


        * Let's see a case where we have an array is possible to be make good, by making swapping..
                    [1, 4, 6, 7]
             index:  0  1  2  3
                            i % 2 == arr[i] % 2
                         *  0 % 2 != 1 % 2      -> (0, 1)   * not match         => count parity
                         *  1 % 2 != 4 % 2      -> (1, 0)   * not match         => count parity
                            2 % 2 == 6 % 2      -> (0, 0)
                            3 % 2 == 7 % 2      -> (1, 1)
                        * We have 2 position where the condition fails: means it's not fall in good array category condition...
                        * but overall, it's has same number of parity for odd & even for: (i % 2) & (arr[i] % 2)
                            * for the case: (i % 2 != arr[i] % 2)
                                    * if we count here, the odd & even number of parity...
                                            * odd = 1, even = 1 -> same..
                                            * so we need only 1 swap to make this good...



    * Now, as per the question can we have to make an array good:
        * In one step we can swap two elements, as per the question...
        * We know that for array is to be good it should follow this condition:
            * (i % 2 == arr[i] % 2)
                * it has equal number of odd & even parity.. 
        * We can say for array to be bad,
            * (i % 2 != arr[i] % 2)
                * but it should have equal number of odd & even parity, then only we can make this good...
                * if it has not equal number of odd & even parity, we can't make it good, & this is bad...
    
    * As per the question, we have to find the minimum number of move in which we can make an array good, or say that it is not possible..


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
    vector<int> arr(n);
    arrInp;
    int even = 0, odd = 0;

    for(int i=0;i<n;i++){
        // first we will check the array is bad or not: 
        if(i % 2 != arr[i] % 2){    // this check the array is bad ?
            // now if it's bad, let's count the number of odd & even parity...
            if(arr[i] % 2 == 0) even++;     // increment even number parity
            else odd++;         // increment odd number parity
            // cout << i%2 << " " << arr[i]%2 << endl;
        }
        // condition for check the array is good ?
        else if(i % 2 == arr[i] % 2){
            // we don't have to do anything here, just for the verbose...
            // cout << i%2 << " " << arr[i]%2 << endl;  // this is for debugging...
        }
    }
    // now we have count all the even & odd parity for the bad condition...
    // condition when there is difference in odd number & even number parity, means not possible..
    if(odd != even){
        cout << -1 << endl;
    }
    // else if it's same, then we can make array good by doing odd or even number of steps swapping: 
    else {
        cout << odd << endl;
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