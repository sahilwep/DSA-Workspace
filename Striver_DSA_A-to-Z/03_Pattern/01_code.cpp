
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
    
    // pattern 2_1

    *
    * *
    *   *
    *     *
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
    
    // pattern 5_1

    * * * * *
    *     *
    *   *
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
    
    // pattern 7_1

                * 
              *   * 
            *       * 
          *           *  
        * * * * * * * * *

    
    // pattern 8

        * * * * * * * * *         
          * * * * * * *     
            * * * * *              
              * * *         
                *
    
    // pattern 9

                * 
              * * * 
            * * * * * 
          * * * * * * *  
        * * * * * * * * *
        * * * * * * * * *         
          * * * * * * *     
            * * * * *              
              * * *         
                *
    
    // pattern 10

    *
    * *
    * * * 
    * * * *
    * * * * *
    * * * * 
    * * * 
    * * 
    * 
    
    // pattern 11

    1
    0 1
    1 0 1 
    0 1 0 1 
    1 0 1 0 1 

    // pattern_12

    1                 1
    1 2             2 1
    1 2 3         3 2 1
    1 2 3 4     4 3 2 1
    1 2 3 4 5 5 4 3 2 1 

    // pattern 13

    1
    2 3
    4 5 6
    7 8 9 10
    11 12 13 14 15

    // pattern : 14

    A 
    A B 
    A B C 
    A B C D 
    A B C D E 
    
    // pattern 14_1

    A 
    B C 
    D E F 
    G H I J 
    K L M N O 
    
    // pattern 15 

    A B C D E 
    A B C D 
    A B C 
    A B 
    A 
    
    // pattern 15_1

    A B C D E
    F G H I
    J K L 
    M N 
    O
    
    // pattern 16

    A         
    B B       
    C C C     
    D D D D   
    E E E E E

    // pattern 17

                A
              A B A
            A B C B A
          A B C D C B A
        A B C D E D C B A


    // pattern 18

    E 
    D E 
    C D E 
    B C D E 
    A B C D E

    // pattern 19 

    * * * * * * * * * *
    * * * *     * * * *
    * * *         * * *
    * *             * *
    *                 *
    *                 *
    * *             * *
    * * *         * * *
    * * * *     * * * *
    * * * * * * * * * *

    // pattern 20

    *                 *
    * *             * *
    * * *         * * *
    * * * *     * * * *
    * * * * * * * * * * 
    * * * *     * * * *
    * * *         * * *
    * *             * *
    *                 *
    
    // pattern 21

    * * * * *
    *       *
    *       *
    *       *
    * * * * *
    
    // pattern 22

    5 5 5 5 5 5 5 5 5 
    5 4 4 4 4 4 4 4 5 
    5 4 3 3 3 3 3 4 5 
    5 4 3 2 2 2 3 4 5 
    5 4 3 2 1 2 3 4 5 
    5 4 3 2 2 2 3 4 5 
    5 4 3 3 3 3 3 4 5 
    5 4 4 4 4 4 4 4 5 
    5 5 5 5 5 5 5 5 5


*/


#include <bits/stdc++.h>
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

