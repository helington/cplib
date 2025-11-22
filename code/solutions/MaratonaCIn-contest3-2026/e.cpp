#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define endl '\n'

int solve(vector<ll> &v) {
    ll l, r; cin >> l >> r;

    auto itl = lower_bound(v.begin(), v.end(), l) - v.begin();
    auto itr = upper_bound(v.begin(), v.end(), r) - v.begin();
    ll ans = itr - itl;

    cout << ans << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<ll> s;

    ll total = 0;
    ll v1 = 1;
    ll v2 = 2;
    ll v3 = 3;
    ll current_value = v1 * v2 * v3;
    while (current_value <= 1e16) {
        s.push_back(current_value);
        v1++; v2++; v3++;
        current_value = v1 * v2 * v3;
    }

    int tc; cin >> tc; while (tc--) {
        solve(s);
    }

    return 0;
}