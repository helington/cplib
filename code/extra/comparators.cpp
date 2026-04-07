// Some custom comparators

// NEVER use <= or >= in a comparator. Always use < or >. If a == b so comp must return false.

bool Comp(const int &a, const int &b) {
    return a > b;
}

//Usage:
vector<int> v;
sort(v.begin(), v.end(), Comp);

// LOWER_BOUND: (Array Element, Target Value)
auto it1 = lower_bound(v.begin(), v.end(), target_cost,
    [](const Item& elem, int val) {
        return elem.cost < val;
    });

// UPPER_BOUND: (Target Value, Array Element)
auto it2 = upper_bound(v.begin(), v.end(), target_cost,
    [](int val, const Item& elem) {
        return val < elem.cost;
    });


struct Comp {
    bool operator()(const int& a, const int& b) const {
        // Example: Sort odd numbers first, then evens
        if ((a % 2) != (b % 2)) return (a % 2) > (b % 2);
        return a < b; 
    }
};

// Usage:
set<int, CustomComp> s;
map<int, string, CustomComp> m;

// Priority Queue requires 3 arguments if you change the comparator:
// Type, Container (usually vector), Comparator
priority_queue<int, vector<int>, Comp> pq;
// REMEMBER: priority_queue is inverted! 
// If CustomComp returns a < b, the PQ will put the LARGEST element at the top.