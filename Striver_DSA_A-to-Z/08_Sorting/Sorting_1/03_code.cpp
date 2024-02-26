/* 

sort ascending order for even place & descending order for odd place..

*/

#include <iostream>
#include <algorithm>
using namespace std;

void customSort(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if (i % 2 == 0) {
            for (int j = i + 2; j < size; j += 2) {
                if (arr[i] < arr[j]) {
                    swap(arr[i], arr[j]);
                }
            }
        } else {
            for (int j = i + 2; j < size; j += 2) {
                if (arr[i] > arr[j]) {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }

    // Print the sorted array
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    customSort(arr, n);

    return 0;
}

