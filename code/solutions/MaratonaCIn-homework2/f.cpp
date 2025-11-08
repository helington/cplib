#include <bits/stdc++.h>

using ll = long long;

using namespace std;

int solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0 ; i < n; i ++) {
        cin >> a[i];
    }

    ll wrost_psum = 0;
    vector<ll> psum(n + 1, 0);
    for (int i = 1; i < n + 1; i ++) {
        psum[i] = psum[i - 1] + a[i - 1];
        if (psum[i] < wrost_psum) {
            wrost_psum = psum[i];
        }
    }

    cout << wrost_psum * -1 << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}