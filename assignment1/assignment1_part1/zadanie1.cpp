#include <iostream>
#include <algorithm>
using namespace std;

// Convert one element to its contribution in: sum = 3*D + 2*U
// Positive x contributes 3*x, negative x contributes 2*x, zero contributes 0.
long long f_weight(long long x) {
    if (x > 0) return 3LL * x;
    if (x < 0) return 2LL * x;
    return 0;
}

// Solve one test case in O(n) (Kadane on weighted values).
// Output: bestL bestR bestSum (0-based indices).
// If all numbers are negative -> empty subarray, print 0 0 0.
void f_solveOne(int n) {
    long long bestSum = 0;
    long long currentSum = 0;

    int bestL = 0, bestR = 0;
    int currentL = 0;

    bool hasNonNegative = false; // needed to detect "all numbers negative"

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;

        if (x >= 0) hasNonNegative = true;

        long long w = f_weight(x);
        currentSum += w;

        // If current sum becomes negative, restart (empty subarray allowed)
        if (currentSum < 0) {
            currentSum = 0;
            currentL = i + 1;
        }
        // Update best if we found a better sum
        else if (currentSum > bestSum) {
            bestSum = currentSum;
            bestL = currentL;
            bestR = i;
        }
    }

    // If all input numbers were negative -> empty subarray by definition
    if (!hasNonNegative) {
        cout << "0 0 0\n";
    } else {
        cout << bestL << " " << bestR << " " << bestSum << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int z;          // number of test cases
    cin >> z;

    while (z--) {
        int n;      // array length
        cin >> n;
        f_solveOne(n);
    }

    return 0;
}