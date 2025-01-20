/*

//  2661. First Completely Painted Row or Column


//  Problem Statement: 
    -> You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].
    -> Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].
    -> Return the smallest index i at which either a row or a column will be completely painted in mat.



// Example:
    Example 1:
        Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
        Output: 2
        Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].

    Example 2:
        Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
        Output: 3
        Explanation: The second column becomes fully painted at arr[3].



// Observations: 
    -> We are given matrix & array, 
    -> We need to paint matrix cell, according to the array element.
    -> at any movement when any row OR any column is completely painted, we can return that minimum index.


    // BruteForce Solution:
        -> use paint grid to track the painted cells.
        -> At any movement any row or any column is painted, we can return true;
        -> we need to return that index.

        -> For painting that particular element from array, we have to traverse all the way to that value, & then paint.
            ->  We can write independent function for that 
        -> For checking wether any row || any column is completely painted, we will have to visit the matrix at every steps.
        -> & at any movement we encounter with the given condition, we will return that minimum index.
        -> Complexity will be higher, but it will work.
            -> TC: O(arrSize * (n*m))
            -> SC: O(n*m)



    // Efficient Solution:
        
        -> Now time to improve our BruteForce Solution:
            -> if somehow we can store the computation of row & col then we can save lot's of time..
            -> Let's Explore the possible options: 
                MAP: 
                    map for row: 
                        we need to track wether any map row has all painted
                    map for col: 
                        we need to track wether any map col has all painted

                    Solution: 
                        -> We can create a map for col & map for row:
                        -> for every row, we will store the frequency count of every row index & once any frequency count reaches to the row size we can return true.
                        -> similarly with column.

                    // Problem is to search efficiently in matrix & paint that.

                    -> for every search we are taking O(n*m)
                        -> While we are searching & updating we can store the rowFrequency & colFrequency at the same time..
                        -> And we will check that whether the frequency is equal to the row size & col size, & if so return that answer.


                    // Now we have to find out the way, that somehow we can be aware of every element location.
                        -> One good thing is we are given matrix value range from (1 to n*m)
                        -> if we get the matrix values coordinated in O(1) operations, it will be very efficient.
                        -> We can store mat value coordinates in map, & when we were searching, we can directly return it from map with O(1)


        // Complexity: 
            -> TC: O(n * m)
                Note: Since arr is a permutation of the elements of mat,
                    arrSize = (n * m) Therefore, O(arrSize) = O(n * m)
            -> AS: O(n * m)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient Solution: 
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {    // TC: O(n*m)
        int arrSize = arr.size();
        int n = mat.size();
        int m = mat[0].size();

        unordered_map<int, int> rowCnt; // use to store frequency of every row
        unordered_map<int, int> colCnt; // use to store frequency of every col
        
        // Preprocessing matrix coordinates:    TC: O(n*m)
        unordered_map<int, pair<int, int>> matPos;  // use to store matrix coordinates
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matPos[mat[i][j]] = {i, j};
            }
        }

        // TC: O(arrSize)
        for(int i=0;i<arrSize;i++){
            int value = arr[i];  // element to paint

            // // This will take O(n*m), but we saved this operation by storing coordinates in map, which will take O(1)
            // for(int row = 0; row < n; row++){
            //     for(int col = 0; col < m; col++){
            //         if(mat[row][col] == value){
            //             // mark that color in hashmap:
            //             // For row:
            //             rowCnt[row]++;
            //             if(rowCnt[row] == m) return i;

            //             // for col:
            //             colCnt[col]++;
            //             if(colCnt[col] == n) return i;
            //         }
            //     }
            // }
            

            // Fetching the coordinates of value from matrix-Hash:
            int row = matPos[value].first;
            int col = matPos[value].second;


            // mark that row & col in hashMap by O(1) & check wether have any row or col is painted or not, by simply checking the frequency count with size of row or col
            // row:
            rowCnt[row]++;
            if(rowCnt[row] == m) return i;  // return that index if we get any row all painted

            // col:
            colCnt[col]++;
            if(colCnt[col] == n) return i;  // return that index if we get any col all painted

        }

        return -1;
    }
};


// BruteForce Solution:
class Solution {
private:
    bool checkMat(vector<vector<bool>> &painted){   // TC: O(n*m)
        int n = painted.size();
        int m = painted[0].size();

        // check every row:
        for(int i=0;i<n;i++){
            bool checkFlag = true;
            for(int j=0;j<m;j++){
                if(painted[i][j] == false){
                    checkFlag = false;
                }

            }
            if(checkFlag){
                return 1;   // found one row, that contains all true:
            }
        }

        // check every col:
        for(int i=0;i<m;i++){
            bool checkFlag = true;
            for(int j=0;j<n;j++){
                if(painted[j][i] == false){
                    checkFlag = false;
                }
            }
            if(checkFlag){
                return 1;   // found one row, that contains all true:
            }
        }

        return 0;   // else return false;
    }
    void painted(vector<vector<int>>& mat, vector<vector<bool>> &paint, int value){ // TC: O(n*m)
        int n = mat.size();
        int m = mat[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == value){
                    paint[i][j] = true;
                    return; // return back
                }
            }
        }
    }
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) { // TC: O(arrSize * (n*m))
        int arrSize = arr.size();
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> paint(n, vector<bool> (m, false));   // this will contains the information of every painted cells

        int minIdx = -1;
        for(int i=0;i<arrSize;i++){ // TC: O(arrSize)
            int value = arr[i];  // element to paint
            
            // TC: O(n*m)
            painted(mat, paint, value);   // paint that particular element

            // TC: O(n*m)
            if(checkMat(paint)){    // if any row || any column is painted, return true.
                minIdx = i;
                break;
            }

        }

        return minIdx;
    }
};