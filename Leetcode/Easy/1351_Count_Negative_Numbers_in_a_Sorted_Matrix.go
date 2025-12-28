/*

//  1351. Count Negative Numbers in a Sorted Matrix


//  Problem Statement:
    -> Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.


// Example:
    Example 1:
        Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
        Output: 8
        Explanation: There are 8 negatives number in the matrix.

    Example 2:
        Input: grid = [[3,2],[1,0]]
        Output: 0

//  Observations:
    -> Iterate in row
        -> for every row, try finding the last positive index
        -> Count the negative values & build answer.


        [4,   3,  2, -1]
        [3,   2,  1, -1]
        [1,   1, -1, -2]
        [-1, -1, -2, -3]


// Complexity:
    -> TC: O(N * log(M))
    -> SC: O(1)


*/

// BruteForce:
func countNegatives(grid [][]int) int {

	var neg int = 0

	for _, rows := range grid {
		for _, val := range rows {
			if val < 0 {
				neg++
			}
		}
	}

	return neg

}

// Optimal:
func countNegatives(grid [][]int) int {
	var colSize int = len(grid[0])
	var neg int = 0

	for _, rows := range grid {
		var low int = 0
		var high int = colSize - 1

		var ans int = -1

		for low <= high {
			var mid = (low + high) / 2

			// find +ve, move right to find the first -ve
			if rows[mid] >= 0 {
				low = mid + 1
				ans = mid
			} else {
				high = mid - 1
			}
		}

		// Count the -ve:
		if ans != -1 {
			neg += colSize - ans - 1
		} else {
			neg += colSize
		}
	}

	return neg
}