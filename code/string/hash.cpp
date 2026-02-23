// String Hashing (Double Hash + RNG Base)

// Fast substring comparisons in O(1).
// Highly resistant to collision attacks.

// Time Complexity: 
// - Build: O(N)
// - Query: O(1)

const ll MOD1 = 1000015553, MOD2 = 1000028537;
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

// Random base between 356 and MOD1-1
static ll BASE = uniform_int_distribution<int>(356, MOD1 - 1)(rng);

struct Hasher {
    int n;
    string s;
    vector<ll> hash1, power1, hash2, power2;

    Hasher() : n(0) {}

    Hasher(const string &_s) : n(_s.size()), s(_s), hash1(n), power1(n), hash2(n), power2(n) {
        power1[0] = power2[0] = 1;
        for (int i = 1; i < n; i++) {
            power1[i] = (BASE * power1[i-1]) % MOD1;
            power2[i] = (BASE * power2[i-1]) % MOD2;
        }

        hash1[0] = hash2[0] = s[0];
        for (int i = 1; i < n; i++) {
            hash1[i] = (hash1[i-1] * BASE + (ll)(s[i])) % MOD1;
            hash2[i] = (hash2[i-1] * BASE + (ll)(s[i])) % MOD2;
        }
    }

    // Returns the combined double-hash for substring s[l...r] (inclusive)
    ll query(int l, int r) {
        if (!l) return (hash1[r] << 30) ^ hash2[r];

        ll ans1 = ((hash1[r] - (hash1[l-1] * power1[r - l + 1])) % MOD1 + MOD1) % MOD1;
        ll ans2 = ((hash2[r] - (hash2[l-1] * power2[r - l + 1])) % MOD2 + MOD2) % MOD2;

        // Pack the two 30-bit numbers into a single 64-bit integer
        return (ans1 << 30) ^ ans2;
    }
};