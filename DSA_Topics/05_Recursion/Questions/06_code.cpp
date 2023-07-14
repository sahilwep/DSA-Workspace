// sum of first N numbers : 

/*
    * We can solve it with 2 ways : 
        * Parameterized
        * Functional
*/

#include<iostream>
using namespace std;

// Functional Way : using return & inside the return we are playing with the values.
int func(int n){
    if(n == 0){
        return 0;
    }
    return(n + func(n-1));
}

int main(void){
    int n;
    cin >> n;
    cout << func(n);
    
    return 0;
}
//  recursive tree : for Functional way.
//                                          n = 5, condition if(n==0)
//                                          func(n)
//                                          return(n+func(n-1))
// 
//    ||           Recursion                                        ||          Returning : when the base condition hit.
//    || func(5)                                                    ||                
//    ||    return(5 + func(4))                                     ||                  5+10 = 15        
//    ||        func(4)                                             ||  
//    ||            return(4 + func(3))                             ||                  4+6 = 10
//    ||                func(3)                                     ||  
//    ||                    return(3 + func(2))                     ||                  3+3 = 6
//    ||                        func(2)                             ||      
//    ||                            return(2 + func(1))             ||                  2+1 = 3
//    ||                                func(1)                     ||                  
//    ||                                    return(1 + func(0))     ||                  1+0 = 1 
//    ||                                        func(0)             ||   => at this condition(n=0), recursion stop. 


/*

// parameterized Way :
void func(int i, int sum){
    if(i<1){
        cout << sum;
        return;
    }
    func(i-1,sum+i);
}

int main(void){
    int n;
    cin >> n;
    func(n,0);

    return 0;
}

//       Recursive tree : for parameterized way 
//                        i = 5, sum = 0
//                        func(i-1, sum+i)
//        func(5,0)
//            func(4,5)
//                func(3,9)
//                    func(2,12)
//                        func(1,14)
//                            func(0,15), at this base condition hit, & it returns.

*/