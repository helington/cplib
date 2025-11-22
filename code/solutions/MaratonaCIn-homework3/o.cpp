#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool dfs(
    int i, vector<vector<int> > &adj,vector<bool> &vis,
    vector<bool> &color, ll &color1, ll &color2, ll &edges
    ) {
    vis[i] = true;
    for (int &u: adj[i]) {
        edges++;
        if (!vis[u]) {
            color[u] = !color[i];
            if (color[u]) color1++; else color2++;
            if (!dfs(u, adj, vis, color, color1, color2, edges)) return false;
        }
        else if (color[i]== color[u]) return false;
    }
    return true;
}

bool fill_colors(
    vector<vector<int> > &adj, vector<bool> &vis, vector<bool> &color,
    int n, vector<ll> &possibilities, vector<ll> &components
    ) {
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            ll color1 = 0, color2 = 1;
            ll edges = 0;
            if (!dfs(i, adj, vis, color, color1, color2, edges)) return false;
            edges /= 2;
            possibilities.push_back(color1 * color2 - edges);
            components.push_back(color1 + color2);
        }
    }
    return true;
}

ll compute_possibilities(vector<ll> &possibilities, vector<ll> &components) {
    if (possibilities.size() == 1) return possibilities[0];

    ll sum = 0, quadratic_sum = 0, possibilites_sum = 0;
    for (int i = 0; i < components.size(); i++) {
        sum += components[i];
        quadratic_sum += pow(components[i], 2);
        possibilites_sum += possibilities[i];
    }
    ll result = (pow(sum, 2) - quadratic_sum)/2;
    result += possibilites_sum;

    return result;
}

int solve() {
    int n, m; cin >> n >> m;

    vector<vector<int> > adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    vector<bool> vis(n, false);
    vector<bool> color(n, false);
    vector<ll> possibilities, components;

    bool possible = fill_colors(adj, vis, color, n, possibilities, components);

    if (!possible) {
        cout << 0 << endl;
    } else {
        ll result = compute_possibilities(possibilities, components);
        cout << result << endl;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}