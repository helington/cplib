// Disjoint Set Union (DSU)

// Supports finding the representative of a set and merging two sets.

// O(alpha(n)) ~ O(1) amortized

struct DSU {
    vector<int> parent, sz;

    DSU(int n) : parent(n), sz(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return false;

        if (sz[u] < sz[v]) swap(u, v);

        sz[u] += sz[v];
        parent[v] = u;
        return true;
    }
};