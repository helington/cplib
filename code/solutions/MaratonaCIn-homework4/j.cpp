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

vl get_inconveniences(vector<pii> &edges, vi &parent, vi &sz, const int n, const int m) {
    vl inconveniences;

    ll inconvencience = ((ll) n * (ll) (n - 1)) / 2ll;
    inconveniences.push_back(inconvencience);

    reverse(all(edges));
    f(i, 0, m - 1) {
        auto [u, v] = edges[i];
        u = find(u, parent); v = find(v, parent);
        if (u != v) {
            inconvencience -= (ll) sz[u] * (ll) sz[v];
            join(u, v, parent, sz);
        }
        inconveniences.push_back(inconvencience);
    }
    reverse(all(inconveniences));

    return inconveniences;
}

int solve() {
    int n, m; cin >> n >> m;

    vector<pii> edges(m);
    f(i, 0, m) {
        int a, b; cin >> a >> b;
        edges[i] = make_pair(a - 1, b - 1);
    }

    vi parent(n);
    f(i, 0, n) parent[i] = i;
    vector<int> sz(n, 1);

    auto ans = get_inconveniences(edges, parent, sz, n, m);
    for (auto v : ans) cout << v << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}