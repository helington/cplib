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

void join(int u, int v, vector<int> &parent, vi &sz) {
    u = find(u, parent);
    v = find(v, parent);

    if (u == v) return;
    if (u < v) swap(u, v);

    parent[v] = u;
    sz[u] += sz[v];
}

int compute_edges(vector<pii> &edges, vi &parent, vi &sz, int n) {
    int total = 0;

    for (auto [u, v] : edges) {
        if (find(v, parent) != find(u, parent)) {
            join(u, v, parent, sz);
        }
    }

    f(i, 0, n) {
        int j;
        for (j = i; j < find(parent[i], parent); j++) {
            if (find(j, parent) != find(i, parent)) {
                join(i, j, parent, sz);
                total ++;
            }
        }
        i = j;
    }

    return total;
}

int solve() {
    int n, m; cin >> n >> m;

    vector<pii> edges(m);
    vector<vi> adj(n);
    f(i, 0, m) {
        int a, b; cin >> a >> b;
        if (a < b) swap(a, b);
        edges[i] = make_pair(a - 1, b - 1);
    }
    sort(all(edges), greater<pii>());

    vi parent(n);
    f(i, 0, n) parent[i] = i;
    vi sz(n, 1);

    int ans = compute_edges(edges, parent, sz, n);

    cout << ans << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}