//  Pattern:
#include<bits/stdc++.h>
using namespace std;

/*
Pattern 1:

    * * * * * 
    * * * * * 
    * * * * * 
    * * * * * 
    * * * * * 

*/ 
void pattern1(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << "* ";
        }
        cout << endl;
    }
}

/*
Pattern 2:

    * 
    * *
    * * *
    * * * *
    * * * * * 

*/ 
void pattern2(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << "* ";
        }
        cout << endl;
    }
}

/*
Pattern 3:

    1
    1 2
    1 2 3
    1 2 3 4
    1 2 3 4 5

*/ 
void pattern3(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << j << " ";
        }
        cout << endl;
    }
}

/*
Pattern 4:

    1
    2 2
    3 3 3
    4 4 4 4
    5 5 5 5 5

*/ 
void pattern4(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << i << " ";
        }
        cout << endl;
    }
}

/*
Pattern 5:

   * * * * *
   * * * *
   * * *
   * *
   * 

*/ 
void pattern5(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout << "* ";
        }
        cout << endl;
    }
}

/*
Pattern 6:

   1 2 3 4 5
   1 2 3 4
   1 2 3
   1 2
   1

*/ 
void pattern6(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            cout << j<< " ";
        }
        cout << endl;
    }
}

/*
Pattern 7:


                 *
               * * *
             * * * * *
           * * * * * * *
         * * * * * * * * * 

*/ 
void pattern7(int n){
    for(int i=1;i<=n;i++){
        // Print first upper half spaces:
        for(int j=1;j<n-i+1;j++){
            cout << "  ";
        }
        // Print second triangle:
        for(int j=1;j<=i;j++){
            cout << "* ";
        }
        // print third triangle: -> this triangle has one less stars..
        for(int j=1;j<i;j++){
            cout << "* ";
        }
        cout << endl;
    }
}


/*
Pattern 8:

         * * * * * * * * * 
           * * * * * * *
             * * * * *
               * * *
                 *

*/ 
void pattern8(int n){
    for(int i=1;i<=n+1;i++){
        // Print first upper half spaces:
        for(int j=1;j<i;j++){
            cout << "  ";
        }
        // Print second triangle:
        for(int j=1;j<=n-i+1;j++){
            cout << "* ";
        }
        // print third triangle: -> this triangle has one less stars..
        for(int j=1;j<=n-i;j++){
            cout << "* ";
        }
        cout << endl;
    }
}


/*
Pattern 9:

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
void pattern9(int n){

    // Up pattern:
    for(int i=1;i<=n;i++){
        // Print first upper half spaces:
        for(int j=1;j<n-i+1;j++){
            cout << "  ";
        }
        // Print second triangle:
        for(int j=1;j<=i;j++){
            cout << "* ";
        }
        // print third triangle: -> this triangle has one less stars..
        for(int j=1;j<i;j++){
            cout << "* ";
        }
        cout << endl;
    }

    // Down pattern:
    for(int i=1;i<=n+1;i++){
        // Print first upper half spaces:
        for(int j=1;j<i;j++){
            cout << "  ";
        }
        // Print second triangle:
        for(int j=1;j<=n-i+1;j++){
            cout << "* ";
        }
        // print third triangle: -> this triangle has one less stars..
        for(int j=1;j<=n-i;j++){
            cout << "* ";
        }
        cout << endl;
    }
}

/*
Pattern 10:

    for n -> ROWS -> (2*n - 1)

            *
            * *
            * * *
            * * * *
            * * * * * 
            * * * *
            * * *
            * *
            *

*/ 

void pattern10(int n){

    // print first half:
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << "* ";
        }
        cout << endl;
    }

    // Print second half:
    for(int i=1;i<n;i++){
        for(int j=1;j<=n-i;j++){
            cout << "* ";
        }
        cout << endl;
    }
}


// ..... im getting bored, i have already implemented all this shit in pattern directory...


int main(){
    int n;
    cin >> n;

    // pattern1(n);
    // cout << endl;

    // pattern2(n);
    // cout << endl;

    // pattern3(n);
    // cout << endl;

    // pattern4(n);
    // cout << endl;

    // pattern5(n);
    // cout << endl;

    // pattern6(n);
    // cout << endl;

    // pattern7(n);
    // cout << endl;

    // pattern8(n);
    // cout << endl;

    // pattern9(n);
    // cout << endl;

    pattern10(n);
    cout << endl;

    return 0;
}