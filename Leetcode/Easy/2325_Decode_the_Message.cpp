#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum number of wins for your cow
int maxWins(int n, int k, vector<int>& a) {
    vector<int> left(n), right(n);  // Arrays to store opponent ranking

    // Build opponent ranking arrays (highest rating to the left/right)
    for (int i = 1; i < n; ++i) {
        left[i] = max(left[i - 1], i - 1);
        for (int j = i - 1; j >= 0; --j) {
            if (a[j] > a[left[i]]) {
                left[i] = j;
                break;
            }
        }
    }

    for (int i = n - 2; i >= 0; --i) {
        right[i] = min(right[i + 1], i + 1);
        for (int j = i + 1; j < n; ++j) {
            if (a[j] > a[right[i]]) {
                right[i] = j;
                break;
            }
        }
    }

    // Simulate matches without swap
    int winsWithoutSwap = 0;
    int curr = k;
    while (curr < n - 1) {
        if (a[curr] > a[right[curr]]) {
            winsWithoutSwap++;
        }
        curr = right[curr];
    }

    // Simulate matches with swap (swap left and right)
    int winsWithSwap = 0;
    curr = k;
    while (curr > 0) {
        if (a[curr] > a[left[curr]]) {
            winsWithSwap++;
        }
        curr = left[curr];
    }

    return max(winsWithoutSwap, winsWithSwap);  // Return the maximum wins
}

int main() {
    // Sample test case
    int n = 6;
    int k = 1;  // Your cow's index (1-based)
    vector<int> a = {12, 10, 14, 11, 8, 3};  // Cowdeforces ratings

    int max_wins = maxWins(n, k - 1, a);  // Adjust k for 0-based indexing

    cout << "Maximum Wins: " << max_wins << endl;

    return 0;
}
