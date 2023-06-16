// Pattern Print
/*
        row   col---->
         |    *  
         |    *  *  
         \/   *  *  *  
              *  *  *  *

    for every row no of column is same.
    in row 1, there is only 1 col.
    in row 2, there is only 2 col.
    in row 3, there is only 3 col.
*/
// pattern Questions.

#include <iostream>
using namespace std;

/*
    *
    *  *
    *  *  *
    *  *  *  *
*/

void pattern_1(){
    for(int row = 1; row <= 4 ; row++){
        for(int col = 1; col <= row ; col++){
            cout << "*" << "  ";
        }
        cout << endl ;
    }
}


/*
    *
    *  *
    *  *  *
    *  *  *  *
    *  *  *  
    *  *  
    *  
*/

void pattern_2(){

    for(int row = 1 ; row <= 4; row++ ){
        for(int col = 1 ; col <= row ; col++){
            cout << "*" << "  ";
        }
        cout << endl;
    }
    for(int row = 1; row <= 3; row++){
        for(int col = 1; col <= row ; col++){
            cout << "*" << "  ";
        }
        cout << endl;
    }
}

/*

               *
            *  *
         *  *  *
      *  *  *  *
   *  *  *  *  * 
*/


void pattern_3(){
    for(int row = 1 ; row <= 5 ; row++ ){
        for(int space = 5 ; space > row ; space--){
            cout << "  " << "  ";
        }
        for(int col = 1; col <= row ; col++){
            cout << " *" << "  " ;
        }
        cout << endl ;
    }

}



/*

               *
            *  *  * 
         *  *  *  *  *
      *  *  *  *  *  *  *
   *  *  *  *  *  *  *  *  * 
*  *  *  *  *  *  *  *  *  *  *

*/

void pattern_4(){
    for(int row = 1 ; row <= 6 ; row++ ){
        for(int space = 6 ; space > row ; space--){
            cout << "  " << "  ";
        }
        for(int col = 1; col <= row ; col++){
            cout << " *" << "  " ;
        }
        for(int col = 1 ; col < row; col++){
            cout << " *" << "  ";
        }
        cout << endl ;
    }
}


int main(void){

    // pattern_1();
    pattern_4();

    return 0;
}