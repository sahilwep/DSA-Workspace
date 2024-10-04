/*

//  1071. Greatest Common Divisor of Strings

//  Observations: 
    * We are given two string s1, & s2, we say "s2 divides s1" if and only if s1 = s2 + s2 + s2 + ... + s2...(i.e s2 is concatenated with itself one or more times).
    * Given two string s1 & s2, return the largest string x such that x divides both string s1 & s2


// Example:

    Input: str1 = "ABCABC", str2 = "ABC"
    Output: "ABC"

    Example 2:

    Input: str1 = "ABABAB", str2 = "ABAB"
    Output: "AB"

    Example 3:

    Input: str1 = "LEET", str2 = "CODE"
    Output: ""


// Key Observations: 
        s1 = ABABAB          s2 = ABAB

        * First Observations: if S1 + s2 != s2 + s1 => return "", 

            * This is because: if they are not same return false

                * Example: When both the string are not same: 

                            s1 = A B A B A B          s2 = A B C D
                                 --  --  --                 --  --
                    let say      x    x   x                 x    y

                    so, If we add s1 + s2 & s2 + s1, which is equal to 
                        x + x + x + x + y   !=  x + y + x + x + x       => Not same
                        ---------   -----       -----   ----------
                            s1       s2          s2         s1



                * Example when both the string becomes same:   

                            s1 = A B A B A B          s2 = A B A B
                                 --  --  --                 --  --
                    let say      x    x   x                  x   x

                    so, If we add s1 + s2 & s2 + s1, which is equal to 
                        x + x + x + x + x   ==  x + x + x + x + x       => Same
                        ---------   -----       -----   ----------  
                            s1       s2           s2        s1


            * Now, we are sure that, if s1 + s2 == s2 + s1 -> we have to look for the greatest common divisor that divides both the string:

            * Why GCD ?
                * Example:
                            s1 = A B A B A B          s2 = A B A B
                            size = 6                   size = 4

                            GCD = 2 -> So first two character that divides both of them..
                        
                    * Now, let's see why gcd will be the size of our string.
                            * as we know that both the string is divisible by the above conditions..
                            * Let's see an example:

                                s1 = x x x x x x          s2 = x x x x
                                      size  = 6,            size = 4
                                

                                * gcd = (6, 4) = 2


                                * Now, 
                                    if we use 4 size, this will divides s2, but in s1, it will left 2 
                                    Which violates the given conditions.
                                    because
                                        s1.size() % 4 = 2   -> violates
                                        s2.size() % 4 = 0
                    

                                * So, we need to choose such numbers which divides both the string..
                                
                                    1, 2 -> divides both the string.
                                    But, here if we take 1
                                        * We need to divides s1 with 6 times & s2 4 times
                                        * Instead, if we use 2, which is pair of (xx), & which divides both the strings.
                                        * and also according to the question we need to return the largest substring that divides both the string.
                                        * So, GCD size substring is our answer.

// Intrusion: 
    * First we check if (str1 + str2 == str2 + str1) -> If not return ""
    * Else:
        * find gcd of both the string, 
        * Then we take substr(0, gcd) -> this will return the string.
            * substr(pos, len) -> position from where to start, & length is nothing but = (pos + len)
        * then return that string.  

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


// Function to check the GCD
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // If both the string are not same after concatenating with s1+s2 & s2+s1, we will return empty ""
        if(str1 + str2 != str2 + str1) return "";

        // Else when s1+s2 == s2+s1, means we need to return, just that maximum substring part that divides both the string.
        // finding the gcd:
        int GCD = gcd(str1.size(), str2.size());

        // returning the gcd size substring from starting to gcd size, which is our answer:
        string res = str1.substr(0, GCD);

        return res; // returning the string.
    }
};

void solve(){
    string s1, s2;

    cin >> s1 >> s2;

    Solution obj;
    string res = obj.gcdOfStrings(s1, s2);
    (res.empty()) ? cout << "Empty" : cout << res;
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