vector<ll> fact[MAXN], invFact[MAXN];

void precompute() {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = inv(fact[i]);
    }
}

ll binomial(ll n, ll k) {
    if (k > n or k < 0) return 0;
    return (fact[n] * invFact[k] % MOD * invFact[n - k] % MOD);
}