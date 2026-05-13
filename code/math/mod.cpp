#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

// Modular Arithmetic Structure (mod_int)

// Provides automated modular arithmetic operations.
// Supports addition, subtraction, multiplication, and division (via Fermat's Little Theorem).

// 0-indexed values internally.
// Time Complexity: O(log MOD) for division, O(1) for others.
// Space Complexity: O(1)

template<ll MOD>
struct mod_int {
    ll v;

    mod_int(ll x = 0) : v((x % MOD + MOD) % MOD) {}

    ll fexp(ll b, ll e) {
        ll res = 1;
        b %= MOD;
        while (e) {
            if (e % 2 == 1) res = (res * b) % MOD;
            e >>= 1;
            b = (b * b) % MOD;
        }
        return res;
    }

    mod_int operator + (const mod_int &b) const { ll a = v + b.v; return a < MOD ? a : a - MOD; }
    mod_int operator - (const mod_int &b) const { ll a = v - b.v; return a < 0 ? a + MOD : a; }
    mod_int operator * (const mod_int &b) const { return mod_int(v * b.v % MOD); }
    mod_int operator / (const mod_int &b) const { return mod_int(v * fexp(b.v, MOD - 2) % MOD); }

    mod_int& operator += (const mod_int &b) { return *this = *this + b; }
    mod_int& operator -= (const mod_int &b) { return *this = *this - b; }
    mod_int& operator *= (const mod_int &b) { return *this = *this * b; }
    mod_int& operator /= (const mod_int &b) { return *this = *this / b; }

    bool operator == (const mod_int &b) const { return v == b.v; }
    bool operator != (const mod_int &b) const { return v != b.v; }
    bool operator <  (const mod_int &b) const { return v <  b.v; }

    friend ostream& operator << (ostream& os, const mod_int &o) { return os << o.v; }
    friend istream& operator >> (istream& is, mod_int &o) {
        ll x; is >> x;
        o = mod_int(x);
        return is;
    }
};

typedef mod_int<(ll)1e9 + 7> mint;