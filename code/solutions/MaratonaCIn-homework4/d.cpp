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
    return find(parent[u],parent);
}

void join(int u, int v, vector<int> &parent, vector<int> &sz) {
    u = find(u, parent);
    v = find(v, parent);

    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);

    parent[v] = u;
    sz[u] += sz[v];
}

ll kruskal(vector<tuple<int,int,int>> &edges, vector<int> &parent, vector<int> &sz) {
    sort(all(edges));

    ll total_cost = 0;
    for (auto [cost, u, v] : edges) {
        if (find(u, parent) != find(v, parent)) {
            join(u, v, parent, sz);
            total_cost += cost;
        }
    }

    return total_cost;
}

void dfs(vector<vi> &adj, vector<bool> &vis, int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) dfs(adj, vis, v);
    }
}

bool check_solution(vector<vi> &adj, int n) {
    vector<bool> vis(n);

    dfs(adj, vis, 0);

    for (int i = 0 ; i < n; i++) if (!vis[i]) return false;
    return true;
}

int solve() {
    int n, m; cin >> n >> m;

    vector<tuple<int, int, int>> edges(m);
    vector<vi> adj(n);
    f(i, 0, m) {
        ll a, b, c; cin >> a >> b >> c;
        edges[i] = make_tuple(c, a - 1, b - 1);
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    bool solution = check_solution(adj, n);
    if (!solution) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> parent(n);
    f(i, 0, n) parent[i] = i;
    vector<int> sz(n, 1);

    ll ans = kruskal(edges, parent, sz);
    cout << ans << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}