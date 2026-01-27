// Longest Increasing Subsequence (LIS)

// Finds the length of the longest strictly increasing subsequence.
// To find Non-Decreasing, change lower_bound to upper_bound.

// O(N log N)

template<typename T>
int lis(const vector<T>& v) {
    if (v.empty()) return 0;
    
    vector<T> tails;
    
    for (const auto& x : v) {
        // lower_bound for Strictly Increasing
        // upper_bound for Non-Decreasing
        auto it = lower_bound(tails.begin(), tails.end(), x);
        
        if (it == tails.end()) {
            tails.push_back(x);
        } else {
            *it = x; // Replace to maintain smallest tail for this length
        }
    }
    
    return tails.size();
}