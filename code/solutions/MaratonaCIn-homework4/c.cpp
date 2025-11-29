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

vi get_pieces(vector<pair<int,int>> &edges, vi &parent, vi &sz, vector<bool> &filled, vi &tears, int n) {
    vi pieces;

    int components = n;
    f(i, 0, edges.size()) {
        auto [u, v] = edges[i];
        if (filled[i] and (find(u, parent) != find(v, parent))) {
            join(u, v, parent, sz);
            components--;
        };
    }

    reverse(all(tears));
    for (auto tear : tears) {
        auto [u, v] = edges[tear];
        pieces.push_back(components);
        if (find(u, parent) != find(v, parent)) {
            join(u, v, parent, sz);
            components--;
        }
    }
    reverse(all(pieces));

    return pieces;
}


int solve() {
    int n, m; cin >> n >> m;

    vector<pii> edges(m);
    f(i, 0, m) {
        ll a, b; cin >> a >> b;
        edges[i] = make_pair(a - 1, b - 1);
    }
    vector<bool> filled(m, true);

    int q; cin >> q;
    vi tears(q);
    f(i, 0, q) {
        int qi; cin >> qi; qi--;
        tears[i] = qi;
        filled[qi] = false;
    }

    vi parent(n);
    f(i, 0, n) parent[i] = i;
    vector<int> sz(n, 1);

    auto ans = get_pieces(edges, parent, sz, filled, tears, n);
    for (int v : ans) cout << v << " ";

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}