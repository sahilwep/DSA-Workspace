/*
//  A. Strong Password

// Observations: 
    * we need to insert any lower letter character in b/w the string..
    * We need to find the maximum time taken to insert the character in the string..
    * Max time can be found by following these:
        * The time to type the first character is 2 sec.
        * The time to type othe than first character is 1 sec if the same as previous, otherwise 2 sec is different..

// Key Observations:
    * We will have to insert character from a-z at every position of string..
    * And we have to check typing cost for for the newly formed string..
        * typing cost can be determine by these constrains: 
            * first character will take 2
            * from second to last character if we have the same consecutive character we will cost 1, else 2
            * last we will return the cost to the parent call
    * At last we will check the cost of newly formed string & old..
    * store the maxCost newly formed result string.


*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef size_t s_t;  // use during string traversal
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define arrInp for(int i=0;i<n;i++) cin >> arr[i];
#define arrOut(k) for(int i=0;i<n;i++) cout << arr[i] <<  k;
#define el cout << endl;
#define SQ(a) (a)*(a);


#include <iostream>
#include <string>
using namespace std;

// Function to calculate the typing time of a string
int typingTime(const string &str) {
    int time = 2; // Time for the first character
    // for other character
    for(int i=1;i<str.size();i++){
        if(str[i] == str[i-1]){
            time += 1;  // for same character it will take 1 sec
        }else{
            time += 2;  // for different character it will take 2 sec
        }
    }
    return time;
}

void solve() {
    string s;
    cin >> s;
    string bestString = "";
    int maxTime = 0;

    // Try inserting each lowercase letter at every possible position:
    for(int i=0;i<=s.size();i++){
        for(char c = 'a';c <= 'z';c++){
            // form the new string by inserting character c at position i
            string temp = s.substr(0, i) + c + s.substr(i);
            // calculate the typing time for this new string
            int currTime = typingTime(temp);
            // if this typing time is grater than the previous maxTime, Update maxTime and best string.
            if(currTime > maxTime){
                maxTime = currTime;
                bestString = temp;    // storing the best string among the others
            }
        }
    }

    cout << bestString << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}