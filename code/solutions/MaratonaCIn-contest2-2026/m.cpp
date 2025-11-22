#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

using ll = long long;

int solve() {
    int n;
    cin >> n;

    vector<int> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];

    ll alice_sum = 0;
    ll bob_sum = 0;
    int best_qnt = 0;

    int left = 0;
    int right = n - 1;
    while (left <= right) {
        if (alice_sum <= bob_sum) {
            alice_sum += w[left];
            left++;
        }
        else {
            bob_sum += w[right];
            right--;
        }

        if (alice_sum == bob_sum) {
            best_qnt = left + (n - 1 - right);
        }
    }

    cout << best_qnt << endl;

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