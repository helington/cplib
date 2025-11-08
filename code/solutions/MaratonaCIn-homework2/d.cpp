#include <bits/stdc++.h>

using ll = long long;

using namespace std;

int solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0 ; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int q;
    cin >> q;
    while (q--) {
        ll pos;
        cin >> pos;
        cout << upper_bound(a.begin(), a.end(), pos) - a.begin() << '\n';
    }

    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}