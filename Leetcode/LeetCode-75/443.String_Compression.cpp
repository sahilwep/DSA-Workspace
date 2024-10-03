/*

//  443. String Compression

//  Observations: 
    * we are given an array of character, we need to build an that store the frequency of that array.
    * NOTE: when we have single element don't store their frequency number in array.



// Example: 

    Input: chars = ["a","a","b","b","c","c","c"]
    Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
    Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".


    Input: chars = ["a"]
    Output: Return 1, and the first character of the input array should be: ["a"]
    Explanation: The only group is "a", which remains uncompressed since it's a single character.


    Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
    Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
    Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".



// IntrusioN:
    // Hashing will Not work:
        * NOTE: We can have element repeated after some while in array, so we need to take care of that:
        * Example: 
                    ["a","a","b","b","c","c","c","a","a"]
                    
                    -> ["a","2","b,"2",c","3","a","2"]

            * Here, a repeated after a while so, if we use hashing it will store all the occurrence, instead of a specific range occurrence      


    // We will use Greedy Approach: 
        * When we have contigious occurrence of element we will count & whenever we encounter with different element, we will store that frequency & element into the array...
        * At the end we will overwrite the array, & return the range. 


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
    int compress(vector<char>& chars) {
        int n = chars.size();
        if(n == 1)  return 1;   // if we have single element return 1

        // storing the element & frequency into string:
        string res = "";
        char ch = chars[0]; // variable that store the temp character.
        int cnt = 1;    // temp counter that count for contigious same occurring element.
        for(int i=1;i<n;i++){
            // Whenever we are encounter with different element:
            if(chars[i] != chars[i-1]){
                // Storing values into the result:
                // if cnt = 1, don't store the frequency number.
                if(cnt == 1){
                    res += ch;      // storing character.
                }
                else{
                    res += ch;                  // storing character
                    res += to_string(cnt);      // storing their count
                }
                // Changing the Current Values for further operations:
                ch = chars[i];  // making temp char 
                cnt = 1;    // making their frequency count = 1
            }
            // Else when we have same char[i] & char[i-1]
            else{
                cnt++;  // increase their frequency count
            }
        }

        // Insertion of last left values: Because last contigious value will never go into else case.
        res += ch;  // Storing the character
        // Storing the frequency
        if(cnt != 1){
            res += to_string(cnt);
        }

        // Getting the size, because that is what we have to return .
        int size = res.size();

        // Overwriting original char array with compressed values:
        int k = 0;
        for(auto i: res) chars[k++] = i;

        return res.size();  // returning the new size:
    }
};

void solve(){
    int n;
    cin >> n;
    vector<char> chars(n);

    for(int i=0;i<n;i++) cin >> chars[i];

    Solution obj;

    n = obj.compress(chars);

    for(int i=0;i<n;i++) cout << chars[i] << " ";
    
    cout << "\n";
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}