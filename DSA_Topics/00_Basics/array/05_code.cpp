// Cumulative sum array : 

/*

Initial Array: [1, 2, 3, 4]
Cumulative Sum: [1, 3, 6, 10]

Initial Array: [1, 1, 1, 1, 1]
Cumulative Sum: [1, 2, 3, 4, 5]

Initial Array: [1, 3, 5, 7, 9]
Cumulative Sum: [1, 4, 9, 16, 25]

*/

#include <iostream>
using namespace std;

void sum(int list[], int size){

    int sum = 0;
    for(int i = 0 ; i < size ;i++){
        sum = sum + list[i];
        list[i] = sum;
    }
    cout << endl << "New List : ";
    for(int i = 0 ; i < size ; i++){
        cout << list[i] << " ";
    }
}

int main(void){

    int list[] = {1, 2, 3, 4};
    int size = sizeof(list)/ sizeof(list[0]);

    sum(list, size);

    return 0;
}
