/*
//  A. Police Recruits


// Observations: 
    * If we observe the patter of crime happening..
    * when police is not there, then only the crime is happening...
    * When there is police available, crime is not happening...
    * Also, if we carefully observe input, we can make the algorithm for this logic...

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
    cin >>n;
    int arr[n];
    arrInp;
    int crime = 0;
    int crimeAfterPolice = 0;
    int police = 0;
    for(int i=0;i<n;i++){
        // Input: 
        if(arr[i] > 0){
            police += arr[i];
            crimeAfterPolice = 0;
        } else if(arr[i] < 0){
            crimeAfterPolice += 1;
        }

        // Operations: 
        if(crimeAfterPolice > 0 && police > 0){
            crimeAfterPolice--;
            police--;
        }

        // Storing Result: 
        if(crimeAfterPolice > 0 && police == 0){
            crime++;
        }
    }
    cout << crime << endl;
}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}