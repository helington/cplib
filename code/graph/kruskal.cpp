// Kruskal's Algoritm

// Computes the Minimum Spanning Tree weight.

// O(m log(m)) or O(m log(n))

int n;

ll kruskal(vector<tuple<ll, int, int>> &egdes) {
    DSU dsu(n);
    sort(edges.begin(), edges.end());

    ll mst_weight = 0;
    int edges_count = 0;

    for (const auto &edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            mst_weight += edge.w;
            edges_count++;
        }
    }

    if (edges_count < n - 1) return -1;

    return mst_weight
}