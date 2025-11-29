#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define f(i,a,b) for(int i=a;i<b;i++)
#define all(x) (x).begin(),(x).end()
#define endl '\n'

vector<pll> get_non_zeros_balances(vector<pll> &balances) {
    vector<pll> non_zeros_balances;
    for (auto i : balances) {
        if (i.first != 0) non_zeros_balances.push_back(i);
    }
    return non_zeros_balances;
}

int solve() {
    int n, m; cin >> n >> m;

    vector<pll> balances(n);

    f(i, 0, n) balances[i].second = i;

    f(i, 0, m) {
        ll a, b, c; cin >> a >> b >> c;
        balances[a - 1].first -= c;
        balances[b - 1].first += c;
    }
    sort(all(balances), greater<pll>());
    auto non_zeros_balances = get_non_zeros_balances(balances);

    cout << non_zeros_balances.size() - 1 << endl;
    f(i, 1, non_zeros_balances.size()) {
        non_zeros_balances[i].first += non_zeros_balances[i - 1].first;
        cout << non_zeros_balances[i - 1].second + 1 << " " << non_zeros_balances[i].second + 1 << " " << non_zeros_balances[i - 1].first << endl;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}