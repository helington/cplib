// Traveling Salesperson Problem (TSP)

// Finds the minimum cost to visit all cities exactly once and return to start.
// Uses DP with Bitmask.

// O(N^2 * 2^N)
// Constraint: N <= 20

const int INF = 1e9;

int tsp(const vector<vector<int>>& dist) {
    int n = dist.size();
    int LIMIT = (1 << n);

    // dp[mask][i] = min cost to visit set 'mask', ending at city 'i'
    vector<vector<int>> dp(LIMIT, vector<int>(n, INF));

    // Base case: Start at city 0
    // Mask 1 (binary ...001) means only city 0 is visited, cost is 0.
    dp[1][0] = 0;

    for (int mask = 1; mask < LIMIT; mask++) {
        for (int u = 0; u < n; u++) {
            // If city 'u' is in the current mask
            if ((mask & (1 << u))) {
                
                // Try to transition to a next city 'v'
                for (int v = 0; v < n; v++) {
                    // If 'v' is NOT in the mask, we can visit it
                    if (!(mask & (1 << v))) {
                        int next_mask = mask | (1 << v);
                        dp[next_mask][v] = min(dp[next_mask][v], dp[mask][u] + dist[u][v]);
                    }
                }
            }
        }
    }

    // Reconstruction: Return to city 0 from the last city
    int ans = INF;
    int full_mask = LIMIT - 1;
    for (int i = 1; i < n; i++) {
        if (dist[i][0] != INF) // Ensure edge exists
             ans = min(ans, dp[full_mask][i] + dist[i][0]);
    }

    return ans;
}