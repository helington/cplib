#include <bits/stdc++.h>
#include "point.cpp"

using namespace std;

// Convex Hull (Monotone Chain Algorithm)

// Finds the convex polygon enclosing a set of points.

// Time Complexity: O(N log N) (due to sorting)
// Space Complexity: O(N)

template <typename T>
vector<Point<T>> convex_hull(vector<Point<T>> v, bool include_collinear=false) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int n = (int) v.size();
    if (n <= 1) return v;

    vector<Point<T>> l, u;
    for (int i = 0; i < n; i++) {
        while (l.size() > 1 and !ccw(l.end()[-2], l.end()[-1], v[i], include_collinear))
            l.pop_back();
        l.push_back(v[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        while (u.size() > 1 and !ccw(u.end()[-2], u.end()[-1], v[i], include_collinear))
            u.pop_back();
        u.push_back(v[i]);
    }

    if (include_collinear and (int)u.size() == n) {
        reverse(u.begin(), u.end());
        return u;
    }

    l.pop_back(); u.pop_back();
    for (auto i : u) l.push_back(i);
    return l;
}