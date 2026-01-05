// Modular Arithmetic

// Basic operations handling modulo logic automatically.
// Includes Modular Inverse (Fermat's Little Theorem) for division.

#define MOD 1000000007

ll mod_add(ll a, ll b) {
    return (a % MOD + b % MOD) % MOD;
}

ll mod_sub(ll a, ll b) {
    return ((a % MOD - b % MOD) + MOD) % MOD;
}

ll mod_mul(ll a, ll b) {
    return (a % MOD * b % MOD) % MOD;
}

// Modular Inverse (1/a % MOD)
// Requires MOD to be Prime.
ll inv (ll a) {
    return fexp(a, MOD - 2);
}