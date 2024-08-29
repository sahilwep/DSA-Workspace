/*
// GCD using Euclidean 
    Euclidean : (a,b) = (a-b,b), a>b

    eg : (15,10) = (5,10)

    * So, to finding the GCD using euclidean : 
        apply euclidean & make it smaller, again apply euclidean & make it smaller.. until one of the number is 0
        * We know that GCD of (0,n) is : n
        * because when one number is zero, remaining number is GCD.
    
    // Bruteforce approach :
        * we can iterate from min(a,b) to 1
        * then we can check for condition if (a%i==0 && b%i==0) : print the i & break
        * else if there is no GCD check in if condition, then 1 is the GCD

    // Optimal solution : 
        (a,b)
        * using the euclidean formula we can check fro the gcd by checking again & and making it smaller....
        * we are doing : euclidean (a-b,b) until until one of them is gets 0
        * so here eg : 
        * from here starting here to 
                              (20,5)   
                                  (15,5)   
                                      (10,5)
                                          (5,5)       
                                            (0,5) 
                                                here.
                * Instead of iterating this euclidean step we can use.
                * we can say that : (20,5) = (0,5) after iteration,
                    * which is equivalent to : ( 20%5 , 5) = (0, 5)
                    * So, we can do (%) modulo instead of iteration, which works same. 

                * Conclusion : 
                    * if one of them is 0 return other,
                    * else perform (b% a, b), where b>a
*/

#include<bits/stdc++.h>
using namespace std;

// function to check the GCD
int gcd(int a, int b){
    // base condition 
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}

//  TC : O(logɸmin(a,b)), Big-o log fi min(a,b)
//  SC : O(1)   // because there is unit step..d

int main(void){

    int x,y;
    cin >> x >> y;

    // checking for the bigger case.
    if(x>y){
        cout << gcd(x,y);
    }
    else {
        cout << gcd(y,x);
    }


    return 0;
}