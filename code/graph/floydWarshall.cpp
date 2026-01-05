// Floyd-Warshall (All-Pairs Shortest Path)

// Computes the shortest distance between every pair of vertices.

// O(n³)

int n;

vector<vector<ll>> floydWarshall(vector<vector<pair<int, ll>>> &adj) {
    vector<vector<ll>> dist(n, vector<ll>(n, LLONG_MAX));

    for (int u = 0; u < n; i++) {
        dist[u][u] = 0;
        for (auto [v, w] : adj[u]) dist[u][v] = min(dist[u][v], w);
    }

    for (int k = 0; k < n; k++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if ((dist[u][k]) != LLONG_MAX) and (dist[k][v] != LLONG_MAX) {
                    dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
                }
            }
        }
    }

    return dist;
}