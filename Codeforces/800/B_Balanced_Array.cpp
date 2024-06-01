/*
//  B. Balanced Array


// observations: 
    * given n, will be even
    * construct array a, of size n
    * first half n/2 element should be even.
    * second half n/2 element should be odd.
    * sum of all even elements is equal to the sum of all odd elements.
    * all element should have distinct positive integer...
    * If is't not possible, print "NO" : else print "YES" & Print that array...

Input: 
    2
    4
    6
    8
    10
Output: 
    NO
    YES
    2 4 1 5 
    NO
    YES
    2 4 6 8 1 3 5 11 
    NO

// Explanation: 

    * If we Observe Carefully,
            2*1 = 2 -> NO, multiplied by 1(odd)
            2*2 = 4 -> YES, multiplied by 2(even)
            2*3 = 6 -> NO, multiplied by 3(odd)
            2*4 = 8 -> YES, multiplied by 4(even)

        * we get that, for what n we have possible solutions....

    * Now, we known that there is solution, let's write the array...
        * Create an array of size n
        * If we observe solution: 

            4 => 2 4 1 5 
            8 => 2 4 6 8 1 3 5 11 

        * half is even & half is odd:

        * For even: 
            * start writing even number from (n/2-1)th to 0th index.
            * at every iteration decrement value by 2.
            * maintain evenSum variable contains all the sum of even numbers..

        * For odd: 
            * start writing odd number from (n/2)th to (n-2)th index(discuss later): Edge case for last index, discuss later...
            * at every iteration increment value by 2.
            * maintain oddSum variable contains all the sum of odd elements..

        * Now we have evenSum contains sum of even element, & oddSum Contains sum of Odd element
        * We just have to insert the last odd number at position (n-1)th index, because we only inserted till (n-2)th index..
        * Now, evenSum - oddSum = lastElement(which is definitely be odd number)
        * because,
            * As Common rule of even & odd : 
                * if we subtract  
                      evenNum - oddNum = oddNum

        * At last we just insert (evenNum - oddNum = oddNum) at last index of array...


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
    int n;      // n should be even
    cin >> n;
    bool flag = false;      // flag is use to identify the possibility of building array..
    int i = 1; 
    // loop will iterate till it's not get original number n...
    while((2 * i) <= n) {
        // condition when the multiple of 2 is odd & makes original number n.
        if(2 * i == n && i % 2 != 0 ){  
            flag = true;        // making flag false, means array is not possible..
            break;  // break out
        }
        i++;    // at every iteration i increment by 1, so that we can check the condition of iteration & condition...
    }
    // flag is true means array is not possible:
    if(flag == true){
        cout << "NO" << endl;
    }
    // else array is possible
    else {
        cout << "YES" << endl;
        int arr[n];     // making array of size n


        // insertion of even elements: 
        int k = n;  // first even element is n itself
        int evenSum = 0;
        for(int i=(n/2)-1;i>=0;i--){
            arr[i] = k;     // storing even numbers
            k -= 2;         // at every iteration decrement by 2, so that we can store the previous even number..
            evenSum += arr[i];      // storing sum of even elements at every iteration...
        }


        // insertion of odd element: 
        int odd = 1;    // first odd number that should be inserted is 1
        int oddSum = 0;
        // iteration goes from (n/2)th to (n-2)th index
        for(int i =n/2;i<n-1;i++){
            arr[i] = odd;       // storing odd number
            odd += 2;           // decrement it by 2
            oddSum += arr[i];     // storing sum of even elements at every iteration...
        }

        // inserting the remaining last element of an array...
        arr[n-1] = evenSum - oddSum;

        // printing array: 
        for(int i=0;i<n;i++) cout << arr[i] << " ";
        el;
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