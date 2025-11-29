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

int find(int u, vector<int> &parent) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u],parent);
}

void join(int u, int v, vector<int> &parent, vector<int> &sz) {
    u = find(u, parent);
    v = find(v, parent);

    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);

    parent[v] = u;
    sz[u] += sz[v];
}

ll kruskal(vector<tuple<ll,int,int>> &edges, vi &perm, vector<int> &parent, vector<int> &sz, const int m) {
    sort(all(edges));

    ll total_cost = 0;
    f(i, 0, m) {
        if (perm[i] == 1) {
            auto [c, u, v] = edges[i];
            if (find(u, parent) == find(v, parent)) {
                return -1;
            }
            join(u, v, parent, sz);
            total_cost += c;
        }
    }

    return total_cost;
}

int solve() {
    int n, m; ll k; cin >> n >> m >> k;

    vector<tuple<ll, int, int>> edges(m);
    f(i, 0, m) {
        ll a, b, c; cin >> a >> b >> c;
        edges[i] = make_tuple(c, a - 1, b - 1);
    }

    vector<int> perm(m, 0);

    f(i, m - (n - 1), m) perm[i] = 1;
    ll ans = LLONG_MAX;
    do {
        vector<int> parent(n);
        f(i, 0, n) parent[i] = i;
        vector<int> sz(n, 1);
        ll current_ans = kruskal(edges, perm, parent, sz, m);

        if (current_ans != -1) ans = min(current_ans % k, ans);
    } while (next_permutation(all(perm)));

    cout << ans << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}