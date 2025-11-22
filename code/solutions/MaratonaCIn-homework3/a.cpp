#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pii pair<int,int>

void dfs(vector<vector<int> > &adj, vector<bool> &vis, int u) {
    vis[u] = true;
    for (int v: adj[u]) {
        if (!vis[v]) dfs(adj, vis, v);
    }
}

int compute_components(vector<vector<int> > &adj, vector<bool> &vis, int n, int first, int second) {
    int components = 0;

    for (int i = 0 ; i < n; i++) {
        if ((i != first and i != second) and !vis[i]) {
            components++;
            dfs(adj, vis, i);
        }
    }

    return components;
}

vector<int> compute_degree(vector<pii> &edges, int n) {
    vector<int> degree(n);
    for (auto [u, v]: edges) {
        degree[u]++;
        degree[v]++;
    }
    return degree;
}

pii compute_better_degrees(vector<vector<int> > &adj, vector<int> &degree, vector<pii> &edges, int n) {
    int first, second;
    int better_degree = 0;
    for (int i = 0; i < n; i++) {
        if (better_degree < degree[i]) {
            better_degree = degree[i];
            first = i;
        }
    }

    int total_candidates = 0;
    vector<int> candidates;
    for (int i = 0 ; i < n; i++) {
        if (degree[i] == better_degree) {
            total_candidates++;
            candidates.push_back(i);
        }
    }

    for (int i = 0; i < candidates.size(); i++) {
        int current_total_candidates = 0;
        for (int u : adj[candidates[i]]) {
            if (degree[u] == better_degree) current_total_candidates++;
        }
        if (current_total_candidates == total_candidates - 1) continue;
        first = candidates[i];
        break;
    }

    for (auto [u, v]: edges) {
        if (u == first) degree[v]--;
        else if (v == first) degree[u]--;
    }

    better_degree = 0;
    for (int i = 0; i < n; i++) {
        if (i != first and better_degree <= degree[i]) {
            better_degree = degree[i];
            second = i;
        }
    }

    total_candidates = 0;
    candidates.clear();
    for (int i = 0 ; i < n; i++) {
        if (i != first and degree[i] == better_degree) {
            total_candidates++;
            candidates.push_back(i);
        }
    }

    for (int i = 0; i < candidates.size(); i++) {
        int current_total_candidates = 0;
        for (int u : adj[candidates[i]]) {
            if (degree[u] == better_degree) current_total_candidates++;
        }
        if (current_total_candidates == total_candidates - 1) continue;
        second = candidates[i];
        break;
    }

    return make_pair(first, second);
}

int solve() {
    int n; cin >> n;

    vector<vector<int> > adj(n);
    vector<pii> edges(n - 1);
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
        edges[i] = make_pair(u - 1, v - 1);
    }

    auto degree = compute_degree(edges, n);
    auto [first, second] = compute_better_degrees(adj, degree, edges, n);

    vector<vector<int> > newAdj(n);
    for (int i = 0; i < n - 1; i++) {
        auto [u, v] = edges[i];
        if (u == first or u == second or v == first or v == second) continue;

        newAdj[u].push_back(v);
        newAdj[v].push_back(u);
    }

    vector<bool> vis(n, false);
    int components = compute_components(newAdj, vis, n, first, second);

    cout << components << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while (tc--) {
        solve();
    }

    return 0;
}