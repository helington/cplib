#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pii pair<int,int>

bool dfs(vector<vector<int> > &adj, vector<bool> &color, vector<bool> &vis, int v) {
    vis[v] = true;
    for (int u: adj[v]) {
        if (!vis[u]) {
            color[u] = !color[v];
            if (!dfs(adj, color, vis, u)) return false;;
        }
        else if (color[u] == color[v]) return false;
    }
    return true;
}

bool fill_colors(vector<vector<int> > &adj, vector<bool> &color, vector<bool> &vis, int m) {
    for (int i = 0; i < m; i++) {
        if (!vis[i]) {
            if (!dfs(adj, color, vis, i)) return false;
        }
    }
    return true;
}

bool crossedRoads(pii road1, pii road2) {
    vector<int> roads_in_ring(4);;
    roads_in_ring[0] = road1.first; roads_in_ring[1] = road1.second;
    roads_in_ring[2] = road2.first; roads_in_ring[3] = road2.second;
    sort(roads_in_ring.begin(), roads_in_ring.end());

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (roads_in_ring[i] == roads_in_ring[j]) return false;
        }
    }

    if (roads_in_ring[0] == road1.first and roads_in_ring[2] == road1.second) return true;
    else if(roads_in_ring[2] == road1.first and roads_in_ring[0] == road1.second)return true;
    else if (roads_in_ring[0] == road2.first and roads_in_ring[2] == road2.second) return true;
    else if(roads_in_ring[2] == road2.first and roads_in_ring[0] == road2.second)return true;
    return false;
}

int solve() {
    int n, m; cin >> n >> m;

    vector<pii> roads(m);
    int a, b;
    for (int i = 0 ; i < m ; i++) {
        cin >> a >> b;
        roads[i] = make_pair(a, b );
    }

    vector<vector<int> > adj(m);

    for (int i = 0 ; i < m; i++) {
        for (int j = i + 1 ; j < m ; j++) {
            if (crossedRoads(roads[i], roads[j])) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<bool> vis(m, false), color(m, false);

    bool ans = fill_colors(adj, color, vis, m);

    if (ans) {
        for (int i = 0 ; i < m ; i++) {
            if (color[i]) cout << "i";
            else cout << "o";
        }
    } else {
        cout << "Impossible";
    }
    cout << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}