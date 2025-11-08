#include <bits/stdc++.h>

#define endl '\n'

using ll = long long;

using namespace std;

ll compute_diagonals(vector<vector<int> > v, int n, int m, int current_i, int current_j, bool upper_left, bool upper_right, bool lower_left, bool lower_right) {
    ll sum = 0;
    if (upper_left) {
        for (int i = current_i - 1, j = current_j - 1; i >= 0 and j >= 0; i--, j--) {
            sum += v[i][j];
        }
    }
    if (upper_right) {
        for (int i = current_i - 1, j = current_j + 1; i >= 0 and j < m; i--, j++) {
            sum += v[i][j];
        }
    }
    if (lower_left) {
        for (int i = current_i + 1, j = current_j - 1; i < n and j >= 0; i++, j--) {
            sum += v[i][j];
        }
    }
    if (lower_right) {
        for (int i = current_i + 1, j = current_j + 1; i < n and j < m; i++, j++) {
            sum += v[i][j];
        }
    }

    return sum;
}

ll find_max_sum(vector<vector<int> > v, int n, int m) {
    ll max_sum = 0;
    ll current_sum;
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < m; j++) {
            current_sum = v[i][j];
            if (i == 0) {
                if (j == 0) {
                    current_sum += compute_diagonals(v, n, m, i, j, false, false, false, true);
                } else if (j == m - 1) {
                    current_sum += compute_diagonals(v, n, m, i, j, false, false, true, false);
                } else {
                    current_sum += compute_diagonals(v, n, m, i, j, false, false, true, true);
                }
            } else if (i == n - 1) {
                if (j == 0) {
                    current_sum += compute_diagonals(v, n, m, i, j, false, true, false, false);
                } else if (j == m - 1) {
                    current_sum += compute_diagonals(v, n, m, i, j, true, false, false, false);
                } else {
                    current_sum += compute_diagonals(v, n, m, i, j, true, true, false, false);
                }
            } else {
                if (j == 0) {
                    current_sum += compute_diagonals(v, n, m, i, j, false, true, false, true);
                } else if (j == m - 1) {
                    current_sum += compute_diagonals(v, n, m, i, j, true, false, true, false);
                } else {
                    current_sum += compute_diagonals(v, n, m, i, j, true, true, true, true);
                }
            }
            if (current_sum > max_sum) max_sum = current_sum;
        }
    }

    return max_sum;
}

int solve() {
    int n, m; cin >> n >> m;

    vector<vector<int> > v(n, vector<int>(m));
    for (int i = 0 ; i < n; i++) for (int j = 0; j < m; j++) cin >> v[i][j];

    cout << find_max_sum(v, n, m) << endl;

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