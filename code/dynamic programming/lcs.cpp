// Longest Common Subsequence (LCS)

// Returns the length of the longest subsequence common to s1 and s2.

// Time Complexity: O(N * M)

int lcs(const string& s1, const string& s2) {
    int n = s1.size();
    int m = s2.size();

    // dp[i][j] stores LCS length of s1[0...i-1] and s2[0...j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                // Characters match: extend the diagonal result
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                // No match: take the best of skipping char from s1 or s2
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

// Reconstruct the String (Backtracking)
string reconstruct(const vector<vector<int>>& dp, string& s1, string& s2) {
    string res = "";
    int i = s1.size(), j = s2.size();
    
    while (i > 0 && j > 0) {
        // If characters match, it was part of the LCS
        if (s1[i - 1] == s2[j - 1]) {
            res += s1[i - 1];
            i--;
            j--;
        }
        // If they didn't match, we came from the cell with the larger value
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--; // Moved down (so go up)
        } else {
            j--; // Moved right (so go left)
        }
    }

    reverse(res.begin(), res.end());
    return res;
}