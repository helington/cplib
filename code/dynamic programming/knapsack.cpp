// 0/1 Knapsack: Each item can be picked AT MOST ONCE.

// Target: Maximize value with capacity W.
// Complexity: O(N * W)

ll knapsack_01(int W, const vector<int> &wt, const vector<int> &val) {
    vector<ll> dp(W + 1, 0);
    int n = wt.size();

    for (int i = 0; i < n; i++) {
        // Iterate BACKWARDS to avoid using the same item twice for the same weight
        for (int w = W; w >= wt[i]; w--) {
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
        }
    }

    return dp[W];
}

// Unbounded Knapsack: Each item can be picked INFINITE times.
ll knapsack_unbounded(int W, const vector<int> &wt, const vector<int> &val) {
    vector<ll> dp(W + 1, 0);
    int n = wt.size();

    for (int i = 0; i < n; i++) {
        // Iterate FORWARDS allows re-using the item we just considered
        for (int w = wt[i]; w <= W; w++) {
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
        }
    }

    return dp[W];
}