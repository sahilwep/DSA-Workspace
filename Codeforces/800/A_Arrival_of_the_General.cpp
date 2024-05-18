/*
//  A. Arrival of the General


// Observations: 
    * According to the questions, the max element will be in front & min element will be in end.
    * We have to swap as min as possible, & count he number of  swap

// Intrusion: 
    * First we will store the index of first max element, because are per the question condition.
    * Then we will store the index of last min element, because are per the question condition
    * Then we will swap & check whether it's on correct postion or not: 
        * Starting from min: 
            * we have to move min element to the front of line.
            * Edge case: when we are with maxIndex element, we have to change the position of max element index, so that our future operations will go smoothly..
            * We will swap minIndex element with next element & update the position of min element.
            * at every swap we will count.
        * Same we do with max:
            * swap with the previous element & update the maxIndex position
            * Count the number of swap.
    * At the end we will print the count..



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
    int arr[n];
    int min = INT_MAX, max = INT_MIN;
    int minIdx, maxIdx;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(arr[i] > max){
            max = arr[i];
            maxIdx = i;
        }
        if(arr[i] <= min){
            min = arr[i];
            minIdx = i;
        }
    }

    // swap & check
    int cnt = 0;
    while(minIdx != n-1){
        // edge case: when we are swapping the min element with max element.
        if(minIdx+1 == maxIdx && arr[minIdx+1] == arr[maxIdx]){
            maxIdx--;
        }
        swap(arr[minIdx],arr[minIdx+1]);
        minIdx++;
        cnt++;
    }


    while(maxIdx != 0){
        swap(arr[maxIdx], arr[maxIdx-1]);
        maxIdx--;
        cnt++;
    }

    cout <<  cnt << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}