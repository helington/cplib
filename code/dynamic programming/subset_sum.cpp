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

// Adaptated ideia, if can i get a subsequence that it's disible by a lcm

ll total_ways(vector<ll> &a) {
    vector<ll> dp(LCM, 0);
    vector<ll> dp_increment(LCM);

    for (auto i : a) {
        dp_increment = dp;

        dp_increment[i % LCM]++;
        for (int j = 0; j < LCM; j++) {
            if (!dp[j]) continue;
            auto key = mod_mul(i, j);
            dp_increment[key] = mod_add(dp_increment[key], dp[j]);
        }

        dp = dp_increment;
    }

    return dp[0];
}