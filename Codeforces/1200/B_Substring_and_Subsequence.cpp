/*
//  B. Substring and Subsequence

// Observations: 
    * we are given two string a & b in lowercase.
    * We have to find minimum possible length of string that contains a as substring & b is subsequence
    * Subsequence: a substring of string which can obtained by removing several(possibly zero) characters from original string.
        * Example: s = abac
           a, b, c, ab, aa, ac, ba, bc, abc, aac, bac and abac
           * The order should not be change while picking elements... 
                * Means for s = abac, we can pick a & then skipping b & picking a again..
                    aa -> subsequence...
                * but if we pick "acb", this is not subsequence...


    * Substring: a substring is contigious sequence of string.
        * Example: s = abac
           a, b, c, ab, ba, ac, aba, bac and abac


// Key-observations:
    * we have to find minimum possible length of string that contains a as substring & b as subsequence,
    * Means the minimum length for sure be the string of size a.
    * we just need to find the subsequence of b that are present in a...
    * If we carefully observe the string size in given constrains, it's 100, means we can use nested loops..

// Examples: 
* Answers are subsequence are in string a will be uppercase 
    a = aba
    b = cb
        * In the first example, one of the possible answers is CaBa

    a = er
    b = cf
        * In the second example, one of the possible answers is erCF

    a = mmm
    b = mmm
        * In the third example, one of the possible answers is MMM

    a = contest
    b = test
        * In the fourth example, one of the possible answers is conTEST
        
    a = cde
    b = abcefg
        * In the fifth example, one of the possible answers is ABCdEFG


// Intrusion: 
    a = contest
    b = test
    * Idea is to start iteration from string b & check in string a, whether the character from a is present or not..
    * We can use two pointers..
        * first pointer, iterating from 0 to b.size()
        * second pointer, for each b[i], we will check b[ptr2] with each string character of a
            t e s t 
            c o n t e s t
            0 0 0 4 3 2 1
                * We get the max of this count i.e 4 & subtract from both the size of strings i.e a.size() & b.size()
                * For 't' in string a, once we find the character 't' in string b
                * we will increment the pointer for a & check next matched characters..

        * Iteration overview
            a = t e s t 
            b = c o n t e s t
                i = 0 -> b[0] = 'c'
                    for j = 0 to j = a.size() not matched
                i = 1 -> b[1] = 'o'
                    for j = 0 to j = a.size() not matched
                i = 2 -> b[2] = 'n'
                    for j = 0 to j = a.size() not matched
                i = 3 -> b[3] = 't'
                    b[3] 't', make a pointer ptr = i(3)
                    j = 0 -> if a[j] == b[ptr] matched
                        a[0] == b[3] matched, 't' == 't'
                        increment ptr++, so that it can match the max length of subsequence..
                        cnt = 1
                    j = 1 -> matched a[j] == b[ptr] matched
                        a[1] == b[4] matched, 'e' == 'e'
                        cnt = 2
                        increment ptr++, so that it can match the max length of subsequence..
                    j = 2 -> matched a[j] == b[ptr] matched
                        a[2] == b[5] matched, 's' == 's'
                        increment ptr++, so that it can match the max length of subsequence..
                        cnt = 3
                    j = 3 -> matched a[j] == b[ptr] matched
                        a[3] == b[6] matched, 't' == 't'
                        increment ptr++, so that it can match the max length of subsequence..
                        cnt = 4
                i = 4 -> b[4] = 'e'
                    b[4] = 'e', make a pointer ptr = i(4)
                        ...
                        ...
                        same steps make..
                        we will get cnt size = 3 
                i = 5 -> b[5] = 's'
                    b[5] = 's', make a pointer ptr = i(4)
                        ...
                        ...
                        same steps make..
                        we will get cnt size = 2
                ...
                ...
                we will do this till end of b.size()...
                at the end of every ith iteration we will store the cnt...
                when the cnt is maximum we will store that only..
            * At the end we will return the result by subtracting cnt from both the size of strings.



                
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
    string a, b;
    cin >> a >> b;

    int ans = 0;
    // we will iterate in second string.
    for(int i=0;i<b.size();i++){
        // pointer that will change accordingly once we found any characters, to check maximum length of subsequence.
        int ptr = i;    // every time pointer start from the ith position of string b
        int cnt = 0;    // count the number of matched characters every time.
        // iteration in first string.
        for(int j=0;j<a.size();j++){
            if(a[j] == b[ptr]){ // if we found the 
                ptr++;
                cnt++;
                if(ptr == b.size()) break;  // edge case when pointer increment till b.size() we need to break, because pointer itself pointing the b[i] elements...
            }
        }
        ans = max(ans, cnt);    // at the end of every iteration we will store the maximum count
    }
    ans = a.size() + b.size() - ans;    // subtract the count from both the size of strings.
    cout << ans << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}