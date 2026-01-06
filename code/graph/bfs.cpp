// Standard BFS

// Computes the shortest distance from vertex 'b' to all other vertices.
// If dist[i] == -1, vertex 'i' is UNREACHABLE from 'b'.

// O(n + m)

int n;

vector<int> bfs(const vector<vector<int>> &adj, int b) {
    vector<int> dist(n, -1);
    dist[b] = 0;

    queue<int> q;
    q.push(b);

    while(!q.empty()) {
        int u = q.front(); q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist;
}

// Grid BFS

// Computes shortest distance from cell "b" to all others.
// If dist[i][j] == -1, the cell (i,j) is UNREACHABLE from the start.

// O(n * m)

int n; int m;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

bool isValid(int i, int j) {
    return i >= 0 and i < n and j >= 0 and j < m;
}

vector<vector<int>> bfs(vector<string> &grid, pair<int, int> b) {
    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[b.first][d.second] = 0;

    queue<pair<int, int>> q;
    q.push(b);

    while(q.empty()) {
        auto [i, j] = q.front(); q.pop();

        for (int k = 0; k < 4; k++) {
            int ni = i + dy[k];
            int nj = j + dx[k];

            if (isValid(ni, nj) and dist[ni][nj] == -1 and grid[ni][nj] != '#') {
                dist[ni][nj] = dist[i][j] + 1;
                q.push({ni, nj});
            }
        }
    }

    return dist;
}