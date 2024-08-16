/*

//  A. Problemsolving Log

// Observations: 
    * we are given a string s, contains uppercase alphabets from 'A' to 'Z'
    * These characters denotes problem solved during the contest..
    * It is known that each problem is solved A->1min, B->2min, C->4min...Z->26min...
    * After the contest we are given a log about the contest, such that ith letters tells which problem monocrap was solving during ith minutes..

// Example Observations:

    // Example 1: 
        s = FEADBBDFFEDFFFDHHHADCC
                    
            Minutes taken by each characters: 
                f = 6
                a = 1
                D = 4
                b = 2
                e = 5

                size: 22
                string:  F E A D B B D F F E  D  F  F  F  D  H  H  H  A  D  C  C
                minutes: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22

                * Storing frequency: 
                    f = 6   solved
                    e = 2   not solved
                    a = 2   solved
                    b = 2   solved
                    d = 4   solved
                    h = 3   not solved

                * In total 4 questions solved

    // Example 2: 
        s = AAAAFPC

            Minutes taken by each characters:
                a = 1
                f = 7
                p = 16
                c = 3

                    n = 7
                    s   = A A A A F P C
                    min = 1 2 3 4 5 6 7
                
                * Storing frequency: 
                    a = 4   solved
                    f = 1   not solved
                    p = 1   not solved
                    c = 1   not solved
                
                * In total 1 question solved

    // Example 3: 
        s = ACBCBC

            Minutes taken by each characters:
                a = 1
                b = 2
                c = 3

                    n = 6
                    s   = A C B C B C
                    min = 1 2 3 4 5 6
                
                * Storing frequency: 
                    a = 1   solved
                    b = 2   not solved
                    c = 3   not solved
                
                * In total 3 questios solved

// Intrusion: 
    * We can make an array that contains the minutes taken by each characters..
    * Or we can use ASCII logic, which will be more helpful in this case..
        * This can used instead of maintaining the array that contains the cost(int(ch - 'A') + 1)
    * Second hash the string characters frequency...
    * after match & return the no fof problem solved...


// Complexity:
    * TC: O(n)
    * AS: O(n)

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

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Now hashing string characters:
    unordered_map<char, int> mp;
    for(auto i : s){
        mp[i]++;
    }

    int solved = 0;
    for(auto i=mp.begin();i!=mp.end();i++){
        // getting values from the cost vector & calculating the number of solved questions.
        int cost = (i->first - 'A') + 1;
        int freq = i->second;
        if(freq >= cost){
            solved++;
        }
    }

    cout << solved << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}