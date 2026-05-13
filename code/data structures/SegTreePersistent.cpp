#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

// Persistent Segment Tree (Struct Implementation)

// Supports point updates and range queries over multiple versions.
// Versatile for Sum, Min, Max, and Range K-th Element queries.

// - Build: O(N)
// - Update: O(log N)
// - Query: O(log N)

// Space Complexity: O(N log N)

template<typename T>
struct PersistentSegTree {
    struct Node {
        int L, R;
        T val;
        Node() : L(0), R(0), val(0) {}
    };

    int N;
    vector<Node> tree;
    vector<int> roots;

    // Define based on specific problem: 0 for Sum, INF for Min, -INF for Max
    const T NEUTRAL = 0;

    PersistentSegTree(int n) : N(n), tree(40 * n) {
        tree.push_back(Node());
        roots.push_back(build(0, N - 1));
    }

    T join(T vl, T vr) { return vl + vr; }

    int new_node(T v=0) {
        tree.push_back(Node());
        tree.back().val = v;
        return tree.size() - 1;
    }

    int build(int l, int r) {
        int node = new_node();
        if (l == r) {
            tree[node].val = NEUTRAL; 
            return node;
        }
        int m = l + (r - l) / 2;
        tree[node].L = build(l, m);
        tree[node].R = build(m + 1, r);
        tree[node].val = join(tree[tree[node].L].val, tree[tree[node].R].val);
        return node;
    }

    int update(int prev_root, int l, int r, int idx, T val) {
        int node = new_node();
        tree[node] = tree[prev_root];
        if (l == r) {
            tree[node].val += val; // Para kth é soma. Substitua por '=' se for setar valor
            return node;
        }
        int m = l + (r - l) / 2;
        if (idx <= m)
            tree[node].L = update(tree[prev_root].L, l, m, idx, val);
        else
            tree[node].R = update(tree[prev_root].R, m + 1, r, idx, val);
        tree[node].val = join(tree[tree[node].L].val, tree[tree[node].R].val);
        return node;
    }

    int update(int prev_version_id, int idx, T val) {
        int new_root = update(roots[prev_version_id], 0, N - 1, idx, val);
        roots.push_back(new_root);
        return roots.size() - 1;
    }

    T query(int node, int l, int r, int a, int b) {
        if (b < l or r < a or node == 0) return NEUTRAL;
        if (a <= l and r <= b) return tree[node].val;

        int m = l + (r - l) / 2;
        return join(query(tree[node].L, l, m, a, b), 
                    query(tree[node].R, m + 1, r, a, b));
    }

    T query(int version_id, int a, int b) { return query(roots[version_id], 0, N - 1, a, b); }

    // Busca o K-ésimo elemento em um range [L, R]
    // OBS: É necessário que a operação 'join' seja de Soma.
    int kth(int node_l, int node_r, int l, int r, T k) {
        if (l == r) return l;
        
        int m = l + (r - l) / 2;
        T count_left = tree[tree[node_r].L].val - tree[tree[node_l].L].val;

        if (count_left >= k)
            return kth(tree[node_l].L, tree[node_r].L, l, m, k);
        else
            return kth(tree[node_l].R, tree[node_r].R, m + 1, r, k - count_left);
    }

    int kth(int l_version_id, int r_version_id, T k) { return kth(roots[l_version_id], roots[r_version_id], 0, N - 1, k); }
};