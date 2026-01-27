// Coordinate Compression

// Maps large sparse values to dense indices [0, 1, 2...].
// Time Complexity: O(N log N)

template<typename T>
void compress(vector<T> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

// Returns the rank (0-based index) of 'val'
template<typename T>
int get_id(const vector<T> &v, T val) {
    return lower_bound(v.begin(), v.end(), val) - v.begin();
}