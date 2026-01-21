// MinQueue 

// - Uses "Index/Timestamp" logic to track element validity.
// - push(x): Adds element to Queue.
// - pop(): Removes element from queue. (removes oldest element).
// - min(): Returns minimum Queue.

// O(1) amortized per operation.

struct MinQueue : deque<pair<int, int>> {
    int cnt_added;
    int cnt_removed;

    MinQueue() : cnt_added(0), cnt_removed(0) {}

    int min() {
        return front().first;
    }

    void push(int new_element) {
        while (!empty() && back().first > new_element)
            q.pop_back();
        
        push_back({new_element, cnt_added});
        cnt_added++;
    }

    void pop() {
        if (!empty() && front().second == cnt_removed)
            pop_front();
        
        cnt_removed++;
    }
};