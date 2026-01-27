// Digit DP Template

// Problem: Count numbers in [0, R] satisfying a property.
// Solution: solve(R) - solve(L-1).

// Memoization table: [index][tight_constraint][custom_state]
ll memo[20][2][200]; 
string S;

// idx: current digit position (from left to right)
// tight: true if we are restricted by the digits of N
// state: problem-specific state (e.g., sum of digits, remainder)
ll dp(int idx, bool tight, int current_sum) {
    if (idx == S.size()) {
        return current_sum; // Base case: return 1 if valid, 0 if not
    }
    
    if (memo[idx][tight][current_sum] != -1) 
        return memo[idx][tight][current_sum];

    ll ans = 0;
    int limit = tight ? (S[idx] - '0') : 9;

    for (int digit = 0; digit <= limit; digit++) {
        // Update tight constraint:
        // Only tight if we were already tight AND we picked the max digit
        bool new_tight = tight && (digit == limit);
        
        ans += dp(idx + 1, new_tight, current_sum + digit);
    }

    return memo[idx][tight][current_sum] = ans;
}

ll solve(ll n) {
    if (n < 0) return 0;
    if (n == 0) return 0; // Handle 0 specific logic if needed
    
    S = to_string(n);
    // memset(memo, -1, sizeof(memo)); // Reset for every query!
    // For many test cases, be careful about memset overhead
    memset(memo, -1, sizeof(memo));
    
    return dp(0, true, 0);
}