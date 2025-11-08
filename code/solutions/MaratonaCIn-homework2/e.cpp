#include <bits/stdc++.h>

#define endl '\n'

using ll = long long;

using namespace std;

int solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0 ; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());

    vector<ll> psum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        psum[i + 1] = psum[i] + a[i];
    }

    while (q--) {
        int x; cin >> x;
        if (x > psum[n]) {
            cout << "-1" << endl;
        } else {
            cout << lower_bound(psum.begin(), psum.end(), x) - psum.begin() << endl;
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}