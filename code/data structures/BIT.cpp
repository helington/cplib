// Binary Indexed Tree (Fenwick Tree)

// Supports Point Updates and Range Sum Queries efficiently.
// NOTE: Uses 1-based indexing internally.

// - Update: O(log N)
// - Query: O(log N)
// - Construction: O(N)

template<typename T>
struct BIT {
    int N;
    vector<T> bit;

    BIT(int n) : N(n+1), bit(n+1, 0) {}

    BIT(const vector<T> &v) : N(v.size() + 1), bit(v.size() + 1, 0) {
        for (int i = 0; i < v.size(); i++) {
            bit[i + 1] = v[i];
        }

        for (int i = 1; i < N; i++) {
            int parent = i + (i & -i);
            if (parent < N) bit[parent] += bit[i];
        }
    }

    void update(int idx, T val) {
        for (; idx < N; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    T query(int idx) {
        T sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }

    T query(int l, int r) {
        return query(r) - query(l-1);
    }
};