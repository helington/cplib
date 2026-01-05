// Sieve of Eratosthenes

// Generates all prime numbers up to MAX_N.

// O(n log(log(n)))

const int MAX_N = 1000005; // Adjust based on problem constraints (usually 1e6 or 1e7)

bool is_prime[MAX_N];
vector<int> primes;

void sieve(int n) {
    fill(is_prime, is_prime + n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            // Start from i*i because smaller multiples have already been marked
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}