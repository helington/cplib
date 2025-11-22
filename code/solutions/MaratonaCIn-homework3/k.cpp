#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pii pair<int,int>

map<pair<int, int>, vector<pii> > make_graph(vector<string> &maze, int n, int m) {
    map<pair<int, int>, vector<pii> > adj;
    vector<pair<int, int> > directions(4);
    directions[0] = make_pair(1, 0); directions[1] = make_pair(0, 1); directions[2] = make_pair(-1, 0); directions[3] = make_pair(0, -1);

    for (int i = 0 ; i < n; i++) {
        for (int j = 0 ; j < m; j++) {
            if (maze[i][j] != '#') {
                vector<pii> edges;

                for (auto [di, dj] : directions) {
                    int ni = i + di, nj = j + dj;

                    if (ni >= 0 and ni < n and nj >= 0 and nj < m and maze[ni][nj] != '#') {
                        edges.push_back(make_pair(ni, nj));
                    }
                }

                adj[make_pair(i, j)] = edges;
            }
        }
    }

    return adj;
}

void dfs(
    vector<string> &maze, map<pair<int, int>, vector<pii> > &adj, vector<vector<bool> > &vis,
    pair<int, int> position, int &good, int &bad)
{
    auto [i, j] = position;
    vis[i][j] = true;
    for (auto u_position: adj[position]) {
        auto [u_i, u_j] = u_position;
        if (!vis[u_i][u_j]) {
            if (maze[u_i][u_j] == 'G') good++;
            else if (maze[u_i][u_j] == 'B') bad++;
            dfs(maze, adj, vis, u_position, good, bad);
        }
    }
}

void block_bads(vector<string> &maze, vector<pii> &bads, int n, int m) {
    vector<pair<int, int> > directions(4);
    directions[0] = make_pair(1, 0); directions[1] = make_pair(0, 1); directions[2] = make_pair(-1, 0); directions[3] = make_pair(0, -1);

    for (auto [i_bad, j_bad]: bads) {
        for (auto [di, dj] : directions) {
            int ni = i_bad + di, nj = j_bad + dj;

            if (ni >= 0 and ni < n and nj >= 0 and nj < m and maze[ni][nj] == '.') {
                maze[ni][nj] = '#';
            }
        }
    }
}

bool solve_maze(vector<string> &maze, vector<pii> &goods, vector<pii> &bads, int n, int m) {
    block_bads(maze, bads, n, m);
    auto adj = make_graph(maze, n, m);

    int good = 0, bad = 0;
    vector<vector<bool> > vis(n, vector<bool>(m, false));
    dfs(maze, adj, vis, make_pair(n - 1, m - 1), good, bad);
    if (good == goods.size() and bad == 0) return true;
    return false;
}

int solve() {
    int n, m; cin >> n >> m;

    vector<string> maze(n);
    for (int i = 0 ; i < n ; i++) cin >> maze[i];

    vector<pii> bads, goods;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (maze[i][j] == 'B') bads.push_back(make_pair(i, j)); else if (maze[i][j] == 'G') goods.push_back(make_pair(i, j));

    bool ans = solve_maze(maze, goods, bads, n, m);

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc; while(tc--) {
        solve();
    }

    return 0;
}