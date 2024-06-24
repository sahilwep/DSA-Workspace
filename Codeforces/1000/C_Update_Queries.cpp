/*
//  C. Update Queries


// Observations: 
    * We have given string s of size n, query q of size m, & string c of size m.
    * we have to perform update operations & we can set s[query[i]] = c[i]..
    * we can perform m operations from the first & last..
    * we are allowed to change the index of array & order of string c..
    * We have to find the smallest lexigraphical string s that can be obtained after doing m operations..
    * we can rearrange query array & string c as we like..
    * Condition for lexigraphical string a is lexigraphical smaller than stirng b, if and only if: 
        * a is prefix of b & a != b
        * In the first position where a & b are differ, the symbol in string a is earlier in the alphabet corrsponding to the string b

// Intrusion: 
    * If we sort the string c & array query and remove duplicate from the query, & then we will start performing update operations,
    * the string that formed will be lexigraphical small.

// TC: O(n)

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


// Function used to remove duplicate from the query..
int remDup(int arr[], int n){
    int k = 0;  // pointer 1 to insert unique values.
    for(int i=1;i<n;i++){   // pointer 2 will be iterating over & finding unique values..
        if(arr[k] != arr[i]){   
            arr[++k] = arr[i];  // storing at pointer 1 & increment their index values..
        }
    }
    return k+1;
}


void solve(){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;   // input of s size n
    int query[m];
    for(int i=0;i<m;i++){
        cin >> query[i];    // input of query
        query[i]--; // making query 0 based index, by subtracting 1 from the value..
    }
    sort(query, query+m);   // sort the values of query..

    int newSize = remDup(query, m); // removing the duplicates & getting new size of query..

    string c;   
    cin >> c;   // input of string c, of size m
    sort(c.begin(), c.end());   // sort string c
    int j = 0;  // maintaining pointer j = 0 which is used iterate over string c

    for(int i=0;i<newSize;i++){
        s[query[i]] = c[j++];   // inserting c[j] to s[query[i]]
    }

    cout << s << endl;  // last we will print string s.
}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}