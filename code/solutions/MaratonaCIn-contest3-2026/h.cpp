#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> b(n);
    b[n-1] = 0;
    for (int i = n-2; i >= 0; i--) {
        if (a[i] == a[i + 1]) {
            b[i] = b[i + 1];
        } else {
            b[i] = (n - (i + 1)) * a[i];
        }
    }

    vector<ll> c(n);
    c[0] = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            c[i] = c[i - 1];
        } else {
            c[i] = (i) * a[i];
        }
    }

    ll best = b[0] + c[0];
    ll sum;
    for (int i = 1; i < n; i++) {
        sum = b[i] + c[i];
        if (sum < best) {
            best = sum;
        }
    }

    cout << best << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while(tc--) {
        solve();
    }

    return 0;
}