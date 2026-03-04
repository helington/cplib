#include <bits/stdc++.h>

using namespace std;

// 2D Point Template

template <typename T>
struct Point {
    T x, y;

    Point(T _x=0, T _y=0) : x(_x), y(_y) {}

    Point operator + (Point o) const { return Point(x + o.x, y + o.y); }
    Point operator - (Point o) const { return Point(x - o.x, y - o.y); }
    Point operator * (T k) const { return Point(k * x, k * y); } // Scalar's product
    Point operator / (T k) const { return Point(x / k, y / k); }

    T operator * (Point o) const { return x * o.y - y * o.x; } // Cross product
    T operator ^ (Point o) const { return x * o.x + y * o.y; } // Dot product

    double len()  const {return hypot(x, y); };
    T len2() const { return x * x + y * y; }

    bool operator == (Point o) const { return tie(x, y) == tie(o.x, o.y); }
    bool operator < (Point o) const { return tie(x, y) < tie(o.x, o.y); }

    friend ostream &operator << (ostream &out, const Point<T> &p) {
        return out << "(" << p.x << ", " << p.y << ")";
    }
    friend istream &operator >> (istream &in, Point<T> &p) {
        return in >> p.x >> p.y;
    }

    friend double dist(Point a, Point b) { return hypot(a.y - b.y, a.x - b.x); }
    friend T dist2(Point a, Point b) {
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    }
};

template <typename T>
int orientation(Point<T> a, Point<T> b, Point<T> c) {
    auto ab = b - a;
    auto bc = c - b;

    auto v = ab * bc;

    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

template <typename T>
bool cw(Point<T> a, Point<T> b, Point<T> c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 or (include_collinear and o == 0);
}

template <typename T>
bool ccw(Point<T> a, Point<T> b, Point<T> c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o > 0 or (include_collinear and o == 0);
}