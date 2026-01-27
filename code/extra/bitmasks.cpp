// Bit Manipulation Tricks

void bit_tricks(int x, int n) {
    // 1. Check if k-th bit is set
    bool is_set = (x & (1 << n));

    // 2. Set k-th bit (Turn ON)
    x |= (1 << n);

    // 3. Clear k-th bit (Turn OFF)
    x &= ~(1 << n);

    // 4. Toggle k-th bit
    x ^= (1 << n);

    // 5. Get the lowest set bit (e.g., 0110 -> 0010)
    int lowbit = x & -x;

    // 6. Turn off the lowest set bit (e.g., 0110 -> 0100)
    x = x & (x - 1);

    // 7. Check if x is a power of 2 (returns true for 0 too, handle separately)
    bool powerOf2 = (x > 0) && !(x & (x - 1));

    // 8. Builtin Functions (GCC specific, very fast)
    int set_bits = __builtin_popcount(x);      // Count 1s (use __builtin_popcountll for long long)
    int trailing_zeros = __builtin_ctz(x);     // Count trailing 0s
    int leading_zeros = __builtin_clz(x);      // Count leading 0s
}

// 9. Iterate over all submasks of a mask m
// (Excludes empty mask 0, allows mask m itself)
// O(3^N) total if iterating submasks for all masks
void iterate_submasks(int m) {
    for (int s = m; s; s = (s - 1) & m) {
        // 's' is a subset of 'm'
        // Process s...
    }
}

// 10. Generate all subsets of size N (Power Set)
// O(2^N)
void generate_all_subsets(int n) {
    for (int mask = 0; mask < (1 << n); mask++) {
        // Process mask...
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                // Element i is in the subset
            }
        }
    }
}
