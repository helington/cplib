// Subset Sum (Space Optimized)

// Checks if 'target' sum is possible using a subset of 'nums'.

// O(N * Target)

bool can_reach_sum(const vector<int>& nums, int target) {
    // dp[i] will be true if sum 'i' is achievable
    vector<bool> dp(target + 1, false);
    
    dp[0] = true; // Base case: Sum 0 is always possible (empty subset)

    for (int x : nums) {
        // Iterate BACKWARDS to avoid using the same element multiple times
        // (Similar to 0/1 Knapsack logic)
        for (int s = target; s >= x; s--) {
            if (dp[s - x]) {
                dp[s] = true;
            }
        }
    }

    return dp[target];
}