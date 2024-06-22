/*
//  B. Fence


// Observation: 
    * There is a fence in front of Polycarpus house, fence contains n plank of same width,which go one after another from left to right.
    * The height of ith plank is hi meter, distinct plank can have distinct heights.
    * Now polycarpus bought paino & thinking how will he get it inside the house..
    * he want's to find the k-consecutive planks that the sum of their height is minimum as possible, so that he can remove these k planks.
    * We need to write a program that finds indexes of k-consecutive plans with minimum height.
    * We have to return the k for(k, k+1, k+2..k+nth) value sum..
        * means we need to return the first plank index of that minimum sum of k-consecutive plank.

// Intrusion: 
    * IF we carefully observe, we need consecutive k elements of an array..
    * means we can use sliding window of k window, approach..
    * At every iteration of sliding window, we will find the sum & compare with previous all the minimum values..
    * at the end of iteration, we will return the starting index of that minimum window.

// Approach: 
    * Used sliding window approach: 
        * First while taking input of all the values, i have taken the window size input.
        * Second, i have iterating k-size sum window from k to n-1
        * Third, at every iteration, we will add arr[i] & subtract arr[i-k], from sum.
        * after we will compare sum at every iteration, & when it's lowest we will store the sum & it's index.

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
    int n, k;
    cin >> n >> k;
    int arr[n];
    int window = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(i < k){
            window += arr[i];   // storing k-size window.
        }
    }

    int minIndex = 1;   // 1, because minimum index constrains is 1.
    int minVal = window;    // same window value will be store in minVal
    for(int i=k;i<n;i++){
        window += arr[i];   // adding the next value of window.
        window -= arr[i-k];     // removing the starting value of window
        // storing the minimum sum while every iteration.
        if(window < minVal){
            minVal = window;
            minIndex = i+1; // adding with 1, because we have to return 1 based index answer.
        }
    }
    // cout << minIndex-k+1 << " "  << minVal << endl;  // for debugging
    // subtracting k & then adding 1, so that it point to the starting address of window.
    if(minIndex-k+1 < 1){   // if subtraction makes it lesser, then we simply print 1, as given constrains for minIndex
        cout << 1 << endl;
    }else{
        cout << minIndex-k+1 << endl;   // else we print the favorable index..
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