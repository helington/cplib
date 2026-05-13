#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

// Disjoint Set Union (DSU)

// Supports finding the representative of a set and merging two sets.

// Time Complexity: O(alpha(N).
// Space Complexity: O(N)

struct DSU {
    vector<int> id, sz;

    DSU(int n) : id(n), sz(n, 1) { iota(id.begin(), id.end(), 0); }

    int find(int u) { return id[u] = (u == id[u] ? u : find(id[u])); }

    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v], id[v] = u;
        return true;
    }

    int size(int u) { return sz[find(u)]; }
    bool same(int u, int v) { return find(u) == find(v); }
};