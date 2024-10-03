/*

//  1657. Determine if Two Strings Are Close


//  Observations: 
    * Two strings are considered close if you can attain one from the other, using the following operations.
    * Operation 1: Swap any two existing characters.
        * For example, abcde -> aecdb
                        -  -     -  -

    * Operation 2: Transform every occurrence of one existing character into another characters, and do the same with the other character.
        * For example, aacabb -> bbcbaa
                       -- ---    -- ---

    * We can use the operations on either string as many times as necessary.
    Given two string, word1 and word2, return true if word1 and word2 are close, and false otherwise.


// Example:

    Input: word1 = "abc", word2 = "bca"
    Output: true
    Explanation: You can attain word2 from word1 in 2 operations.
    Apply Operation 1: "abc" -> "acb"
    Apply Operation 1: "acb" -> "bca"


    Input: word1 = "a", word2 = "aa"
    Output: false
    Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.


    Input: word1 = "cabbba", word2 = "abbccc"
    Output: true
    Explanation: You can attain word2 from word1 in 3 operations.
    Apply Operation 1: "cabbba" -> "caabbb"
    Apply Operation 2: "caabbb" -> "baaccc"
    Apply Operation 2: "baaccc" -> "abbccc"


// Key Observations: 
    Input: word1 = "cabbba", word2 = "abbccc"       ->      True

        * If we carefully observe these two string, we just change the count of the characters, means
        * If we have (1 -> c, 3 -> b and 2 -> a) then in final string we have (1 -> a, 2 -> b and 3 -> c)
            * here, elements are not, change, we just change their frequency in final...
            * Also, when the element is changes, the frequency is changes, but if we saw frequency count also, total frequency count is not changes..
        * Using these key Observations, if we try to match few things, like characters, & their frequency -> by this we can determine whether strings are close or not?
        * Example:

                Input: word1 = "cabbba", word2 = "abbccc"       ->      True

                    Word1: 
                        characters = {a, b, c}

                        frequency: 
                          char      freq
                            c    ->  1
                            a    ->  2
                            b    ->  3
                    
                    Word2: 
                        Characters = {a, b, c}

                        frequency:
                          char      freq
                            a    ->  1
                            b    ->  2
                            c    ->  3

                * Here, if we exclude this factor that that frequency is not dependent on characters.
                * We just store the frequency in an array, & matched both of them, then it's same. 
                * the characters & frequency, it's same for both the word.

            * Another Example:

                Input: word1 = "uau", word2 = "ssx"       ->      False

                    Word1: 
                        characters = {u, a}

                        frequency: 
                          char      freq
                            a    ->  1
                            u    ->  2
                    
                    Word2: 
                        Characters = {s, x}

                        frequency:
                          char      freq
                            x    ->  1
                            s    ->  2

                    * Here frequency is same, but character is not same of both word.

 
// Intrusion: 
    * We can build two function:
        * Function 1: check the frequency matched:
            * First, we will use two map to store the frequency of both the element, then convert the frequency into two vectors.
            * Then, we will sort both the vectors, so that matching is easy.
            * Then, we will match every element of both the character,
            * Once, all the checks are passed, return true, or false othewise.
        * Function 2: check the characters matched:
            * First, we will use two sets to insert both the word.
            * This will make sure not to insert duplicates values.
            * Then we will match both the set characters.
            * Once all the checks are passed, return true, or false otherwise.
    * TC: O(n), n = max(w1.size(), w2.size())


*/

#include<bits/stdc++.h>
#include<algorithm>
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
#define mod 1000000007

class Solution {
public:
    // Function 1: check frequency of both the word:
    bool checkFrq(string word1, string word2){
        // Storing frequency of word 1 -> converting it into vector afterwards.
        unordered_map<int, int> mp1;
        for(auto i: word1) mp1[i]++;

        vector<int> v1;
        for(auto i: mp1){
            v1.push_back(i.second);
        }

        // Storing frequency of word 2 -> converting it into vector afterwards.
        unordered_map<int, int> mp2;
        for(auto i: word2) mp2[i]++;

        vector<int> v2;
        for(auto i: mp2){
            v2.push_back(i.second);
        }

        if(v1.size() != v2.size()) return 0;  // checking the size of both the frequency vector, if they are not same return 0


        // Sorting both the frequency vector, so that we can match it afterwards.
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());


        // Checking the frequency on both the frequency vector after sorting, whether it's same or not?
        for(int i=0;i<v1.size();i++){
            // At any movement if the any any frequency is not matched we return false.
            if(v1[i] != v2[i]) return 0;
        }

        return 1;   // else return true.
    }

    // Checking character on both the array:
    bool checkChar(string w1, string w2){
        // Using set to store the elements from first word
        set<char> s1;
        for(auto i: w1) s1.insert(i);

        // Using set to store the elements from second word
        set<char> s2;
        for(auto i: w2) s2.insert(i);


        // matching elements from set:
        auto i1 = s1.begin();
        auto i2 = s2.begin();

        while(i1 != s1.end() && i2 != s2.end()){
            if(*i1 != *i2) return 0;    // if they are not matched return false
            i1++;
            i2++;
        }

        return 1;   // else return true:
    }
    // function to check closest string:
    bool closeStrings(string w1, string w2) {
        if(w1.size() != w2.size()) return 0;    // if both words size are not equal, return false

        return (checkFrq(w1, w2) && checkChar(w1, w2));     // if both the function calls true return true, else false
    }
};


void solve(){
    string s1, s2;
    cin >> s1 >> s2;

    Solution obj;
    (obj.closeStrings(s1, s2)) ? cout << "true" : cout << "false";
    cout << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}