
/* 
    // pattern 1
    * * * * 
    * * * * 
    * * * * 
    * * * * 

    // pattern 2

    *
    * * 
    * * *
    * * * * 
    * * * * * 

    // pattern 3

    1
    1 2
    1 2 3 
    1 2 3 4
    1 2 3 4 5

    // pattern 4

    1
    2 2 
    3 3 3
    4 4 4 4
    5 5 5 5 5

    // pattern 5

    * * * * * 
    * * * * 
    * * * 
    * * 
    * 
    
    // pattern 6

    1 2 3 4 5
    1 2 3 4 
    1 2 3 
    1 2 
    1 
    
    // pattern 6.1

        1 2 3 4 5
          1 2 3 4 
            1 2 3 
              1 2 
                1 

    // pattern 6.2

        5 4 3 2 1
          4 3 2 1
            3 2 1
              2 1
                1

    // pattern 6.3

      5 4 3 2 1 
        5 4 3 2
          5 4 3
            5 4
              5

    
    // pattern 7

                * 
              * * * 
            * * * * * 
          * * * * * * *  
        * * * * * * * * *
    
    // pattern 8

        * * * * * * * * *         
          * * * * * * *     
            * * * * *              
              * * *         
                *
    
*/

#include <iostream>
using namespace std;    

void pattern_1(int n){
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern_2(int n){
    for(int i =0;i<n;i++){
        for(int j = 0;j<=i;j++){
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern_3(int n){
    for(int i =1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << j << " ";
        }
        cout << endl;
    }
}

void pattern_4(int n){
    for(int i =1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << i << " ";
        }
        cout << endl;
    }
}

void pattern_5(int n){
    for(int i =n ;i>=1;i--){
        for(int j = 1;j<=i;j++){
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern_6(int n){
    for(int i = n;i >= 1;i--){
        for(int j =1;j<=i;j++){
            cout << j << " ";
        }
        cout << endl;
    }
}

void pattern_6_1(int n){
    for(int i =0;i<n;i++){
        for(int j =1;j<=i;j++){
            cout << "  ";
        }
        // Here we start from "1" and go till "n-i"
        for(int j = 1; j<=n-i;j++){
            cout << j << " ";
        }
        cout << endl;

    }
}

void pattern_6_2(int n){
    for(int i = 1;i<=n;i++){
        for(int j = 1; j < i ;j++){
            cout << "  ";
        }
        // here we start from "n-i+1" & iterate the loop till "1"
        for(int j = n-i+1; j >=1;j--){
            cout << j << " ";
        }
        cout << endl ;
    }

}

void pattern_6_3(int n){
    for(int i = 1; i<=n;i++){
        for(int j = 1;j<i;j++){
            cout << "  ";
        }
        for(int j = n; j>=i;j--){
            cout << j << " " ;
        }
        cout << endl;
    }
}

void pattern_7(int n ){

/* 
    Concept : 
                               n = 5
                               formula for star : (2*i -1 ) 
                    *             for i = 1    =>      1      
                  * * *           for i = 2    =>      3
                * * * * *         for i = 3    =>      5       
              * * * * * * *       for i = 4    =>      7
            * * * * * * * * *     for i = 5    =>      9
 
                                   formula for space :  (n-i)
                                   for i = 1    =>    4
                                   for i = 2    =>    3
                                   for i = 3    =>    2
                                   for i = 4    =>    1
                                   for i = 5    =>    0
*/
    //  NOTE : In order to better understanding print "#" in a place of (" ") spaces.

    // i starts from "1" & goes till n
    for(int i = 1; i <= n ;i++){
        // formula for space : (n-i)
        for(int j = 1 ; j <= (n-i); j++){
            cout << "  ";
        }
        // formula for star : 2*i-1
        for(int j = 1; j<=(2*i-1) ;j++){
            cout << "* ";
        }
        // formula for space : (n-i)
        for(int j = 1 ; j <= (n-i); j++){
            cout << "  ";
        }
        cout << endl;
    }
}   

void pattern_8(int n){
/*
    Concept : 
                               n = 5
                               formula for star : (2*n - (2*i -1) ) 
            * * * * * * * * *   for i = 1    =>      9      
              * * * * * * *     for i = 2    =>      7
                * * * * *       for i = 3    =>      5       
                  * * *         for i = 4    =>      3
                    *           for i = 5    =>      1
 
                                   formula for space :  (i-1)
                                   for i = 1    =>    0
                                   for i = 2    =>    1
                                   for i = 3    =>    2
                                   for i = 4    =>    3
                                   for i = 5    =>    4      
*/

    for(int i = 1; i <=n ; i++){
        for(int j = 1; j <=i-1;j++){
            cout << "  ";
        }
        for(int j = 1; j <= 2*n- (2*i-1);j++){
            cout << "* ";
        }
        for(int j = 1; j <=i-1;j++){
            cout << "  ";
        }
        cout << endl;
    }
}


int main(void){ 

    int n = 5;   //the input value of loop
    int times = 1;  // no of times we want to print the loop
    for(int i =0;i<times;i++){   
        pattern_1(n);
        pattern_2(n);
        pattern_3(n);
        pattern_4(n);
        pattern_5(n);
        pattern_6(n);
        pattern_6_1(n);
        pattern_6_2(n);
        pattern_6_3(n);
        pattern_7(n);
        pattern_8(n);
    }

    return 0;
}