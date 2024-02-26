// Factorial of number n

// TC : O(n)
// SC : O(n)

#include <bits/stdc++.h>
using namespace std;

// parameterized way :
void par(int n, int res){
    if(n==1){
        cout << res;
        return;
    }
    par( (n-1) , (res*n) );    
}

// functional way : 
int fun(int n){
    if(n == 1){
        return n;  // we can return (1 or n) returning the value : 0 will makes whole 0. 
    }
    return (n*fun(n-1));
}

int main(void){

    int n;
    cin >> n;
    // par(n,1);        // parameterized way. 
    cout << "Functional way : " << fun(n) << endl;         // functional way 

    return 0;
}

/*
    Observation : Functional way 
                                * n = 5, condition (n==1) return n; 
                func(n)
                    return(n*func(n-1))


    ||           Recursion                                        ||          Returning : when the base condition hit.
    || func(5)                                                    ||                
    ||    return(5 * func(4))                                     ||                  5*24 = 120        
    ||        func(4)                                             ||  
    ||            return(4 * func(3))                             ||                  4*6 = 24
    ||                func(3)                                     ||  
    ||                    return(3 * func(2))                     ||                  3*2 = 6
    ||                        func(2)                             ||      
    ||                            return(2 * func(1))             ||                  2*1 = 2
    ||                                func(1)                     ||   => at this condition(n=1), recursion stop.               
    ||                                                            ||                  



*/