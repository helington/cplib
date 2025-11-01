#include <bits/stdc++.h>

using namespace std;

int solve() {
    int n, t, q;
    cin >> t >> n >> q;

    vector<set<int> > baixados(n);
    for (int i = 0; i < q; i++) {
        int d, p, x;
        cin >> d >> p >> x;
        int final_day = d - 1 + x;
        if (final_day > n) {
            final_day = n;
        }
        for (int j = d - 1; j < final_day;j ++) {
            baixados[j].insert(p);
        }
    }

    int actual_student = 1;
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            cout << " ";
        }
        if (baixados[i].size() < t) {
            while (baixados[i].count(actual_student) != 0) {
                actual_student++;
                if (actual_student > t) {
                    actual_student = 1;
                }
            }
            cout << actual_student;
        } else {
            cout << "-1";
        }
        actual_student++;
        if (actual_student > t) {
            actual_student = 1;
        }
    }
    cout << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}