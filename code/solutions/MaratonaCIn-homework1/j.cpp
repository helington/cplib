#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int solve() {
    int n;
    cin >> n;

    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> pmin(n);
    pmin[0] = a[0];
    for (int i = 1; i < n; i++) {
       pmin[i] = min(a[i], pmin[i - 1]);
    }

    vector<int> smax(n);
    smax[n -1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        smax[i] = max(a[i], smax[i + 1]);
    }

    for (int i = 0; i < n; i++) {
        if (i == 0 or i == n - 1) {
            cout << "1";
            continue;
        }

        if (a[i] <= pmin[i] or a[i] >= smax[i]) {
            cout << "1";
        }
        else {
            cout << "0";
        }
    }
    cout << endl;

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