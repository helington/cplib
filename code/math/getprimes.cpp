// Prime Factorization (Trial Division)

// Decomposes n into its prime factors.
// Returns a vector of pairs: {prime_factor, exponent}

// O(sqrt(n))

vector<pair<ll, int>> getprimes(ll n) {
    vector<pair<ll, int>> primes;

    for (ll i = 2; i * i <= n; i++) {
        int cnt = 0;

        while (n % i == 0) {
            n /= i;
            cnt++;
        }

        if (cnt > 0) primes.push_back({i, cnt});
    }

    if (n > 1) primes.push_back({n, 1});
    
    return primes;
}