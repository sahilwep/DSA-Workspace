
/*

// 779. K-th Symbol in Grammar


// Problem Statement:
    -> We build a table of n rows (1-indexed). We start by writing 0 in the 1st row. 
    -> Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

    -> For example, for n = 3, the 1st row is 0, the 2nd row is 01, and the 3rd row is 0110.
    -> Given two integer n and k, return the kth (1-indexed) symbol in the nth row of a table of n rows.


// Example:

    Example 1:

        Input: n = 1, k = 1
        Output: 0
        Explanation: row 1: 0

    Example 2:

        Input: n = 2, k = 1
        Output: 0
        Explanation: 
        row 1: 0
        row 2: 01

    Example 3:

        Input: n = 2, k = 2
        Output: 1
        Explanation: 
        row 1: 0
        row 2: 01


//  Observations: 

    'n' Given rows:
    -> We will have to replace '0' with '01' & '1' with '10'


        n = 1 :   0
        n = 2 :   01
        n = 3 :   0110
        n = 4 :   01101001
        n = 5 :   0110100110010110
        n = 6 :   0110100110010110|1001011001101001
                  01101001100101101001011001101001

// Bruteforce Solution:
    * First Generate the given Pattern for each row
    * Iterate in generate pattern & get return the kth value


// Efficient Solution:

        n = 1 :   0
        n = 2 :   01
        n = 3 :   0110
        n = 4 :   01101001
        n = 5 :   0110100110010110
        n = 6 :   0110100110010110|1001011001101001

            Observe n = 6:

                    0110100110010110|1001011001101001
                    ----------------
                    same as n = 5

                                    1001011001101001 -> For this half

                                    10010110|01101001
                                            01101001 -> n = 4  -> This is n = 4

                                    10010110 -> reversed of n = 4
            
            -> From this above generated string, will have to return the kth value.

    // Observations:
    
        -> for every n, it's fetching the values from it's previous 'n'
        -> For 'n'
            -> half size is "n-1"
            -> Other half is:
                -> first half is half of 'n-1'
                -> second half is half of 'n-1' but it's reversed in order.
    
        -> Based on the above Observations, we can generate our "nth" string easily, without generating string every times.
        
        -> Another Interesting Observations: 

        n = 6 :   0110100110010110|1001011001101001
                  ----------------   
                                     |
                    01101001|10010110|10010110|01101001
                                     |
                        a       b         b       a             -> these portions of string are same.

        n = 4 :     01101001

                             |
                        01|10|10|01
                             |
                        a   b  b  a     -> These portions are same.

        
        -> Based on the above observations we can generate our nth "pattern" efficiently.

        -> Thinking more, can we directly return the kth query without creating pattern..

        Example: 
            n = 4, k = 7
                
                n = 4 -> pattern: 01101001
                                        |
                                        7th => 0
                    

                    n = 1 -> 0
                    n = 2 -> 01

                Can we directly generate nth pattern, instead generating all pattern before it..

                    n = 4

                    n = 1: "0"
                    n = 2: "01"
                    n = 3: "01" + s.substr(s.size()/2, s.size() - s.size()/2) + s.substr(0, s.size()/2);
                                        second_half->first_half               + second_half->second_half

        -> This is the logic, let's implement & check..
            if(n == 1) check manually
            if(n == 2) check manually

            if(n > 2) generate sequence:
                            |
                    s = 01|10|10|01
                        a  b  b  a
                        ----
                        prev_s

                    Generate s = prev_s + b + a

                    a & b are the string portions, we can get these from by using substr() function

                        // Solution:
                        int kthGrammar(int n, int k) {

                            if(n == 0) return 0;    // 0
                            if(n == 1){ // 01
                                if(k == 1) return 0;
                                else return 1;
                            }

                            // For n > 2 => Generate nth sequence:'
                            string s = "01";
                            n = n - 2;  // decrement n by 2, because we have already checked for n < 2
                            while(n--){
                                s = s + s.substr(s.size()/2, s.size() - s.size()/2) + s.substr(0, s.size()/2);  // this will Generate 's'
                            }

                            // In nth Sequence -> return kth character directly:
                            return (s[k-1] - '0');
                        }

        - From the above solutions This gives Memory Limit exceed, because of strict constrains..
        - Let's see how we can further improve our solution.
            
            // Interesting Observations: 
                for 0 -> we increase it with 01
                for 1 -> we increase it with 10

                means size of n is double of (n - 1)
                Example:
                    n = 1  0
                    n = 2  01
                    n = 3  [01][10]
                             0   1

                             -> size is twice..



        // Let's observe this question further:

            n = 5, k = 7 -> '0'
                
                sequence = 0110100110010110
            
                '0110' -> n = 3
                0110
                

                n = 4 01101001
                n = 5 0110100110010110


                n = 4 01101001
                n = 5 01101001 "10010110"
                    if we Observe carefully, for n = 5:
                        first half is n = 4
                        second half is complement of(n = 4), complement is bit's opposite.
                        n = 4 => 01101001
                        complement of n = 4  => 10010110
                
        

                So, for n = 5, we can return our answer form n = 4 => Observations..
                    -> This means for n = 5, we can find our answer form n = 4
                    -> for n = 4, we can find our answer from n = 3
                    ...

                Look's like recursively we can iterate & find our answer 'kth' number of 'nth' row



        // Recursive Solution:

                    n = 1 :   0
                    n = 2 :   01
                    n = 3 :   0110
                    n = 4 :   01101001
                    n = 5 :   0110100110010110
                    n = 6 :   01101001100101101001011001101001

                Base case: 

                    when n = 1, we can have only one value of 'k', i.e k = 1
                    -> the value we will return is '0'

                        if(n == 1 && k == 1) return 0

                Recursive case:

                    n = 3 0110
                    n = 4 01101001

                        let see: if k = 3, & n = 4
                        answer can be found easily from n = 3
                                    mid
                        because 0110|1001
                                n=3  Tn=3
                                        Tn = transpose of n

                        from this Observations, we can say:
                        if(k <= mid) -> we can find our answer from (n-1)
                        Example: k = 4 & n = 4
                        we can look on n = 3 -> 0110 -> return last value '0'

                        what if k > mid:
                            we saw from previous observation, second half of n is transpose of (n - 1)
                            Example: 
                                k = 5, & n = 4
                                    n = 01101001
                                    n-1 = 0110
                                                mid
                                            0110|0110
                                            1234|5678   -> index
                                            5678        -> index

                                            if we subtract mid from k: we can reach at index 1 or 5 whatever we can say.
                                            So, if(k > mid):
                                                return (k - mid)th element, but
                                                This time we will return the transpose of '0' i.e '1'
                        
                        So, we have seen two case: 
                            if(k <= mid):
                                return solve(n-1, k);
                            else
                                return solve(n-1, k - mid) -> we can return (k - mid), to reach the desired index.

                        // Finding Mid: 
                            mid is half of the string or length of (n - 1) string
                                    
                                    n = 1 0             2^(1-1) = 2^0 = 1
                                    n = 2 01            2^(2-1) = 2^1 = 2
                                    n = 3 0110          2^(3-1) = 2^2 = 4
                                    n = 4 01101001      2^(4-1) = 2^3 = 8
                                                        
                                        length of n = 2^(n-1)
                                        mid = n / 2 => 2^(n-1) / 2

                Let's write our recursive solution:


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    // Efficient Solution: Recursive Solution TC:O(n), SC:O(n)
    int kthGrammar(int n, int k) {
        // Base case:
        if(n == 1 && k == 1) return 0;  // when n = 1, sequence: '0', this is why we have return 0

        int mid = pow(2, (n-1)) / 2;    // getting the middle position

        // recursive case:
        if(k <= mid){ // if k is found in mid range, we can find our solution in (n-1) call, without changing 'k'
            return kthGrammar(n-1, k);
        }
        else{   // if k is grater than n, we can still found our solution, but we will subtract mid from k -> (k - mid) -> this will give us the index that are in range of (n-1)th value
            // return !kthGrammar(n-1, k - mid);    // '!' will transpose the result.
            return 1 - kthGrammar(n-1, k - mid);    // 1 - recursive_call() -> this will give us transpose of our result, for 0 it will give 1, & for 1 it will give 0
        }   
    }


    // Method 2: Bruteforce:  TC:O(2^n), SC:O(2^n)
    int kthGrammar_brute(int n, int k) {

        if(n == 0) return 0;    // 0
        if(n == 1){ // 01
            if(k == 1) return 0;
            else return 1;
        }

        // For n > 2 => Generate nth sequence:'
        string s = "01";
        n = n - 2;  // decrement n by 2, because we have already checked for n < 2
        while(n--){
            s = s + s.substr(s.size()/2, s.size() - s.size()/2) + s.substr(0, s.size()/2);  // this will Generate 's'
        }

        // In nth Sequence -> return kth character directly:
        return (s[k-1] - '0');
    }

    // Method 1: Brute-BruteForce:	TC:O(2^n), SC:O(2^n)
    int kthGrammar_Brute_1(int n, int k) {
        vector<string> res;

        string s = "0";  // -> n = 1
        n--;    // n should be decreased.
        res.push_back(s);


        while(n > 0){
            string temp = "";
            // Generate Combinations:
            for(int i=0;i<s.size();i++){
                if(s[i] == '0'){
                    temp += "01";
                }else{
                    temp += "10";
                }
            }
            s = temp;   // after every generation of temp, update string 's'
            // push back into our result vector.
            res.push_back(temp);
            n--;
        }

        // iterating in last row:
        int r = res.size();
        int lastElSize = res[r-1].size();
        
        int val = 0;
        for(int i=0;i<lastElSize;i++){
            if(k == 1){
                val =  res[r-1][i] - '0';
            }
            k--;
        }

        return val;
        
    }
};