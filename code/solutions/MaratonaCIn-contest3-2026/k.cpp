#include <bits/stdc++.h>

using ll = long long;

using namespace std;

#define endl '\n'

ll total_possibilities(vector<ll> s,ll n, ll x, ll d, ll i = 0, ll total_members = 0, ll sum = 0, ll wrost = 0, ll best = 0, ll total = 0)  {
    if (sum >= x and best - wrost <= d and total_members > 0) {
        total++;
    }

    if (i >= n) return total;

    ll no_add = total_possibilities(s, n, x, d, i + 1, total_members, sum, wrost, best, 0);

    if (s[i] > best) {
        best = s[i];
    }

    if (s[i] < wrost or total_members == 0) {
        wrost = s[i];
    }

    ll add = total_possibilities(s, n, x, d, i + 1, total_members + 1, sum + s[i], wrost, best, 0);

    return add + no_add;
}

int solve() {
    ll n, x, d; cin >> n >> x >> d;

    vector<ll> s(n);
    for (ll i = 0 ; i < n; i++) cin >> s[i];

    cout << total_possibilities(s,n, x, d) << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}