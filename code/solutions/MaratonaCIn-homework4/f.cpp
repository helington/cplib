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

const ll INF=1e9*2500;

void dfs(vector<vi> &adj, vector<bool> &vis, int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) dfs(adj, vis, v);
    }
}

vector<tuple<int,int,int>> invert_edges(vector<tuple<int,int,int>> &edges, vector<vi> &adj) {
    vector<tuple<int,int,int>> new_edges;
    for (auto [w, u, v] : edges) {
        new_edges.push_back({w, v, u});
        adj[v].push_back(u);
    }
    return new_edges;
}

pair<ll, bool> bellman_ford(vector<tuple<int,int,int>> &edges, int n) {
    vector<ll> distFrom0(n, -INF);
    distFrom0[0] = 0;

    for (int i = 0 ; i < n - 1; i++) {
        for (auto edge : edges) {
            auto [w, u, v] = edge;
            distFrom0[v] = max(distFrom0[v], distFrom0[u] + w);
        }
    }

    vector<bool> vis0(n, false);
    vector<vi> adj0(n);
    for (auto [w, u, v] : edges) adj0[u].push_back(v);
    dfs(adj0, vis0, 0);

    bool cicloPositivoFrom0 = false;
    for (auto [w, u, v] : edges) {
        if (distFrom0[v] < distFrom0[u] + w) cicloPositivoFrom0 = true;
    }

    vector<ll> distFromN(n, -INF);
    distFromN[n - 1] = 0;
    vector<vi> adjN(n);
    auto new_edges = invert_edges(edges, adjN);

    vector<bool> visN(n, false);
    dfs(adjN, visN, n - 1);

    for (int i = 0 ; i < n - 1; i++) {
        for (auto edge : new_edges) {
            auto [w, u, v] = edge;
            distFromN[v] = max(distFromN[v], distFromN[u] + w);
        }
    }

    bool cicloPositivoFromN = false;
    for (auto [w, u, v] : new_edges) {
        if (visN[v] and vis0[v] and distFromN[v] < distFromN[u] + w) cicloPositivoFromN = true;
    }

    bool cicloPositivo = cicloPositivoFrom0 and cicloPositivoFromN;

    return {distFrom0[n - 1], cicloPositivo};
}

int solve() {
    int n, m; cin >> n >> m;

    vector<tuple<int, int, int>> edges(m);
    f(i, 0, m) {
        ll a, b, c; cin >> a >> b >> c;
        edges[i] = make_tuple(c, a - 1, b - 1);
    }

    auto [ans, cicloPositivo] = bellman_ford(edges, n);

    if (cicloPositivo) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}