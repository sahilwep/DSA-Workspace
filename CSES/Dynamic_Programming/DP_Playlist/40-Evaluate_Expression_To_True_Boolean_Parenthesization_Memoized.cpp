/*

//  Evaluate Expression to True Boolean Parenthesization Memoization: 


//  Problem Statement:
    * Given a boolean expression s, with following symbol:
            'T' ---> true
            'F' ---> false
    * and following operators:
            &   ---> boolean AND
            |   ---> boolean OR
            ^   ---> boolean XOR
    * Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true


// Example: 

    Input: 
    n = 7
    s = T|T&F^T
    Output: 
    4
    Explaination: The expression evaluates to true in 4 ways ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).

    Input: 
    n = 5
    s = T^F|F
    Output: 
    2
    Explaination: ((T^F)|F) and (T^(F|F)) are the only ways.


// MCM Identification: 
    * We are given an instruction that we can apply brackets in order to get true, & we need to count of them..
    * In Worse case, we will apply brackets at every possible index, so that we can make our solution..
        * Example:
                s = "T|T&F^T"
                    (T|(T&(F^T)))

        * So, we are doing partition at every possible index in range (start --- end)




// Problem Visualization: 
    * Let's solve this question with MCM Format: -> We will be solving this question using recursive solution, then afterwards we will memoized this.......
        * In what ways, we can apply brackets, so that we can get maximum true, 
        * we need to find the number of ways in which we can get true from the above expression.



        // Identification of Solve() -> function & it's parameters:
            * We are dealing with the problem where we need to perform boolean expression, & upon that we need to take some possibility so that we can get maximum true, & we need to count all the True case
            * So, what extra we needed in our function definition ?
                * As we are computing Boolean expression, So, we only need to add one parameter which can hold the values T/F..
                * Extra we will adding one variable "isTrue", which will hold the possible values..
                * Return type of the function is "INT", because we are returning the no of ways..
                * So, Function definition Looks Something like this:

                    int boolExp(string &s, int i, int j, bool isTrue){
                        ... logic ..
                    }


        // Identification of (i & j) -> Starting & ending ranges:
       
                    s = "T | T & F ^ T"


                * In the given String, on what Possible position we can apply (i & j), so that our expression is logic is valid.

                        0 1 2 3 4 5 6   -> index
                        T | T & F ^ T   -> String
                
                * If we have applied (i = 0) & (j = n-1), there is no problem, because we will perform our partition in range (i to j), & also we we will have to look for every possible characters..

                        0 1 2 3 4 5 6
                        T | T & F ^ T
                        i           j

                        So, we will place (i = 0) & (j = n - 1), n = s.size(), & s = string


        // Identification of Base Condition: 

                // if (i > j) -> there is empty string, when i exceeds j -> size = 0

                    If string is empty there is no way we can get any ways, to make our expression True.
                



                // if (i == j): when i & j pointing on same index

                    As we are Checking these base condition, means these will execute when we have recursive calls for left & right subproblems..
                    And we are doing partition on Operators, Not Operands..
                    So, During the computation of these base case, We will have either ("T" or "F" )in our string, not ('&', '|', '^')


                    So, possible string characters that comes are either "T" or "F"


                    Now, One more Extra things we need to take care, i.e:
                            While we computing left_subproblem & right_subproblem, we need to check for Both "True" and "False" Possibility.
                                               

                                                {------| k |---------}  -> When our string break on any Operator ('&', '|', '^'):
                                                    /           \
                                        {left Subproblem}    {right Subproblem} -> these are the two subproblem that we have to solve
                                            /    \                  /   \
                                        (True)  (False)        (True)   (False)     -> every side of subProblem can have two Possibility, Because we are not sure on what Operator it will break, it can be either('&', '|', '^')


                                    Now, {left Subproblem}:
                                            -> It can have two Possibility {True, False}
                                            -> You might be thinking why Two Possibility, 
                                            -> Think again about our problem, we are finding how we can make our expression True in order to apply brackets in a way so that our expression results in True.....    (@ _ @)!
                                            -> LetMe Explain MORE: 
                                                
                                                    Suppose we are computing '|' OR

                                                                                        OR BOOLEANS CASES
                                                                                            T T -> T
                                                                                            T F -> T
                                                                                            F T -> T
                                                                                            F F -> F

                                                    Let say,
                                                    From left subProblem -> {..XYZ...} we can have some partition, & after Computing this "...XYZ..." recursively, whatever expression we have...
                                                    Let say we Got "False" from left Side,  ->   Now to make this whole expression, "TRUE",  ->   we need "True" from right subProblem..
                                                    because, if we are not getting "True" from right side subProblem, there is no possible chance we will get make this expression, "True"
                                                    

                                                    Similarly, we can have any operators like "&" AND, "^" XOR, So we need to find the possible way we can get the results...
                                                    This is why we are checking for both the case, when we we have {True / False}

                                    
                                    Also, we need to know, What left_Subproblem OR right_Subproblem, "VALUES THEY WANT" & what values they contains..
                                    -> let me explain you more, "What left_Subproblem OR right_Subproblem Value they want"
                                    -> To make this whole expression True, expression can have Two value passed in recursive calls for "isTrue" variable...
                                    -> Depending On the recursive calls, the values they have passed for "isTrue", & the values the string contains we will have to take decisions on that. 
                                    -> In Simple Word, Recursive calls for {left: will pass value (isTrue = [True  and  False]) } & {right: will pass value (isTrue = [True  and  False]) }
                                    -> So, we will have to take care of "isTrue" condition also, and based on that we will Compute (i == j)



                                    NOTE: YOU MIGHT BE OVERWHELMED, WHY I HAVE EXPLAINED THIS ALL WHICH MAKING NO SENSE NOW... :(
                                    BUT , IT WILL ALL MAKE SENSE ONCE WE WILL GO ON THE CONDITION WHEN RECURSIVE CALLS HAPPENED...



                                    -> Concluding in Simple Word for (i == j)

                                        // When we have Single element..
                                        if( i == j){
                                            // Let say if the Subproblem has called for "True" case, means Subproblem has passed (isTrue = 1).
                                            if(isTrue == true){
                                                // Now checking the string, what value they contains, Note: we only have one string, because (i == j)..  [+_+]
                                                if(s[i] == 'T'){    // string has true, & subproblem want's 'True'
                                                    return true;    // so, we will return true,
                                                }
                                                // Means Subproblem calls for "True" case, & string has "F" False
                                                else{
                                                    return false;   // we are returning 'false', because subproblem calls for something else, & string contains something else..
                                                }
                                            }
                                            // Condition when Subproblem calls for "False" case, means Subproblem has passed (isTrue = 0).
                                            else{
                                                // If string Contains 'F' in it, means they want false & they got false, So, we will return true, because whatever they want they got that... {$__$}!!
                                                if(s[i] == 'F'){
                                                    return true;
                                                }
                                                // means string has 'T' & subproblem want's "true"..      :/
                                                else{
                                                    return false;   // sad...   :(
                                                }
                                            }
                                        }


                                    -> You might be wondering, why every time, i'm comparing s[i] == 'T' / 'F', not s[j] = 'T' / 'F'                        ->  HAHAHAH... look on the above condition (i == j) pointing on same string.....

                                    -> these are the possible condition when we have single condition...



        // Identification of 'k' partitions: 

                * Now let's check where we can apply 'k' in given Expression:


                        T | T & F ^ T
                        0 1 2 3 4 5 6

                * One thing we are sure that, we can't apply brackets on 'T'/'F', Because:
                        

                        k   k   k   k   -> if we apply partition on 'T'/'F', 
                        T | T & F ^ T
                        0 1 2 3 4 5 6
                        i           j

                                Let say if k is at 'T'     ->          k
                                which making no sense.     ->   (T | ) T ( & F ^ T) -> Invalid Case.. 

                        So, we will only perform partition on "Operators"


                * Means, we can only partition on "operators"

                          k   k   k
                        T | T & F ^ T
                        0 1 2 3 4 5 6
                        i           j

                                ->  if k is at '&'               k 
                                -> Partition look like:  (T | T) & (F ^ T)


                        So, k starts (i + 1) & goes till (j-1) last

                        start: (k = i + 1)
                        end:   (k <= j - 1)

                // Identification of 'k' increment:
                          
                          k   k   k
                        T | T & F ^ T
                        0 1 2 3 4 5 6
                        i           j

                        If we observe the pattern of 'k', every time k is incremented by '2'
                        So, (k = k + 2)
                

                // Final K partition loop:

                    for(int k = i + 1; k <= j-1; k = k + 2){
                        ... logic
                    }

                
        // Finding the Partition Scheme of 'k'

                          k   k   k
                        T | T & F ^ T
                        0 1 2 3 4 5 6
                        i           j

                Let say: k is at '&'

                               k
                         T | T & F ^ T

                    // K partition logic from MCM: 
                        for(int k = i + 1; k <= j-1; k = k + 2) // in loop we were finding left subproblem & right subproblem and generating temp solution & then afterwards we are finding the final answer..

                            // left Part:  Solve left part & Store it in temp answer

                            // right Part:  Solve right part & Store it in temp answer


                            left   k    right
                         (T | T )  &  ( F ^ T)
                          i   |    |    |   j
                              |    |    |
                            k-1    k    k+1

                        // from here we can say Partition scheme: 
                                -> left will go from  (i to k - 1)  
                                -> right will go from (k + 1 to j)

        
        // Finding the temp Answer:

            In loop we are doing partition (i to k - 1) & (k + 1 to j)
            & we were finding the left & right subproblems..
                

                NOTE: we are evalutating Boolean expression, So, any side of subproblem can give anything 'T'/'F'
                So, we are not sure what value they will provide...
                This is why we will pass (True and False) for every part of subproblem..
                In Simple word:

                    // left Subproblem: 
                        -> Check for true case: What result will left subproblem give, if we provide 'True'
                        -> Check for false case: What result will left subproblem give, if we provide 'False'
                    
                    // right Subproblem:
                        -> Check for true case: What result will right subproblem give, if we provide 'True'
                        -> Check for false case: What result will right subproblem give, if we provide 'False'


                You might be wondering why we are passing 'True' & 'false', for every side of subproblem, it's because we want to make our expression true, and we are not sure for what 'k -> operator' we will perform the partition, it can be ('&', '|', '^')...
                In simple word, we need to check all possible value(T/F) for left Subproblem & all possible value(T/F) right Subproblem 

                
            So, Temp answer can be found as: 

                // Finding possible values from left Subproblems:
                    leftTrue = boolExp(s, i, k-1, 1);       // For true case, we are passing (isTrue = true) ->{Extra: This is what i was talking previously in base condition when i == j}
                    leftFalse = boolExp(s, i, k-1, 0);      // for false condition

                // Finding possible value for right Subproblems:
                    rightTrue = boolExp(s, k-1, j, 1);
                    rightFalse = boolExp(s, k-1, j, 0);

                            NOTE: for left Subproblem We will use left partition scheme, whether we are passing T/F, and Vice versa...


        // Function that evaluates temporary solution: 

                So far we have calculated the result of (left subproblem & right subproblem)

                                        |---------|     k    |----------|
                                            /           |            \
                                (left Subproblem)       |     (right Subproblem)
                                                        |
                                            (Compute the result for this)
                
                We only need to compute the result of this 'k' -> which is Operator in our case: ('&', '|', '^')
                And after that we will be done to generate our Solution:

                    Boolean Expression Logics:

                        //  AND  '&' 
                            left    right   =>  answer
                             T        T     =>     T
                             T        F     =>     F
                             F        T     =>     F
                             F        F     =>     F
                        
                        //  OR  '|'
                            left    right   =>  answer
                             T        F     =>     T
                             F        T     =>     T
                             T        T     =>     T
                             F        F     =>     F
                        
                        //  XOR  '^'
                            left    right   =>  answer
                             T        T     =>     F
                             F        F     =>     F
                             T        F     =>     T
                             F        T     =>     T

                We are doing Partition on 'k' which is a operator ('&', '|', '^')
                So, from the possible solution we will check for every operator & generate the result:

                NOTE: [Outer the for loop, create a variable "ways = 0", which will hold our final answer]

                    
                    // When partition performed at '&'
                    if(s[k] == '&'){ 
                        // Possible ways when '&' condition are true:
                        if(isTrue == true){
                            ways += (leftTrue * rightTrue);
                        }
                        // Possible ways when '&' condition are false:
                        else{
                            ways += (leftTrue * rightFalse) + (leftFalse * rightTrue) + (leftFalse * rightFalse);
                        }
                    }


                    -------------------------------------
                        NOTE: You might be wondering how do why i am doing  ->  "ways = (Ways1 * ways2)"

                            Since we are looking the total number of ways: in which we can makes our expression 'true'

                                    { left part }  * { right part}
                                        /                   \
                                       x                     y           -> let say the left yeld 'x' & right yeld 'y'
                                
                                    x : imagine this is x number of ways
                                    y : imagine this is y number of ways

                                So, total number of ways: 
                                    Total ways = x * y
                    -------------------------------------
                        
                    // When partition performed at '|'
                    else if(s[k] == '|'){ 
                        // Possible ways when '|' condition are true:
                        if(isTrue == true){
                            ways += (leftTrue * rightTrue) + (leftTrue * rightFalse) + (leftFalse * rightTrue);
                        }
                        // Possible ways when '|' condition are false:
                        else{
                            ways += (leftFalse * rightFalse);
                        }
                    }


                    // When partition performed at '^'
                    else if(s[k] == '^'){ 
                        // Possible ways when '^' condition are true:
                        if(isTrue == true){
                            ways += (leftTrue * rightFalse) + (leftFalse * rightTrue);
                        }
                        // Possible ways when '^' condition are false:
                        else{
                            ways += (leftTrue * rightTrue) + (leftFalse * rightFalse);
                        }
                    }

        // At the end we will return the ways after the 'k' partition loop.


// TC For recursive Solution:
    * TC: O(4^n) -> We are taking 4 decisions calls for ever n...
    * AS: O(n) -> the recursion call stack go upto n.


// Problem With the Above Recursive Solution: 
    * Problem Occurred when we have overlapping subproblems.
    * Solution to that we can store the result of that in some sort of table, & whenever it's needed we will return that...


// Intrusion: 
    * We can fix this issue by using memoization table which will store the solution of subproblems..
    * Create memo table for (variable or Changing) values in recursive solution: 
        * Changing values are: 
            i , j , isTrue
        * Take a size expectations: 
            i goes max till n -> take n+1
            j goes max till n => take n+1
            isTrue has fixed 2 values T/T => size = 2

    * Create 3D table: 
        int t[n][n][bool]   -> this will sore the result of every subproblems..

    * Initialize it by -1 default value

    * In boolExp() function:
        * Apply check after the base condition that, if the subproblem exist, return directly without going into the recursive calls..
        * Wherever we were returning the result, apply "t[i][j][isTrue]", it will store the answer before returning the result.

    * Simple & easy...



// Complexity For Memoization Solution:
    * TC: O(n^3)
            => O(n^3) -> to recursive calls which fills, all the answer of subproblems..
            => O(n * n * 2) => Sums up n^3


// Note: 
    * I have used % mod everywhere, because i want to round the value, so that it can be accepted everywhere...

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long
#define mod 1003        // NOTE: mod constrains has changes, because in GFG, they have accepted the solution for  (% 1003), not 10e9+7

// Memoization Solution: 
// Function to Count the number of ways we can parenthesize the expression so that value of expression is True:
int boolExp(string &s, int i, int j, bool isTrue, vector<vector<vector<ll> > > &t){
    // base case: 
    if(i > j) return 0;         // no ways to form true, for empty string
    
    // When we have single element: -> Either it can be True/False
    if(i == j){
        // For flag = True condition 
        if(isTrue){
            // if string has true -> return true : else return false
            if(s[i] == 'T') return 1;
            else return 0;
        }
        // For flag = False condition
        else{
            // if string has false, -> return true : else return false
            if(s[i] == 'F') return 1;   // -> we are returning true, because when we want "False" & (s[i] == 'F') string has False, means we want false, & string has false, so return true ;)
            else return 0;
        }
    }

    // Checking In memo table, Before going into recursive calls, whether result of subproblem exist of not?
    if(t[i][j][isTrue] != -1) return t[i][j][isTrue];
    
    // K Partitions: 
    ll ways = 0;
    
    // Iterations start from (i+1), & goes till (j-1), and incremented by 2, so that pointers is on operators only.. (*_-)!
    for(int k=i+1;k<=j-1;k=k+2){

        // Possible Value For left & right:
        // Left:  -> Left can be true or False, so we need to check for both the condition... 
        ll lT = boolExp(s, i, k-1, 1, t);
        ll lF = boolExp(s, i, k-1, 0, t);
        
        
        // right: -> right can be true or False, so we need to check for both the condition... 
        ll rT = boolExp(s, k+1, j, 1, t);
        ll rF = boolExp(s, k+1, j, 0, t);
        

        // Checking Possible Operators Condition: &, |, ^

        // '&' AND condition:
        if(s[k] == '&'){
            // Case for True:
            if(isTrue){
                ways = (ways + (lT * rT) % mod ) % mod;
            }
            // Case for False:
            else{
                ways = (ways + (lT * rF) % mod + (lF * rT) % mod + (lF * rF) % mod) % mod;
            }
        }
        // '|' OR condition:
        else if(s[k] == '|'){
            // Case for True:
            if(isTrue){
                ways = (ways + (lT * rT) % mod + (lT * rF) % mod + (lF * rT) % mod ) % mod;
            }
            // Case for False:
            else{
                ways = (ways + (lF * rF) % mod ) % mod;
            }
        }
        // '^' XOR Condition:
        else{
            // Case for True:
            if(isTrue){
                ways = (ways + (lT * rF) % mod + (lF * rT) % mod ) % mod;
            }
            // Case for False:
            else{
                ways = (ways + (lT * rT) % mod + (lF * rF) % mod ) % mod;
            }
        }
    }
    
    return t[i][j][isTrue] = ways;    // Store the values, then return the number of ways we can get True from the given expression..
}

void solve(){
    string s;
    cin >> s;
    int n = s.size();

    // Creating 3D memo table: with filling "-1" default values.
    vector<vector<vector<ll> > > t(n+1, vector<vector<ll> > (n+1, vector<ll> (2, -1))); 

    // We are passing (i = 0) starting index & (j = n-1) end index, and (isTrue = 1) because we are checking for true condition, (Extra: if we want to check for false condition, we can put 0, but question is saying for TUURRU)
    cout << boolExp(s, 0, n-1, 1, t) << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}