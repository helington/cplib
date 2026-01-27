// Two Pointers (Variable Window)

// Finds the longest/shortest subarray satisfying a condition.
// Time Complexity: O(N) (Each element added and removed at most once)

void two_pointers(const vector<int>& v) {
    int n = v.size();
    int left = 0;
    
    // Current window state (e.g., Sum, Count of unique elements)
    ll current_sum = 0; 

    for (int right = 0; right < n; right++) {
        // 1. Add right element to window
        current_sum += v[right];

        // 2. Shrink from left while condition is broken
        // Example: Find longest subarray with Sum <= K
        while (current_sum > 100 /* K */ && left <= right) {
            current_sum -= v[left];
            left++;
        }

        // 3. Update Answer (Window is valid here)
        // int current_len = right - left + 1;
        // ans = max(ans, current_len);
    }
}