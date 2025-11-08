#include <bits/stdc++.h>

#define endl '\n'

using ll = long long;

using namespace std;

ll minimum_difference(vector<int> a, int n, int i = 0, ll sum_a = 0, ll sum_b = 0) {
    if (i >= n) {
        return abs(sum_a - sum_b);
    }

    ll group_a = minimum_difference(a, n, i + 1, sum_a + a[i], sum_b);
    ll group_b = minimum_difference(a, n, i + 1, sum_a, sum_b + a[i]);

    return min(group_a, group_b);
}

int solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0 ; i < n ; i++) cin >> a[i];

    cout << minimum_difference(a, n) << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}