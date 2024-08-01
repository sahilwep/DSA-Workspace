/*
//  B. Make Majority

// Observations: 
    * We are given an array which is given value in 0 & 1, we can apply several operations in the sequence,
    * In every operations we can select two integers, l & r, (1 <= l <= r <= |a|) (where |a| is current length of an a), & replace [al,....ar] with a single element x, where x is majority of [al....ar]
    * Here majority of a sequence consisting 0 & 1 is defined as follows: 
        * suppose there are c0 zeroes & c1 ones in the sequence respectively
        * If c0 >= c1, the majority is 0
        * if c0 < c1, the majority is 1
    * We have to determine wether we are able to build arr[] = {1} in finite number of step or not...

// Key observations: 
    * In each iterations we can select two range l & r & replace this range with single element x,
    * x is the majority of l & r
        Exapmle:
            arr[] = 0 1 1 0
                if we select l = 0, & r = 2
                            [0 1 1] 0
                            l    r
                    * In this range if the count of zeroes is in majority, our sequence will be 0, means x = 0
                    * If in this range the count of ones is in majority, our sequence will be 1, means x = 1
                    * So In Conclusion we can say we have to take x = the number of most occurring element in that range.
                * For the above exapmle: 
                    x = 1, because 1 occur 2 times & 0 occur 1 times.
                * so we replace this value with 1, so the new array will form: 
                        1 0

            * If we select the whole range, means l = 0, & r = 3
                        [0 1 1 0]
                        l      r
                * The majority will be 0, because we have given condition that if (c0 >= c1 => majority will be 0)

    * Example: 
        example: 1 0 0 0 1
                    1 [0 0 0] 1
                    [1 0 1]
                    1
        * We can make this to 1

        example: 0 0 0 0 1 1 0 0 0 0
                    0 0 0 0 1 1 [0 0 0 0]
                    [0 0 0 0] 1 1 0
                     0 1 1 0
                     from this we can't minimize 0 further, the only thing we can minimize is 1
                     [0 1 1 0]
                      0
    * In conclusion we can say: 
        we have to minimize the number of 0's that are occurring in sequence..
        & last we can count the number of 1's & 0's, and if 1's > 0's then print "YES" : "NO"
        because if we have number of 1's more than 0's, for every possible condition we can form array of [1], by minimizing [0]


// Intrusion: 
    * We are minimizing the count of number of 0, & it's can be done by minimizing the count of number of zeroes that are contigious in sequence...
    * once we have minimized all the number of 0, we can count the number of zeroes & ones, & if one occurring most we print "YES" : else "NO"
    * If we encounter consecutive occurrence of 0, we only have to store it once..
        * we can use a flag that will make sure it's will store '0', only when it has stored '1' previously....


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
    cin >> n;     // input of string size
    string s;
    cin >> s;   // input of string
    string res = "";    // this will store the result of it..
    bool flag = 0;  // flag will use to consecutively select the repeating element

    for(int i=0;i<s.size();i++){
        // if we have occurring of 1's we will store it
        if(s[i] == '1'){
            res += '1'; 
            flag = 0;   // making the flag = 0, will ready to store the first occurrence of 0 after this recent encountered 1
        }
        // if we have 0, & flag = 0, means we just encounter the 1 before, then only it will go & store '0'
        if(s[i] == '0' && flag == 0){   
            res += '0';     // storing 0's
            flag = 1;   // making flag = 1, will make sure that it will not 0, until it stores any 1...
        }
    }

    // at last we can count the number of occurrence of ones & zeros...
    int ones = 0, zeros = 0;
    for(auto i : res){
        if(i == '0') zeros++;
        else ones++;
    }

    // if we have more frequency of ones than zeroes, we can definitely build an array [1]
    (ones > zeros) ? cout << "YES" : cout << "NO";
    el;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}