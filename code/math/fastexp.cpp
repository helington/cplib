// Fast Modular Exponentiation (Binary Exponentiation)

// Computes (base^exp) % MOD efficiently using bitwise operations.

// O(log (exp))

ll fexp(ll base, ll exp) {
    ll res = 1;
    base %= MOD;

    while (exp) {
        if (exp & 1) res = mod_mul(res, base);
        base = mod_mul(base, base);
        exp >>= 1;
    }

    return res;
}