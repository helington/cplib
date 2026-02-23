// 1D Sweep Line (Difference Array + Coord Comp)

// Processes interval events on a timeline.
// Extremely useful when coordinate ranges are large (10^9) 
// but the number of intervals is small (10^5).

// Time Complexity: O(N log N) (due to sorting and lower_bound)
// Space Complexity: O(N)

void sweep_line(const vector<pair<int, int>> &intervals) {
    vector<int> all;

    // Collect all interesting points
    for (const auto &[l, r] : intervals) {
        all.push_back(l);
        all.push_back(r); 
        // NOTE: If intervals are [L, R] INCLUSIVE, push back 'r + 1' instead of 'r'
        // all.push_back(r + 1);
    }

    // Coordinate Compression
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    // Difference Array
    int m = all.size();
    vector<int> cnt(m, 0);

    for (const auto &[l, r] : intervals) {
        // Map original coordinates to compressed indices [0 ... m-1]
        int idx_l = lower_bound(all.begin(), all.end(), l) - all.begin();
        int idx_r = lower_bound(all.begin(), all.end(), r) - all.begin();

        cnt[idx_l]++;
        cnt[idx_r]--; 
        // NOTE: If [L, R] INCLUSIVE, find the index for 'r + 1' and decrement that:
        // int idx_r_plus_1 = lower_bound(all.begin(), all.end(), r + 1) - all.begin();
        // cnt[idx_r_plus_1]--;
    }

    // Prefix Sums to compute active intervals
    int max_active = 0;
    int current_active = 0;
    
    // pref[i] represents how many intervals cover the compressed segment 'i'
    for (int i = 0; i < m; i++) {
        current_active += cnt[i];
        max_active = max(max_active, current_active);
    }
}