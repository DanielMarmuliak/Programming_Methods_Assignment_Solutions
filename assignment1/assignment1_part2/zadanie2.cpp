#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100;
long long A[MAXN][MAXN];

// Kadane's algorithm that allows an empty subarray -> result is always >= 0
long long f_kadaneNonNegative(const long long arr[], int len) {
    long long best = 0;
    long long cur = 0;
    for (int i = 0; i < len; i++) {
        cur = max(0LL, cur + arr[i]);   // if cur becomes negative, reset to 0 (empty)
        best = max(best, cur);          // update best
    }
    return best;
}

// Computes the maximum sum sub-rectangle in a matrix (empty rectangle allowed -> 0)
long long f_maxSubmatrixSum(int n, int m) {
    // To achieve O(max(n,m) * n * m), we iterate over the smaller dimension as "rows".
    // If n > m, we treat columns as rows (logical transpose in access).
    bool transposed = false;
    int R = n, C = m;
    if (n > m) {
        transposed = true;
        R = m;  // number of "rows" in transposed view
        C = n;  // number of "cols" in transposed view
    }

    long long best = 0;
    long long colSum[MAXN];

    for (int top = 0; top < R; top++) {
        // Reset column sums for the current top row
        for (int c = 0; c < C; c++)
            colSum[c] = 0;

        for (int bottom = top; bottom < R; bottom++) {
            // Add the next row (bottom) into colSum
            for (int c = 0; c < C; c++) {
                long long val;
                if (!transposed) {
                    // normal access: A[row][col]
                    val = A[bottom][c];
                } else {
                    // transposed access: A[col][row]
                    val = A[c][bottom];
                }
                colSum[c] += val;
            }

            // The best contiguous subarray in colSum gives the best rectangle for rows [top..bottom]
            best = max(best, f_kadaneNonNegative(colSum, C));
        }
    }

    return best;
}

void f_readMatrix(int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int z;          // number of test cases
    cin >> z;

    while (z--) {
        int n, m;    // number of rows and columns
        cin >> n >> m;

        f_readMatrix(n, m);

        long long ans = f_maxSubmatrixSum(n, m);

        // If all values are <= 0, the best (empty) sub-rectangle has sum 0.
        // f_kadaneNonNegative already enforces this behavior.
        cout << ans << "\n";
    }

    return 0;
}