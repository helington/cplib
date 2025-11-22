#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define endl '\n'

bool dfs(
    int i, vector<vector<int> > &adj,vector<bool> &vis,
    vector<bool> &color, int &color1, int &color2
    ) {
    vis[i] = true;
    for (int &u: adj[i]) {
        if (!vis[u]) {
            color[u] = !color[i];
            if (color[u]) color1++; else color2++;
            if (!dfs(u, adj, vis, color, color1, color2)) return false;
        }
        else if (color[i]== color[u]) return false;
    }
    return true;
}

bool fill_colors(
    vector<vector<int> > &adj, vector<bool> &vis, vector<bool> &color,
    int n, vector<pair<pii, pii> > &combinations
    ) {
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            int color1 = 0, color2 = 1;
            if (!dfs(i, adj, vis, color, color1, color2)) {
                return false;
            }
            pii v = make_pair(color1, color2);
            swap(color1, color2);
            pii u = make_pair(color1, color2);
            if (combinations.empty()) {
                combinations.push_back(make_pair(v, u));
            } else {

            }
        }
    }
    return true;
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
    vector<pair<pii, pii> > combinations;

    bool possible = fill_colors(adj, vis, color, n, combinations);

    if (!possible) {
        cout << 0 << endl;
    } else {
        vector<pii> possibilities;
        while (possibilities.size() < combinations.size() * 2) {
            auto v = combinations.back(); combinations.pop_back();

        }
        ll result = color1 * color2;
        result -= m;
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