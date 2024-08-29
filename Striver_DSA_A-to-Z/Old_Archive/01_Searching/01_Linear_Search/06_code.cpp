// Linear Search in 2D array

#include <iostream>
using namespace std;

// linear search in 2D array.
bool linearSearch(int list[][3], int target, int row_size, int col_size){
    for(int i = 0 ;i < row_size; i++){
        for(int j = 0 ; j < col_size; j++){
            if(list[i][j] == target){
                return true;
            }
        }
    }
    return false;
}

void print(int list[][3], int row_size, int col_size){
    cout << endl << "Array list : " << endl ;
    for(int i = 0 ;i < row_size; i++){
        for(int j = 0 ; j < col_size; j++){
            cout << list[i][j] << "  ";
        }
        cout << endl ;
    }
    cout << endl ;
}


int main(void){

    int list[][3] = { 
        {1, 2, 3}, 
        {4, 5, 6}, 
        {7, 8, 9},
        {10, 11, 12}
    };

    int target = 12;

    int row_size = sizeof(list)/sizeof(list[0]);
    int total_size = sizeof(list)/sizeof(list[0][0]);
    int col_size = total_size / row_size;

    // cout << endl << row_size  << endl << total_size << endl << col_size << endl ;

    print(list, row_size, col_size);

    int result = linearSearch(list, target, row_size, col_size);
    (result == 0) ? cout << endl << "Not Found." : cout << endl <<"Found.";

    return 0;
}