// Dijkstra (Heap version)

// Computes the lowest cost from vertex 'b' to all other vertices.
// If dist[i] == LLONG_MAX, vertex 'i' is UNREACHABLE from 'b'.

// O((n + m)log(m))

// For all pairs: O(n³log(n))

int n;

vector<ll> dijkstra(vector<vector<pair<int, ll>>> &adj, int b) {
    vector<ll> dist(n, LLONG_MAX);
    dist[b] = 0;

    priority_queue<
        pair<ll, int>,
        vector<pair<ll, int>>,
        greater<pair<ll, int>>,
    > pq;
    pq.push({0, b});

    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d <= dist[u]) {
            for(auto [v, w] : adj[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    return dist;
}

// Dijkstra (Non-Heap version)

// Computes the lowest cost from vertex 'b' to all other vertices.
// If dist[i] == LLONG_MAX, vertex 'i' is UNREACHABLE from 'b'.

// O(n²)

// For all pairs: O(n³)

int n;

vector<ll> dijkstra(vector<vector<pair<int, ll>>> &adj, int b) {
    vector<ll> dist(n, LLONG_MAX);
    dist[b] = 0;

    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        int u = -1;
        ll mn = LLONG_MAX;

        for (int j = 0; j < n; j++) {
            if ((!visited[j]) and (dist[j] < mn)) {
                mn = dist[j];
                u = j;
            }
        }
        if (u==-1) break;

        visited[u] = true;

        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    return dist;
}