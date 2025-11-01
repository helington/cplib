#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

using ll = long long;

int solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector <ll> psum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        psum[i + 1] = psum[i] + a[i];
    }

    for (int i = 0; i < m; i++) {
        int s_d, s_m, e_d, e_m;
        cin >> s_d >> s_m >> e_d >> e_m;

        ll days;
        if (e_m - s_m == 0) {
            if (e_d < s_d) {
                days = psum[n] - (s_d - e_d) + 1;
            }
            else {
                days = e_d - s_d + 1;
            }
        }
        else if (e_m - s_m == 1) {
            days = a[s_m - 1] - s_d + 1 + e_d;
        }
        else if (e_m - s_m < 0) {
            days = psum[n] - psum[s_m - 1] - s_d + 1;
            if (e_m == 1) {
                days += e_d;
            }
            else {
                days += psum[e_m - 1] + e_d;
            }
        }
        else {
            days = psum[e_m - 1] - psum[s_m - 1] + e_d - s_d + 1;
        }

        cout << days << endl;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        solve();
    }

    return 0;
}