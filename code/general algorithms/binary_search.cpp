// Binary Search on Answer

// Finds the FIRST value in [low, high] where check(val) is TRUE.
// Assumption: Function is Monotonic (False, False, ... True, True).

// Time Complexity: O(log(Range) * T_check)

ll binary_search_first_true(ll left, ll right, function<bool(ll)> check) {
    ll ans = right + 1; // Default: Not found
    
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        
        if (check(mid)) {
            ans = mid;
            right = mid - 1; // Try smaller
        } else {
            left = mid + 1;  // Need bigger
        }
    }
    
    return ans;
}

// Example Check Function
bool check(ll x) {
    // Return true if x is valid
    return x * x >= 50; 
}