void pattern_2_1(int n){
    for(int i = 1 ; i<=n; i++){
        for(int j = 1; j<=i; j++){
            if( i==n || j==1|| j==i){
                cout << "* ";
            }
            else{
                cout << "  ";
            }
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

void pattern_5_1(int n){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n-i+1; j++){
            if(i==1|| j==n-i+1|| j==1){
                cout << "* ";
            }
            else cout << "  ";
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
                    *             for i = 1    =>      1(stars)      
                  * * *           for i = 2    =>      3(stars)
                * * * * *         for i = 3    =>      5(stars)       
              * * * * * * *       for i = 4    =>      7(stars)
            * * * * * * * * *     for i = 5    =>      9(stars)
 
                                   formula for space :  (n-i)
                                   for i = 1    =>    4(spaces)
                                   for i = 2    =>    3(spaces)
                                   for i = 3    =>    2(spaces)
                                   for i = 4    =>    1(spaces)
                                   for i = 5    =>    0(spaces)
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

void pattern_7_1(int n){
    for(int i=1; i<=n; i++){
        // spaces
        for(int j=1; j<=n-i; j++){
            cout << "  ";
        }
        // stars
        for(int j=1; j<=2*i-1; j++){
            if(i==n || j==1 || j==2*i-1){
                cout << "* ";
            }
            else cout << "  ";
        }
        // spaces
        for(int j=1; j<=n-i; j++){
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
            * * * * * * * * *   for i = 1    =>      9(stars)      
              * * * * * * *     for i = 2    =>      7(stars)
                * * * * *       for i = 3    =>      5(stars)       
                  * * *         for i = 4    =>      3(stars)
                    *           for i = 5    =>      1(stars)
 
                                   formula for space :  (i-1)
                                   for i = 1    =>    0(spaces)
                                   for i = 2    =>    1(spaces)
                                   for i = 3    =>    2(spaces)
                                   for i = 4    =>    3(spaces)
                                   for i = 5    =>    4(spaces)      
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

void pattern_9(int n){
/*
    // for this pattern combine pattern_(7 & 8)

                * 
              * * * 
            * * * * * 
          * * * * * * *  
        * * * * * * * * *   
        * * * * * * * * *      
          * * * * * * *    
            * * * * *                  
              * * *        
                *          
*/

    for(int i = 1 ; i<=n; i++){
        for(int j = 1; j <= n-i; j++){
            cout << "  ";
        }
        for(int j = 1; j<=2*i-1; j++){
            cout << "* ";
        }
        for(int j = 1; j <= n-i; j++){
            cout << "  ";
        }
        cout << endl;
    }
    for(int i=1; i <= n;i++){
        for(int j=1;j <= i-1 ;j++){
            cout << "  ";
        }
        for(int j =1; j<= 2*n-(2*i-1);j++){
            cout << "* ";
        }
        for(int j=1;j <= i-1 ;j++){
            cout << "  ";
        }
        cout << endl;
    }
}

void pattern_10(int n){
/*                         
            Concept : 
                        passed value of n : 5 

                            i starts from 1 till (2*-1)
                                        Start : 
    *                   `i = 1   ->         1
    * *`                 i = 2   ->         2                    
    * * *                i = 3   ->         3
    * * * *              i = 4   ->         4
    * * * * *            i = 5   ->         5   til n it's i, after the value of n, decrement happened.
    * * * *              i = 6   ->         4   from this we can use (2*n - i ) >> which fulfill our condition. => 2*5 - 6 = 4
    * * *                i = 7   ->         3                         2*5 - 7 = 3
    * *                  i = 8   ->         2                         2*5 - 8 = 2
    *                    i = 9   ->         1                         2*5 - 9 = 1
                                                Solution : we can use conditions (i<=n) for printing stars till n, & after when i > n -> it prints decrement value by (2*n-i) formula.
*/      


    for(int i = 1; i <= 2*n - 1;i++){
        if(i <= n){
            for(int j = 1; j <= i; j++){
                cout << "* ";
            }
            cout << endl;
        }
        else{
            for(int j = 1 ; j <= 2*n-i; j++){
                cout << "* ";
            }
            cout << endl;
        }
    }


}

void pattern_11(int n){
/* 
            basics but number are flip when it print 1 & it prints only 1 or 0 
                                                         starts with : 
    1                         i = 1(odd)          =>          odd  
    0 1                       i = 2(even)         =>          even
    1 0 1                     i = 3(odd)          =>          odd
    0 1 0 1                   i = 4(even)         =>          even
    1 0 1 0 1                 i = 5(odd)          =>          odd

        solution : we will use nested loop.
                        *  when our loop start with even no : we use for loop to print the rows in flip manner by simply using the condition of odd & even, like when our nested loop start with even no : we print "true" i.e 1, & else "false" which is 0
                        * when our loop start with even no : we use for loop to print the rows in flip manner by simply using the condition of odd & even, like when our nested loop start with odd no : we print "true", else we print "false".
                     
*/
    int val = 1;
    for(int i = 1; i<=n; i++){
        if(i % 2 == 0){
            for(int j = 1; j<=i;j++){
                (j % 2 == 0) ? cout << true << " " : cout << false << " ";
            }
        }
        else{
            for(int j = 1; j <=i;j++){
                (j % 2 != 0) ? cout << true << " " : cout << false << " ";
            }
            
        }
        cout << endl;
    }
}

void pattern_12(int n){

/*
            This pattern is simillar to pattern 8, the difference is we have to print the numbers instead of spaces, & spaces in place of stars.
            
            * for first part, it's simple : we can use nested loop,with outer loop i & inner loop j : with printing the "j" value in inner loop loop & using condition (j<=i)
            * for space : 
                                                        for spaces : (2*n- 2*i)
    1                 1         i = 1       =>          8(spaces)  -> 10-2 = 8
    1 2             2 1         i = 2       =>          6(spaces)  -> 10-4 = 6
    1 2 3         3 2 1         i = 3       =>          4(spaces)  -> 10-6 = 4
    1 2 3 4     4 3 2 1         i = 4       =>          2(spaces)  -> 10-8 = 2
    1 2 3 4 5 5 4 3 2 1         i = 5       =>          0(spaces)  -> 10-10 = 0
            * note for better understanding print # instead of spaces.

            * for 3rd part : numbers start backward : pattern_6_2 explain well but it just inverted, but here is explained solution : 

                                                  -> start with value of outer loop ie. "i" say : and goes till 1
                                                  -> we can iterate loop fro i till 1, i.e : (j = i ; j>=1;j--)
                                1    i = 1    =>
                              2 1    i = 2    =>    
                            3 2 1    i = 3    => 
                          4 3 2 1    i = 4    => 
                        5 4 3 2 1    i = 5    => 

    * note for better understanding print # instead of spaces.
*/

    for(int i = 1; i<=n ;i++){
        // numbers 
        for(int j = 1; j<=i ;j++){
            cout << j << " ";
        }
        // spaces 
        for(int j = 1; j<=(2*n-2*i); j++){
            cout << "  ";
        }
        // numbers 
        for(int j = i; j>=1; j--){
            cout << j << " ";
        }
        cout << endl;
    }
}

void pattern_13(int n){
    // this is simple : we need to create a variable that store value 1 & then perform increment with every iteration. 
    int num = 1;
    for(int i = 1; i<=n ;i++){
        for(int j = 1; j<=i; j++){
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}

void pattern_14(int n){
    // same we need to use character ie. : A, and increment it with every iteration in inner loop, in ASCI the value of A is : 65
    char ch = 'A';
    // cout << int(ch);   // this will print the ASCII value of A.
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i; j++){
            cout << ch << " ";
            ch++;
        }
        ch = 'A';
        cout << endl;
    }
}

void pattern_14_1(int n){
    // same we need to use character ie. : A, and increment it with every iteration in inner loop & outer loop , in ASCI the value of A is : 65
    char ch = 'A';
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i; j++){
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }
}

void pattern_15(int n){
    char ch = 'A';
    for(int i = 0; i<=n; i++){
        for(int j = 1; j<=n-i; j++){
            cout << ch << " ";
            ch++;
        }
        ch = 'A';
        cout << endl;
    }
}

void pattern_15_1(int n){
    char ch = 'A';
    for(int i = 0; i<=n; i++){
        for(int j = 1; j<=n-i;j++){
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }
}

void pattern_16(int n){
    char ch = 'A';
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i; j++){
            cout << ch << " ";
        }
        ch++;
        cout << endl;
    }
}

void pattern_17(int n){

/*
        Concept : 

                it is same as pattern 7, but instead of * it print Char, but after painting the character, it's decrement the character after a certain


            A                   i = 1    =>           
          A B A                 i = 2    =>         here i = 2, so char is decrementing 
        A B C B A               i = 3    =>         here i = 3, so after printing 3 char, it decrementing...
      A B C D C B A             i = 4    =>          
    A B C D E D C B A           i = 5    =>          
                                        so, we can use (j<i) cout << ch ,else cout << --;

                Notice : at the value of i, it will decrement, So we use some condition for printing the pattern.
*/
    char ch = 'A';
    for(int i = 1; i<=n; i++){
        // spaces 
        for(int j = 1; j<=n-i;j++){
            cout << "  ";
        }        
        // char
        for(int j = 1; j<=2*i-1; j++){
            // here we use (j<i), because if we use (j<=i), then the else will start printing value with 1 increment to it, because we use ch++ which will increment the value after the condition end i.e (j<=i).
            // So, if we use (j<i), this will satisfied the condition for ch++.
            if(j<i){
                cout << ch << " ";
                ch++;
            }
            else{
                cout << ch << " ";
                ch--;
            }
        }
        // spaces
        for(int j = 1; j<=n-i;j++){
            cout << "  ";
        }   
        ch = 'A';     
        cout << endl;
    }
}

void pattern_18(int n){
    char ch = 'A';
    ch = ch + n-1;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=i; j++){
            cout << ch << " ";
            ch++;
        }
        ch = 'A';
        ch = ch + n-1 - i; // this will decrement the value of ch, after every outer loop of iteration. 
        cout << endl;
    }
}

void pattern_19(int n){
/*  
        Concept : we can use pattern 9, and instead of stars we print space, and instead of spaces we print stars.

        // bruteforce solution : using tow different outer loop and then combine them. 
                * For first half : 
                    * till i <= 5, we can use patten that we use before

                * For Second half : 
                    * we can print the another loop for second half start from i = 1 till 5                             
    * * * * * * * * * *    i = 1                 
    * * * *     * * * *    i = 2
    * * *         * * *    i = 3
    * *             * *    i = 4
    *                 *    i = 5
    *                 *    i = 1   because, if split into 2nd half   i = 1 => 8      (2*n - 2*i) : 10 - 2  => 8
    * *             * *    i = 2   because, if split into 2nd half   i = 2 => 6                    10 - 4  => 6
    * * *         * * *    i = 3   because, if split into 2nd half   i = 3 => 4                    10 - 6  => 4 
    * * * *     * * * *    i = 4   because, if split into 2nd half   i = 4 => 2                    10 - 8  => 2
    * * * * * * * * * *    i = 5   because, if split into 2nd half   i = 5 => 0                    10 - 10 => 0

                * combining them together, and we will get the pattern.

        // Advance Solution : we don't use two half to print, instead in one single outer loop we print the whole pattern. 

    * * * * * * * * * *    i = 1            for i = 1      =>      0(spaces)  using this formula : (2*i-2) : 2-2 = 0                 
    * * * *     * * * *    i = 2            for i = 2     =>       2(spaces)                        4-2 = 2
    * * *         * * *    i = 3            for i = 3     =>       4(spaces)                        6-2 = 4
    * *             * *    i = 4            for i = 4     =>       6(spaces)                        8-2 = 6
    *                 *    i = 5------------for i = 5-----=>-------8(spaces)------------------- 
    *                 *    i = 6            for i = 6     =>       8(spaces)         
    * *             * *    i = 7            for i = 7     =>       6(spaces)          
    * * *         * * *    i = 8            for i = 8     =>       4(spaces)                      
    * * * *     * * * *    i = 9            for i = 9     =>       2(spaces)                    
    * * * * * * * * * *    i = 10           for i = 10    =>       0(spaces)       
            
            let say : count = (2*n-i)
    for i  = 6    :  8(spaces) (2*n-i+4) equivalent to (2*n-i+count) equivalent to (2*n-i+(2*n-i))  :  10-6+(10-6)   = 8   
    for i  = 7    :  6(spaces) (2*n-i+3) equivalent to (2*n-i+count) equivalent to (2*n-i+(2*n-i))  :  10-7+(10-7)   = 6 
    for i  = 8    :  4(spaces) (2*n-i+2) equivalent to (2*n-i+count) equivalent to (2*n-i+(2*n-i))  :  10-8+(10-8)   = 4 
    for i  = 9    :  2(spaces) (2*n-i+1) equivalent to (2*n-i+count) equivalent to (2*n-i+(2*n-i))  :  10-9+(10-9)   = 2 
    for i  = 10   :  0(spaces) (2*n-i+0) equivalent to (2*n-i+count) equivalent to (2*n-i+(2*n-i))  :  10-10+(10-10) = 0 

                so, we can say : (2*n-i+(2*n-i)) is formula for this half space pattern.
    
                        // for better understanding use # instead of spaces.
*/

    // Advance Solution : Using single outer loop to print all the pattern.
    for(int i = 1; i<=2*n; i++){
        // stars :
        if(i<=n){
            for(int j = 1; j<=n-i+1;j++){
                cout << "* ";
            }
        }
        else{
            // this condition is simple : our star is increment after n, so (i-n)
            for(int j = 1; j<=i-n;j++){
                cout << "* ";
            }
        }
        // spaces :
        // the upper half spaces are simple, we can refer pervious patterns.
        if(i<=n){
            for(int j = 1; j<=(2*i-2); j++){
                cout << "  ";
            }
        }
        // for half spaces
        else{
            for(int j = 1; j<=(2*n-i+(2*n-i)); j++){
                cout << "  ";
            }
        }

        stars :
        if(i<=n){
            for(int j = 1; j<=n-i+1;j++){
                cout << "* ";
            }
        }
        else{
            // this condition is simple : our star is increment after n, so (i-n)
            for(int j = 1; j<=i-n;j++){
                cout << "* ";
            }
        }
        cout << endl;
    }

/*
    // Bruteforce Solution : works fine.
    // first half
    for(int i = 1; i<=n; i++){        
        // stars
        for(int j = 1; j<=n-i+1;j++){
            cout << "* ";
        }
        // spaces
        for(int j = 1; j<=(2*i-1-1); j++){
            cout << "  ";
        }
        // stars
        for(int j = 1; j<=n-i+1;j++){
            cout << "* ";
        }
        cout << endl;
    }
    //  Second half
    for(int i = 1; i<=n; i++){
        // stars
        for(int j  = 1; j<=i;j++){
            cout << "* ";
        }
        // spaces
        for(int j = 1; j<=(2*n-2*i); j++){
            cout << "  ";
        }
        // stars
        for(int j  = 1; j<=i;j++){
            cout << "* ";
        }
        cout << endl;
    }
*/
}

void pattern_20(int n){
/*
    *                 *
    * *             * *
    * * *         * * *
    * * * *     * * * *
    * * * * * * * * * * 
    * * * *     * * * *        
    * * *         * * *
    * *             * *
    *                 *
                    // Bruteforce Solution :
                        * we can use 2 pattern 8 & 7, and replacing their stars with spaces & print then by combining them.

                    // Optimal Solution : 
                                    For First space : 
                                                Starts from i = 1 till 5 :    so formula we get is : (2*n-2*i) 
                                                    for i = 1       =>  8(spaces)       10-2=8
                                                    for i = 2       =>  6(spaces)       10-4=6
                                                    for i = 3       =>  4(spaces)       10-6=4
                                                    for i = 4       =>  2(spaces)       10-8=2
                                                    for i = 5       =>  0(spaces)       10-10=0

                                    For Second Space : 
                                                Starts from when i > 5 :      so formula we get is : (2*i-2*n)
                                                    for i = 6        =>  2(spaces)       12-10=2     
                                                    for i = 7        =>  4(spaces)       14-10=4
                                                    for i = 8        =>  6(spaces)       16-10=6
                                                    for i = 9        =>  8(spaces)       18-10=8
   This case not print, because iteration is till 9 for i = 10       =>  0(spaces)       

                    * NOTE : use # & @ instead of spaces for better understanding. 

*/
    for(int i = 1; i <= 2*n-1;i++){
        // first star
        if(i<=n){
            for(int j = 1; j<=i;j++){
                cout << "* ";
            }
        }
        else{
            for(int j = 1; j<=2*n-i;j++){
                cout << "* ";
            }
        }
        // first space
        for(int j = 1; j <= (2*n-2*i); j++){
            cout << "  ";
        }
        // second space
        if(i>n){            // condition when  i > n this loop will execute.
            for(int j = 1; j<=(2*i-2*n); j++){
                cout << "  ";
            }
        }
        // second star
        if(i<=n){
            for(int j = 1; j<=i;j++){
                cout << "* ";
            }
        }
        else{
            for(int j = 1; j<=2*n-i;j++){
                cout << "* ";
            }
        }
        cout << endl;
    }
}

void pattern_21(int n){

/*
    * * * * *
    *       *
    *       *
    *       *
    * * * * *
               Solution : 
                * it is simple like this :
                                          i       i 
                                          1       n
                                    j-> 1 * * * * * 
                                          * * * * * 
                                          * * * * * 
                                          * * * * * 
                                    n-> n  * * * * * 
                * so we check if (i==1|| i==n || j==1 || j==n) {print *} else print{ space }
    NOTE : For better understanding use # instead of spaces.
*/
    for(int i = 1; i<=n;i++){
        for(int j = 1; j<=n; j++){
            if(i==1 || i==n || j==1 || j==n){
                cout << "* ";
            }
            else{
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void pattern_22(int n){
/*
    for N = 5

    5 5 5 5 5 5 5 5 5 
    5 4 4 4 4 4 4 4 5 
    5 4 3 3 3 3 3 4 5 
    5 4 3 2 2 2 3 4 5 
    5 4 3 2 1 2 3 4 5 
    5 4 3 2 2 2 3 4 5 
    5 4 3 3 3 3 3 4 5 
    5 4 4 4 4 4 4 4 5 
    5 5 5 5 5 5 5 5 5

        Solution : For better understanding let's subtract each value of the pattern FROM N
            * Observation : 

                0   0   0   0   0   0   0   0   0 
                0   1   1   1  {1}  1   1   1   0 
                0   1   2   2   2   2   2   1   0 
                0   1   2   3   3   3   2   1   0 
                0   1   2   3   4   3   2   1   0 
                0   1   2   3   3   3   2   1   0 
                0   1   2   2   2   2   2   1   0 
                0   1   1   1   1   1   1   1   0 
                0   0   0   0   0   0   0   0   0 

            * for any value we see like for example : 1, 
                * it has distance of current cell of each the square is : (min(1,4,4,7)), i.e min(min(top,bottom), min(left,right))
                            * top = i 
                            * left = j 
                            * right = (2*n-2)-j
                            * bottom = (2*n-2)-i
                            
            * taking min(min(top,bottom), min(left,right)) & subtracting them into N we will get the pattern.
*/

    for(int i = 0; i<2*n-1;i++){
        for(int j = 0; j<2*n-1;j++){
            int top = i;
            int left = j;
            int right =  (2*n-2)-j;
            int bottom = (2*n-2)-i;

            cout << (n - min(min(top,bottom), min(left,right))) << " ";
            
        }

        cout << endl;
    }
}



int main(void){ 

    int n = 5;   //the input value of loop
    int times = 1;  // no of times we want to print the loop
    for(int i = 1; i<=times; i++){   
        pattern_1(n);
        cout << endl;
        pattern_2(n);
        cout << endl;
        pattern_2_1(n);
        cout << endl;
        pattern_3(n);
        cout << endl;
        pattern_4(n);
        cout << endl;
        pattern_5(n);
        cout << endl;
        pattern_5_1(n);
        cout << endl;
        pattern_6(n);
        cout << endl;
        pattern_6_1(n);
        cout << endl;
        pattern_6_2(n);
        cout << endl;
        pattern_6_3(n);
        cout << endl;
        pattern_7(n);
        cout << endl;
        pattern_7_1(n);
        cout << endl;
        pattern_8(n);
        cout << endl;
        pattern_9(n);
        cout << endl;
        pattern_10(n);
        cout << endl;
        pattern_11(n);
        cout << endl;
        pattern_11(n);
        cout << endl;
        pattern_12(n);
        cout << endl;
        pattern_13(n);
        cout << endl;
        pattern_14(n);
        cout << endl;
        pattern_14_1(n);
        cout << endl;
        pattern_15(n);
        cout << endl;
        pattern_15_1(n);
        cout << endl;
        pattern_16(n);
        cout << endl;
        pattern_17(n);
        cout << endl;
        pattern_18(n);
        cout << endl;
        pattern_19(n);
        cout << endl;
        pattern_20(n);
        cout << endl;
        pattern_21(n);
        cout << endl;
        pattern_22(n);
        cout << endl;
    }

    return 0;
}