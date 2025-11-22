#include <bits/stdc++.h>

using namespace std;

int solve() {
    int n, m, end;
    cin >> n >> m >> end;

    vector<int> l(n);
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
       cin >> l[i] >> r[i];
    }

    vector<int> x(n);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> v[i];
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}