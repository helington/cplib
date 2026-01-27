// 1D Sweep Line

// Processes events on a timeline.
// Time Complexity: O(N log N) (due to sorting)

struct Event {
    int time;
    int type; // +1 for Start, -1 for End
    
    // Sort by time. 
    // If times are equal, process START (+1) before END (-1) to include boundaries.
    // If [L, R] is inclusive, end event should often be at R + 1.
    bool operator<(const Event& other) const {
        if (time != other.time) return time < other.time;
        return type > other.type; // Process +1 before -1
    }
};

int max_overlap(const vector<pair<int, int>>& intervals) {
    vector<Event> events;
    for (auto p : intervals) {
        events.push_back({p.first, 1});
        events.push_back({p.second, -1}); // Assumes interval is [L, R)
        // If interval is [L, R] inclusive, use: events.push_back({p.second + 1, -1});
    }
    sort(events.begin(), events.end());

    // Prefix sum idea
    int max_active = 0;
    int current_active = 0;

    for (auto e : events) {
        current_active += e.type;
        max_active = max(max_active, current_active);
    }
    return max_active;
}