/*

// Matrix Chain Multiplication Recursive 


// Problem Statement:
    * we are given an array that contain dimension of multiple matrix & we need to find the multiplication of it..
            arr[] = {40, 20, 30, 10, 30}
            
        * We are given dimension of some matrix: 

            A1      A2      A3      A4  ...         -> matrix
            2x5     20x20   30x10   ....            -> Dimensions

        * We need to multiply these matrix, & during multiplications the cost should be minimum..
        * Cost = Number of multiplications, should be minimum
        * Matrix Multiplications rules:
            * If one matrix is of dimension AxB, and other is of CxD
            * Then it can only be able to multiplied if (B == C), & new matrix will from with dimension AxD
        * Example: Given matrix
                    [  ]            [  ]
                        2x3             3x6

                    Cost should be minimum

                    matrix dimension: 2 * 3  * 3 * 6
                    new dimension:    2 *   3    * 6    = 36 Cost

                    Cost = number of multiplications -> here number of multiplications is 3.
        
        * In This question, we are given some matrix: A1, A2, A3, A4..
        * And dimension is stored in array...
        * We need to multiplications..
        * So, the possible ways to multiply is: 
                    
                    A1 A2 A3 A4
                                         
                                                            Cost of multiplication
                    ( ( A1 * A2 ) * ( A3 * A4 ) )       ->  C1
                    (A1 (A2 ( A3 * A4 ) ) )             ->  C2
                    (A1 ( A2 * A3 ) A4)                 ->  C3
                    ....                                ->  ...
                                                        -------------
                                                            Cx
                                                    We have to select that cost, which is minimum..
                                                
                     
        * Now, coming back to the Question: 
                arr[] = {40, 20, 30, 10, 30}

                * We have given 5 Matrix, (whatever the size of array, we will always have one less matrix (n-1) matrix)
                * Dimension are given in this array:

                * Matrix: 

                                        {40, 20, 30, 10, 30}
                                         0    1   2   3   4

                        A1 = 40x20 -> A1 = arr[0] * arr[1]
                        A2 = 20x30 -> A2 = arr[1] * arr[2]
                        A3 = 30x10 -> A3 = arr[2] * arr[3]
                        A4 = 10x30 -> A4 = arr[3] * arr[4]
                        ....    
                    -------------------------------------------

                                      A(i) = arr[i-1] * arr[i]

                * From this we have concluded an equations, which is matrix A(i) = arr[i-1] * arr[i]
                * Formula to find dimension of matrix:  {  A(i) = arr[i-1] * arr[i]  }

        * MCM Identification: 
            * For this particular we don't know, where to put brackets in order to multiply the matrix so that we can get minimum cost.
            * So, for this question we will use MCM, because we will break our array range (i----j) to every index with k...
            * & that's how we will try to calculate the minimum cost..
            * Example:
                * we will break our array: 
                         (A1) (A2 A3 A4) 
                           |        |
                        min_cost  min_cost
                    -------------------------
                    * we will calculate the minimum cost from both of them, & Then we will multiply both of them & find the temporary answer...
                    * after breaking all possible k, we will have multiple temporary answer, & from them we will select the minimum..
            * So, identification is we will have to apply brackets at every position, & recursively solve this & find the minimum cost.

        * Coming back to the format of MCM:
            * First step of the MCM Format: break an array/string into valid (i & j)

                            |-------------------|
                (left end)i                   j(right end)    -> not necessary always the pointer is at end..


                * So, if we break our array with (i & j) at end, is this valid:
                    
                    index:   0  1  2  3  4
                            [40|20|30|10|30]
                            |           |
                            i           j


                            * Problem is that if we create a matrix: Ai = arr[i-1] * arr[i]


                            so, Ai  = arr[i-1] * arr[i]
                                A1 = arr[-1] * arr[0] -> Invalid case, because there is no -1 index.
                            
                            Solution: we need to take i from 1, so that we can get arr[i-1] = arr[0] index

                * So, we need to place pointer 'i' at index 1
                * Now let's check for 'j' also, 
                    arr[j] = arr[j-1] * arr[j] -> valid pointer, there is not case of, pointer pointing at invalid index.
                
                * So, i & j placed at:

                                        -|-------------|-
                                        i(1)          j(n-1)
                    

                            final range (i, j) = (1, (n-1))

                * We will have to return cost, which is integer, so return type is 'int', & parameter will be (arr, size, i, j)
                * in main function we will have to pass (i, j) with value (1, (n-1))

            * Next Step is to find right base condition:
                    * From the format:   
                        if(i > j)  return 0

                            (i > j => size = 0)

                    * But if (i == j) -> is this valid, let's check:

                        |----------|----------|
                                ij
                            
                            (i == j => size = 1)

                        When we have both i & j at same index, it's means we are at one element of an array, but according to the question, matrix dimension is given (arr[i-1]*arr[i]) -> means it's required 2 index
                        So, single index is not valid to from a matrix..

                        So, we can say, (size = 0 & 1) both invalid.

                    * Fixed base case: 
                        if(i >= j) return 0
                    

            * Next step is to move 'k' from 'i' to 'j'
                * From the format: 
                    for(int k=i;k<j;k++){
                        ....
                    }   
                * Let's check this:

                       [40 | 20 | 30 | 10 | 30]
                             i               j
                             K                        -> if k is start at i
                

                    If we have taken k at index 'i'
                    We can break this, & solve: 
                        solve(i, k)         -> solve i to k
                        solve(k+1, j)       -> solve k+1 to j
                

                * Now, if 'k' reaches at 'j' is this valid, let's check:

                       [40 | 20 | 30 | 10 | 30]
                             i               j
                                             K  

                    If k is at j, the breaking will be like this:

                            (i to k) -> this will contains all the matrix (40x20, 20x30, 30x10, 10x30)
                            (k+1 to j) -> this is invalid..

                        So, we can't move our k till j

                * If we have move 'k' till (j-1), this will give us atleast 1 matrix.

                       [40 | 20 | 30 | 10 | 30]
                             i               j
                                        K  

                            solve(i to k) -> (40x20, 20x30, 30x10)
                            solve(K+1 to j) -> (10x30)  -> this will give us atleast 1 matrix.
                
                * So, correct breaking of 'k' start & goes till:
                        (k = i & k <= j-1)

                * We can have other sequence also, if we have change the i & j indexes -> then k starting & ending pointer will be changed..
                    * Example: we can take any scheme...
                         start      end                 break
                         i = k      k = j-1     ->  i to k      &   k+1 to j
                         i = k+1    k = j       ->  i to k-1    &   k to j

                         But make sure to not mismatched..

                * Till now we can have: 

                        for(int k=i;k<=j-1;k++){
                            solve(i, k)
                            solve(k+1, j)
                        }

                    {|------------------}  |  {------------------------|}
                    i                      k                           j

                    solve(i to k)          +        solve(k+1, j)
                    minCost                         minCost

                    * From this we can find the cost of (AB) and (CD), but we need to find the cost fo (AB) * (CD) => which is the cost of whole, & store this answer into temp result..
                    * We can say Temp answer can be found as: 

                            solve(i to k) + (Cost to multiply both side) + solve(k+1, j)    =  temp_Answer
                                                      ^
                                                      |
                                        We need to find this cost

                    * Once, we find this cost, we can have our temp answer..          
                    * Let's find this cost with an Example: 

                            0   1    2    3    4        -> index   
                          [40 | 20 | 30 | 10 | 30]      -> array
                                i     |        j        -> i & j pointer
                                |     K     |           -> Let's say k is here..
                                |           |
                        /------             ------\
                    (i to k )                   (k+1 to j)
                
                40x20, 20x30                    30x10, 10x30        -> matrix in this ranges
                    |                               |
                40 * 20 * 30                     30 * 10 * 30       -> Multiplications of matrix
                    |                                  |    
                  40x30                             30x30           -> New Matrix Form
                      |                             |
                       \                           /    
                             40 * 30 * 30 * 30                      -> Multiplications of matrix = (AB) * (CD)
                                  -------                       
                               40 * 30 * 30                        -> These to terms combined   -> We can can found the cost from here
                                    |
                                  40x30                            -> New matrix will be form with dimension 40x30


                              40 * 30 * 30   -> Let's analyze these terms:
                            i-1  * k  * j   -> These terms are found at index
                        arr[i-1] * arr[k] * arr[j]

                * So, cost of multiply the whole after solved in recursive calls are: 
                        Extra cost = arr[i-1] * arr[k] * arr[j] -> This is the extra cost which is use to multiply both the cost..
            
                * So, we can say, the calls in loop happens like:

                    solve(i to k) + (arr[i-1] * arr[k] * arr[j]) + solve(k+1 to j)
                

            * Once we have computed all the cost, we will have to take minimum, so from the temp answer, we will choose minimum answer..


* TC : O(2^n)->  This solutions will give us TLE


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Recursive solution of MCM:
int mcm(int arr[], int i, int j){
    // base condition: 
    if(i >= j){ // we have used equal condition also, because we don't allow to single element to be compare.
        return 0;
    }
    int res = INT_MAX;  // we need minimum cost, so we are setting it with maximum value..
    // iteration start from (k = i to k <= j-1)
    for(int k=i;k<=j-1;k++){
        // break into two recursive calls: (i to k, k+1 to j):
        //  tempAnswer first_Cost       ExtraCost           SecondCost
        int tempAns = mcm(arr, i, k) + mcm(arr, k+1, j) + (arr[i-1] * arr[k] * arr[j]);
        // getting the minimum answer..
        if(tempAns < res){
            res = tempAns;
        }
    }

    return res; // return the result.
}

void solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    // MCM Calling: i = 1 & j = n-1 -> passed
    cout << mcm(arr, 1, n-1);


}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}