#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b > a) {
        return gcd(b, a);
    }

    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }

    return a;
}

int greatest_gcd(vector<int> v, int best_gcd) {
    int current_gcd = gcd(v[0], v[1]);

    for (int i = 2; i < v.size(); i++) {
        current_gcd = gcd(v[i], current_gcd);
    }

    return max(current_gcd, best_gcd);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int smallest_lcm(vector<int> v, int best_lcm) {
    int current_lcm = lcm(v[0], v[1]);

    for (int i = 2; i < v.size(); i++) {
        current_lcm = lcm(v[i], current_lcm);
    }

    return min(current_lcm, best_lcm);
}

int solve() {
    int n;

    cin >> n;

    vector<int> best_gcds(n);
    int best_lcm;
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;

        vector<int> v(a);
        for (int j = 0; j < a; j++) {
            cin >> v[j];
        }

        vector<int> v_copy;
        v_copy = v;

        int best_gcd = 1;
        if (a > 2) {
            for (int j = 0; i < a; i++) {
                v_copy.erase(v.begin() + i);

                best_gcd = greatest_gcd(v_copy, best_gcd);

                v_copy.push_back(v[j]);
            }
        } else {
            best_gcd = max(v[0], v[1]);
        }
    }

    vector<int> best_gcds_copy;
    best_gcds_copy = best_gcds;
    for (int i = 0; i < n; i++) {
        best_gcds_copy.erase(best_gcds_copy.begin() + i);

        best_lcm = smallest_lcm(best_gcds_copy, best_lcm);

        best_gcds_copy.push_back(best_lcm);
    }

    cout << best_lcm << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}