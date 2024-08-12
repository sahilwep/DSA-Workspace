/*

//  B. Lecture

// Observations: 
    * We have new professor of graph theory, he speaks very quickly, so we came up with following plan to keep up with lecture, & make notes..
    * we know two language, & professor is giving lecture in first language..
    * The word of both language consist of lower letter, each word consist several characters..
    * For each word the words are different, they spelled differently..
    * Moreover the word of these language have one to one correspondence, 
    * i.e for each word in each language there exist only one word in other language having has same meaning..
    * we can write every word of professor of either in first language or second language..
    * of course, during the lecture we write each word in a language, in which the word is shorter..
    * in case of equal length of corresponding word, we prefer to write the word of first language...
    * We are given text of lecture the professor is going to read,
    * we have to find out how the lecture will be recorded in our notes...

// Example: 
    Input
        4 3
        codeforces codesecrof
        contest round
        letter message
        codeforces contest letter contest       // final give string, we have to compare from here..

    Output
        codeforces round letter round

    Explanations
        1st Codeforces: 
            we have codeforces that have less size
        2nd contest:
            we have round that have less size
        3rd letter:
            letter have less size
        4th contest
            letter have less size


    Input
        5 3
        joll wuqrd
        euzf un
        hbnyiyc rsoqqveh
        hbnyiyc joll joll euzf joll
    Output
        hbnyiyc joll joll un joll


// Intrusion:
    // Bruteforce Solution: TLE
        * We can get string from final string, & compare from the list...

    // Efficient Solution: 
        * We can use hashing approach: 
            * We can use map data structure that will take O(logn) complexity..

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


// Efficient Solution:
void solve(){
    int n, m;
    cin >> n >> m;
    map<string, string>  mp;    // Map decelerations
    for(int i=0;i<m;i++){
        string a, b;
        cin >> a >> b;
        mp[a] = b;
    }

    // fetching string from map:
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        string x = mp[s];   // we are fetching the hashed value
        // once we fetch the hashed value, we can compare it with input string:
        // if string size is lesser than the fetched value size, we print input string : else we print hashed value.
        if(s.size() <= x.size()){
            cout << s << " ";
        }else{
            cout << x << " ";
        }
    }
    el;

}


// BruteForce Solution:
string compare(vector<vector<string> > arr, string s){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<2;j++){
            if(arr[i][j] == s){
                if(j == 0){
                    if(arr[i][j].size() <= arr[i][j+1].size()){
                        return arr[i][j];
                    }
                    else{
                        return arr[i][j+1];
                    }
                }else{
                    if(arr[i][j].size() < arr[i][j-1].size()){
                        return arr[i][j];
                    }
                    else{
                        return arr[i][j-1];
                    }
                }
            }
        }
    }
    return "";
}

void solve_(){
    int n, m;
    cin >> n >> m;
    // creating a vector containing "n" vector each of size "m".
    vector<vector<string> > arr(m, vector<string> (2));
    for(int i=0;i<m;i++){
        for(int j=0;j<2;j++){
            cin >> arr[i][j];
        }
    }
    // storing final string:
    string final[n];
    for(int i=0;i<n;i++) cin >> final[i];

    // Operations:
    for(int i=0;i<n;i++){
        cout << compare(arr, final[i]) << " ";
    }
    el;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;

    // cin.ignore();   // Ignore the newline character left in the buffer

    while(t--){
        solve();
    }
    
    return 0;
}