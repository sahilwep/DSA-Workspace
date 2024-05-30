/*
//  A. Choosing Teams


// Observations: 
    * As per the question, Ther is ICPC contest going on...
    * We have list of n student who participate in ICPC
    * Each student at most participate 5 times..
    * The head want to make a team of 3 student, to participate, but he has condition that each player should be play K times...

    Input: 
        5 2
        0 4 5 1 0
    Output: 
        1
    Explanations: 
        total no of student: n = 5
        no of times these teams should play : k = 2
        No of times student play : 0 4 5 1 0
                          student: 1 2 3 4 5

        if we take student (1 4 5), these can participate 2 times in Competition, & they can't exceed the constrains of Competitions (i.e at max 5 times playing ICPC) 
        * So we can make only 1 team..
    
    Input: 
        6 4
        0 1 2 3 4 5
    Output: 
        0
    Explanations: 
        total no of student: n = 6
        no of times these teams should play : k = 4
        No of times student play : 0 1 2 3 4 5
                          student: 1 2 3 4 5 6

        if we saw carefully only student 1, 2 have the ability to play 4 times, & rest of the student are not fit the constrains of competition..
        * and we need 3 student to make a team, so we can't make a team..
    
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
    arrInp;
    int team = 0;
    for(int i=0;i<n;i++){
        // we simply subtract each player played games by 5 so that we can get the remaining chance they have left, and then we compare with k so that is they are eligible to play in competition or not?
        if(5 - arr[i] >= k){
            team++;
        }
    }
    team = team / 3;    // we get the number of participant who are eligible to play, so we divide them by 3, in order to get the number of team..
    cout << team << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}