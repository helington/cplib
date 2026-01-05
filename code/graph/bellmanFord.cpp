// Bellman-Ford

// Computes shortest paths from 'b' handling negative edges.
// If an empty vector is returned {}, a negative cycle is detected.
// If dist[i] == INF, it's unreachable.

// O(n * m)

int n;

const ll INF = 1e18; // based on question's contraints

vector<ll> bellmanFord(vector<vector<pair<int, ll>>> &adj, int b) {
    vector<ll> dist(n, INF);
    dist[b] = 0;

    for (int i = 0; i < n - 1; i++) {
        bool any_update = false;

        for (int u = 0; u < n; u++) {
            if (dist[u] == INF) continue;

            for (auto [v, w] : adj[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    any_update = true;
                }
            }
        }

        if (!any_update) break;
    }

    for (int u = 0; u < n; u++) {
        if (dist[u] == INF) continue;

        for(auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                return {};
            }
        }
    }

    return dist;
}