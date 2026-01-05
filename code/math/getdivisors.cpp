// Get Divisors

// Finds all divisors of n.
//
// Time Complexity: O(sqrt(n))

vector<ll> getdivisors(ll n) {
    vector<ll> divisors;

    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n/i) divisors.push_back(n / i);
        }
    }

    sort(divisors.begin(), divisors.end()) // If it's necessarily
    return divisors;
}