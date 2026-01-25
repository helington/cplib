// Pascal's Triangle (nCr Precomputation)

// Precomputes nCr values using Dynamic Programming.
// Formula: C(n, k) = C(n-1, k-1) + C(n-1, k)

// CONSTRAINTS:
// - Max N ~ 2000 (due to O(N^2) memory/time).
// - For N > 2000, use Factorial/Inverse Factorial method (O(N) precompute, O(1) query).
// - Without MOD: Works for N <= 66 (fits in long long).

// O(N^2)

vector<vector<ll>> get_pascal_triangle(int MAXN) {
    // Initialize 2D vector with 0
    vector<vector<ll>> C(MAXN + 1, vector<ll>(MAXN + 1, 0));

    for (int i = 0; i <= MAXN; i++) {
        C[i][0] = 1; // C(n, 0) = 1
        for (int j = 1; j <= i; j++) {
            // C(n, k) = C(n-1, k-1) + C(n-1, k)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }

    return C;
}